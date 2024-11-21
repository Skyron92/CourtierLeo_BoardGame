// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectMinigame/IHarvester.h"

// Add default functionality here for any IIHarvester functions that are not pure virtual.
void IIHarvester::Harvest(UCollectableComponent* collectable) {
	Collectables.AddUnique(collectable);
}

void IIHarvester::LeaveAll() {
	Collectables.Empty();
}

void IIHarvester::ClaimAll() {
	int key = 0;
	for (auto item : Collectables){
		score += item->GetScore();
		GEngine->AddOnScreenDebugMessage(key,10, FColor::Green, FString::Printf(TEXT("Score: %d"), score));
		Collectables.Remove(item);
		key++;
	}
}

void IIHarvester::Push() {
}