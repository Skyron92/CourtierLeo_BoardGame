// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollectMinigame/CollectableComponent.h"
#include "GameFramework/Actor.h"
#include "CollectableItem.generated.h"

// Item ramassable.
// Un item n'a pas besoin d'hériter de cette classe pour être ramassé,
// mais uniquement d'avoir le component UCollectableComponent.
UCLASS()
class ACollectableItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectableItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMeshComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UCollectableComponent* Collectable;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
