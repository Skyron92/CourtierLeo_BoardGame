// Fill out your copyright notice in the Description page of Project Settings.


#include "MemoryManager.h"

#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AMemoryManager::AMemoryManager() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMemoryManager::BeginPlay() {
	Super::BeginPlay();
	Initialize();
}

// Called every frame
void AMemoryManager::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AMemoryManager::Initialize(){
	path = GeneratePath();
	DisplayGrid();
}

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
					}
				}
				if (CurrentPosIsInRange(increment, currentPos)) {
					yLengthRemaining--;
					currentPos.Y += increment;
					result.AddUnique(FIntVector2(currentPos));
					GEngine->AddOnScreenDebugMessage(-3 * i, 200000, FColor::Red, FString::Printf(
						                                 TEXT("Last card added = %d, %d"),currentPos.X, currentPos.Y));
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
				                                 TEXT("Last card added = %d, %d\n"), currentPos.X, currentPos.Y));
		}
	}
	return result;
}

void AMemoryManager::InitializeLimitTile(int pathIndex, float offset, FIntVector2 coord) {
	auto tile = GetWorld()->SpawnActor(cardClass);
	auto limitCardPos = Grid[path[pathIndex].X][path[pathIndex].Y]->GetActorLocation();
	tile->SetActorLocation(FVector(limitCardPos.X, limitCardPos.Y + offset, 0));
	auto tileAsCard = Cast<AMemoryCard>(tile);
	tileAsCard->Reveal(FColor::Green);
	tileAsCard->SetCoord(coord);
	tileAsCard->isRevealed = true;
}

void AMemoryManager::DisplayGrid() {
	if(cardClass == nullptr) return;
	for (int x = 0; x < XSize; x++){
		for (int y = 0; y < YSize; y++){
			auto a = GetWorld()->SpawnActor(cardClass);
			a->SetActorLocation(FVector(y * cardOffset,x * cardOffset, 0));
			auto c = Cast<AMemoryCard>(a);
			c->SetCoord(FIntVector2(x,y));
			c->SetManager(this);
			Grid[x][y] = c;
		}
	}
	InitializeLimitTile(0, -cardOffset, FIntVector2(-1,-1));
	InitializeLimitTile(path.Num()-1, cardOffset, FIntVector2(XSize,YSize));
}

bool AMemoryManager::MoveIsTowardEnd(int increment, FIntVector2 currentPos, int end)
{
	bool result = (end > currentPos.Y && currentPos.Y + increment <= end) ||
		(end < currentPos.Y && currentPos.Y + increment >= end);
	return result;
}

bool AMemoryManager::CurrentPosIsInRange(int increment, FIntVector2 currentPos) const {
	return currentPos.Y + increment < YSize && currentPos.Y + increment >= 0;
}

bool AMemoryManager::IsValidTileByCoord(int x, int y) {
	return IsValidTile(FIntVector2(x, y));
}

bool AMemoryManager::IsValidTile(FIntVector2 coord) {
	//return path[pos] == coord;
	return path.Contains(coord);
}

void AMemoryManager::PickTileByCoord(int x, int y){
	PickTile(FIntVector2(x,y));
}

void AMemoryManager::PickTile(FIntVector2 coord){
	bool isValid = IsValidTile(coord);
	if(isValid) pos++;
	auto tile = Grid[coord.X][coord.Y]; 
	tile->Reveal(isValid ? FColor::Green : FColor::Red);
	tile->Reverse(180);
	if(pos == path.Num()) DisplayVictory();
}

void AMemoryManager::BindReverse()
{
	TimerDelegate.BindUFunction(this, "ReverseAllTiles");
}

void AMemoryManager::ReverseAllTiles() {
	pos = 0;
	for (int x = 0; x < XSize; x++){
		for (int y = 0; y < YSize; y++){
			auto tile = Grid[x][y];
			if(tile->isRevealed){
				tile->Reverse(0);
				tile->Reveal(FColor::White);
				tile->isRevealed = false;
			}
		}
	}
	GetWorld()->GetFirstPlayerController()->bEnableClickEvents = true;
	GetWorld()->GetFirstPlayerController()->bEnableMouseOverEvents = true;
}
