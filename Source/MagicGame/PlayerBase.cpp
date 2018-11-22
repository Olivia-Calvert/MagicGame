// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerBase.h"


// Sets default values
APlayerBase::APlayerBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box)"));

	WizardMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Player Mesh"));
	WizardMesh->SetSimulatePhysics(true);
	RootComponent = WizardMesh;

	Sprinting = false;
	Jumping = false;
}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator newRotation;

	if (!CurrentVelocity.IsZero())
	{
		if (Sprinting)
		{
			CurrentVelocity = CurrentVelocity * sprintMultiplier;
		}
		
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);	
	}
	else
	{
		newRotation.Pitch = 0.0f;
	}
	
	SetActorRotation(newRotation);
}

// Called to bind functionality to input
void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerBase::MoveRight);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &APlayerBase::SprintStart);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &APlayerBase::SprintStop);
	//PlayerInputComponent->BindAction("JumpStart", IE_Pressed, this, &APlayerBase::JumpStart);
	//PlayerInputComponent->BindAction("JumpStop", IE_Released, this, &APlayerBase::JumpStop);
}


void APlayerBase::MoveForward(float value)
{
	CurrentVelocity.X = value * moveSpeed;
}

void APlayerBase::MoveRight(float value)
{
	CurrentVelocity.Y = value * moveSpeed;
}

void APlayerBase::SprintStart()
{
	Sprinting = true;
}

void APlayerBase::SprintStop()
{
	Sprinting = false;
}

void APlayerBase::JumpStart()
{
	if (!Jumping)
	{
		CurrentVelocity.Z += 100.0f;
		Jumping = true;
	}
}

void APlayerBase::JumpStop()
{
	//CurrentVelocity.Z = 0.0f;
	//Jumping = false;
}
