// Fill out your copyright notice in the Description page of Project Settings.


#include "Dice.h"

#include <stdexcept>

// Sets default values
ADice::ADice() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

int ADice::Roll(int diceNumber) {
	if (maxValue <= 0 || minValue >= maxValue || minValue <= 0) {
		throw std::invalid_argument("min/max value incorrect.");
	}
	diceResult = 0;
	for (int i = 0; i < diceNumber; i++) {
		diceResult += FMath::RandRange(minValue, maxValue);
	}
	return diceResult;
}
// Called when the game starts or when spawned
void ADice::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ADice::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}
