// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnController.h"

// Sets default values
APawnController::APawnController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APawnController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

