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
	for (auto item : Collectables){
		score += item->GetScore();
		Collectables.Remove(item);
	}
	GEngine->AddOnScreenDebugMessage(5,10, FColor::Green, FString::Printf(TEXT("Score: %d"), score));
}

void IIHarvester::OnHit() {
	LeaveAll();
}
