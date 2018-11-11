// Fill out your copyright notice in the Description page of Project Settings.

#include "Tile3D.h"

ATile3D::ATile3D() {
	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = TileMesh;
}

ATile3D::~ATile3D() {
}
