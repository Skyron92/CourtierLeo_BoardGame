// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Symbol.generated.h"

USTRUCT(BlueprintType)
struct FSymbol {
	GENERATED_BODY()

	// Sets default values for this struct's properties
	FSymbol();
	FSymbol(int rank, FColor color);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int rank;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor color;

	bool RankIsCorrect(int rankToCheck);
	bool ColorIsCorrect(FColor colorToCheck);
};
