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
}

// Called every frame
void AMastermindBrain::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AMastermindBrain::GenerateSequence() {
	for (int i = 0; i < 4; i++) {
		sequence[i] = FSymbol(i, colors[FMath::RandRange(0, colors.Num() - 1)]);
		DisplaySymbolTile(i);
	}
}

EMastermindBrainState AMastermindBrain::CheckSymbol(FSymbol symbolToCheck, int index) {
	bool ColorIsCorrect = symbolToCheck.ColorIsCorrect(sequence[index].color);
	return ColorIsCorrect ? Correct : ColorIsValid(symbolToCheck.color) ? BadRank : Wrong;
}

bool AMastermindBrain::ColorIsValid(FColor color) {
	for (int i = 0; i < 4; i++) {
		if (sequence[i].color == colors[i]) {
			return true;
		}
	}
	return false;
}

void AMastermindBrain::CheckSequence(FSymbol sequenceToCheck[4]) {
	for (int i = 0; i < 4; i++) {
		CheckSymbol(sequenceToCheck[i], i);
	}
}

void AMastermindBrain::DisplaySymbolTile(int i) {
	auto a = GetWorld()->SpawnActor(SymbolTileClass);
	a->SetActorLocation(FVector(0, i * TileOffset, 0));
	auto s = Cast<ASymbolTile>(a);
	auto color = sequence[i].color;
	s->SetColor(color);
}
