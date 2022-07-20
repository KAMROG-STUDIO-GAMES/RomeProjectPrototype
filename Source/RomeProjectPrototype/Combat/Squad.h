// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

	UFUNCTION(BlueprintCallable)
	float GetHealth();

	UFUNCTION(BlueprintCallable)
	float GetArmor();

	UFUNCTION(BlueprintCallable)
	float GetDamage();

	UFUNCTION(BlueprintCallable)
	float GetAttackSpeed();

	UFUNCTION(BlueprintCallable)
	float GetRange();

	UFUNCTION(BlueprintCallable)
	FString GetName();

	UFUNCTION(BlueprintCallable)
	FString GetDescription();

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Health = 100;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Armor = 2;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Damage = 10;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float AttackSpeed = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Range = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Name = "Squad Name";

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Description = "Squad Desc";
};
