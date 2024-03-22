// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Actor.h"
#include "N_ItemActor.generated.h"

UCLASS()
class NEVS_API AN_ItemActor : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components")
	USceneComponent* IA_SceneComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components")
	UStaticMeshComponent* IA_StaticMesh;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components")
	UArrowComponent* IA_Arrow;
public:	
	// Sets default values for this actor's properties
	AN_ItemActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
