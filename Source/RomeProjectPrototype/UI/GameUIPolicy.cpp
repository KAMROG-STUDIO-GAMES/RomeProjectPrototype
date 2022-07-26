// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameUIPolicy.h"
#include "CommonActivatableWidget.h"
#include "Engine/LocalPlayer.h"
#include "GameUIManagerSubsystem.h"
//#include "CommonLocalPlayer.h"
#include "PrimaryGameLayout.h"
#include "Engine/Engine.h"
//#include "LogCommonGame.h"

// Static
UGameUIPolicy* UGameUIPolicy::GetGameUIPolicy(const UObject* WorldContextObject)
{
	if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		if (UGameInstance* GameInstance = World->GetGameInstance())
		{
			if (UGameUIManagerSubsystem* UIManager = UGameInstance::GetSubsystem<UGameUIManagerSubsystem>(GameInstance))
			{
				return UIManager->GetCurrentUIPolicy();
			}
		}
	}

	return nullptr;
}

UGameUIManagerSubsystem* UGameUIPolicy::GetOwningUIManager() const
{
	return CastChecked<UGameUIManagerSubsystem>(GetOuter());
}

UWorld* UGameUIPolicy::GetWorld() const
{
	return GetOwningUIManager()->GetGameInstance()->GetWorld();
}

UPrimaryGameLayout* UGameUIPolicy::GetRootLayout(const ULocalPlayer* LocalPlayer) const
{
	return RootLayout;
}

void UGameUIPolicy::AddLayoutToViewport(ULocalPlayer* LocalPlayer, UPrimaryGameLayout* Layout)
{
	//UE_LOG(LogTemp, Log, TEXT("[%s] is adding player [%s]'s root layout [%s] to the viewport"), *GetName(), *GetNameSafe(LocalPlayer), *GetNameSafe(Layout));

	Layout->SetPlayerContext(FLocalPlayerContext(LocalPlayer));
	Layout->AddToPlayerScreen(1000);

	OnRootLayoutAddedToViewport(LocalPlayer, Layout);
}

void UGameUIPolicy::RemoveLayoutFromViewport(ULocalPlayer* LocalPlayer, UPrimaryGameLayout* Layout)
{
	TWeakPtr<SWidget> LayoutSlateWidget = Layout->GetCachedWidget();
	if (LayoutSlateWidget.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] is removing player [%s]'s root layout [%s] from the viewport"), *GetName(), *GetNameSafe(LocalPlayer), *GetNameSafe(Layout));

		Layout->RemoveFromViewport();
		if (LayoutSlateWidget.IsValid())
		{
			UE_LOG(LogTemp, Log, TEXT("Player [%s]'s root layout [%s] has been removed from the viewport, but other references to its underlying Slate widget still exist. Noting in case we leak it."), *GetNameSafe(LocalPlayer), *GetNameSafe(Layout));
		}

		//OnRootLayoutRemovedFromViewport(LocalPlayer, Layout);
	}
}

void UGameUIPolicy::OnRootLayoutAddedToViewport(ULocalPlayer* LocalPlayer, UPrimaryGameLayout* Layout)
{
#if WITH_EDITOR
	if (GIsEditor && LocalPlayer->IsPrimaryPlayer())
	{
		// So our controller will work in PIE without needing to click in the viewport
		FSlateApplication::Get().SetUserFocusToGameViewport(0);
	}
#endif
}

void UGameUIPolicy::CreateLayoutWidget(ULocalPlayer* LocalPlayer)
{
	if (APlayerController* PlayerController = LocalPlayer->GetPlayerController(GetWorld()))
	{
		TSubclassOf<UPrimaryGameLayout> LayoutWidgetClass = GetLayoutWidgetClass(LocalPlayer);
		if (ensure(LayoutWidgetClass && !LayoutWidgetClass->HasAnyClassFlags(CLASS_Abstract)))
		{
			UPrimaryGameLayout* NewLayoutObject = CreateWidget<UPrimaryGameLayout>(PlayerController, LayoutWidgetClass);
			RootLayout = NewLayoutObject;

			AddLayoutToViewport(LocalPlayer, NewLayoutObject);
		}
	}
}

TSubclassOf<UPrimaryGameLayout> UGameUIPolicy::GetLayoutWidgetClass(ULocalPlayer* LocalPlayer)
{
	return LayoutClass.LoadSynchronous();
}

void UGameUIPolicy::NotifyPlayerAdded(ULocalPlayer* LocalPlayer)
{
	/*LocalPlayer->OnPlayerControllerSet.AddWeakLambda(this, [this](ULocalPlayer* LocalPlayer, APlayerController* PlayerController)
		{
			NotifyPlayerRemoved(LocalPlayer);

			if (FRootViewportLayoutInfo* LayoutInfo = RootViewportLayouts.FindByKey(LocalPlayer))
			{
				AddLayoutToViewport(LocalPlayer, LayoutInfo->RootLayout);
				LayoutInfo->bAddedToViewport = true;
			}
			else
			{
				CreateLayoutWidget(LocalPlayer);
			}
		});*/

	if (RootLayout && LocalPlayer)
	{
		AddLayoutToViewport(LocalPlayer, RootLayout);
	}
	else
	{
		CreateLayoutWidget(LocalPlayer);
	}
}