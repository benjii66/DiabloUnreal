// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "UD_CameraBehaviour.generated.h"

USTRUCT()
struct FUD_CameraSettings
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
		FVector offset;
	UPROPERTY(EditAnywhere)
		float cameraSpeed;
	UPROPERTY(EditAnywhere)
		float lookAtSpeed;
	UPROPERTY(EditAnywhere)
		APawn* playerToFollow;
	UPROPERTY(EditAnywhere)
		bool canMove = true;
	UPROPERTY(EditAnywhere)
		bool canRotate = true;

public:
	FORCEINLINE FVector GetOffset() { return offset; };
	FORCEINLINE float GetCameraSpeed() { return cameraSpeed; };
	FORCEINLINE float GetLookAtSpeed() { return lookAtSpeed; };
	FORCEINLINE bool GetCanMove() { return canMove; };
	FORCEINLINE bool GetCanRotate() { return canRotate; };
	FORCEINLINE bool IsPlayer() { return (playerToFollow != nullptr); };
	
	FORCEINLINE FVector GetPlayerLocation()
	{
		if (!playerToFollow) return FVector::ZeroVector;
		return playerToFollow->GetActorLocation();
	};

	FORCEINLINE FVector GetFinalPosition()
	{
		if (!playerToFollow) return FVector::ZeroVector;
		return GetOffset() + playerToFollow->GetActorLocation();
	};

	FORCEINLINE void SetOffset(FVector _offset) { offset = _offset; };
	FORCEINLINE void SetPlayer(APawn* _player) { playerToFollow = _player; };
	FORCEINLINE void SetCameraSpeed(float _speed) { cameraSpeed = _speed; };
	FORCEINLINE void SetLookAtSpeed(float _speed) { lookAtSpeed = _speed; };
	FORCEINLINE void Init(FVector _offset, APawn* _player, float _cameraSpeed, float _lookAtSpeed)
	{
		SetOffset(_offset);
		SetPlayer(_player);
		SetCameraSpeed(_cameraSpeed);
		SetLookAtSpeed(_lookAtSpeed);
	};
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIABLOUNREAL_API UUD_CameraBehaviour : public UActorComponent
{
	GENERATED_BODY()

public:	
	UUD_CameraBehaviour();

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
		FUD_CameraSettings cameraSettings;
	UPROPERTY(EditAnywhere)
		FString id = "camera";

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	FORCEINLINE FString GetID() { return id; };
	FORCEINLINE FUD_CameraSettings GetSettings() { return cameraSettings; };

	void InitCamera(FVector _offset, APawn* _player, float _cameraSpeed, float _lookAtSpeed);
	void InitHandler();

	void MoveTo(float _deltaTime);
	void Rotate(float _deltaTime);

	void DrawGizmos(FVector _position);
};
