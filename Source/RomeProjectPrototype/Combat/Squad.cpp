// Fill out your copyright notice in the Description page of Project Settings.


#include "Combat/Squad.h"

// Sets default values
ASquad::ASquad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

float ASquad::ApplyDamage_Implementation(float IncomingDamage)
{
	return IncomingDamage - Armor;
}

// Called when the game starts or when spawned
void ASquad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASquad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ASquad::GetHealth()
{
	return Health;
}

float ASquad::GetArmor()
{
	return Armor;
}

float ASquad::GetDamage()
{
	return Damage;
}

float ASquad::GetAttackSpeed()
{
	return AttackSpeed;
}

float ASquad::GetRange()
{
	return Range;
}

FString ASquad::GetName()
{
	return  Name;
}

FString ASquad::GetDescription()
{
	return Description;
}

