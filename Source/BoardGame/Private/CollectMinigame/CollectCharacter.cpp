// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectMinigame/CollectCharacter.h"
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
void ACollectCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &ACollectCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &ACollectCharacter::MoveRight);
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (Input) {
		/*if (MoveAction) {
			Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACollectCharacter::InputMove);
		}*/
		if (PushAction) {
			Input->BindAction(PushAction, ETriggerEvent::Started, this, &ACollectCharacter::StartPush);
		}
	}
}

void ACollectCharacter::StartPush(const FInputActionValue& value) {
	GEngine->AddOnScreenDebugMessage(8000, 10, FColor::Magenta, "StartPush");
	Push();
}

void ACollectCharacter::Push() {
	IIHarvester::Push();
	FVector Start = GetActorLocation();
	FVector End = Start + FVector(0.f, 0.f, -500.f);
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

