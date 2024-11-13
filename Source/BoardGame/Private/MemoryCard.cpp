// Fill out your copyright notice in the Description page of Project Settings.


#include "MemoryCard.h"

#include "MemoryManager.h"

AMemoryCard::AMemoryCard() {

}

void AMemoryCard::Reveal(FColor col) const {
	
	Mid->SetVectorParameterValue("Color", col);
}

void AMemoryCard::SetCoord(FIntVector2 Coord) {
	coord = Coord;
}

void AMemoryCard::GetCoord(int &x, int &y) {
	x = coord.X;
	y = coord.Y;
}

void AMemoryCard::BeginPlay() {
	Super::BeginPlay();
	Mid = UMaterialInstanceDynamic::Create(mat, mesh);
	mesh->SetMaterial(0, Mid);
}

void AMemoryCard::SetManager(AMemoryManager* manager){
	MemoryManager = manager;
}

void AMemoryCard::Reverse(float targetPitch) {
	animationStartTime = GetWorld()->GetTimeSeconds();
	FTimerDelegate delegate;
	float pos = GetActorLocation().Z;
	delegate.BindUFunction(this, "ReverseAnimation", this, pos, targetPitch);
	GetWorld()->GetTimerManager().SetTimer(cardTimer, delegate, timeDelay, true);
	isRevealed = targetPitch == 180;
}

void AMemoryCard::ReverseAnimation(AActor* tile, float startPoint, float targetPitch){
	float sin = FMath::Sin((animationStartTime - GetWorld()->GetTimeSeconds()) * speed);
	sin *= sin;
	FVector newPos = tile->GetActorLocation();
	newPos.Z = sin * ZOffset;
	tile->SetActorLocation(newPos);
	if(GetActorRotation().Euler().X -180 <= .1f){
		FRotator newRot = FRotator(degreeOffset,0,0);
		tile->AddActorLocalRotation(newRot);
	}
	if(tile->GetActorLocation().Z - startPoint <= 1.0f)
	{
		tile->SetActorRotation(FRotator(targetPitch,0,0));
		GetWorld()->GetTimerManager().ClearTimer(cardTimer);
		if(!MemoryManager->IsValidTile(coord)) {
			FTimerHandle tempHandle;
			MemoryManager->BindReverse();
			GetWorld()->GetTimerManager().SetTimer(tempHandle, MemoryManager->TimerDelegate, 1.0f, false);
		}
	}
}
