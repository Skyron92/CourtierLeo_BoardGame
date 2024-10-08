// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cell.generated.h"

UCLASS()
class BOARDGAME_API ACell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACell();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstance* mat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* mesh;
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ApplyEffect() const;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator rotator;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	void ChangeColor(FLinearColor c) const;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
