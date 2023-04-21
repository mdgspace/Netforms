// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Checkpoint.generated.h"

UCLASS()
class NETFORMS_API ACheckpoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACheckpoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SM_Checkpoint;

	UPROPERTY(EditAnywhere)
		UBoxComponent* BoxComponent;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
