// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CommonUIExtensions.generated.h"

/**
 * 
 */
UCLASS()
class ROMEPROJECTPROTOTYPE_API UCommonUIExtensions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UCommonUIExtensions() { }

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Global UI Extensions")
	static UCommonActivatableWidget* PushContentToLayer_ForPlayer(const ULocalPlayer* LocalPlayer, UPARAM(meta = (Categories = "UI.Layer")) FGameplayTag LayerName, UPARAM(meta = (AllowAbstract = false)) TSubclassOf<UCommonActivatableWidget> WidgetClass);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Global UI Extensions")
	static void PushStreamedContentToLayer_ForPlayer(const ULocalPlayer* LocalPlayer, UPARAM(meta = (Categories = "UI.Layer")) FGameplayTag LayerName, UPARAM(meta = (AllowAbstract = false)) TSoftClassPtr<UCommonActivatableWidget> WidgetClass);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Global UI Extensions")
	static void PopContentFromLayer(UCommonActivatableWidget* ActivatableWidget);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Global UI Extensions")
	static ULocalPlayer* GetLocalPlayerFromController(APlayerController* PlayerController);
};
