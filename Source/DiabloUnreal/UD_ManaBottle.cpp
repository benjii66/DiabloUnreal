// Fill out your copyright notice in the Description page of Project Settings.


#include "UD_ManaBottle.h"
#include "UD_PlayerCharacter.h"
#include "PlayerCharacterGameMode.h"
#include <DiabloUnreal/UD_PlayerControllerCharacter.h>

// Sets default values
AUD_ManaBottle::AUD_ManaBottle()
{
	Interactable = CreateEditorOnlyDefaultSubobject<UUD_InteractableObject>(TEXT("Interactable"));


 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AUD_ManaBottle::Use(UEntityStats* _statTarget)
{
	UE_LOG(LogTemp, Error, TEXT("you use it"));
	quantity--;
	_statTarget->AddLife(manaValue);
}

void AUD_ManaBottle::InitItem()
{
	id = 2;
	itemName = objectName;
}

// Called when the game starts or when spawned
void AUD_ManaBottle::BeginPlay()
{
	Super::BeginPlay();
	
	BoxCollider = FindComponentByClass<UBoxComponent>();
	if (!BoxCollider)return;
		BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AUD_ManaBottle::OnBoxOverlap);
}

// Called every frame
void AUD_ManaBottle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Rotate(allowRotation);

}

void AUD_ManaBottle::OnBoxOverlap(UPrimitiveComponent* _component, AActor* _otherActor, UPrimitiveComponent* _otherComp, int32 _otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlayerCharacterGameMode* _gameMode = GetWorld()->GetAuthGameMode<APlayerCharacterGameMode>();
	if (_gameMode)
	{
		AUD_PlayerCharacter* _player = Cast<AUD_PlayerCharacter>(_otherActor);
		if (_player)
		{
			_player->GetInventory()->AddItem(id, nbItems);
			this->Destroy();
		}
	}
}

void AUD_ManaBottle::Rotate(bool _allowRotation)
{
	FRotator _rotation = FRotator(xValue, yValue, zValue);
	FQuat _quaternion = FQuat(_rotation);

	if (_allowRotation == true)
		AddActorLocalRotation(_quaternion, false, 0, ETeleportType::None);
}

