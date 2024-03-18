// Fill out your copyright notice in the Description page of Project Settings.


#include "N_Character.h"

#include "MotionControllerComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/WidgetInteractionComponent.h"

// Sets default values
AN_Character::AN_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Camera=CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
	LeftMotionController=CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftMotionController"));
	LeftMotionController->SetupAttachment(RootComponent);
	RightMotionController=CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightMotionController"));
	RightMotionController->SetupAttachment(RootComponent);
	LeftWidgetInteraction=CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("LeftWidgetInteraction"));
	LeftWidgetInteraction->SetupAttachment(LeftMotionController);
	RightWidgetInteraction=CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("RightWidgetInteraction"));
	RightWidgetInteraction->SetupAttachment(RightMotionController);
	LeftHand=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftHand"));
	LeftHand->SetupAttachment(LeftMotionController);
	RightHand=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightHand"));
	RightHand->SetupAttachment(RightMotionController);
}

// Called when the game starts or when spawned
void AN_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AN_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AN_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

