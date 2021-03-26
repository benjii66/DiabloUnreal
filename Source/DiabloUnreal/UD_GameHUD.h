// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerWidget.h"
#include "EntityStats.h"
#include "UD_PlayerCharacter.h"
#include "UD_Item.h"
#include "UD_GameHUD.generated.h"

/**
 *
 */
UCLASS()
class DIABLOUNREAL_API AUD_GameHUD : public AHUD
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TSubclassOf<UPlayerWidget> widgetClass = nullptr;
	UPROPERTY(VisibleAnywhere)
		UPlayerWidget* widget = nullptr;
	UPROPERTY(VisibleAnywhere)
		AUD_PlayerCharacter* Player= nullptr;

	UPROPERTY(VisibleAnywhere)
		AUD_Item* Item = nullptr;
private:
	virtual void DrawHUD() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	void InitUI();
};
