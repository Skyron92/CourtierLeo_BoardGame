// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectMinigame/PlayerCounterWidget.h"

void UPlayerCounterWidget::SetValue(int value) const {
	if(TextBlock) TextBlock->SetText(FText::FromString(FString::FromInt(value)));
}
