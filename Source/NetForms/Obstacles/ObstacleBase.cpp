// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleBase.h"

// Sets default values
AObstacleBase::AObstacleBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Obstacle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObstacleMesh"));
	SetRootComponent(SM_Obstacle);

	TBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TBOX"));
	TBox->SetGenerateOverlapEvents(true);
	TBox->SetupAttachment(RootComponent);
	//SM_Obstacle->SetSimulatePhysics(true);
	//SM_Obstacle->SetEnableGravity(false);

	ForceDir = FVector();

	ForceMag = 5.0f;
}

// Called when the game starts or when spawned
void AObstacleBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstacleBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObstacleBase::TriggerEnter(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

}

void AObstacleBase::TriggerExit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 otherBodyIndex)
{

}
