// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectMinigame/Slot.h"
#include "CollectibleSpawner.generated.h"

UCLASS()
class BOARDGAME_API ACollectibleSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectibleSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FTimerDelegate TimerDelegate;
	FTimerHandle TimerHandle;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ACollectableItem> ItemClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSlot> slots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StartSpawnProbability = 10;

	TArray<AActor*> SpawnedItem;

	void SpawnCollectible();
};
