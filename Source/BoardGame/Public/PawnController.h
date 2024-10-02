// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnController.generated.h"

UCLASS()
class BOARDGAME_API APawnController : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnController();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Setup)
	int playerID;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
