// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MemoryController.generated.h"

/**
 * 
 */
UCLASS()
class BOARDGAME_API AMemoryController : public APlayerController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	
};
