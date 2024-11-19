// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectMinigame/CollectableComponent.h"

#include "CollectMinigame/IHarvester.h"

// Sets default values for this component's properties
UCollectableComponent::UCollectableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	OnComponentBeginOverlap.AddDynamic(this, &UCollectableComponent::OnActorOverlap);
}


// Called when the game starts
void UCollectableComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UCollectableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCollectableComponent::OnActorOverlap(UPrimitiveComponent* component, AActor* other,
	UPrimitiveComponent* otherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (other->Implements<UIHarvester>()){
		auto harvester = Cast<IIHarvester>(other);
		harvester->Harvest(this);
		GetOwner()->Destroy();
	}
}

