// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectMinigame/CollectableItem.h"

// Sets default values
ACollectableItem::ACollectableItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(StaticMeshComponent);

	Collectable = CreateDefaultSubobject<UCollectableComponent>("Collectable");
	Collectable->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ACollectableItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

