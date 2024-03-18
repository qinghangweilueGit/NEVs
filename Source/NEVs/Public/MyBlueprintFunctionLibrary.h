// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class NEVS_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	//获取项目目录
	UFUNCTION(BlueprintCallable)
	static FString GetProjectDirectory();
	//读取内容
	UFUNCTION(BlueprintCallable)
	static bool ReadFile(FString FileName,FString& OutData,FString& FilePath);
	//写入内容
	UFUNCTION(BlueprintCallable)
	static bool WriteFile(FString FileName, FString Data);
	//删除文件
	UFUNCTION(BlueprintCallable)
	static bool RemoveFile(FString FilePath);
	
	//矩阵排列
	//螺旋上升排列
	UFUNCTION(BlueprintCallable)
	static TArray<FVector>  ArrangeActorsInHalfCircle_1(TArray<AActor*> Actors,FVector CenterLocation,float Radius);
	//平面矩阵排序
	UFUNCTION(BlueprintCallable)
	static TArray<FVector>  ArrangeActorsInHalfCircle_2(TArray<AActor*> Actors, FVector CenterLocation, float Radius, int32 Rows, int32 Columns);
	//圆球矩阵排序
	UFUNCTION(BlueprintCallable)
	static TArray<FVector>  ArrangeActorsInHalfCircle_3(TArray<AActor*> Actors, FVector CenterLocation, float Radius, int32 Rows, int32 Columns);

};
