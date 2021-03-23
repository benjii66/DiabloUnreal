// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UD_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class DIABLOUNREAL_API AUD_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void SetupInputComponent();

protected:
	UPROPERTY(EditAnywhere)
		TArray<TEnumAsByte<EObjectTypeQuery>> objects;

	DECLARE_EVENT_OneParam(AC_PlayerController, FOnLeftClickEvent, FVector);
	FOnLeftClickEvent OnLeftClick;

	void OnLeftClickAction();

public:
	FORCEINLINE FOnLeftClickEvent& OnLeftClickEvent() { return OnLeftClick; };
	const FName mouseMove = "MoveClick";
};
