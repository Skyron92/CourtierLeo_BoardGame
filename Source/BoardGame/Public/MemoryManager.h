// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MemoryCard.h"
#include "GameFramework/Actor.h"
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

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid")
	int XSize = 4;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid")
	int YSize = 4;

	AMemoryCard* Grid[4][4] = {
		{nullptr,nullptr,nullptr,nullptr},
		{nullptr,nullptr,nullptr,nullptr},
		{nullptr,nullptr,nullptr,nullptr},
		{nullptr,nullptr,nullptr,nullptr},
	};
	// The correct sequence
	TArray<FIntVector2> path;

	// The number of tiles picked by the player in once session.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid")
	int pos = 0;
	int pathLenght = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid")
	TSubclassOf<AMemoryCard> cardClass;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Grid")
	float cardOffset = 100;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Initialize();

	TArray<FIntVector2> GeneratePath();
	void InitializeLimitTile(int pathIndex, float offset, FIntVector2 coord);

	void DisplayGrid();

	// Unused
	static bool MoveIsTowardEnd(int increment, FIntVector2 currentPos, int end);

	bool CurrentPosIsInRange(int increment, FIntVector2 currentPos) const;

	// Allows to call IsValidTile from blueprint
	// (because FIntVector2 doesn't exist in bp)
	UFUNCTION(BlueprintCallable)
	bool IsValidTileByCoord(int x, int y);

	// Return true if the tile is in the sequence in the same order as picked by player.
	bool IsValidTile(FIntVector2 coord);
	
	FTimerHandle TimerHandle;
	FTimerDelegate TimerDelegate;

	// Allows to call PickTile from blueprint
	// (because FIntVector2 doesn't exist in bp)
	UFUNCTION(BlueprintCallable)
	void PickTileByCoord(int x, int y);
	
	void PickTile(FIntVector2 coord);

	void BindReverse();

	UFUNCTION()
	void ReverseAllTiles();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void DisplayVictory();
};
