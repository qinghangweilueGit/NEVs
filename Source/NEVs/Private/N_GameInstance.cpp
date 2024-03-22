// Fill out your copyright notice in the Description page of Project Settings.


#include "N_GameInstance.h"
#include"Engine/DataTable.h"

const FQuestStruct UN_GameInstance::LoadingTasksByDataTable(UDataTable* QuestDataTable, int32 QuestID, bool& Success)
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
