// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPhysicsHandler.h"

// Sets default values for this component's properties
UCharacterPhysicsHandler::UCharacterPhysicsHandler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCharacterPhysicsHandler::BeginPlay()
{
	Super::BeginPlay();

	// ...

	MyOwner = GetOwner();
}


// Called every frame
void UCharacterPhysicsHandler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if(NoOfForceApplied)
	{
		ApplyForce(DeltaTime);
	}
}

void UCharacterPhysicsHandler::AddForce(FVector ForceDir, float ForceMag)
{
	Force += ForceDir * ForceMag;
	NoOfForceApplied++;
}

void UCharacterPhysicsHandler::ApplyForce(float DeltaTime)
{
	if (MyOwner != nullptr)
	{
		FVector pos = MyOwner->GetActorLocation();
		pos += Force * DeltaTime;
		MyOwner->SetActorLocation(pos);
	}
}

void UCharacterPhysicsHandler::RemoveForce(FVector ForceDir, float ForceMag)
{
	Force -= ForceDir * ForceMag;
	NoOfForceApplied--;
}

