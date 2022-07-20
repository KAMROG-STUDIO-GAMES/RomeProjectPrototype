// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProductionQueueComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOrderCompleted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOrderCanceled);


UCLASS()
class UQueueOrderHandler : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION()
	virtual void HandleOrderCompleted()
	{
	}
};


USTRUCT(BlueprintType)
struct FQueueOrderStruct
{
	GENERATED_BODY()

	FQueueOrderStruct(UQueueOrderHandler* Handler, const float InitialTime);
	FQueueOrderStruct();

	UPROPERTY(BlueprintReadOnly)
	UQueueOrderHandler* Handler = nullptr;

	UPROPERTY(BlueprintReadOnly)
	float Time = 0;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class ROMEPROJECTPROTOTYPE_API UProductionQueueComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UProductionQueueComponent();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "ProductionQueue"))
	FQueueOrderStruct GetCurrentOrder();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "ProductionQueue"))
	TArray<FQueueOrderStruct> GetPendingOrders();

	UFUNCTION(BlueprintCallable)
		void StartNewOrder();

	UFUNCTION(BlueprintCallable)
		void CompleteOrder();

	UFUNCTION(BlueprintCallable)
		bool CancelOrder(int Index);

	UFUNCTION(BlueprintCallable)
		bool CancelCurrent();

	UFUNCTION(BlueprintCallable)
		void CreateOrder(UQueueOrderHandler* Handler, float Time);


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	TArray<FQueueOrderStruct> Orders;

	UPROPERTY()
	FTimerHandle Timer;

	UPROPERTY()
	float Efficiency = 1;

	UPROPERTY()
	bool InProgress = false;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FOnOrderCompleted OnOrderCompleted;

	FOnOrderCanceled OnOrderCanceled;
		
};
