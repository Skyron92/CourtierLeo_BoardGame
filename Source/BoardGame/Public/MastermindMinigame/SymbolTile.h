// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MastermindBrain.h"
#include "GameFramework/Actor.h"
#include "SymbolTile.generated.h"

UCLASS()
class BOARDGAME_API ASymbolTile : public APawn {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASymbolTile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int colorIndex = 0;
	FName colorName = "Color";

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstance* mat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstanceDynamic* Mid;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AMastermindBrain* brain;

	void SetColor(FColor color);
	FColor GetColor();
	UFUNCTION()
	void OnTileClicked(AActor* actor, FKey keyCalled);
};
