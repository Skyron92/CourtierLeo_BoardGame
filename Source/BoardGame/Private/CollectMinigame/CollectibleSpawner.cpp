// Fill out your copyright notice in the Description page of Project Settings.

#include "CollectMinigame/CollectibleSpawner.h"
#include "CollectMinigame/CollectableItem.h"

// Sets default values
ACollectibleSpawner::ACollectibleSpawner() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACollectibleSpawner::BeginPlay() {
	Super::BeginPlay();
	int key = -10;
	for (auto slot : slots) {
		slot.Taken = FMath::RandRange(0,100) < StartSpawnProbability;
		if (slot.Taken) {
			auto item = GetWorld()->SpawnActor(ItemClass);
			item->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
			item->SetActorRelativeLocation(slot.Location);
			SpawnedItem.AddUnique(item);
			// Problème ici !!
			GEngine->AddOnScreenDebugMessage(key, 50, FColor::Orange, FString::Printf(TEXT("Slot loc : %s, item loc : %s"),
												 *slot.Location.ToString(), *item->GetActorLocation().ToString()));
		}
		key++;
	}
	TimerDelegate.BindUFunction(this, "SpawnCollectible");
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, FMath::RandRange(0,3), false);
}

// Called every frame
void ACollectibleSpawner::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void ACollectibleSpawner::SpawnCollectible() {
	GEngine->AddOnScreenDebugMessage(-500, 5, FColor::Yellow, "Spawned");
	for (auto slot : slots) {
		//slot.Taken = FMath::RandRange(0,100) < 50;
		if (slot.Taken) {
			auto item = GetWorld()->SpawnActor(ItemClass);
			item->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
			item->SetActorRelativeLocation(slot.Location);
			GEngine->AddOnScreenDebugMessage(-500, 5, FColor::White,
			                                 FString::Printf(TEXT("Slot loc : %s, item loc : %s"),
			                                 	*slot.Location.ToString(), *item->GetActorLocation().ToString()));
			SpawnedItem.AddUnique(item);
			GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, FMath::RandRange(2,5), false);
			return;
		}
	}
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, FMath::RandRange(2,5), false);
}

void ACollectibleSpawner::OnHit()
{
	IHitable::OnHit();
}

