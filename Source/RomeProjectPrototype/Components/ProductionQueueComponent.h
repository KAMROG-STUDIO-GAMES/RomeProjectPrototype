// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProductionQueueComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOrderCompleted, int, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOrderCreated, UQueueOrder*, Order);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOrderCanceled, int, Index);


UCLASS(BlueprintType)
class UQueueOrder : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION()
	virtual void HandleOrderCompleted();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual FText GetName() { return FText(); }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual UTexture2D* GetIcon() { return nullptr; }

	UPROPERTY(BlueprintReadOnly)
	float Time = 10;
};


class ASquad;
UCLASS()
class USquadQueueOrder : public UQueueOrder
{
	GENERATED_BODY()

public:

	virtual void HandleOrderCompleted() override;
	virtual FText GetName() override;
	virtual UTexture2D* GetIcon() override;
	TSubclassOf<ASquad> SquadClass;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class ROMEPROJECTPROTOTYPE_API UProductionQueueComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UProductionQueueComponent();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "ProductionQueue"))
	UQueueOrder* GetCurrentOrder() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "ProductionQueue"))
	TArray<UQueueOrder*> GetPendingOrders() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "ProductionQueue"))
	TArray<UQueueOrder*> GetOrders() const;

	UFUNCTION(BlueprintCallable)
	void StartNewOrder();

	UFUNCTION(BlueprintCallable)
	void CompleteOrder();

	UFUNCTION(BlueprintCallable)
	bool CancelOrder(int Index);

	UFUNCTION(BlueprintCallable)
	bool CancelCurrent();

	UFUNCTION(BlueprintCallable)
	void CreateOrder(UQueueOrder* Order);

	UFUNCTION(BlueprintCallable)
	void CreateSquadOrder(TSubclassOf<ASquad> SquadClass);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "ProductionQueue"))
	float GetProgress() const;


protected:

	UPROPERTY()
	TArray<UQueueOrder*> Orders;

	UPROPERTY()
	FTimerHandle Timer;

	UPROPERTY()
	float Efficiency = 1;

	UPROPERTY()
	bool InProgress = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Category = "ProductionQueue"))
	int CurrentQueueSize = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Category = "ProductionQueue"))
	int MaxQueueSize = 10;

public:	

	UPROPERTY(BlueprintAssignable, meta = (Category = "ProductionQueue"))
	FOnOrderCompleted OnOrderCompleted;

	UPROPERTY(BlueprintAssignable, meta = (Category = "ProductionQueue"))
	FOnOrderCreated OnOrderCreated;

	UPROPERTY(BlueprintAssignable, meta = (Category = "ProductionQueue"))
	FOnOrderCanceled OnOrderCanceled;
		
};
