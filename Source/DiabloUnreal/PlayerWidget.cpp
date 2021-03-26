// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWidget.h"

void UPlayerWidget::NativeConstruct()
{

}

void UPlayerWidget::UpdateManaSliderValue(float _mana)
{
	if (!ManaBar)return;
	ManaBar->SetPercent(_mana);
}

void UPlayerWidget::UpdateLifeSliderValue(float _life)
{
	if (!LifeBar)return;
	LifeBar->SetPercent(_life);
}

void UPlayerWidget::UpdateStockText(int _id, int _stock)
{
	FText _stockText = FText::FromString(FString::FromInt(_stock));

	switch (_id)
	{
	case(1):
		LifeStock->SetText(_stockText);
		break;
	case(2):
		ManaStock->SetText(_stockText);
		break;
	}
}
