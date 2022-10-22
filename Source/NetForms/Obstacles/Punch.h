// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstacleBase.h"
#include "Punch.generated.h"

UENUM()
enum class STATE : uint8 {
	IDLE UMETA(DisplayName = "IDLE"),
	PUNCHING UMETA(DisplayName = "PUNCHING"),
	RETURNING UMETA(DisplayName = "RETURNING"),
};

UCLASS()
class NETFORMS_API APunch : public AObstacleBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APunch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PunchMechanism(float DeltaTime);

	virtual void TriggerEnter(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) override;

	UPROPERTY(EditAnywhere)
		float ReturnSpeed;

	UPROPERTY(EditAnywhere)
		float ImpulseSpeed;

	UPROPERTY(EditAnywhere)
		float TimeBetweenPunches = 5;

	float TimeTillNextPunch;

	bool isPunching=false;

	float InitialX;
	float FinalX;

	STATE CurrState;
};
