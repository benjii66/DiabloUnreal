// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EntityStats.h"
#include "UD_Item.h"
#include "UD_Inventory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIABLOUNREAL_API UUD_Inventory : public UActorComponent
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TMap<int, AUD_Item*> allItems;


public:	
	// Sets default values for this component's properties
	UUD_Inventory();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddItem(int _id, int _numberOfItems);
	void UseItem(int _id, UEntityStats* _statTarget);

	void DisplayInventory();

	void InitInventory();

	FORCEINLINE TMap<int, AUD_Item*> GetItems() { return allItems; }


	template<typename T>
	void AddInitItem();
};


