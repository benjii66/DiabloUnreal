// Fill out your copyright notice in the Description page of Project Settings.


#include "UD_PlayerMovement.h"
#include "UD_PlayerController.h"

// Sets default values for this component's properties
UUD_PlayerMovement::UUD_PlayerMovement()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UUD_PlayerMovement::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void UUD_PlayerMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveTo(DeltaTime);
}

void UUD_PlayerMovement::Init()
{
	targetPosition = GetOwner()->GetActorLocation();
	AUD_PlayerController* _controller = GetWorld()->GetFirstPlayerController<AUD_PlayerController>();
	_controller->OnLeftClickEvent().AddUObject(this, &UUD_PlayerMovement::NextPosition);
}


#pragma region Movement

void UUD_PlayerMovement::MoveTo(float _deltaTime)
{
	FVector _currentLocation = GetOwner()->GetActorLocation();
	GetOwner()->SetActorLocation(FMath::LerpStable(_currentLocation, targetPosition, _deltaTime));
}

void UUD_PlayerMovement::NextPosition(FVector _position)
{
	targetPosition = _position;
}

#pragma endregion


