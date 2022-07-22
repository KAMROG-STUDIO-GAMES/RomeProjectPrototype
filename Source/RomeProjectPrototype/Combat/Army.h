// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Army.generated.h"

class ASquad;

USTRUCT(BlueprintType)
struct FRowFormation
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, meta = (Category = "RowFormation"))
	TArray<ASquad*> RowSquads;

};



UCLASS()
class ROMEPROJECTPROTOTYPE_API AArmy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArmy();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Army Formation"))
	TArray<FRowFormation> GetFormation() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Army Formation"))
	FRowFormation GetRowFormation(int RowIndex) const;

	UFUNCTION(BlueprintCallable, meta = (Category = "Army Formation"))
	void AddSlotInRow(int RowIndex);

	UFUNCTION(BlueprintCallable, meta = (Category = "Army Formation"))
	void SetSquadRef(int RowIndex, int SlotIndex, ASquad* Squad);

protected:

	TArray<ASquad*> Squads;

	TArray<FRowFormation> Formation;

public:	


};
