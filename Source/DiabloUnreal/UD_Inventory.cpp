// Fill out your copyright notice in the Description page of Project Settings.


#include "UD_Inventory.h"
#include "UD_LifeBottle.h"

// Sets default values for this component's properties
UUD_Inventory::UUD_Inventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UUD_Inventory::BeginPlay()
{
	Super::BeginPlay();

	InitInventory();
	DisplayInventory();
}


// Called every frame
void UUD_Inventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UUD_Inventory::AddItem(int _id, int _numberOfItems)
{
	allItems[_id]->AddStock(_numberOfItems);
	DisplayInventory();
}

void UUD_Inventory::UseItem(int _id, UEntityStats* _statTarget)
{
	//problème de pair dans le tmap 
	//id correspond pas ? 


	UE_LOG(LogTemp, Error, TEXT("id : %d"), _id);
	UE_LOG(LogTemp, Error, TEXT("should be used"));

	//if (!allItems[_id]->GotOne())
	//{
	//	UE_LOG(LogTemp, Error, TEXT("No more quantity"));
	//	return;
	//}
	//allItems[_id]->Use(_statTarget);

}

void UUD_Inventory::DisplayInventory()
{
	for (auto& _element : allItems)
		_element.Value->ItemToString();

}

void UUD_Inventory::InitInventory()
{
	AddInitItem<AUD_LifeBottle>();
	AddInitItem<AUD_LifeBottle>();
}


template<typename T>
void UUD_Inventory::AddInitItem()
{
	T* _healPotion = NewObject<T>();
	_healPotion->InitItem();
	allItems.Add(_healPotion->ID(), _healPotion);
}

