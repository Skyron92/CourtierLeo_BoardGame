// Fill out your copyright notice in the Description page of Project Settings.

#include "MastermindMinigame/SymbolTile.h"

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
	OnClicked.AddDynamic(this, &ASymbolTile::OnTileClicked);
}

// Called every frame
void ASymbolTile::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void ASymbolTile::SetColor(FColor color) {
	if (Mid) {
		Mid->SetVectorParameterValue(colorName, FLinearColor(color));
	}
}

FColor ASymbolTile::GetColor() {
	if (Mid) {
		FLinearColor c = Mid->K2_GetVectorParameterValue(colorName);
		return FColor(c.R, c.G, c.B);
	}
	return FColor(0, 0, 0);
}

void ASymbolTile::OnTileClicked(AActor* actor, FKey keyCalled) {
	if (!brain) return;
	SetColor(brain->GetNextColor(colorIndex));
}
