// Fill out your copyright notice in the Description page of Project Settings.


#include "UD_Item.h"

// Sets default values
AUD_Item::AUD_Item()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUD_Item::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUD_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUD_Item::ItemToString()
{
	UE_LOG(LogTemp, Warning, TEXT("Item : %s, Quantity : %d"), *itemName, quantity);
}

void AUD_Item::InitItem()
{

}

