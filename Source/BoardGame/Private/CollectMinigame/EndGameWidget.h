// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "EndGameWidget.generated.h"

/**
 * 
 */
UCLASS()
class UEndGameWidget : public UUserWidget
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables")
	UButton* button;

	virtual void NativeConstruct() override;

	UFUNCTION()
	void LoadLevel();
};
