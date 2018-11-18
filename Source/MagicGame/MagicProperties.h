// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MagicProperties.generated.h"

UENUM(BlueprintType)
enum class EMagicTypes : uint8 {
	FIRE		UMETA(DisplayName = "Fire"),
	WATER		UMETA(DisplayName = "Water"),
	EARTH		UMETA(DisplayName = "Earth"),
	WIND		UMETA(DisplayName = "Wind"),
	FORCE		UMETA(DisplayName = "Force"),
	ICE			UMETA(DisplayName = "Ice"),
};

UENUM(BlueprintType)
enum class EStatusEffects : uint8 {
	BURNING		UMETA(DisplayName = "Burning"),
	FROZEN		UMETA(DisplayName = "Frozen"),
	CONFUSED	UMETA(DisplayName = "Confused"),
};

USTRUCT(BlueprintType)
struct FStatusChance {
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int id;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float chance;
};