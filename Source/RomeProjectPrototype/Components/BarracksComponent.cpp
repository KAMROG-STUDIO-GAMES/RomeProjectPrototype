// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/BarracksComponent.h"
#include "Combat/Squad.h"
#include "Combat/Army.h"

// Sets default values for this component's properties
UBarracksComponent::UBarracksComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UBarracksComponent::CreateSquad(TSubclassOf<ASquad> SquadClass)
{
	auto CreatedSquad = Cast<ASquad> (GetWorld()->SpawnActor(SquadClass));
	if (CreatedSquad)
	{
		Squads.Add(CreatedSquad);
		SquadsNum++;
		OnNewSquadAdded.Broadcast(CreatedSquad);
	}
}

TArray<ASquad*> UBarracksComponent::GetSquads() const
{
	return Squads;
}

bool UBarracksComponent::HasFreeSpace() const
{
	return SquadsNum < MaxSquadsNum;
}

