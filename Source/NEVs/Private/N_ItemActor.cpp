// Fill out your copyright notice in the Description page of Project Settings.


#include "N_ItemActor.h"

// Sets default values
AN_ItemActor::AN_ItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	IA_SceneComponent=CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent=IA_SceneComponent;
	IA_StaticMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	IA_StaticMesh->SetupAttachment(IA_SceneComponent);
	IA_Arrow=CreateDefaultSubobject<UArrowComponent>(TEXT("InteractivePositionArrow"));
	IA_Arrow->SetupAttachment(IA_SceneComponent);
}

// Called when the game starts or when spawned
void AN_ItemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AN_ItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

