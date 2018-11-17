// Fill out your copyright notice in the Description page of Project Settings.

#include "GameManager.h"
#include "Misc/Paths.h"

AGameManager::AGameManager() {
	LoadSpells();
	LoadStatusEffects();
}

void AGameManager::LoadSpells() {
	FString path = FPaths::ProjectContentDir() + "/SpellData.csv";
	fstream inFile(TCHAR_TO_UTF8(*path));

	if (!inFile || !inFile.good())
		return;

	string line;
	while (getline(inFile, line)) {
		if (line[0] == '#')
			continue;

		string element;
		vector<string> elements;
		for (int i = 0; i < line.length(); i++) {
			if (line[i] != ',') {
				element += line[i];
			} else {
				elements.push_back(element);
				element = "";
			}
		}

		FSpell spell;
		spell.id = spellList.size();
		if (!elements[0].empty())
			spell.Name = UTF8_TO_TCHAR(elements[0].c_str());
		if (!elements[1].empty())
			spell.Type = (EMagicTypes)stoi(elements[1]);
		if (!elements[2].empty())
			spell.Power = stof(elements[2]);
		if (!elements[3].empty())
			spell.Accuracy = stof(elements[3]);
		for (int i = 4; i < elements.size(); i++) {
			int elementLength = elements[i].length();
			int regexIndex = elements[i].find_first_of(':');

			FStatusChance effect;
			effect.id = stoi(elements[i].substr(0, regexIndex));
			effect.chance = stoi(elements[i].substr(regexIndex + 1, elementLength - regexIndex - 1)) / 100.0f;

			spell.StatusEffects.Add(effect);
		}
		spellList.push_back(spell);
	}
}

void AGameManager::LoadStatusEffects() {
	FString path = FPaths::ProjectContentDir() + "/EffectData.csv";
	fstream inFile(TCHAR_TO_UTF8(*path));

	if (!inFile || !inFile.good())
		return;

	string line;
	while (getline(inFile, line)) {
		if (line[0] == '#')
			continue;

		string element;
		vector<string> elements;
		for (int i = 0; i < line.length(); i++) {
			if (line[i] != ',') {
				element += line[i];
			} else {
				elements.push_back(element);
				element = "";
			}
		}

		FStatusEffect effect;
		effect.id = statusList.size();
		if (!elements[0].empty())
			effect.Name = UTF8_TO_TCHAR(elements[0].c_str());
		//if (!elements[1].empty())
		//	effect.Type = (EMagicTypes)stoi(elements[1]);
		statusList.push_back(effect);
	}
}
