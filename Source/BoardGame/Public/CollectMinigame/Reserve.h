// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IHarvester.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Reserve.generated.h"

UCLASS()
class BOARDGAME_API AReserve : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AReserve();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* sphere;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent* component, AActor* other, UPrimitiveComponent* otherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
