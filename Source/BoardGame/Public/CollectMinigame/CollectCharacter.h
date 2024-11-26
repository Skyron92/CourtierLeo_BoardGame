// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollectableItem.h"
#include "Hitable.h"
#include "IHarvester.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "CollectCharacter.generated.h"


// Forward declarations
class UInputMappingContext;
class UInputAction;

// Character qui implémente l'interface IHarvester.
UCLASS(Blueprintable)
class BOARDGAME_API ACollectCharacter : public ACharacter, public IIHarvester, public IHitable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACollectCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Harvest(UCollectableComponent* collectable) override;

	virtual void ClaimAll() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collect")
	TSubclassOf<AActor> ItemVisualizer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collect")
	float ItemStep = 50;

	UPROPERTY(EditAnywhere, Category="Collect")
	FTransform ItemBaseLocation;

	UPROPERTY(EditAnywhere, Category="Collect")
	float collisionSize;

	TArray<AActor*> CollectedItems;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	// Input Binding Functions
	void Move(const FInputActionValue& Value);

	// Input System
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* PushAction;
	
	virtual void Push() override;

	virtual void OnHit() override;
	int key = 7;
};
