// Fill out your copyright notice in the Description page of Project Settings.


#include "MemoryManager.h"

// Sets default values
AMemoryManager::AMemoryManager() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMemoryManager::BeginPlay() {
	Super::BeginPlay();
	GeneratePath();
}

// Called every frame
void AMemoryManager::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AMemoryManager::Initialize() {}

TArray<FIntVector2> AMemoryManager::GeneratePath() {
	int start = 0;
	int end = 0;
	// min card number to pass through to win
	int yLengthRemaining = 0;
	while (pathLenght <= XSize) {
		start = FMath::RandRange(0, YSize - 1);
		end = FMath::RandRange(0, YSize - 1);
		yLengthRemaining = start > end ? start - end : end - start;
		pathLenght = yLengthRemaining + XSize;
	}
	// Correct jusqu'ici
	GEngine->AddOnScreenDebugMessage(-1, 20000000, FColor::Green, FString::Printf(
		                                 TEXT("pathLenght = %d\n start = %d\n end = %d\n YLength remaining = %d"),
		                                 pathLenght, start, end, yLengthRemaining));
	TArray<FIntVector2> result = TArray<FIntVector2>();
	FIntVector2 currentPos = FIntVector2::ZeroValue;
	int xLengthRemaining = XSize - 1;
	for (int i = 0; i < pathLenght; i++) {
		if (i == 0) {
			currentPos = FIntVector2(0, start);
			result.AddUnique(FIntVector2(currentPos));
			GEngine->AddOnScreenDebugMessage(-2 * i, 200000, FColor::Orange, FString::Printf(
				                                 TEXT("first card = %d, %d\n"), currentPos.X, currentPos.Y));
			continue;
		}
		// true = x, false = y
		bool dir = xLengthRemaining > 0 ? FMath::RandBool() : false;
		// Advance on Y
		if (!dir) {
			if (yLengthRemaining > 0) {
				int increment = FMath::RandBool() ? -1 : 1;
				// Check if we can advance on Y, else advance on X
				if (!CurrentPosIsInRange(increment, currentPos) || result.Contains(FIntVector2(currentPos))) {
					increment *= -1;
					if (!CurrentPosIsInRange(increment, currentPos) || result.Contains(FIntVector2(currentPos))) {
						dir = !dir;
						GEngine->AddOnScreenDebugMessage(-5 * i, 200000, FColor::Purple, FString::Printf(
							                                 TEXT("Y limit, change to X")));
					}
				}
				if (CurrentPosIsInRange(increment, currentPos)) {
					yLengthRemaining--;
					currentPos.Y += increment;
					result.AddUnique(FIntVector2(currentPos));
					GEngine->AddOnScreenDebugMessage(-3 * i, 200000, FColor::Red, FString::Printf(
						                                 TEXT(
							                                 "Result size : %d\n Last card added = %d, %d\n YLenght remaining : %d"),
						                                 result.Num(), currentPos.X, currentPos.Y, yLengthRemaining));
				}
			}
			else {
				dir = !dir;
			}
		}
		if (dir && xLengthRemaining > 0) {
			currentPos.X++;
			result.AddUnique(FIntVector2(currentPos));
			xLengthRemaining--;
			GEngine->AddOnScreenDebugMessage(-4 * i, 200000, FColor::Magenta, FString::Printf(
				                                 TEXT(
					                                 "Result size : %d\n Last card added = %d, %d\n XLenght remaining : %d"),
				                                 result.Num(), currentPos.X, currentPos.Y, xLengthRemaining));
		}
	}
	GEngine->AddOnScreenDebugMessage(100, 5000000, FColor::Yellow,
	                                 FString::Printf(TEXT("Generated pathLenght = %d"), result.Num()));
	return result;
}

bool AMemoryManager::MoveIsTowardEnd(int increment, FIntVector2 currentPos, int end) const {
	bool result = (end > currentPos.Y && currentPos.Y + increment <= end) ||
		(end < currentPos.Y && currentPos.Y + increment >= end);
	return result;
}

bool AMemoryManager::CurrentPosIsInRange(int increment, FIntVector2 currentPos) const {
	return currentPos.Y + increment < YSize && currentPos.Y + increment >= 0;
}

bool AMemoryManager::PickTileByCoord(int x, int y) {
	return PickTile(FIntVector2(x, y));
}

bool AMemoryManager::PickTile(FIntVector2 coord) {
	return path[pos].X == coord.X && path[pos].Y == coord.Y;
}
