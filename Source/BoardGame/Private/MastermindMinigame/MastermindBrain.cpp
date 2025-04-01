// Fill out your copyright notice in the Description page of Project Settings.


#include "MastermindMinigame/MastermindBrain.h"
#include "MastermindMinigame/SymbolTile.h"

// Sets default values
AMastermindBrain::AMastermindBrain() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMastermindBrain::BeginPlay() {
	Super::BeginPlay();
	GenerateSequence();
	CheckSequence(sequence);
}

// Called every frame
void AMastermindBrain::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AMastermindBrain::GenerateSequence() {
	for (int i = 0; i < 4; i++) {
		sequence[i] = FSymbol(i, colors[FMath::RandRange(0, colors.Num() - 1)]);
		GEngine->AddOnScreenDebugMessage(-2000 + i, 10.f, FColor::Green, FString::Printf(TEXT("Symbol %d: %d, %d, %d"), i, sequence[i].color.R, sequence[i].color.G, sequence[i].color.B));
	}
}

/// <summary>
/// Allows to know if the symbol is correct at the given index.
/// <summary>
EMastermindBrainState AMastermindBrain::CheckSymbol(FSymbol symbolToCheck, int index) {
	bool ColorIsCorrect = symbolToCheck.ColorIsCorrect(sequence[index].color);
	return ColorIsCorrect ? Correct : ValueIsValid(symbolToCheck.color) ? BadRank : Wrong;
}

FColor AMastermindBrain::GetNextColor(int& index) {
	if (index >= colors.Num()-1) index = -1;
	index++;
	return colors[index];
}

/// <summary>
/// Allows to know if the given color exists in the sequence.
/// <summary>
bool AMastermindBrain::ValueIsValid(FColor color) {
	for (int i = 0; i < 4; i++) {
		if (sequence[i].color == colors[i]) {
			return true;
		}
	}
	return false;
}

std::vector<EMastermindBrainState> AMastermindBrain::CheckSequence(FSymbol sequenceToCheck[4]) {
	std::vector<EMastermindBrainState> results;
	for (int i = 0; i < 4; i++) {
		results.push_back(CheckSymbol(sequenceToCheck[i], i));
	}
	for (int i = 0; i < 4; i++) {
		GEngine->AddOnScreenDebugMessage(i, 10.f, results[i] == Correct ? FColor::Green : results[i] == Wrong ?
			FColor::Red : FColor::Yellow, FString::Printf(TEXT("Symbol %d: %s"), i, *UEnum::GetValueAsString(results[i])));
	}
	return results;
}
