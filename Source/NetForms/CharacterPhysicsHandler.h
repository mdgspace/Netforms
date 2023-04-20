// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterPhysicsHandler.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NETFORMS_API UCharacterPhysicsHandler : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterPhysicsHandler();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	AActor* MyOwner;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddForce(FVector ForceDir, float ForceMag);
	void ApplyForce(float DeltaTime);
	void RemoveForce(FVector ForceDir, float ForceMag);

	int NoOfForceApplied = 0;

	FVector Force = FVector(0, 0, 0);
};
