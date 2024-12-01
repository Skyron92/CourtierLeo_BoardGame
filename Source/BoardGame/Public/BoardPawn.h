// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "GameFramework/Actor.h"
#include "BoardPawn.generated.h"

UCLASS()
class BOARDGAME_API ABoardPawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoardPawn();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Render")
	TArray<UStaticMeshComponent*> meshes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Render")
	UMaterialInstance* mat;
	UFUNCTION(BlueprintCallable)
	void SetColor(FLinearColor col) const;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Position")
	float ZOffset = 50;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void BeginIdleAnimation(FTransform& hands, FTransform& head, FTransform inHands, FTransform inHead);

	UFUNCTION()
	void IdleAnimation();
	void MoveBone(FTransform& t, float val, float offset);

	FTimerHandle TimerIdle;
	FTimerDelegate TimerIdleDelegate;
	float idleStartTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	float idleSpeed; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	float handsZOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	float headZOffset;
	FTransform handsTransform;
	FTransform headTransform;
	int key = 500;
};
