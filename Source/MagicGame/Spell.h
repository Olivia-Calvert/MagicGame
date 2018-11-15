// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "MagicProperties.h"
#include "Spell.generated.h"

USTRUCT(BlueprintType)
struct FSpell {
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FString Name;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		EMagicTypes Type;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Power;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float Accuracy;
};