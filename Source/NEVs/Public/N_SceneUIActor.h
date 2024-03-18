// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Actor.h"
#include "N_SceneUIActor.generated.h"

UCLASS()
class NEVS_API AN_SceneUIActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AN_SceneUIActor();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UWidgetComponent* WidgetComponent;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
