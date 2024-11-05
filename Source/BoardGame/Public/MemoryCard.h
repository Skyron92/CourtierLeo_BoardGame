// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MemoryCard.generated.h"

/**
 * 
 */
UCLASS()
class BOARDGAME_API AMemoryCard : public AActor {
	GENERATED_BODY()
public:

	AMemoryCard();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstance* mat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* mesh;

	void Reveal(FColor col) const;
};
