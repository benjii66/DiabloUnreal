// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IStats.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIStats : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DIABLOUNREAL_API IIStats
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		bool IsDead();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		int Life(int _lifeValue = 0);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		int Mana(int _manaValue = 0);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void TakeDamage(int _damageValue);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void AddLife(int _lifeValue);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void AddMana(int _manaValue);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void UseMana(int _manaValue);
};
