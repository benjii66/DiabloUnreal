// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "IStats.h"
#include "EntityStats.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DIABLOUNREAL_API UEntityStats : public UActorComponent, public IIStats
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UEntityStats();

	UPROPERTY(EditAnywhere)
		int life = 70;
	UPROPERTY(EditAnywhere)
		int mana = 40;
	UPROPERTY(EditAnywhere)
		int maxLife = 100;
	UPROPERTY(EditAnywhere)
		int maxMana = 100;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		bool IsDead();
	virtual bool IsDead_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		int Life(int _lifeValue = 0);
	virtual int Life_Implementation(int _lifeValue);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		int Mana(int _manaValue = 0);
	virtual int Mana_Implementation(int _manaValue);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void TakeDamage(int _damageValue);
	virtual void TakeDamage_Implementation(int _damageValue);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void AddLife(int _lifeValue);
	virtual void AddLife_Implementation(int _lifeValue);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void AddMana(int _manaValue);
	virtual void AddMana_Implementation(int _manaValue);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void UseMana(int _manaValue);
	virtual void UseMana_Implementation(int _manaValue);


public:

	void SetLife(float _life);
	void SetMana(float _mana);

	int GetLife() { return life; };
	int GetMana() { return mana; };

};
