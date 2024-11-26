// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectMinigame/CollectCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACollectCharacter::ACollectCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Initialisation des propriétés
	DefaultMappingContext = nullptr;
	MoveAction = nullptr;
	PushAction = nullptr;
}

// Called when the game starts or when spawned
void ACollectCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			// Ajoute le Mapping Context par défaut
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ACollectCharacter::Harvest(UCollectableComponent* collectable)
{
	IIHarvester::Harvest(collectable);
	auto item = GetWorld()->SpawnActor(ItemVisualizer);
	item->AttachToActor(this,  FAttachmentTransformRules::KeepWorldTransform);
	FVector location = GetActorLocation();
	location.Z += ItemStep * Collectables.Num();
	item->SetActorLocation(location);
	UCollectableComponent* collectableComponent = Cast<UCollectableComponent>(item->GetComponentByClass(UCollectableComponent::StaticClass()));
	if (collectableComponent) collectableComponent->collectable = false;
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
void ACollectCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	/*PlayerInputComponent->BindAxis("Move Forward / Backward", this, &ACollectCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &ACollectCharacter::MoveRight);*/
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Associer les actions
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACollectCharacter::Move);
		EnhancedInputComponent->BindAction(PushAction, ETriggerEvent::Triggered, this, &ACollectCharacter::Push);
	}
}

void ACollectCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		// Applique le mouvement sur les axes
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void ACollectCharacter::Push() {
	IIHarvester::Push();
	FVector Start = GetActorLocation() + FVector(100.f, 0.f, 0.f);
	FVector End = Start + FVector(0.f, 0.f, -50.f);
	float Radius = 100.f;
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);
	FHitResult OutHit;

	// Traçage
	bool bHit = UKismetSystemLibrary::SphereTraceSingle(
		GetWorld(),
		Start,
		End,
		Radius,
		TraceTypeQuery1,
		false,
		ActorsToIgnore,
		EDrawDebugTrace::ForDuration,
		OutHit,
		true
	);

	if (bHit) {
		auto out = OutHit.GetActor();
		if(out->Implements<UHitable>()) {
			GEngine->AddOnScreenDebugMessage(666,10,FColor::Emerald, TEXT("Hitable detected"));
			auto harvester = Cast<IHitable>(out);
			harvester->OnHit();
		}
	}
}

void ACollectCharacter::OnHit()
{
	IHitable::OnHit();
	LeaveAll();
}

