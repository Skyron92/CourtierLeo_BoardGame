// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCounterWidget.h"
#include "GameFramework/GameModeBase.h"
#include "CollectGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ACollectGameMode : public AGameModeBase
{
	GENERATED_BODY()

	ACollectGameMode();

	virtual void BeginPlay() override;

	// Timer
	int _currentTime;
	FTimerHandle _timer;
	void StartTimer();
	UFUNCTION()
	void IncrementTime();
	UPlayerCounterWidget* TimerWidget;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CollectGameMode")
	TSubclassOf<UUserWidget> TimerWidgetClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game")
	int _maxTime;

protected:
	// End game
	void EndGame();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CollectGameMode")
	TSubclassOf<UUserWidget> EndGameWidget;
};
