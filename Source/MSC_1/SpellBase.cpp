// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellBase.h"

// Sets default values
ASpellBase::ASpellBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpellMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpellMesh"));
	SpellMesh->SetNotifyRigidBodyCollision(true);
	RootComponent = SpellMesh;

}

// Called when the game starts or when spawned
void ASpellBase::BeginPlay()
{
	Super::BeginPlay();
	
	SetLifeSpan(5.0f);
	SpellMesh->OnComponentHit.AddDynamic(this, &ASpellBase::OnHit);
}

void ASpellBase::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor != this && OtherActor != Caster && OtherComp)
	{
		Destroy();
	}
}

// Called every frame
void ASpellBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + GetActorForwardVector() * DeltaTime * 500.0f);
}

