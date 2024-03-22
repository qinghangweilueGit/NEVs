// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include"Camera/CameraComponent.h"
#include"MotionControllerComponent.h"
#include"Components/WidgetInteractionComponent.h"

#include "GameFramework/Character.h"
#include "N_Character.generated.h"


UCLASS()
class NEVS_API AN_Character : public ACharacter
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Camera")
	UCameraComponent* Camera;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MotionController")
	UMotionControllerComponent* LeftMotionController;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MotionController")
	UMotionControllerComponent* RightMotionController;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="WidgetInteraction")
	UWidgetInteractionComponent* LeftWidgetInteraction;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="WidgetInteraction")
	UWidgetInteractionComponent* RightWidgetInteraction;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="StaticMesh")
	UStaticMeshComponent* LeftHand;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="StaticMesh")
	UStaticMeshComponent* RightHand;

public:
	// Sets default values for this character's properties
	AN_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
