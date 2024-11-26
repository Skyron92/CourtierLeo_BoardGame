// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectMinigame/CollectableItem.h"

// Sets default values
ACollectableItem::ACollectableItem() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(StaticMeshComponent);

	Collectable = CreateDefaultSubobject<UCollectableComponent>("Collectable");
	Collectable->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ACollectableItem::BeginPlay() {
	Super::BeginPlay();
	DefineFruitType();
}

void ACollectableItem::SetFruitProperties()
{
	if(Fruit.IsValid()) {
		StaticMeshComponent->SetMaterial(0,Fruit.Material);
		Collectable->SetScore(Fruit.Score);
	}
}

void ACollectableItem::SetFruitProperties(FFruit f) {
	if (f.IsValid()) {
		Fruit = f;
		StaticMeshComponent->SetMaterial(0, Fruit.Material);
		Collectable->SetScore(Fruit.Score);
	}
}

void ACollectableItem::DefineFruitType()
{
	if (FruitTypes.Num() == 1) {
		Fruit = FruitTypes[0];
		Collectable->SetFruit(Fruit);
	}
	else {
		int probability = FMath::RandRange(0, 100);
		for (int i = 0; i < FruitTypes.Num(); i++) {
			auto fruitType = FruitTypes[i];
			if (probability <= fruitType.Probability) {
				Fruit = fruitType;
				Collectable->SetFruit(Fruit);
				break;
			}
			probability -= fruitType.Probability;
			if (probability <= 0) {
				Fruit = fruitType;
				Collectable->SetFruit(Fruit);
				GEngine->AddOnScreenDebugMessage(-576, 10, FColor::Red, "Error : Probability out of range.\n"
				                                 "The sum of all fruits probability must be equal to 100 !");
				break;
			}
		}
	}
	SetFruitProperties();
}

// Called every frame
void ACollectableItem::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void ACollectableItem::Fall() {
	StaticMeshComponent->SetCollisionProfileName("BlockAllDynamic");
	StaticMeshComponent->SetSimulatePhysics(true);
	Collectable->collectable = true;
}