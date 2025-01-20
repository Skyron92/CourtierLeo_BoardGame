// Fill out your copyright notice in the Description page of Project Settings.


#include "MastermindMinigame/SymbolTile.h"

#include "Components/BoxComponent.h"

// Sets default values
ASymbolTile::ASymbolTile() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASymbolTile::BeginPlay() {
	Super::BeginPlay();
	Mid = UMaterialInstanceDynamic::Create(mat, mesh);
	mesh->SetMaterial(0, Mid);
}

// Called every frame
void ASymbolTile::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}
