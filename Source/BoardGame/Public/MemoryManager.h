// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MemoryCard.h"
#include "MemoryManager.generated.h"

UCLASS()
class BOARDGAME_API AMemoryManager : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMemoryManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int XSize = 4;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int YSize = 4;

	UMemoryCard* Grid[4][4] = {
		{NewObject<UMemoryCard>(), NewObject<UMemoryCard>(), NewObject<UMemoryCard>(), NewObject<UMemoryCard>()},
		{NewObject<UMemoryCard>(), NewObject<UMemoryCard>(), NewObject<UMemoryCard>(), NewObject<UMemoryCard>()},
		{NewObject<UMemoryCard>(), NewObject<UMemoryCard>(), NewObject<UMemoryCard>(), NewObject<UMemoryCard>()},
		{NewObject<UMemoryCard>(), NewObject<UMemoryCard>(), NewObject<UMemoryCard>(), NewObject<UMemoryCard>()},
	};
	TArray<FIntVector2> path;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int pos = 0;
	int pathLenght = 0;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Initialize();

	TArray<FIntVector2> GeneratePath();

	bool MoveIsTowardEnd(int increment, FIntVector2 currentPos, int end) const;

	bool CurrentPosIsInRange(int increment, FIntVector2 currentPos) const;

	UFUNCTION(BlueprintCallable)
	bool PickTileByCoord(int x, int y);

	bool PickTile(FIntVector2 coord);
};
