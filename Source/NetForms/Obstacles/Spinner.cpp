// Fill out your copyright notice in the Description page of Project Settings.


#include "Spinner.h"

// Sets default values
ASpinner::ASpinner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpinner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpinner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator NewRot = FRotator(PitchValue, YawValue, RollValue);

	FQuat QuatRot = FQuat(NewRot);

	AddActorLocalRotation(QuatRot, false, 0, ETeleportType::None);
}

