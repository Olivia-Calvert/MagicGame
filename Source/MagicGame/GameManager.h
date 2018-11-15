// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <fstream>
#include <vector>

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Spell.h"
#include "GameManager.generated.h"

using namespace std;

UCLASS()
class MAGICGAME_API AGameManager : public AGameMode {
	GENERATED_BODY()
private:
	vector<FSpell> spellList;
protected:
	
private:
	void LoadSpells();
public:
	// Functions
};
