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

