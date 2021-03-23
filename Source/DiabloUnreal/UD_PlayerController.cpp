// Fill out your copyright notice in the Description page of Project Settings.


#include "UD_PlayerController.h"

void AUD_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	SetShowMouseCursor(true);
	check(InputComponent);

	InputComponent->BindAction(mouseMove, IE_Released, this, &AUD_PlayerController::OnLeftClickAction);
}

void AUD_PlayerController::OnLeftClickAction()
{
	FHitResult _result;
	if (GetHitResultUnderCursorForObjects(objects, true, _result))
		OnLeftClick.Broadcast(_result.Location);
}
