// Fill out your copyright notice in the Description page of Project Settings.


#include "UD_CameraBehaviour.h"
#include "DiabloUnrealGameModeBase.h"

UUD_CameraBehaviour::UUD_CameraBehaviour()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UUD_CameraBehaviour::BeginPlay()
{
	Super::BeginPlay();
	InitHandler();	
}

#pragma region Init

void UUD_CameraBehaviour::InitCamera(FVector _offset, APawn* _player, float _cameraSpeed, float _lookAtSpeed)
{
	cameraSettings.Init(_offset, _player, _cameraSpeed, _lookAtSpeed);
}

void UUD_CameraBehaviour::InitHandler()
{
	TSoftObjectPtr<AUD_CameraManager> _manager = GetWorld()->GetAuthGameMode<ADiabloUnrealGameModeBase>()->GetCameraManager();
	if (_manager) _manager.Get()->Add(this);
}

#pragma endregion

#pragma region Movement

void UUD_CameraBehaviour::MoveTo(float _deltaTime)
{
	if (!cameraSettings.GetCanMove()) return;
	FVector _currentLocation = GetOwner()->GetActorLocation();
	FVector _targetLocation = cameraSettings.GetFinalPosition();
	GetOwner()->SetActorLocation(FMath::Lerp(_currentLocation, _targetLocation, _deltaTime * cameraSettings.GetCameraSpeed()));
}

void UUD_CameraBehaviour::Rotate(float _deltaTime)
{
	if (!cameraSettings.GetCanRotate()) return;
	FVector _currentLocation = GetOwner()->GetActorLocation();
	FVector _targetLocation = cameraSettings.GetPlayerLocation();
	FQuat _targetRotation = UKismetMathLibrary::FindLookAtRotation(_currentLocation, _targetLocation).Quaternion();
	FQuat _currentRotation = GetOwner()->GetActorRotation().Quaternion();
	GetOwner()->SetActorRotation(FMath::Lerp(_currentRotation, _targetRotation, _deltaTime * cameraSettings.GetLookAtSpeed()));
}

#pragma endregion


// Called every frame
void UUD_CameraBehaviour::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UUD_CameraBehaviour::DrawGizmos(FVector _position)
{
	DrawDebugCamera(GetWorld(), GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation(), 90, 2,FColor::Cyan, false, -1, 0);
	if (cameraSettings.IsPlayer())
	{		
		DrawDebugCamera(GetWorld(), cameraSettings.GetFinalPosition(), GetOwner()->GetActorRotation(), 90, 2, FColor::Green, false, -1, 0);
		DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), cameraSettings.GetPlayerLocation(), FColor::Purple, false, -1, 0, 1);
		DrawDebugSphere(GetWorld(), cameraSettings.GetPlayerLocation(), 20, 20, FColor::Blue, false, -1, 0, 1);
	}
}

