// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Symbol.h"
#include <vector>
#include "GameFramework/Actor.h"
#include "MastermindBrain.generated.h"

UENUM(BlueprintType)
enum EMastermindBrainState {
	Correct,
	BadRank,
	Wrong
};

UCLASS()
class BOARDGAME_API AMastermindBrain : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMastermindBrain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FSymbol sequence[4] = {};

	UPROPERTY(EditAnywhere, Category = Gameplay)
	TArray<FColor> colors;

	void GenerateSequence();

	bool ValueIsValid(FColor color);
	EMastermindBrainState CheckSymbol(FSymbol symbolToCheck, int index);

	FColor GetNextColor(int &index);

	std::vector<EMastermindBrainState> CheckSequence(FSymbol sequenceToCheck[4]);
	
	UPROPERTY(EditAnywhere, Category = Gameplay)
	float TileOffset;
};
