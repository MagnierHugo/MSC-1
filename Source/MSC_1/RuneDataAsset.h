// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RuneType.h"
#include "RuneDataAsset.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct FRuneAssetInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rune")
	FString RuneName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rune")
	FString RuneDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rune")
	UTexture2D* RuneIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rune")
	ERuneType RuneType;

};

/**
 * 
 */
UCLASS(BlueprintType)
class MSC_1_API URuneDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rune")
	FRuneAssetInfo RuneAssets;
	
};
