// Fill out your copyright notice in the Description page of Project Settings.


#include "RPPGameInstance.h"

#include "GameplayTagContainer.h"
#include "UI/GameUIManagerSubsystem.h"

URPPGameInstance::URPPGameInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}


int32 URPPGameInstance::AddLocalPlayer(ULocalPlayer* NewPlayer, int32 ControllerId)
{
	int32 ReturnVal = Super::AddLocalPlayer(NewPlayer, ControllerId);
	if (ReturnVal != INDEX_NONE)
	{
		if (!PrimaryPlayer.IsValid())
		{
			UE_LOG(LogTemp, Log, TEXT("AddLocalPlayer: Set %s to Primary Player"), *NewPlayer->GetName());
			PrimaryPlayer = NewPlayer;
		}

		GetSubsystem<UGameUIManagerSubsystem>()->NotifyPlayerAdded(Cast<ULocalPlayer>(NewPlayer));
	}

	return ReturnVal;
}

void URPPGameInstance::Init()
{
	Super::Init();

	// After subsystems are initialized, hook them together
	/*FGameplayTagContainer PlatformTraits = ICommonUIModule::GetSettings().GetPlatformTraits();

	UCommonUserSubsystem* UserSubsystem = GetSubsystem<UCommonUserSubsystem>();
	if (ensure(UserSubsystem))
	{
		UserSubsystem->SetTraitTags(PlatformTraits);
		UserSubsystem->OnHandleSystemMessage.AddDynamic(this, &UCommonGameInstance::HandleSystemMessage);
		UserSubsystem->OnUserPrivilegeChanged.AddDynamic(this, &UCommonGameInstance::HandlePrivilegeChanged);
	}*/
}