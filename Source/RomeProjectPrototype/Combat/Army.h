// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Army.generated.h"

class ASquad;

UCLASS()
class ROMEPROJECTPROTOTYPE_API AArmy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArmy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TArray<ASquad*> Squads;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
