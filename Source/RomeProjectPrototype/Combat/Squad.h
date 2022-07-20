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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Squad"))
	float GetHealth();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Squad"))
	float GetArmor();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Squad"))
	float GetDamage();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Squad"))
	float GetAttackSpeed();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Squad"))
	float GetRange();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Squad"))
	FString GetSquadName();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Squad"))
	FString GetSquadDescription();

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (Category = "Squad"))
	UTexture2D* GetSquadIcon();

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

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Category = "Squad"))
	FString Name = "Squad Name";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Category = "Squad"))
	FString Description = "Squad Desc";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Category = "Squad"))
	UTexture2D* Icon;

};
