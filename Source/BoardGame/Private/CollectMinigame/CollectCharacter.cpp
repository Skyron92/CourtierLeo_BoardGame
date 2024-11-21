// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectMinigame/CollectCharacter.h"

#include "MovieSceneTracksComponentTypes.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACollectCharacter::ACollectCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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
	location.Z += ItemStep * Collectables.Num();
	item->SetActorLocation(location);
	CollectedItems.AddUnique(item);
}

void ACollectCharacter::ClaimAll()
{
	IIHarvester::ClaimAll();
	for (auto item : CollectedItems){
		item->Destroy();
	}
	CollectedItems.Empty();
	Collectables.Empty();
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

void ACollectCharacter::Push()
{
	IIHarvester::Push();
	FVector Start = GetActorLocation();                       // Point de départ
	FVector End = Start + FVector(0.f, 0.f, -500.f);          // Direction et distance du traçage
	float Radius = 100.f;                                     // Rayon de la sphère
	TArray<AActor*> ActorsToIgnore;                          // Acteurs à ignorer (optionnel)
	ActorsToIgnore.Add(this);                                 // Ignorer cet acteur
	FHitResult OutHit;

	// Effectuer le traçage
	bool bHit = UKismetSystemLibrary::SphereTraceSingle(
		GetWorld(),
		Start,                      // Point de départ
		End,                        // Point final
		Radius,                     // Rayon
		TraceTypeQuery1,             // Channel de collision
		false,                      // Ignorer self ?
		ActorsToIgnore,             // Acteurs ignorés
		EDrawDebugTrace::ForDuration, // Débogage visuel (optionnel)
		OutHit,                     // Résultat
		true                        // Retourne des hit complexes
	);

	if (bHit) {
		auto out = OutHit.GetActor();
		if(out->Implements<UHitable>()) {
			auto harvester = Cast<IHitable>(out);
			harvester->OnHit();
		}
	}
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

void ACollectCharacter::OnHit()
{
	IHitable::OnHit();
	LeaveAll();
}

