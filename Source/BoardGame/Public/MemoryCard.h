// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputCoreTypes.h"
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
	UMaterialInstanceDynamic* Mid;

	// Show the card
	void Reveal(FColor col) const;

	FIntVector2 coord;

	void SetManager(const class AMemoryManager* manager);

	UPROPERTY(BlueprintReadOnly)
	const AMemoryManager* MemoryManager = nullptr;

	void SetCoord(FIntVector2 Coord);

	// Allows to see coord in BP
	// because FIntVector2 doesn't exist in BP
	UFUNCTION(BlueprintCallable, BlueprintPure)
	void GetCoord(int &x, int &y);

	virtual void BeginPlay() override;

	bool pickable;

	FTimerHandle cardTimer;
	float animationStartTime;
	float timeDelay = 0.01f;
	float ZOffset = 100.0f;
	float degreeOffset = 45;
	float speed = 3;

	void Reverse(float targetPitch);
	
	UFUNCTION()
	void ReverseAnimation(AActor* tile, float startPoint, float targetPitch);
};
