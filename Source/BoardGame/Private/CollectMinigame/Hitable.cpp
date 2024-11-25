// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectMinigame/Hitable.h"

// Add default functionality here for any IHitable functions that are not pure virtual.
void IHitable::OnHit()
{
	GEngine->AddOnScreenDebugMessage(700, 10, FColor::White, "Hit !");
}
