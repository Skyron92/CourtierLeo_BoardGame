// Fill out your copyright notice in the Description page of Project Settings.


#include "MemoryController.h"

void AMemoryController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	bEnableClickEvents = true;
}
