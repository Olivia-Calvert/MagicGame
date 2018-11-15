// Fill out your copyright notice in the Description page of Project Settings.

#include "GameManager.h"

void AGameManager::LoadSpells() {
	fstream fileStream("SpellData.csv");

	if (fileStream.fail()) { return; }
	while (fileStream.good()) {

	}
}
