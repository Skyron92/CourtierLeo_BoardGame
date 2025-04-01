// Fill out your copyright notice in the Description page of Project Settings.

#include "MastermindMinigame/Monitor.h"

#include "MastermindMinigame/SymbolTile.h"

// Sets default values
AMonitor::AMonitor()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMonitor::BeginPlay()
{
	Super::BeginPlay();
	OnClicked.AddDynamic(this, &AMonitor::OnButtonClicked);
	for (int i = 0; i < 4; i++) {
		FActorSpawnParameters spawnParameters = FActorSpawnParameters();
		spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		Tiles[i] = GetWorld()->SpawnActor<ASymbolTile>(SymbolTileClass, FTransform(GetActorLocation() + FVector(0, i*TileOffset + TileOffset, 0)), spawnParameters);
		Tiles[i]->brain = Brain;
	}
}

// Called every frame
void AMonitor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMonitor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMonitor::OnButtonClicked(AActor* actor, FKey keyCalled) {
	if (Tiles.Num() == 0) return;
	FSymbol sequenceToCheck[4];
	for (int i = 0; i < Tiles.Num(); i++) {
		FSymbol s = FSymbol(i, Tiles[i]->GetColor());
		sequenceToCheck[i] = s;
	}
	Brain->CheckSequence(sequenceToCheck);
}
