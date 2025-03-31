// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MastermindBrain.h"
#include "SymbolTile.h"
#include "GameFramework/Pawn.h"
#include "Monitor.generated.h"

UCLASS()
class BOARDGAME_API AMonitor : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMonitor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UActorComponent*> Leds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ASymbolTile*> Tiles;
	UPROPERTY(BlueprintReadWrite)
	TArray<FTransform> SpawnTilesTransforms; ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AMastermindBrain* Brain;
	
	UPROPERTY(EditAnywhere, Category = Gameplay)
	TSubclassOf<ASymbolTile> SymbolTileClass;

	UFUNCTION()
	void OnButtonClicked(AActor* actor, FKey keyCalled);
};
