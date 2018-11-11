// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Tile3D.generated.h"

class StaticMeshComponent;

UCLASS()
class MAGICGAME_API ATile3D : public AStaticMeshActor {
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* TileMesh;
public:
	ATile3D();
	~ATile3D();
};
