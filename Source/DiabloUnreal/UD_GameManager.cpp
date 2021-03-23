// Fill out your copyright notice in the Description page of Project Settings.


#include "UD_GameManager.h"
#include "DiabloUnrealGameModeBase.h"

// Sets default values
AUD_GameManager::AUD_GameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUD_GameManager::BeginPlay()
{
	Super::BeginPlay();
	InitInputs();
}

// Called every frame
void AUD_GameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUD_GameManager::InitInputs()
{
	//
}

void AUD_GameManager::SwitchCamera()
{
	index++;
	if (index >= cameras.Num()) index = 0;
	TSoftObjectPtr<AUD_CameraManager> _manager = GetWorld()->GetAuthGameMode<ADiabloUnrealGameModeBase>()->GetCameraManager();
	if (_manager) _manager.Get()->ControlCamera(cameras[index]);
}

void AUD_GameManager::SwitchDebugs()
{
	TSoftObjectPtr<AUD_CameraManager> _manager = GetWorld()->GetAuthGameMode<ADiabloUnrealGameModeBase>()->GetCameraManager();
}

