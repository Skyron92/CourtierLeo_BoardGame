// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectMinigame/EndGameWidget.h"

#include "Kismet/GameplayStatics.h"

void UEndGameWidget::NativeConstruct() {
	Super::NativeConstruct();
	if(button) button->OnClicked.AddDynamic(this, &UEndGameWidget::LoadLevel);
}

void UEndGameWidget::LoadLevel() {
	UGameplayStatics::OpenLevel(GetWorld(),"MainLevel");
}
