// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
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
class APlayerBase : public ACharacter {
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	APlayerBase();

	//UPROPERTY(EditAnywhere)
		//UBoxComponent* CollisionBox;

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

	void Move(float value);
	void Strafe(float value);
	void BeginSprint();
	void EndSprint();

	void Yaw(float value);
	void Pitch(float value);
};
