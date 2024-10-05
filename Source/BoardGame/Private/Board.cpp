// Fill out your copyright notice in the Description page of Project Settings.
#include "Board.h"

// Sets default values
ABoard::ABoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABoard::MovePawnToCell(ABoardPawn* pawn, FVector cellPos) const {
	pawn->SetActorLocation(cellPos);
}

int ABoard::MovePawnToCellByIndex(ABoardPawn* pawn, int cellIndex) const {
	int gridSize = Grid.Num() - 1;
	if(cellIndex > gridSize){
		pawn->SetActorLocation(Grid[gridSize]->GetActorLocation());
		return gridSize;
	}
	pawn->SetActorLocation(Grid[cellIndex]->GetActorLocation());
	return cellIndex;
}

bool ABoard::IsLastCell(ACell* c) const{
	return c == Grid.Last();
}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

