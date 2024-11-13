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
	UFUNCTION(BlueprintCallable)
	void Reveal(FColor col) const;

	FIntVector2 coord;

	int key = 200;

	void SetManager(class AMemoryManager* manager);

	UPROPERTY(BlueprintReadOnly)
	AMemoryManager* MemoryManager = nullptr;

	void SetCoord(FIntVector2 Coord);

	UPROPERTY(BlueprintReadOnly)
	bool isRevealed;

	// Allows to see coord in BP
	// because FIntVector2 doesn't exist in BP
	UFUNCTION(BlueprintCallable, BlueprintPure)
	void GetCoord(int &x, int &y);

	virtual void BeginPlay() override;

	FTimerHandle cardTimer;
	float animationStartTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Reverse Animation")
	float timeDelay = 0.1f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Reverse Animation")
	float ZOffset = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Reverse Animation")
	float degreeOffset = 90;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Reverse Animation")
	float speed = 3;

	void Reverse(float targetPitch);
	
	UFUNCTION()
	void ReverseAnimation(AActor* tile, float startPoint, float targetPitch);
};
