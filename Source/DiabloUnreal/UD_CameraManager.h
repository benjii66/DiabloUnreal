// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UD_CameraBehaviour.h"
#include "UD_Camera.h"
#include "Camera/CameraComponent.h"
#include "UD_CameraManager.generated.h"

UENUM(BlueprintType)
enum EUD_CameraType
{
	FPS UMETA(DisplayName = "FPS"),
	TPS UMETA(DisplayName = "TPS")
};

UCLASS()
class DIABLOUNREAL_API AUD_CameraManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AUD_CameraManager();

protected:
	UPROPERTY(EditAnywhere)
		UClass* cameraBP = nullptr;
	virtual void BeginPlay() override;
	TMap<FString, UUD_CameraBehaviour*> cameras = TMap<FString, UUD_CameraBehaviour*>();

	DECLARE_EVENT_OneParam(AUD_CameraManager, FOnCameraUpdate, float);
	FOnCameraUpdate OnCameraUpdate;

	DECLARE_EVENT_OneParam(AUD_CameraManager, FOnCameraDrawDebugs, FVector);
	FOnCameraDrawDebugs OnCameraDrawDebugs;

public:	
	virtual void Tick(float DeltaTime) override;
	UClass* GetCameraBP() { return cameraBP; };

	void Add(UUD_CameraBehaviour* _camera);
	void Remove(FString _id);

	bool Exist(UUD_CameraBehaviour* _camera);
	bool Exist(FString _id);

	void Enable(FString _id);
	void Disable(FString _id);

	void DrawDebugs();

	void CreateCamera(APawn* _player, EUD_CameraType _type);
	void ControlCamera(FString _id);
};
