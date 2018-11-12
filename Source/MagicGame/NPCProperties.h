// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ENPCType : uint8 {
	PASSIVE			UMETA(DisplayName = "Passive"),			// Always runs
	NEUTRAL			UMETA(DisplayName = "Neutral"),			// Attack when provoked
	HOSTILE			UMETA(DisplayName = "Hostile"),			// Always attack
	GUARD			UMETA(DisplayName = "Guard"),			// Only attack hostile by nature
	MERCHANT		UMETA(DisplayName = "Merchant"),		// Interact for menu
	QUESTER			UMETA(DisplayName = "Quest Giver"),		// Interact for quest
};

UENUM(BlueprintType)
enum class EGender : uint8 {
	NONE			UMETA(DisplayName = "Neither"),
	MALE			UMETA(DisplayName = "Male"),
	FEMALE			UMETA(DisplayName = "Female"),
};