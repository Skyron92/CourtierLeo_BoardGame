// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardPawn.h"

// Sets default values
ABoardPawn::ABoardPawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABoardPawn::SetColor(FLinearColor col) const {
	for(int i = 0; i < meshes.Num(); i++){
		UMaterialInstanceDynamic* Mid = UMaterialInstanceDynamic::Create(mat, meshes[i]);
		meshes[i]->SetMaterial(0, Mid);
		Mid->SetVectorParameterValue("Color", col);
	}
}

// Called when the game starts or when spawned
void ABoardPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoardPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABoardPawn::BeginIdleAnimation(FTransform& hands, FTransform& head, FTransform inHands, FTransform inHead)
{
	handsTransform = inHands;
	headTransform = inHead;
	hands = handsTransform;
	head = headTransform;
	idleStartTime = GetWorld()->GetTimeSeconds();
	TimerIdleDelegate.BindUFunction(this, "IdleAnimation");
	GetWorld()->GetTimerManager().SetTimer(TimerIdle, TimerIdleDelegate, .1f, true);
}

void ABoardPawn::IdleAnimation()
{
	float sin = FMath::Sin((idleStartTime - GetWorld()->GetTimeSeconds()) * idleSpeed);
	sin *= sin;
	// hands
	MoveBone(handsTransform, sin, handsZOffset);
	// head
	MoveBone(headTransform, sin, headZOffset);
}

void ABoardPawn::MoveBone(FTransform& t, float val, float offset)
{
	GEngine->AddOnScreenDebugMessage(key, 5.f, FColor::Red, TEXT("Move bone"));
	key++;
	auto newPos = t.GetLocation();
	newPos.Z = val * offset;
	t.SetLocation(newPos);
}

