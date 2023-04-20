// Fill out your copyright notice in the Description page of Project Settings.


#include "Spinner.h"
#include "GameFramework/Character.h"
#include "./../CharacterPhysicsHandler.h"

// Sets default values
ASpinner::ASpinner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TBox->OnComponentBeginOverlap.AddDynamic(this, &ASpinner::TriggerEnter);
	TBox->OnComponentEndOverlap.AddDynamic(this, &ASpinner::TriggerExit);
}

// Called when the game starts or when spawned
void ASpinner::BeginPlay()
{
	Super::BeginPlay();
	
	InitPos = GetActorLocation();
}

// Called every frame
void ASpinner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsOnPlatform)
	{
		DelTime = DeltaTime;
	}

	FRotator NewRot = FRotator(PitchValue, YawValue, RollValue);

	FQuat QuatRot = FQuat(NewRot);

	AddActorLocalRotation(QuatRot, false, 0, ETeleportType::None);
}

void ASpinner::TriggerEnter(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::TriggerEnter(HitComponent, OtherActor, OtherComp, otherBodyIndex, bFromSweep, SweepResult);

	IsOnPlatform = true;

	ACharacter* OtherCharacter = Cast<ACharacter>(OtherActor);
	/*UCharacterPhysicsHandler* CharacterPhysicsController = Cast<UCharacterPhysicsHandler>(OtherActor);*/
	
	if (OtherCharacter != nullptr)
	{
		float Force = (OtherActor->GetActorLocation() - InitPos).Size();
		ForceDir = (OtherActor->GetActorLocation() - InitPos)/Force;
		ForceMag = FMath::Square(YawValue) * Force;

		//CharacterPhysicsController->AddForce(ForceDir, ForceMag);
	}
}

void ASpinner::TriggerExit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 otherBodyIndex)
{
	Super::TriggerExit(HitComponent, OtherActor, OtherComp, otherBodyIndex);

	UCharacterPhysicsHandler* CharacterPhysicsController = Cast<UCharacterPhysicsHandler>(OtherActor);

	/*if (CharacterPhysicsController != nullptr)
	{
		CharacterPhysicsController->RemoveForce(ForceDir, ForceMag);
	}*/

	IsOnPlatform = false;
}