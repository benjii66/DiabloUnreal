// Fill out your copyright notice in the Description page of Project Settings.


#include "UD_GameHUD.h"

void AUD_GameHUD::DrawHUD()
{
	Super::DrawHUD();

}


void AUD_GameHUD::BeginPlay()
{
	Super::BeginPlay();
	

	InitUI();
}

void AUD_GameHUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


void AUD_GameHUD::InitUI()
{
	widget = CreateWidget<UPlayerWidget>(GetWorld(), widgetClass);
	if (!widget)return;
	widget->AddToViewport();
	widget->UpdateLifeSliderValue(Player->playerLife);//life
	widget->UpdateManaSliderValue(Player->playerMana);//mana 
	widget->UpdateStockText(Item->id,Item->quantity);//id, stock
}