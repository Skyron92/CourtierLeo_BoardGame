// Fill out your copyright notice in the Description page of Project Settings.


#include "MemoryCard.h"

AMemoryCard::AMemoryCard()
{
	
}

void AMemoryCard::Reveal(FColor col) const {
	UMaterialInstanceDynamic* Mid = UMaterialInstanceDynamic::Create(mat, mesh);
	mesh->SetMaterial(0, Mid);
	Mid->SetVectorParameterValue("Color", col);
}

void AMemoryCard::SetCoord(FIntVector2 Coord)
{
	coord = Coord;
}

void AMemoryCard::GetCoord(int &x, int &y)
{
	x = coord.X;
	y = coord.Y;
}

void AMemoryCard::SetManager(const AMemoryManager* manager){
	MemoryManager = manager;
}
