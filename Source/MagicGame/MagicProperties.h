// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EMagicTypes : uint8 {
	FIRE		UMETA(DisplayName = "Fire"),
	WATER		UMETA(DisplayName = "Water"),
	EARTH		UMETA(DisplayName = "Earth"),
	WIND		UMETA(DisplayName = "Wind"),
};