// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RPPGameInstance.generated.h"

/**
 * 
 */
UCLASS(Abstract, Config = Game, Blueprintable)
class ROMEPROJECTPROTOTYPE_API URPPGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	URPPGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual int32 AddLocalPlayer(ULocalPlayer* NewPlayer, int32 ControllerId) override;
	//virtual bool RemoveLocalPlayer(ULocalPlayer* ExistingPlayer) override;
	virtual void Init() override;
	//virtual void ReturnToMainMenu() override;


private:
	/** This is the primary player*/
	TWeakObjectPtr<ULocalPlayer> PrimaryPlayer;
};
