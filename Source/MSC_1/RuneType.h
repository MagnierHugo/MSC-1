#pragma once

#include "CoreMinimal.h"
#include "RuneType.generated.h"

/**
 * Custom enum to demonstrate how to expose enums to Blueprints.
 */
UENUM(BlueprintType)
enum class ERuneType : uint8
{
	Shape UMETA(DisplayName = "Shape"),
	Element UMETA(DisplayName = "Element"),
	Modifier UMETA(DisplayName = "Modifier")
};