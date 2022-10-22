// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "ObstacleBase.generated.h"

UCLASS()
class NETFORMS_API AObstacleBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacleBase();

	UPROPERTY(EditAnywhere)
		UBoxComponent* TBox;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SM_Obstacle;

	UPROPERTY(EditAnywhere)
		FVector ForceDir;      

	UPROPERTY(EditAnywhere)
		float ForceMag;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		virtual void TriggerEnter(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,  int32 otherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

};
