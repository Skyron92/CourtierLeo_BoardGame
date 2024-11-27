// Fill out your copyright notice in the Description page of Project Settings.

#include "CollectMinigame/CollectCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/WidgetComponent.h"

#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACollectCharacter::ACollectCharacter()
{
	// Set this character to call Tick() every frame.
	// You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Initialisation des propriétés
	InputMappingContext = nullptr;
	MoveAction = nullptr;
	PushAction = nullptr;
}

// Called when the game starts or when spawned
void ACollectCharacter::BeginPlay() {
	Super::BeginPlay();
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController())) {
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) {
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
	}
	counterWidgetComponent = Cast<UWidgetComponent>(GetComponentByClass(UWidgetComponent::StaticClass()));
	counterWidgetComponent->SetVisibility(false);
	playerCounterWidget = Cast<UPlayerCounterWidget>(counterWidgetComponent->GetWidget());
}

void ACollectCharacter::Harvest(UCollectableComponent* collectable) {
	auto temp = collectable;
	IIHarvester::Harvest(temp);
	auto item = GetWorld()->SpawnActor(ItemVisualizer);
	item->AttachToActor(this,  FAttachmentTransformRules::KeepWorldTransform);
	auto collectableItem = Cast<ACollectableItem>(item);
	UCollectableComponent* collectableComponent = Cast<UCollectableComponent>(
		collectableItem->GetComponentByClass(UCollectableComponent::StaticClass()));
	if (collectableComponent) {
		collectableComponent->collectable = false;
	}
	FVector location = GetActorLocation();
	location.Z += ItemStep * Collectables.Num();
	item->SetActorLocation(location);
	
	collectableItem->SetFruitProperties(temp->GetFruit());
	
	CollectedItems.AddUnique(item);
	UpdateWidget();
}

void ACollectCharacter::ClaimAll() {
	IIHarvester::ClaimAll();
	for (auto item : CollectedItems){
		item->Destroy();
	}
	CollectedItems.Empty();
	Collectables.Empty();
	UpdateWidget();
}

// Called every frame
void ACollectCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACollectCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACollectCharacter::Move);
		EnhancedInputComponent->BindAction(PushAction, ETriggerEvent::Triggered, this, &ACollectCharacter::Push);
	}
}

void ACollectCharacter::Move(const FInputActionValue& Value) {
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (Controller != nullptr) {
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void ACollectCharacter::Push() {
	IIHarvester::Push();
	FVector Start = GetActorLocation() + FVector(100.f, 0.f, 50.f);
	FVector End = Start + FVector(0.f, 0.f, 100.f);
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

void ACollectCharacter::UpdateWidget(){
	if(counterWidgetComponent){
		int itemNum = CollectedItems.Num();
		if(itemNum >= 3){
			counterWidgetComponent->SetVisibility(true);
			playerCounterWidget->SetValue(itemNum);
		}
		else {
			counterWidgetComponent->SetVisibility(false);
		}
	}
}

