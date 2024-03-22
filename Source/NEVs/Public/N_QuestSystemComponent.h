// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintNodeHelpers.h"
#include "N_Struct.h"
#include "Components/ActorComponent.h"
#include "N_QuestSystemComponent.generated.h"


UCLASS( Blueprintable,ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEVS_API UN_QuestSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	//当前任务
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Quest")
	FQuestStruct CurrentTask;
	//查找的数据表
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	UDataTable* DT_Quest;
	//是否开启提示
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	bool Tips=false;
private:
	//传引用，项目中不会和这个值联动
	 bool Succes=false;
public:	
	// Sets default values for this component's properties
	UN_QuestSystemComponent();

	//根据传入的数据表和id进行任务加载
	UFUNCTION(BlueprintCallable,Category="Quest")
	const FQuestStruct LoadingTasksByDataTable(UDataTable* QuestDataTable,int32 QuestID,  bool& Success);
	//流程提示
	UFUNCTION(BlueprintCallable,Category="QuestTips")
	void ProcessTips(const bool& IsTips );
	//步骤提示
	UFUNCTION(BlueprintCallable,Category="QuestTips")
	void StepTips(const bool& IsTips );

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
