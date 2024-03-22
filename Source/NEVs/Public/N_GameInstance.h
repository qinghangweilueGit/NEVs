// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include"N_Struct.h"
#include "Engine/GameInstance.h"
#include "N_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class NEVS_API UN_GameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	EMoudle Moudle;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Quest")
	FQuestStruct CurrentTask;
public:
	//根据传入的数据表和id进行任务加载
	UFUNCTION(BlueprintCallable,Category="Quest")
	const FQuestStruct LoadingTasksByDataTable(UDataTable* QuestDataTable,int32 QuestID,  bool& Success);

};
