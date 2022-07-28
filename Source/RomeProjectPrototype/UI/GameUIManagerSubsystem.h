// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameUIManagerSubsystem.generated.h"

class ULocalPlayer;
class UGameUIPolicy;
/**
 * 
 */
UCLASS(Config=Game, Blueprintable)
class ROMEPROJECTPROTOTYPE_API UGameUIManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UGameUIManagerSubsystem() { }

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	const UGameUIPolicy* GetCurrentUIPolicy() const { return CurrentPolicy; }
	UGameUIPolicy* GetCurrentUIPolicy() { return CurrentPolicy; }

	virtual void NotifyPlayerAdded(ULocalPlayer* LocalPlayer);
	//virtual void NotifyPlayerRemoved(UCommonLocalPlayer* LocalPlayer);
	//virtual void NotifyPlayerDestroyed(UCommonLocalPlayer* LocalPlayer);

protected:

	void SwitchToPolicy(UGameUIPolicy* InPolicy);

private:

	UPROPERTY(Transient)
	UGameUIPolicy* CurrentPolicy = nullptr;

	UPROPERTY(config, EditAnywhere)
	TSoftClassPtr<UGameUIPolicy> DefaultUIPolicyClass;
};
