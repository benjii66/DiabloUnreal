// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UD_PlayerCharacter.h"
#include "PlayerCharacterGameMode.generated.h"

/**
 * 
 */
UCLASS()
class DIABLOUNREAL_API APlayerCharacterGameMode : public AGameModeBase
{
	GENERATED_BODY()

		AUD_PlayerCharacter* player;

public: 
	APlayerCharacterGameMode();
	AUD_PlayerCharacter* GetPlayer();

};
