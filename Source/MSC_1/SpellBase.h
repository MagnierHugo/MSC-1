// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpellBase.generated.h"

UCLASS()
class MSC_1_API ASpellBase : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* SpellMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spell Properties")
	TSoftObjectPtr<UTexture2D> SpellIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spell Properties", Meta = (ExposeOnSpawn=true))
	AActor* Caster;

	// Sets default values for this actor's properties
	ASpellBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BLueprintCallable)
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
