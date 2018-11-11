// Fill out your copyright notice in the Description page of Project Settings.

#include "Tile3D.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"

ATile3D::ATile3D() {
	this->SetActorLocation(worldPos);
	this->SetActorTickEnabled(false);

	RootComponent->SetMobility(EComponentMobility::Static);
	RootComponent->SetComponentTickEnabled(false);
}

ATile3D::~ATile3D() {
}
