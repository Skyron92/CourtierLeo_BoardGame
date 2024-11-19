// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectMinigame/Reserve.h"

// Sets default values
AReserve::AReserve()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(mesh);
	sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	sphere->SetupAttachment(GetRootComponent());

	sphere->OnComponentBeginOverlap.AddDynamic(this, &AReserve::OnActorOverlap);
}

// Called when the game starts or when spawned
void AReserve::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReserve::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AReserve::OnActorOverlap(UPrimitiveComponent* component, AActor* other, UPrimitiveComponent* otherComponent,
                              int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	GEngine->AddOnScreenDebugMessage(50, 5, FColor::Red, "Reserve");
	if (other->Implements<UIHarvester>()){
		
		auto harvester = Cast<IIHarvester>(other);
		harvester->ClaimAll();
	}
}

