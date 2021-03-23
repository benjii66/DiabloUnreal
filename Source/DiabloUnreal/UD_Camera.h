// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UD_CameraBehaviour.h"
#include "Camera/CameraComponent.h"
#include "UD_Camera.generated.h"

UCLASS()
class DIABLOUNREAL_API AUD_Camera : public AActor
{
	GENERATED_BODY()
	
public:	
	AUD_Camera();

protected:
	UPROPERTY(EditAnywhere)
		UUD_CameraBehaviour* cameraBehaviour = nullptr;
	UPROPERTY(EditAnywhere)
		UClass* cameraBP = nullptr;
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
