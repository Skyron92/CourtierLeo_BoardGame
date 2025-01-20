// Fill out your copyright notice in the Description page of Project Settings.


#include "MastermindMinigame/MastermindGameMode.h"

#include "MastermindMinigame/MastermindPlayerController.h"

AMastermindGameMode::AMastermindGameMode() {
	PlayerControllerClass = AMastermindPlayerController::StaticClass();
}
