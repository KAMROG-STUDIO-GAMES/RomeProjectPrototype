// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BarracksComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSquadCreated, ASquad*, Squad);


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

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "BarracksComponent"))
	TArray<ASquad*> GetSquads() const;

	UFUNCTION()
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

public:	

	UPROPERTY(BlueprintAssignable, meta = (Category = "BarracksComponent"))
	FOnSquadCreated OnNewSquadAdded;
		
};
