// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCBase.h"

ANPCBase::ANPCBase() {
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
}

void ANPCBase::BeginPlay() {
	Super::BeginPlay();
}

void ANPCBase::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}