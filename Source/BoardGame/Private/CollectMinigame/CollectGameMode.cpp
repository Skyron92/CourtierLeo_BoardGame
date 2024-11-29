// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectMinigame/CollectGameMode.h"

#include "Blueprint/UserWidget.h"
#include "CollectMinigame/CollectPlayerController.h"

ACollectGameMode::ACollectGameMode()
{
	PlayerControllerClass = ACollectPlayerController::StaticClass();
}

void ACollectGameMode::BeginPlay()
{
	Super::BeginPlay();
	if(TimerWidgetClass){
		auto widget = CreateWidget(GetWorld(), TimerWidgetClass);
		if(widget){
			widget->AddToViewport();
			TimerWidget = Cast<UPlayerCounterWidget>(widget);
		}
	}
	StartTimer();
}

void ACollectGameMode::StartTimer()
{
	_currentTime = _maxTime;
	FTimerDelegate timerDelegate;
	timerDelegate.BindUFunction(this, "IncrementTime");
	GetWorldTimerManager().SetTimer(_timer, timerDelegate, 1.0f, true);
}

void ACollectGameMode::IncrementTime() {
	_currentTime--;
	TimerWidget->SetValue(_currentTime);
	if(_currentTime <= 0) {
		EndGame();
	}
}

void ACollectGameMode::EndGame() {
	GetWorldTimerManager().ClearTimer(_timer);
	if(EndGameWidget){
		auto widget = CreateWidget(GetWorld(), EndGameWidget);
		if(widget) widget->AddToViewport();
	}
	ACollectPlayerController* const MyPlayer = Cast<ACollectPlayerController>(GetWorld()->GetFirstPlayerController());
	if (MyPlayer) {
		MyPlayer->bShowMouseCursor = true;
		MyPlayer->SetPause(true);
	}
}
