// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UD_PlayerMovement.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIABLOUNREAL_API UUD_PlayerMovement : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUD_PlayerMovement();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	FVector targetPosition;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Init();
	void MoveTo(float _deltaTime);
	void NextPosition(FVector _position);
		
};
