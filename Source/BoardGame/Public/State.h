// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" 
#include "State.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class BOARDGAME_API UState : public UObject
{
	GENERATED_BODY()
public:
	virtual void Enter(class APlayerFSM* fsm) const;
	virtual void Do(APlayerFSM* fsm) const;
	virtual void Exit(APlayerFSM* fsm) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTransform> bones;
};