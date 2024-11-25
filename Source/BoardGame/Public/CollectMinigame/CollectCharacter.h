// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Hitable.h"
#include "IHarvester.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"
#include "CollectCharacter.generated.h"

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ItemVisualizer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ItemStep = 50;

	UPROPERTY(EditAnywhere)
	FTransform ItemBaseLocation;

	UPROPERTY(EditAnywhere, Category="Collect")
	float collisionSize;

	TArray<AActor*> CollectedItems;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	UPROPERTY(EditAnywhere, Category="Input")
	UEnhancedInputComponent* EnhancedInputComponent;
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* PushAction;

	UFUNCTION()
	void StartPush(const FInputActionValue& value);
	
	virtual void Push() override;

	UFUNCTION()
	void MoveForward(float value);
	UFUNCTION()
	void MoveRight(float value);

	virtual void OnHit() override;
};
