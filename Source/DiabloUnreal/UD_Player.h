// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DiabloUnrealGameModeBase.h"
#include "UD_Player.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIABLOUNREAL_API UUD_Player : public UActorComponent
{
	GENERATED_BODY()

public:	
	UUD_Player();

protected:
	UPROPERTY(EditAnywhere)
		TEnumAsByte<EUD_CameraType> cameraType = EUD_CameraType::TPS;
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Init();
};
