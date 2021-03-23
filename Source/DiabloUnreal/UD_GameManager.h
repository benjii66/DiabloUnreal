// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UD_GameManager.generated.h"

UCLASS()
class DIABLOUNREAL_API AUD_GameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AUD_GameManager();

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
		TArray<FString> cameras;
	UPROPERTY()
		int index = 0;

public:
	virtual void Tick(float DeltaTime) override;
	void SwitchCamera();
	void SwitchDebugs();
	void InitInputs();
};
