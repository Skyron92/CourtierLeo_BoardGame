// Fill out your copyright notice in the Description page of Project Settings.


#include "MemoryCard.h"

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

void AMemoryCard::SetManager(const AMemoryManager* manager){
	MemoryManager = manager;
}

void AMemoryCard::Reverse(float targetPitch) {
	animationStartTime = GetWorld()->GetTimeSeconds();
	FTimerDelegate delegate;
	float pos = GetActorLocation().Z;
	delegate.BindUFunction(this, "ReverseAnimation", this, pos, targetPitch);
	GetWorld()->GetTimerManager().SetTimer(cardTimer, delegate, timeDelay, true);
}

void AMemoryCard::ReverseAnimation(AActor* tile, float startPoint, float targetPitch){
	float sin = FMath::Sin((animationStartTime - GetWorld()->GetTimeSeconds()) * speed);
	sin *= sin;
	FVector newPos = tile->GetActorLocation();
	newPos.Z = sin * ZOffset;
	tile->SetActorLocation(newPos);
	if(GetActorRotation().Euler().X -180 <= .1f){
		FRotator newRot = FRotator(degreeOffset,0,0);
		GEngine->AddOnScreenDebugMessage(8, 5000000, FColor::Green,
										 FString::Printf(TEXT("Angle : %f"), GetActorRotation().Euler().X));
		tile->AddActorLocalRotation(newRot);
	}
	if(tile->GetActorLocation().Z - startPoint <= .1f){
		tile->SetActorRotation(FRotator(targetPitch,0,0));
		GEngine->AddOnScreenDebugMessage(7, 5000000, FColor::Blue,
									 FString::Printf(TEXT("End !")));
		GetWorld()->GetTimerManager().ClearTimer(cardTimer);
	}
}
