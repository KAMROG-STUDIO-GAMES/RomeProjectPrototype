// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/Texture2D.h"
#include "Squad.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ROMEPROJECTPROTOTYPE_API ASquad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASquad();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	float ApplyDamage(float IncomingDamage);
	float ApplyDamage_Implementation(float IncomingDamage);


public:	

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Squad"))
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Squad"))
	float GetArmor() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Squad"))
	float GetDamage() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Squad"))
	float GetAttackSpeed() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Squad"))
	float GetRange() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Squad"))
	FText GetSquadName() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Squad"))
	FText GetSquadDescription() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Squad"))
	UTexture2D* GetSquadIcon() const;

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Category = "Squad"))
	float Health = 100;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Category = "Squad"))
	float Armor = 2;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Category = "Squad"))
	float Damage = 10;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Category = "Squad"))
	float AttackSpeed = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Category = "Squad"))
	float Range = 1;


	#define LOCTEXT_NAMESPACE "SquadNamespace"

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Category = "Squad"))
	FText Name = LOCTEXT("SquadName", "Squad Name");

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Category = "Squad"))
	FText Description = LOCTEXT("SquadDescription", "Squad Description");

	#undef LOCTEXT_NAMESPACE


	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Category = "Squad"))
	UTexture2D* Icon;

};
