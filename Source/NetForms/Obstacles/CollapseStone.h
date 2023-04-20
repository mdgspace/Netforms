// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstacleBase.h"
#include "CollapseStone.generated.h"

UCLASS()
class NETFORMS_API ACollapseStone : public AObstacleBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollapseStone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void TriggerEnter(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void TriggerExit(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 otherBodyIndex) override;

	bool IsCollapsed = false;
	bool IsPlayerOnPlatform = false;

	float TimeBetweenCollapse = 4;

	float TimeTillNextCollapse;

	UStaticMesh* MyMesh;
	UMaterialInstanceDynamic* DynamicMaterial;

	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material;
};
