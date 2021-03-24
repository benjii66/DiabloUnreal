// Fill out your copyright notice in the Description page of Project Settings.


#include "EntityStats.h"

// Sets default values for this component's properties
UEntityStats::UEntityStats()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEntityStats::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UEntityStats::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UEntityStats::SetLife(float _life)
{
	life = _life;

	if (life > maxLife)
		life = maxLife;
	else if (life <= 0)
		life = 0;
}

void UEntityStats::SetMana(float _mana)
{
	mana = _mana;

	if (mana > maxMana)
		mana = maxMana;
	else if (mana <= 0)
		mana = 0;
}


bool UEntityStats::IsDead_Implementation()
{
	if (life <= 0)
		return true;
	return false;
}

int UEntityStats::Life_Implementation(int _lifeValue)
{
	return life = _lifeValue;
}

int UEntityStats::Mana_Implementation(int _manaValue)
{
	return mana = _manaValue;
}

void UEntityStats::TakeDamage_Implementation(int _damageValue)
{
	if (IsDead())return;
	SetLife(life - _damageValue);
}

void UEntityStats::AddLife_Implementation(int _lifeValue)
{
	SetLife(life += _lifeValue);
}

void UEntityStats::AddMana_Implementation(int _manaValue)
{
	SetMana(mana += _manaValue);

}

void UEntityStats::UseMana_Implementation(int _manaValue)
{
	SetMana(mana -= _manaValue);
}
