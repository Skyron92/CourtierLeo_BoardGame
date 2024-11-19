// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectMinigame/CollectCharacter.h"

#include "MovieSceneTracksComponentTypes.h"

// Sets default values
ACollectCharacter::ACollectCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	collectiblesStep = ItemStep;
}

// Called when the game starts or when spawned
void ACollectCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ACollectCharacter::Harvest(UCollectableComponent* collectable)
{
	IIHarvester::Harvest(collectable);
	
	auto item = GetWorld()->SpawnActor(ItemVisualizer);
	item->AttachToActor(this,  FAttachmentTransformRules::KeepWorldTransform);
	FVector location = GetActorLocation();
	location.Z += collectiblesStep * Collectables.Num();
	item->SetActorLocation(location);
	CollectedItems.AddUnique(item);
}

void ACollectCharacter::ClaimAll()
{
	IIHarvester::ClaimAll();
	for (auto item : CollectedItems){
		item->Destroy();
	}
}

// Called every frame
void ACollectCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACollectCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &ACollectCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &ACollectCharacter::MoveRight);
}

void ACollectCharacter::MoveForward(float value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, value);
}

void ACollectCharacter::MoveRight(float value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, value);
}

