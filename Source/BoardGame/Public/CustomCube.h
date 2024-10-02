// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomCube.generated.h"

UCLASS(Blueprintable)
class BOARDGAME_API ACustomCube : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACustomCube();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor col;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstance* mat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ChangeColor(FLinearColor c) const;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
