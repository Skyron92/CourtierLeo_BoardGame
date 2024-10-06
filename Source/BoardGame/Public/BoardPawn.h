// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
