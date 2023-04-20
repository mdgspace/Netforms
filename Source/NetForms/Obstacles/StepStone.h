// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstacleBase.h"
#include "StepStone.generated.h"

UCLASS()
class NETFORMS_API AStepStone : public AObstacleBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStepStone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float speed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector movDir = FVector(1, 0, 0);
};
