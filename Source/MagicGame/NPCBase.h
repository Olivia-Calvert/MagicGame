// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NPCProperties.h"
#include "NPCBase.generated.h"

UCLASS()
class MAGICGAME_API ANPCBase : public APawn {
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Properties")
		ENPCType NPCType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Properties")
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Properties")
		EGender Gender;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "NPC")
		float CurrentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
		ESpells[] SpellList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle Stats")
		float MaxHealth;	// Out of 250, avg. 100
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle Stats")
		float MagicDamage;	// Out of 20, avg. 8
	// TODO? Spell type weaknesses, spell type strengths
protected:
	virtual void BeginPlay() override;
public:	
	ANPCBase();
	virtual void Tick(float DeltaTime) override;
};
