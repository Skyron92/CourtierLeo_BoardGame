// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fruit.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FFruit
{
 GENERATED_BODY()

 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 UMaterialInstance* Material;
 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 int Score = 10;
 UPROPERTY(EditAnywhere, BlueprintReadWrite)
 int Probability = 50;

 bool IsValid() {
  return Material != nullptr && Score != NULL && Probability != NULL;
 }
};
