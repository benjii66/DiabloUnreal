// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UD_CameraManager.h"
#include "DiabloUnrealGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DIABLOUNREAL_API ADiabloUnrealGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<AUD_CameraManager> cameraManager = nullptr;

public:
	FORCEINLINE TSoftObjectPtr<AUD_CameraManager> GetCameraManager() { return cameraManager; };
	
};
