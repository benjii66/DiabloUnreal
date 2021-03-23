// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EntityStats.h"
#include "UD_Item.generated.h"

UENUM(BlueprintType)
enum class EUD_ItemEnum : uint8
{
	HEALTH_POTION = 0,
	MANA_POTION = 1
};


UCLASS()
class DIABLOUNREAL_API AUD_Item : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUD_Item();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		int id = 0;
	UPROPERTY(EditAnywhere)
		FString itemName = "itemName";
	UPROPERTY(EditAnywhere)
		int quantity = 0;

	FORCEINLINE int ID() { return id; };
	FORCEINLINE bool GotOne() { return quantity > 0; };
	FORCEINLINE void AddStock(int _quantity) { quantity += _quantity; };

	virtual void Use(UEntityStats* _statTarget) PURE_VIRTUAL(UItem::Use, )
	virtual void ItemToString();
	virtual void InitItem();

};

