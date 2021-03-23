// Fill out your copyright notice in the Description page of Project Settings.


#include "UD_Camera.h"
#include "DiabloUnrealGameModeBase.h"

// Sets default values
AUD_Camera::AUD_Camera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));


}

// Called when the game starts or when spawned
void AUD_Camera::BeginPlay()
{
	Super::BeginPlay();
	cameraBP = GetWorld()->GetAuthGameMode<ADiabloUnrealGameModeBase>()->GetCameraManager()->GetCameraBP();
}

// Called every frame
void AUD_Camera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

