// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BarracksComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSquadCreated, ASquad*, Squad);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnArmyCreated, AArmy*, Army);

class AArmy;
class ASquad;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class ROMEPROJECTPROTOTYPE_API UBarracksComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBarracksComponent();

	UFUNCTION()
	void CreateSquad(TSubclassOf<ASquad> SquadClass);

	UFUNCTION(BlueprintCallable, meta = (Category = "BarracksComponent"))
	AArmy* CreateArmy();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "BarracksComponent"))
	TArray<ASquad*> GetSquads() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "BarracksComponent"))
	TArray<AArmy*> GetArmies() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "BarracksComponent"))
	bool HasFreeSpace() const;

protected:

	UPROPERTY(BlueprintReadOnly)
	TArray<ASquad*> Squads;

	UPROPERTY(BlueprintReadOnly)
	TArray<AArmy*> Armies;

	UPROPERTY(EditAnywhere, meta = (Category = "BarracksComponent"))
	int SquadsNum = 0;

	UPROPERTY(EditAnywhere, meta = (Category = "BarracksComponent"))
	int MaxSquadsNum = 10;

	UPROPERTY(EditAnywhere, meta = (Category = "BarracksComponent"))
	int ArmiesNum = 0;

	UPROPERTY(EditAnywhere, meta = (Category = "BarracksComponent"))
	int MaxArmiesNum = 10;



public:	

	UPROPERTY(BlueprintAssignable, meta = (Category = "BarracksComponent"))
	FOnSquadCreated OnNewSquadAdded;

	UPROPERTY(BlueprintAssignable, meta = (Category = "BarracksComponent"))
	FOnArmyCreated OnNewArmyCreated;
		
};
