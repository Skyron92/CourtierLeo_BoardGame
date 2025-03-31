// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MastermindPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BOARDGAME_API AMastermindPlayerController : public APlayerController {
	GENERATED_BODY()

	virtual void BeginPlay() override;

	UFUNCTION()
	void Pick(AActor* ClickedComp, FKey ButtonPressed);
};
