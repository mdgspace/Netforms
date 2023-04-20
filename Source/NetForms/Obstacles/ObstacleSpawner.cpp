// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleSpawner.h"
#include "ObstacleBase.h"

// Sets default values
AObstacleSpawner::AObstacleSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);
}

// Called when the game starts or when spawned
void AObstacleSpawner::BeginPlay()
{
	Super::BeginPlay();

	TimeTillNextSpawn = TimeBetweenSpawn;
}

// Called every frame
void AObstacleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeTillNextSpawn -= DeltaTime;

	if (TimeTillNextSpawn < 0)
	{
		GetWorld()->SpawnActor<AObstacleBase>(BP_Obstacle,GetActorLocation(),GetActorRotation());
		TimeTillNextSpawn = TimeBetweenSpawn;
	}
}

