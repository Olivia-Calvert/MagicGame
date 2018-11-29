// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Spell.h"
#include "StatusEffect.h"
#include "GameManager.generated.h"

using namespace std;

UCLASS()
class MAGICGAME_API AGameManager : public AGameMode {
	GENERATED_BODY()
protected:
	vector<FSpell> spellList;
	vector<FStatusEffect> statusList;
private:
	void LoadSpells();
	void LoadStatusEffects();
public:
	AGameManager();
	FSpell GetSpell(int id);
};
