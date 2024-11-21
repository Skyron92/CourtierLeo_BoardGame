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

