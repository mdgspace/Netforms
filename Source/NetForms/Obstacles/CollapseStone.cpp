// Fill out your copyright notice in the Description page of Project Settings.


#include "CollapseStone.h"
#include "GameFramework/Character.h"

// Sets default values
ACollapseStone::ACollapseStone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TBox->OnComponentBeginOverlap.AddDynamic(this, &ACollapseStone::TriggerEnter);
	TBox->OnComponentEndOverlap.AddDynamic(this, &ACollapseStone::TriggerExit);
}

// Called when the game starts or when spawned
void ACollapseStone::BeginPlay()
{
	Super::BeginPlay();

	TimeTillNextCollapse = TimeBetweenCollapse;
	MyMesh = SM_Obstacle->GetStaticMesh();

	DynamicMaterial = UMaterialInstanceDynamic::Create(Material, NULL);
	MyMesh->SetMaterial(0, DynamicMaterial);
}

// Called every frame
void ACollapseStone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!IsCollapsed)
	{
		if (IsPlayerOnPlatform)
		{
			TimeTillNextCollapse -= DeltaTime;
		}
		/*else
		{
			TimeTillNextCollapse += DeltaTime;
		}*/
		if (TimeTillNextCollapse < 0)
		{
			IsCollapsed = true;
			TimeTillNextCollapse = TimeBetweenCollapse;
			SM_Obstacle->SetStaticMesh(nullptr);
		}
	}
	else
	{
		TimeTillNextCollapse -= DeltaTime;
		if (TimeTillNextCollapse < 0)
		{
			IsCollapsed = false;
			TimeTillNextCollapse = TimeBetweenCollapse;
			SM_Obstacle->SetStaticMesh(MyMesh);
		}
	}
	float blend = TimeTillNextCollapse/ TimeBetweenCollapse;
	//GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Blue, FString::Printf(TEXT("lol, %f"), blend));
	DynamicMaterial->SetScalarParameterValue(TEXT("Blend"), blend);
}

void ACollapseStone::TriggerEnter(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::TriggerEnter(HitComponent, OtherActor, OtherComp, otherBodyIndex, bFromSweep, SweepResult);
	UE_LOG(LogTemp, Warning, TEXT("Stone"));
	IsPlayerOnPlatform = true;
}

void ACollapseStone::TriggerExit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 otherBodyIndex)
{
	Super::TriggerExit(HitComponent, OtherActor, OtherComp, otherBodyIndex);
	IsPlayerOnPlatform = false;
}

