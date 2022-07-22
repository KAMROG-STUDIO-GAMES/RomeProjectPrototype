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

float ASquad::GetHealth() const
{
	return Health;
}

float ASquad::GetArmor() const
{
	return Armor;
}

float ASquad::GetDamage() const
{
	return Damage;
}

float ASquad::GetAttackSpeed() const
{
	return AttackSpeed;
}

float ASquad::GetRange() const
{
	return Range;
}

FText ASquad::GetSquadName() const
{
	return  Name;
}

FText ASquad::GetSquadDescription() const
{
	return Description;
}

UTexture2D* ASquad::GetSquadIcon() const
{
	return Icon;
}

