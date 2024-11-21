// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollectMinigame/CollectableComponent.h"
#include "UObject/Interface.h"
#include "IHarvester.generated.h"

// Interface que doit implémenter celui qui collecte (joueur comme IA)
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIHarvester : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOARDGAME_API IIHarvester
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// Collectibles actuellement en poche
	TArray<UCollectableComponent*> Collectables;
	
	int score = 0;
	
	virtual void Harvest(UCollectableComponent* collectable);
	
	virtual void LeaveAll();

	virtual void ClaimAll();

	virtual void Push();
};
