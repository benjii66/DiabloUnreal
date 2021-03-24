// Fill out your copyright notice in the Description page of Project Settings.


#include "UD_PlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Materials/Material.h"
#include "Engine/World.h"

// Sets default values
AUD_PlayerCharacter::AUD_PlayerCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	SpringArm->TargetArmLength = 800.f;
	SpringArm->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	SpringArm->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Create a decal in the world to show the cursor's location
	CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	CursorToWorld->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UMaterial> _cursorMaterial(TEXT("Material'/Game/Blueprints/Materials/Cursor_Decal.Cursor_Decal'"));

	if (_cursorMaterial.Succeeded())
		CursorToWorld->SetDecalMaterial(_cursorMaterial.Object);

	CursorToWorld->DecalSize = FVector(16.0f, 32.0f, 32.0f);
	CursorToWorld->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());



	EntityStats = CreateEditorOnlyDefaultSubobject<UEntityStats>(TEXT("Stats"));

	Inventory = CreateEditorOnlyDefaultSubobject<UUD_Inventory>(TEXT("Inventory"));



	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUD_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AUD_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

// Called to bind functionality to input
void AUD_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AUD_PlayerCharacter::Move()
{
	if (CursorToWorld != nullptr)
	{
		if (APlayerController* _player = Cast<APlayerController>(GetController()))
		{
			FHitResult _hitResult;
			_player->GetHitResultUnderCursor(ECC_Visibility, true, _hitResult);

			FVector _cursorVector = _hitResult.ImpactNormal;
			FRotator _cursorRotator = _cursorVector.Rotation();

			CursorToWorld->SetWorldLocation(_hitResult.Location);
			CursorToWorld->SetWorldRotation(_cursorRotator);
		}
	}
}

