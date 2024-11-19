// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectMinigame/CollectPlayerController.h"

void ACollectPlayerController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = false;
}
