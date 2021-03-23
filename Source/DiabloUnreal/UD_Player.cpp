// Fill out your copyright notice in the Description page of Project Settings.


#include "UD_Player.h"

// Sets default values for this component's properties
UUD_Player::UUD_Player()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UUD_Player::BeginPlay()
{
	Super::BeginPlay();
	Init();
}


// Called every frame
void UUD_Player::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UUD_Player::Init()
{
	TSoftObjectPtr<AUD_CameraManager> _manager = GetWorld()->GetAuthGameMode<ADiabloUnrealGameModeBase>()->GetCameraManager();
	if (_manager)
	{
		GetWorld()->GetFirstPlayerController()->GetPawn();
		APawn* _pawn = StaticCast<APawn*>(GetOwner());
		if (_pawn) _manager.Get()->CreateCamera(_pawn, cameraType);
	}
	//_manager.Get()->CreateCamera(GetWorld()->GetFirstPlayerController()->GetPawn(), cameraType);


}

