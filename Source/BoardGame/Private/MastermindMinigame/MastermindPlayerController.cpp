// Fill out your copyright notice in the Description page of Project Settings.

#include "MastermindMinigame/MastermindPlayerController.h"

void AMastermindPlayerController::BeginPlay() {
	Super::BeginPlay();
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	OnClicked.AddDynamic(this, &AMastermindPlayerController::Pick);
}

void AMastermindPlayerController::Pick(AActor* ClickedComp, FKey ButtonPressed) {
	GEngine->AddOnScreenDebugMessage(-1, 5.0, FColor::Red, "Picked up");
}
