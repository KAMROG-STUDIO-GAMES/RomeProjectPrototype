// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ProductionQueueComponent.h"
#include "Combat/Squad.h"
#include "BarracksComponent.h"
void UQueueOrder::HandleOrderCompleted()
{
	
}

void USquadQueueOrder::HandleOrderCompleted()
{
	Super::HandleOrderCompleted();
	auto Owner = Cast<UProductionQueueComponent>(GetOuter());
	auto District = Owner->GetOwner();
	auto BarracksComponent = Cast<UBarracksComponent>(District->GetComponentByClass(UBarracksComponent::StaticClass()));
	if(BarracksComponent)
	{
		BarracksComponent->CreateSquad(SquadClass);
	}
	
}

FText USquadQueueOrder::GetName()
{
	if (SquadClass) {
		ASquad* SquadCDO = Cast<ASquad>(SquadClass.Get()->ClassDefaultObject);
		FString Name = SquadCDO->GetSquadName();
		return FText(FText::FromString(Name));
	}
	FString Name = "OLEG";
	return FText(FText::FromString(Name));

}

UTexture2D* USquadQueueOrder::GetIcon()
{
	if (SquadClass) {
		ASquad* SquadCDO = Cast<ASquad>(SquadClass.Get()->ClassDefaultObject);
		return SquadCDO->GetSquadIcon();
	}
	return Super::GetIcon();
}


// Sets default values for this component's properties
UProductionQueueComponent::UProductionQueueComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//Orders.AddDefaulted(5);
	// ...
}

UQueueOrder* UProductionQueueComponent::GetCurrentOrder() const
{
	if (Orders.IsValidIndex(0))
		return Orders[0];
	return nullptr;
}

TArray<UQueueOrder*> UProductionQueueComponent::GetPendingOrders() const
{
	auto PendingOrders = Orders;
	PendingOrders.RemoveAt(0);
	return PendingOrders;
}

TArray<UQueueOrder*> UProductionQueueComponent::GetOrders() const
{
	return Orders;
}

void UProductionQueueComponent::StartNewOrder()
{
	if(!InProgress && Orders.IsValidIndex(0))
	{
		InProgress = true;
		float Time = Orders[0]->Time * Efficiency;
		GetWorld()->GetTimerManager().SetTimer(Timer, this, &UProductionQueueComponent::CompleteOrder, Time, false);
	}
}

void UProductionQueueComponent::CompleteOrder()
{
	if(Orders.IsValidIndex(0))
	{
		Orders[0]->HandleOrderCompleted();
		Orders.RemoveAt(0);
		OnOrderCompleted.Broadcast(0);
		InProgress = false;
		StartNewOrder();
	}
	
}

bool UProductionQueueComponent::CancelOrder(int Index)
{
	if (Orders.IsValidIndex(Index))
	{
		Orders.RemoveAt(Index);
		OnOrderCanceled.Broadcast(Index);
	}
	return true;
}

bool UProductionQueueComponent::CancelCurrent()
{
	return CancelOrder(0);
}


void UProductionQueueComponent::CreateOrder(UQueueOrder* Order)
{
	Orders.Add(Order);
	OnOrderCreated.Broadcast(Order);
	if (Orders.Num() == 1)
	{
		StartNewOrder();
	}
}

void UProductionQueueComponent::CreateSquadOrder(TSubclassOf<ASquad> SquadClass)
{
	USquadQueueOrder* Handler = NewObject<USquadQueueOrder>(this);
	Handler->SquadClass = SquadClass;
	CreateOrder(Handler);
}

float UProductionQueueComponent::GetProgress () const
{
	if (InProgress) {
		float Progress = GetWorld()->GetTimerManager().GetTimerElapsed(Timer) / GetCurrentOrder()->Time;
		return Progress;
	}
	return 0;
}
