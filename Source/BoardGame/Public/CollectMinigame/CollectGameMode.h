// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CollectGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ACollectGameMode : public AGameModeBase
{
	GENERATED_BODY()

	ACollectGameMode();

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACharacter> DefaultCharacterClass;
};
