// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SymbolTile.generated.h"

UCLASS()
class BOARDGAME_API ASymbolTile : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASymbolTile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstance* mat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstanceDynamic* Mid;

	void SetColor(FColor color);
};

inline void ASymbolTile::SetColor(FColor color) {
	Mid->SetVectorParameterValue("Color", color);
}
