// Fill out your copyright notice in the Description page of Project Settings.


#include "Combat/Army.h"
#include "Squad.h"
// Sets default values
AArmy::AArmy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

TArray<FRowFormation> AArmy::GetFormation() const
{
	return Formation;
}

FRowFormation AArmy::GetRowFormation(const int RowIndex) const
{
	return Formation[RowIndex];
}

void AArmy::AddSlotInRow(const int RowIndex)
{
	Formation[RowIndex].RowSquads.AddDefaulted();
}

void AArmy::SetSquadRef(const int RowIndex, const int SlotIndex, ASquad* Squad)
{
	Formation[RowIndex].RowSquads[SlotIndex] = Squad;
}



