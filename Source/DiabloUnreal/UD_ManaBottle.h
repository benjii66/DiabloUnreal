// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UD_InteractableObject.h"
#include "EntityStats.h"
#include "Engine/TriggerBox.h"
#include "Components/BoxComponent.h"
#include "UD_Item.h"
#include "UD_ManaBottle.generated.h"

UCLASS()
class DIABLOUNREAL_API AUD_ManaBottle : public AUD_Item
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUD_ManaBottle();

	FORCEINLINE class UUD_InteractableObject* GetInteractable() { return Interactable; }
	UPROPERTY(EditAnywhere)
		float manaValue = 10;

	virtual void Use(UEntityStats* _statTarget) override;
	virtual void InitItem() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditInstanceOnly, Category = Name)
		FString objectName = "life bottle";
	UPROPERTY(EditInstanceOnly, Category = NumberOfItems)
		int nbItems = 2;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditInstanceOnly, Category = AllowRotation)
		bool allowRotation = true;
	UPROPERTY(EditInstanceOnly, Category = RotationValue)
		float xValue = 0;
	UPROPERTY(EditInstanceOnly, Category = RotationValue)
		float yValue = 0;
	UPROPERTY(EditInstanceOnly, Category = RotationValue)
		float zValue = 2;

	UPROPERTY(EditAnywhere, Category = BoxCollision)
		UBoxComponent* BoxCollider;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Interactable, meta = (AllowPrivateAccess = "true"))
		class UUD_InteractableObject* Interactable;

	UFUNCTION()
		void OnBoxOverlap(UPrimitiveComponent* _component, AActor* _otherActor, UPrimitiveComponent* _otherComp, int32 _otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void Rotate(bool _allowRotation);

};
