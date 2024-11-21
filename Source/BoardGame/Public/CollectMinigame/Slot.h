// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Slot.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FSlot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Taken = false;
};
