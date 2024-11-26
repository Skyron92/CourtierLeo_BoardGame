// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fruit.h"
#include "CollectMinigame/CollectableComponent.h"
#include "GameFramework/Actor.h"
#include "CollectableItem.generated.h"

// Implémentation d'un item ramassable.
// Un item n'a pas besoin d'hériter de cette classe pour être ramassé,
// mais uniquement d'avoir le component UCollectableComponent.
UCLASS()
class ACollectableItem : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ACollectableItem();
	
	void SetFruitProperties();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMeshComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UCollectableComponent* Collectable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fruit")
	TArray<FFruit> FruitTypes;
	
	FFruit Fruit;

	void DefineFruitType();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Fall();

};
