// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "Components/WidgetComponent.h"
#include "PlayerCounterWidget.generated.h"

/**
 * 
 */
UCLASS()
class BOARDGAME_API UPlayerCounterWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextBlock* TextBlock;

	void SetValue(int value) const;
};
