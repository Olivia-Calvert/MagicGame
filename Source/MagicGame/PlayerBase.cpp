// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerBase.h"

// Sets default values
APlayerBase::APlayerBase() {
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box)"));
}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void APlayerBase::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Move", this, &APlayerBase::Move);
	PlayerInputComponent->BindAxis("Strafe", this, &APlayerBase::Strafe);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &APlayerBase::BeginSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &APlayerBase::EndSprint);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerBase::Jump);

	PlayerInputComponent->BindAxis("Yaw", this, &APlayerBase::Yaw);
	PlayerInputComponent->BindAxis("Pitch", this, &APlayerBase::Pitch);
}

void APlayerBase::Move(float value) {
	FVector dir = GetActorForwardVector();
	AddMovementInput(dir, value);
}

void APlayerBase::Strafe(float value) {
	FVector dir = GetActorRightVector();
	AddMovementInput(dir, value);
}

void APlayerBase::BeginSprint() {
	GetCharacterMovement()->MaxWalkSpeed *= 1.5f;
}

void APlayerBase::EndSprint() {
	GetCharacterMovement()->MaxWalkSpeed /= 1.5f;
}

void APlayerBase::Yaw(float value) {
	FRotator rotation = GetActorRotation();
	rotation.Yaw += value;
	SetActorRotation(rotation);
}

void APlayerBase::Pitch(float value) {
	FRotator rotation = GetActorRotation();
	rotation.Pitch += value;
	SetActorRotation(rotation);
}