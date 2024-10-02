// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dice.generated.h"

UCLASS()
class BOARDGAME_API ADice : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADice();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dice")
	int diceResult;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice")
	int minValue = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice")
	int maxValue = 6;
	UFUNCTION(BlueprintCallable, Category = "Dice")
	int Roll(int diceNumber = 1);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
