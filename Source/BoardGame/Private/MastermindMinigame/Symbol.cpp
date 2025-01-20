// Fill out your copyright notice in the Description page of Project Settings.


#include "MastermindMinigame/Symbol.h"

// Sets default values
FSymbol::FSymbol() {
	rank = 0;
	color = FColor::White;
}

FSymbol::FSymbol(int r, FColor& c) {
	rank = r;
	color = c;
}

bool FSymbol::RankIsCorrect(int rankToCheck) {
	return rank == rankToCheck;
}

bool FSymbol::ColorIsCorrect(FColor colorToCheck) {
	return color == colorToCheck;
}
