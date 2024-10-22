// Fill out your copyright notice in the Description page of Project Settings.


#include "State.h"

void UState::Enter(APlayerFSM* fsm) const
{
}

void UState::Do(APlayerFSM* fsm) const
{
}

void UState::Exit(APlayerFSM* fsm) const
{
}

void UState::Print(FString content) const
{
	if(GEngine) GEngine->AddOnScreenDebugMessage(1,5,FColor::Red, content); 
}
