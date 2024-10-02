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

void ABoard::MovePawnToCellByIndex(ABoardPawn* pawn, int cellIndex) const {
	pawn->SetActorLocation(Grid[cellIndex]->GetActorLocation());
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

