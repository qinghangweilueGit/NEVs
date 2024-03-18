// Fill out your copyright notice in the Description page of Project Settings.


#include "N_SceneUIActor.h"

// Sets default values
AN_SceneUIActor::AN_SceneUIActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	WidgetComponent=CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	WidgetComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AN_SceneUIActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AN_SceneUIActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

