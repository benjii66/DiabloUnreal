// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterGameMode.h"

APlayerCharacterGameMode::APlayerCharacterGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = APlayerCharacterGameMode::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> _player(TEXT("Blueprint'/Game/Blueprints/Player/UD_PlayerCharacter_BP.UD_PlayerCharacter_BP'"));
	if (_player.Class != nullptr)
		DefaultPawnClass = _player.Class;
}

AUD_PlayerCharacter* APlayerCharacterGameMode::GetPlayer()
{
	return player;
}

