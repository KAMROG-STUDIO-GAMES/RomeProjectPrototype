// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameUIPolicy.generated.h"

class ULocalPlayer;
class UPrimaryGameLayout;
class UGameUIManagerSubsystem;

/**
 * 
 */
UCLASS(Abstract, Blueprintable, Within = GameUIManagerSubsystem)
class ROMEPROJECTPROTOTYPE_API UGameUIPolicy : public UObject
{
	GENERATED_BODY()

public:
	template <typename GameUIPolicyClass = UGameUIPolicy>
	static GameUIPolicyClass* GetGameUIPolicyAs(const UObject* WorldContextObject)
	{
		return Cast<GameUIPolicyClass>(GetGameUIPolicy(WorldContextObject));
	}

	static UGameUIPolicy* GetGameUIPolicy(const UObject* WorldContextObject);

	virtual UWorld* GetWorld() const override;
	UGameUIManagerSubsystem* GetOwningUIManager() const;
	UPrimaryGameLayout* GetRootLayout(const ULocalPlayer* LocalPlayer) const;

protected:
	void AddLayoutToViewport(ULocalPlayer* LocalPlayer, UPrimaryGameLayout* Layout);
	void RemoveLayoutFromViewport(ULocalPlayer* LocalPlayer, UPrimaryGameLayout* Layout);

	virtual void OnRootLayoutAddedToViewport(ULocalPlayer* LocalPlayer, UPrimaryGameLayout* Layout);
	//virtual void OnRootLayoutRemovedFromViewport(UCommonLocalPlayer* LocalPlayer, UPrimaryGameLayout* Layout);
	//virtual void OnRootLayoutReleased(UCommonLocalPlayer* LocalPlayer, UPrimaryGameLayout* Layout);

	void CreateLayoutWidget(ULocalPlayer* LocalPlayer);
	TSubclassOf<UPrimaryGameLayout> GetLayoutWidgetClass(ULocalPlayer* LocalPlayer);


private:

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<UPrimaryGameLayout> LayoutClass;

	UPROPERTY(Transient)
	UPrimaryGameLayout* RootLayout = nullptr;

	//UPROPERTY(Transient)
	//ULocalPlayer* LPlayer = nullptr;

	void NotifyPlayerAdded(ULocalPlayer* LocalPlayer);
	//void NotifyPlayerRemoved(ULocalPlayer* LocalPlayer);
	//void NotifyPlayerDestroyed(ULocalPlayer* LocalPlayer);

	friend class UGameUIManagerSubsystem;
};
