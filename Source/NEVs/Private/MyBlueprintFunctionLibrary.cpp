// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

#include "Engine/StaticMesh.h"
#include "Misc/FileHelper.h"
#include "Async/Async.h"
#include "Misc/Paths.h"
#include "HAL/FileManager.h"
#include "HAL/PlatformFilemanager.h"
#include"Json.h"
#include"JsonObjectConverter.h"

#include "SocketSubsystem.h"
#include "Sockets.h"
#include "IPAddress.h"
//获取静态网格体信息
#include "AssetRegistryModule.h"
#include "Engine/StaticMesh.h"

FString UMyBlueprintFunctionLibrary::GetProjectDirectory()
{
	FString ProjectDir=FPaths::ProjectDir();
	return ProjectDir;
}

bool UMyBlueprintFunctionLibrary::ReadFile(FString FileName,FString& OutData,FString& FilePath)
{
	FString ProjectDir=GetProjectDirectory();
	FilePath=FPaths::Combine(ProjectDir,*FileName);
	
	return FFileHelper::LoadFileToString(OutData,*FilePath);
}


bool UMyBlueprintFunctionLibrary::WriteFile(FString FileName, FString Data)
{
	FString ProjectDir=GetProjectDirectory();
	FString FilePath=FPaths::Combine(ProjectDir,*FileName);
	return FFileHelper::SaveStringToFile(Data,*FilePath);
}

bool UMyBlueprintFunctionLibrary::RemoveFile(FString FilePath)
{
	IFileManager& FileManager=IFileManager::Get();
	if(FileManager.DirectoryExists(*FilePath))
	{
		if(FileManager.DeleteDirectory(*FilePath,false,true))
		{
			UE_LOG(LogTemp, Warning, TEXT("File deleted successfully: %s"), *FilePath);
			return true;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to delete directory: %s"), *FilePath);
			return false;
		}
	}
	else
	{
		if(FileManager.Delete(*FilePath,false,true,false))
		{
			UE_LOG(LogTemp, Warning, TEXT("File deleted successfully: %s"), *FilePath);
			return true;
		}
	
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to delete directory: %s"), *FilePath);
			return false;
		}
	}
	

}

TArray<FVector> UMyBlueprintFunctionLibrary::ArrangeActorsInHalfCircle_1(TArray<AActor*> Actors, FVector CenterLocation,
                                                                         float Radius)
{

	TArray<FVector> Locations;
	int32 NumActors = Actors.Num();
	if (NumActors == 0)
	{
		// 如果没有传入任何Actor，直接返回
		return Locations;
	}

	float LatitudeIncrement = 90.0f / (NumActors - 1); // 纬度角度增量
	float LongitudeIncrement = 360.0f / NumActors; // 经度角度增量

	for (int32 Index = 0; Index < NumActors; ++Index)
	{
		// 计算当前Actor的纬度角度和经度角度
		float CurrentLatitude = Index * LatitudeIncrement;
		float CurrentLongitude = Index * LongitudeIncrement;

		// 将角度转换为弧度
		float LatitudeRadians = FMath::DegreesToRadians(CurrentLatitude);
		float LongitudeRadians = FMath::DegreesToRadians(CurrentLongitude);

		// 计算Actor的位置，以球坐标系表示
		FVector Offset = FVector(
			Radius * FMath::Sin(LatitudeRadians) * FMath::Cos(LongitudeRadians),
			Radius * FMath::Sin(LatitudeRadians) * FMath::Sin(LongitudeRadians),
			Radius * FMath::Cos(LatitudeRadians)
		);

		// 最终位置 = 中心位置 + 偏移
		FVector FinalLocation = CenterLocation + Offset;

		// 设置Actor的位置
		//Actors[Index]->SetActorLocation(FinalLocation);
		Locations.Add(FinalLocation);
	}
	return Locations;
}

TArray<FVector> UMyBlueprintFunctionLibrary::ArrangeActorsInHalfCircle_2(TArray<AActor*> Actors, FVector CenterLocation, float Radius, int32 Rows, int32 Columns)
{
	TArray<FVector> Locations;
	int32 NumActors = Actors.Num();
	if (NumActors == 0)
	{
		// 如果没有传入任何Actor，直接返回
		return Locations;
	}

	if (Rows <= 0 || Columns <= 0)
	{
		// 防止除以零或者无效的行列数
		return Locations;
	}

	float RowSpacing = 2.0f * Radius / (Rows - 1);
	float ColumnSpacing = 2.0f * Radius / (Columns - 1);

	for (int32 RowIndex = 0; RowIndex < Rows; ++RowIndex)
	{
		for (int32 ColumnIndex = 0; ColumnIndex < Columns; ++ColumnIndex)
		{
			int32 ActorIndex = RowIndex * Columns + ColumnIndex;

			if (ActorIndex >= NumActors)
			{
				// 如果超过了Actor的数量，退出循环
				return Locations;
			}

			// 计算当前Actor的位置
			FVector Offset = FVector(
				-Radius + ColumnIndex * ColumnSpacing,
				-Radius + RowIndex * RowSpacing,
				0.0f
			);

			// 最终位置 = 中心位置 + 偏移
			FVector FinalLocation = CenterLocation + Offset;

			// 设置Actor的位置
			//Actors[ActorIndex]->SetActorLocation(FinalLocation);
			Locations.Add(FinalLocation);
		}
	}
	return  Locations;
}

TArray<FVector> UMyBlueprintFunctionLibrary::ArrangeActorsInHalfCircle_3(TArray<AActor*> Actors, FVector CenterLocation, float Radius, int32 Rows, int32 Columns)
{
	TArray<FVector> Locations;
	int32 NumActors = Actors.Num();
	if (NumActors == 0)
	{
		UE_LOG(LogTemp,Warning,TEXT("aaaaa"));
		// 如果没有传入任何Actor，直接返回
		return Locations;
		
	}

	if (Rows <= 0 || Columns <= 0)
	{
		UE_LOG(LogTemp,Warning,TEXT("bbb"));
		// 防止除以零或者无效的行列数
		return Locations;
	}

	float LatitudeIncrement = 90.0f / (Rows - 1); // 纬度角度增量
	float LongitudeIncrement = 360.0f / Columns; // 经度角度增量

	for (int32 RowIndex = 0; RowIndex < Rows; ++RowIndex)
	{
		for (int32 ColumnIndex = 0; ColumnIndex < Columns; ++ColumnIndex)
		{
			int32 ActorIndex = RowIndex * Columns + ColumnIndex;

			if (ActorIndex >= NumActors)
			{
				// 如果超过了Actor的数量，退出循环
				UE_LOG(LogTemp,Warning,TEXT("cccc"));
				return Locations;
			}

			// 计算当前Actor的纬度角度和经度角度
			float CurrentLatitude = 90.0f - RowIndex * LatitudeIncrement;
			float CurrentLongitude = ColumnIndex * LongitudeIncrement;

			// 将角度转换为弧度
			float LatitudeRadians = FMath::DegreesToRadians(CurrentLatitude);
			float LongitudeRadians = FMath::DegreesToRadians(CurrentLongitude);

			// 计算Actor的位置，以球坐标系表示
			FVector Offset = FVector(
				Radius * FMath::Sin(LatitudeRadians) * FMath::Cos(LongitudeRadians),
				Radius * FMath::Sin(LatitudeRadians) * FMath::Sin(LongitudeRadians),
				Radius * FMath::Cos(LatitudeRadians)
			);

			// 最终位置 = 中心位置 + 偏移
			FVector FinalLocation = CenterLocation + Offset;

			// 设置Actor的位置
			//Actors[ActorIndex]->SetActorLocation(FinalLocation);
			Locations.Add(FinalLocation);
		}
	}
	return  Locations;
}
