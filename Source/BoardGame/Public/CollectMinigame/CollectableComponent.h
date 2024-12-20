// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fruit.h"
#include "Components/SphereComponent.h"
#include "CollectableComponent.generated.h"

// Component qui permet à un objet d'être collecté
UCLASS()
class BOARDGAME_API UCollectableComponent : public USphereComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCollectableComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	int Score = 10;

	FFruit fruit;

public:
	bool collectable = true;
	
	int GetScore() const;
	void SetScore(int score);

	FFruit GetFruit() const;
	void SetFruit(FFruit& f);
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent* component, AActor* other, UPrimitiveComponent* otherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
