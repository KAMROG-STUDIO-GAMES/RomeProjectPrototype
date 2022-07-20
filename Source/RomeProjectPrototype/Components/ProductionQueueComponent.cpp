// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ProductionQueueComponent.h"

FQueueOrderStruct::FQueueOrderStruct(UQueueOrderHandler* Handler, const float InitialTime) :
Handler(Handler), Time(InitialTime)
{
}

FQueueOrderStruct::FQueueOrderStruct()
{
}

// Sets default values for this component's properties
UProductionQueueComponent::UProductionQueueComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

FQueueOrderStruct UProductionQueueComponent::GetCurrentOrder()
{
	if (Orders.IsValidIndex(0))
		return Orders[0];
	FQueueOrderStruct* tmp = new FQueueOrderStruct();
	return *tmp;
}

void UProductionQueueComponent::StartNewOrder()
{
	if(!InProgress || Orders.IsValidIndex(0))
	{
		InProgress = true;
		float Time = Orders[0].Time * Efficiency;
		GetWorld()->GetTimerManager().SetTimer(Timer, this, &UProductionQueueComponent::CompleteOrder, Time, false);
	}
}

void UProductionQueueComponent::CompleteOrder()
{
	if(Orders.IsValidIndex(0))
	{
		Orders[0].Handler->HandleOrderCompleted();
		Orders.Pop();
	}
	
}

bool UProductionQueueComponent::CancelOrder(int Index)
{
	if (Orders.IsValidIndex(Index))
	{
		Orders.RemoveAt(Index);
	}
	return true;
}

bool UProductionQueueComponent::CancelCurrent()
{
	return CancelOrder(0);
}


void UProductionQueueComponent::CreateOrder(UQueueOrderHandler* Handler, float Time)
{
	int Index = Orders.AddDefaulted(1);
	Orders[Index].Handler = Handler;
	Orders[Index].Time = Time;
}

// Called when the game starts
void UProductionQueueComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UProductionQueueComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

