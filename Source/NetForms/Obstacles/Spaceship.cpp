// Fill out your copyright notice in the Description page of Project Settings.


#include "Spaceship.h"
#include "GameFramework/Character.h"

// Sets default values
ASpaceship::ASpaceship()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TBox->OnComponentBeginOverlap.AddDynamic(this, &ASpaceship::TriggerEnter);
	TBox->OnComponentEndOverlap.AddDynamic(this, &ASpaceship::TriggerExit);
}

// Called when the game starts or when spawned
void ASpaceship::BeginPlay()
{
	Super::BeginPlay();
}

void ASpaceship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}


void ASpaceship::TriggerEnter(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::TriggerEnter(HitComponent, OtherActor, OtherComp, otherBodyIndex, bFromSweep, SweepResult);

	OtherCharacter = Cast<ACharacter>(OtherActor);
	PlayerController = Cast<APlayerController>(OtherActor);

	OtherCharacter->DisableInput(PlayerController);
}