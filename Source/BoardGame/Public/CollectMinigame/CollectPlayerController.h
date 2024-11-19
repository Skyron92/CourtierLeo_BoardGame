// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CollectPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ACollectPlayerController : public APlayerController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	
};
