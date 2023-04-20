// Fill out your copyright notice in the Description page of Project Settings.


#include "StepStone.h"
#include "GameFramework/Character.h"

// Sets default values
AStepStone::AStepStone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStepStone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStepStone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector currLocation = GetActorLocation();
	currLocation += movDir * speed * DeltaTime;
	SetActorLocation(currLocation);
}

