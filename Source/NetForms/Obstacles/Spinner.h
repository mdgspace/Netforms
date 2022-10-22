// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstacleBase.h"
#include "Spinner.generated.h"

UCLASS()
class NETFORMS_API ASpinner : public AObstacleBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpinner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = Movement)
		float PitchValue = 0;

	UPROPERTY(EditAnywhere, Category = Movement)
		float YawValue = 0;

	UPROPERTY(EditAnywhere, Category = Movement)
		float RollValue = 0;
};
