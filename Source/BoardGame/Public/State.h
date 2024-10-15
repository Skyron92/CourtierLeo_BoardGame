// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "State.generated.h"

/**
 * 
 */
UCLASS()
class BOARDGAME_API UState : public UObject
{
	GENERATED_BODY()
public:
	virtual void Enter() const;
	virtual void Do() const;
	virtual void Exit() const;
};