// Fill out your copyright notice in the Description page of Project Settings.


#include "N_QuestSystemComponent.h"
#include"Engine/DataTable.h"
#include "Kismet/GameplayStatics.h"
#include"UObject/ConstructorHelpers.h"

// Sets default values for this component's properties
UN_QuestSystemComponent::UN_QuestSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UDataTable> QuestDatatableBP(TEXT("/Script/Engine.DataTable'/Game/N_DataTable/DT_Quest.DT_Quest'"));
	DT_Quest=QuestDatatableBP.Object;
	// ...
	
}

//根据数据表加载任务
const FQuestStruct UN_QuestSystemComponent::LoadingTasksByDataTable(UDataTable* QuestDataTable,int32 QuestID,  bool& Success)
{
	Success=false;
	FQuestStruct Temp;
	if(!QuestDataTable)
	{
		UE_LOG(LogTemp,Warning,TEXT("DataTable is null!!!"));
		return Temp;
	}
	if(QuestDataTable->RowStruct==FQuestStruct::StaticStruct())
	{
		static const FString ContextString(TEXT("FindQuestByID"));
		for(const auto& Pair:QuestDataTable->GetRowMap())
		{
			const FQuestStruct* Row=reinterpret_cast<FQuestStruct*>(Pair.Value);
			if(Row&&Row->QuestID==QuestID)
			{
				Temp=*Row;
				Success=true;
				return Temp;
			}
		}
	}
	
	return Temp;
}

void UN_QuestSystemComponent::ProcessTips(const bool& IsTips)
{
	if(IsTips)
	{
		
	}
	else
	{
		
	}
}

void UN_QuestSystemComponent::StepTips(const bool& IsTips)
{
	if(IsTips)
	{
		
	}
	else
	{
		
	}
}




// Called when the game starts
void UN_QuestSystemComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentTask=LoadingTasksByDataTable(DT_Quest,1001,Succes);
	

}


// Called every frame
void UN_QuestSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

