// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MagicProperties.h"
#include "StatusEffect.generated.h"

USTRUCT(BlueprintType)
struct FStatusEffect {
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int id;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FString Name;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		EMagicTypes Type;
};