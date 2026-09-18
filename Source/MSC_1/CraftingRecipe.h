// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "RuneDataAsset.h"
#include "SpellBase.h"
#include "CraftingRecipe.generated.h"


USTRUCT(BlueprintType)
struct FCraftingRecipe : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<URuneDataAsset*> Ingredients;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ASpellBase> Result;

};
