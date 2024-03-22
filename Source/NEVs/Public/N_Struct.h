// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "N_Struct.generated.h"

UENUM(BlueprintType)
enum class ECompletedStatus: uint8
{
	Unfinished	UMETA(DisplayName="未完成"),
	InProgress UMETA(DisplayName="进行中"),
	Completed	UMETA(DisplayName="已完成")
};
UENUM(BlueprintType)
enum class EMoudle: uint8
{
	cognition	UMETA(DisplayName="认知"),
	PracticalTraining UMETA(DisplayName="实训"),
	assessment	UMETA(DisplayName="考核")
};
UENUM(BlueprintType)
enum class ECognitiveFunction: uint8
{
	Default	UMETA(DisplayName="默认"),
	Perspective UMETA(DisplayName="透视")
};
UENUM(BlueprintType)
enum class ESubtaskType: uint8
{
	Disassembly	UMETA(DisplayName="拆卸"),
	Installation UMETA(DisplayName="安装"),
	Detection	UMETA(DisplayName="检测"),
	Maintenance UMETA(DisplayName="维修"),
	SelectionTool UMETA(DisplayName="选择工具"),
	WearTools UMETA(DisplayName="穿戴工具")
};
//物品
USTRUCT(BlueprintType)
struct FItemDataStruct:public FTableRowBase
{
public:
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 ID;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString Name;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UTexture2D* Icon;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString Description;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	USoundWave* DescriptionSound;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	AActor* StaticActor;
};
//任务子流程
USTRUCT(BlueprintType)
struct FQuestSubtaskStruct:public FTableRowBase
{
public:
	GENERATED_BODY()
	//子流程ID
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 SubtaskID;
	//
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString SubtaskName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	ECompletedStatus Complete;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 Number;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 Mark;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString Content;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString ProcessPromp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	ESubtaskType Type=ESubtaskType::Disassembly;

};
//任务
USTRUCT(BlueprintType)
struct FQuestStruct:public FTableRowBase
{
public:
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 QuestID;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString QuestName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString Content;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UTexture2D* QuestIcon;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 QuestLimitTime;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 QuestTime;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 QuestMark;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	ECompletedStatus Complete;
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	AActor* QuestActor;
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TArray<FQuestSubtaskStruct> Subtask;

};
UCLASS()
class NEVS_API UN_Struct : public UObject
{
	GENERATED_BODY()
	
};
