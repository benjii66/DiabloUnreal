// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EntityStats.h"
#include "UD_Inventory.h"
#include "UD_PlayerControllerCharacter.generated.h"

/**
 *
 */
UCLASS()
class DIABLOUNREAL_API AUD_PlayerControllerCharacter : public APlayerController
{
	GENERATED_BODY()

protected:
	bool mouseClick = false;

	
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;


	UPROPERTY(EditAnywhere)
		UEntityStats* entity;

	UPROPERTY(EditAnywhere)
		UUD_Inventory* inventory;

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();

	void UsePotion();

public: 
	AUD_PlayerControllerCharacter();

};
