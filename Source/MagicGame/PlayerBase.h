// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/InputComponent.h"
#include "PlayerBase.generated.h"

UENUM(BlueprintType)
enum class Direction : uint8 {
	DIRECTION_FORWARD,
	DIRECTION_BACKWARD,
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
	DIRECTION_NONE,
};

UCLASS()
class MAGICGAME_API APlayerBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerBase();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* WizardMesh;
	//UPROPERTY(EditAnywhere)
		//UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere)
		FVector CurrentVelocity;
	UPROPERTY(EditAnywhere)
		FVector StartPosition;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float moveSpeed = 85.0f;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float sprintMultiplier = 3.0f;
	UPROPERTY(VisibleAnywhere, Category = "Movement")
		bool Sprinting;
	UPROPERTY(VisibleAnywhere, Category = "Movement")
		bool Jumping;
	UPROPERTY(VisibleAnywhere, Category = "Movement")
		Direction PlayerDirection;

	UPROPERTY(EditAnywhere, Category = "Stats")
		float MaxHealth;
	UPROPERTY(VisibleAnywhere, Category = "Stats")
		float CurrentHealth;
	UPROPERTY(EditAnywhere, Category = "Stats")
		float MaxStamina;
	UPROPERTY(VisibleAnywhere, Category = "Stats")
		float CurrentStamina;
	UPROPERTY(EditAnywhere, Category = "Stats")
		float MaxMana;
	UPROPERTY(VisibleAnywhere, Category = "Stats")
		float CurrentMana;
	UPROPERTY(EditAnywhere, Category = "Stats")
		float MagicDamage;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void MoveForward(float value);
	virtual void MoveRight(float value);
	virtual void SprintStart();
	virtual void SprintStop();
	virtual void JumpStart();
	virtual void JumpStop();
	
};
