// Fill out your copyright notice in the Description page of Project Settings.


#include "Punch.h"
#include "GameFramework/Character.h"

// Sets default values
APunch::APunch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	TBox->OnComponentBeginOverlap.AddDynamic(this, &APunch::TriggerEnter);

	ReturnSpeed = 200;
	ImpulseSpeed = 1000;
}

// Called when the game starts or when spawned
void APunch::BeginPlay()
{
	Super::BeginPlay();

	TimeTillNextPunch = TimeBetweenPunches;
	InitialX = GetActorLocation().X;
	FinalX = InitialX + 500;

	CurrState = STATE::IDLE;
	//SM_Obstacle->AddImpulse(FVector(200000, 100, 0));
}

// Called every frame
void APunch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PunchMechanism(DeltaTime);
}

void APunch::PunchMechanism(float DeltaTime)
{
	if (CurrState==STATE::IDLE)
	{
		TimeTillNextPunch -= DeltaTime;
		if (TimeTillNextPunch <= 0)
		{
			CurrState = STATE::PUNCHING;
		}
	}
	else if (CurrState == STATE::PUNCHING)
	{
		FVector CurrLocation = GetActorLocation();
		CurrLocation.X += DeltaTime * ImpulseSpeed;
		SetActorLocation(CurrLocation);
		if (CurrLocation.X >= FinalX)
		{
			CurrState = STATE::RETURNING;
		}
	}
	else
	{
		FVector CurrLocation = GetActorLocation();
		CurrLocation.X -= DeltaTime * ReturnSpeed;
		SetActorLocation(CurrLocation);
		if (CurrLocation.X <= InitialX)
		{
			CurrState = STATE::IDLE;
			TimeTillNextPunch = TimeBetweenPunches;
		}
	}
}

void APunch::TriggerEnter(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	Super::TriggerEnter(HitComponent, OtherActor, OtherComp, otherBodyIndex, bFromSweep, SweepResult);

	ACharacter* OtherCharacter = Cast<ACharacter>(OtherActor);
	if (OtherCharacter != nullptr)
	{
		OtherCharacter->LaunchCharacter(FVector(500, 0, 250), false, true);
	}
}


