// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFSM.h"

// Sets default values
APlayerFSM::APlayerFSM()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerFSM::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerFSM::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerFSM::ChangeState(UState* state)
{
	if(CurrentState)
	{
		CurrentState->Exit(this);
	}
	CurrentState = state;
	if(CurrentState)
	{
		CurrentState->Enter(this);
	}
}

