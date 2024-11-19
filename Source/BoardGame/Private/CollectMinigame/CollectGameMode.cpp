// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectMinigame/CollectGameMode.h"

#include "CollectMinigame/CollectPlayerController.h"
#include "GameFramework/Character.h"

ACollectGameMode::ACollectGameMode()
{
	PlayerControllerClass = ACollectPlayerController::StaticClass();
	DefaultPawnClass = DefaultCharacterClass;
}
