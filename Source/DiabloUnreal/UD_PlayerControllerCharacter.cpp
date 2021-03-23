// Fill out your copyright notice in the Description page of Project Settings.


#include "UD_PlayerControllerCharacter.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UD_LifeBottle.h"
#include "UD_PlayerCharacter.h"
#include "Engine/World.h"


AUD_PlayerControllerCharacter::AUD_PlayerControllerCharacter()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void AUD_PlayerControllerCharacter::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	if (mouseClick)
		MoveToMouseCursor();
}

void AUD_PlayerControllerCharacter::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("MoveClick", IE_Pressed, this, &AUD_PlayerControllerCharacter::OnSetDestinationPressed);
	InputComponent->BindAction("MoveClick", IE_Released, this, &AUD_PlayerControllerCharacter::OnSetDestinationReleased);
	InputComponent->BindAction("UsePotion", IE_Pressed, this, &AUD_PlayerControllerCharacter::UsePotion);
}

void AUD_PlayerControllerCharacter::MoveToMouseCursor()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
		SetNewMoveDestination(Hit.ImpactPoint);
}



void AUD_PlayerControllerCharacter::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void AUD_PlayerControllerCharacter::OnSetDestinationPressed()
{
	mouseClick = true;
}

void AUD_PlayerControllerCharacter::OnSetDestinationReleased()
{
	mouseClick = false;
}

void AUD_PlayerControllerCharacter::UsePotion()
{
	TArray<AActor*> _players;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AUD_PlayerCharacter::StaticClass(), _players);
	AUD_PlayerCharacter* _player = Cast<AUD_PlayerCharacter>(_players[0]);


	if (!_player) return;
	UUD_Inventory* _inventory = _player->GetInventory();


	UE_LOG(LogTemp, Warning, TEXT("id : %d"), (int)EUD_ItemEnum::HEALTH_POTION);


	if (!_inventory) return;
	_inventory->UseItem((int)EUD_ItemEnum::HEALTH_POTION, _player->GetEntityStats());
}

