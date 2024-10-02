// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BoardPawn.h"
#include "Cell.h"
#include "GameFramework/Actor.h"
#include "Board.generated.h"

UCLASS()
class BOARDGAME_API ABoard : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABoard();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board")
	TArray<ACell*> Grid;
	UFUNCTION(BlueprintCallable, Category = "Board")
	void MovePawnToCell(ABoardPawn* pawn, FVector cellPos) const;
	UFUNCTION(BlueprintCallable, Category = "Board")
	void MovePawnToCellByIndex(ABoardPawn* pawn, int cellIndex) const;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
