// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomCube.h"

// Sets default values
ACustomCube::ACustomCube() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACustomCube::BeginPlay() {
	Super::BeginPlay();
}

void ACustomCube::ChangeColor(FLinearColor c) const {
	UMaterialInstanceDynamic* Mid = UMaterialInstanceDynamic::Create(mat, mesh);
	mesh->SetMaterial(0, Mid);
	Mid->SetVectorParameterValue("Color", c);
}

// Called every frame
void ACustomCube::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}
