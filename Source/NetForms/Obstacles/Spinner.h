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

	void TriggerEnter(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	void TriggerExit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 otherBodyIndex) override;

	UPROPERTY(EditAnywhere, Category = Movement)
		float PitchValue = 0;

	UPROPERTY(EditAnywhere, Category = Movement)
		float YawValue = 0;

	UPROPERTY(EditAnywhere, Category = Movement)
		float RollValue = 0;

	UPROPERTY(EditAnywhere, Category = Movement)
		float DelTime = 0;

	UPROPERTY(EditAnywhere, Category = Movement)
		FVector InitPos;

	UPROPERTY(EditAnywhere, Category = Movement)
		bool IsOnPlatform = false; 
};
