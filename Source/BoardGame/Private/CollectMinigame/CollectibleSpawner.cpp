// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectMinigame/CollectibleSpawner.h"

#include <string>

#include "CollectMinigame/CollectableItem.h"

// Sets default values
ACollectibleSpawner::ACollectibleSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACollectibleSpawner::BeginPlay()
{
	Super::BeginPlay();
	int key = 1000;
	for (auto slot : slots) {
		slot.Taken = FMath::RandRange(0,100) < 20;
		if (slot.Taken) {
			auto item = GetWorld()->SpawnActor(ItemClass);
			item->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
			item->SetActorRelativeLocation(slot.Location);
			SpawnedItem.AddUnique(item);
			GEngine->AddOnScreenDebugMessage(key, 5, FColor::Orange, "Spawned");
		}
		key++;
	}
}

// Called every frame
void ACollectibleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollectibleSpawner::SpawnCollectible()
{
	auto item = GetWorld()->SpawnActor(ItemClass);
}

