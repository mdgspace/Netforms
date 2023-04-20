// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstacleBase.h"
#include "Spaceship.generated.h"

UCLASS()
class NETFORMS_API ASpaceship : public AObstacleBase
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ASpaceship();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void TriggerEnter(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	ACharacter* OtherCharacter;
	APlayerController* PlayerController;
};
