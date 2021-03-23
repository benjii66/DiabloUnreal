// Fill out your copyright notice in the Description page of Project Settings.


#include "UD_CameraManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AUD_CameraManager::AUD_CameraManager()
{ 	
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AUD_CameraManager::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AUD_CameraManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	OnCameraUpdate.Broadcast(DeltaTime);
	OnCameraDrawDebugs.Broadcast(FVector::ZeroVector);
}

#pragma region Add/Remove

void AUD_CameraManager::Add(UUD_CameraBehaviour* _camera)
{
	if (!_camera || Exist(_camera)) return;
	cameras.Add(TPair<FString, UUD_CameraBehaviour*>(_camera->GetID(), _camera));
	OnCameraUpdate.AddUObject(_camera, &UUD_CameraBehaviour::MoveTo);
	OnCameraUpdate.AddUObject(_camera, &UUD_CameraBehaviour::Rotate);
	OnCameraDrawDebugs.AddUObject(_camera, &UUD_CameraBehaviour::DrawGizmos);
}

void AUD_CameraManager::Remove(FString _id)
{
	if (!Exist(_id)) return;
	cameras.Remove(_id);
}

#pragma endregion

#pragma region Exist

bool AUD_CameraManager::Exist(UUD_CameraBehaviour* _camera)
{
	return cameras.Contains(_camera->GetID());
}

bool AUD_CameraManager::Exist(FString _id)
{
	return cameras.Contains(_id);
}

#pragma endregion

#pragma region Enable Disable

void AUD_CameraManager::Enable(FString _id)
{
	if (!Exist(_id)) return;
	cameras.FindChecked(_id)->Activate();
}

void AUD_CameraManager::Disable(FString _id)
{
	if (!Exist(_id)) return;
	cameras.FindChecked(_id)->Deactivate();
}

#pragma endregion


void AUD_CameraManager::DrawDebugs()
{
	DrawDebugSphere(GetWorld(), GetActorLocation(), 20, 20, FColor::Red, false, -1, 0, 1);
}

#pragma region Camera

void AUD_CameraManager::CreateCamera(APawn* _player, EUD_CameraType _type)
{
	FVector _position = GetActorLocation();
	FRotator _rotation = GetActorRotation();
	if (!cameraBP) return;
	AUD_Camera* _camera = GetWorld()->SpawnActor<AUD_Camera>(cameraBP, _position, _rotation);
	if (!_camera) return;
	UUD_CameraBehaviour* _cameraBehaviour = _camera->FindComponentByClass<UUD_CameraBehaviour>();
	if (!_cameraBehaviour) return;

	switch (_type)
	{
	case EUD_CameraType::FPS:
		_cameraBehaviour->InitCamera(FVector(0, 0, 0), _player, 100, 100);
		break;
	case EUD_CameraType::TPS:
		_cameraBehaviour->InitCamera(FVector(-200, 0, 500), _player, 5, 5);
		break;
	default:
		break;
	}
	ControlCamera(_cameraBehaviour->GetID());

}

void AUD_CameraManager::ControlCamera(FString _id)
{
	if (!Exist(_id)) return;
	UE_LOG(LogTemp, Warning, TEXT("take control"));
	UUD_CameraBehaviour* _cam = *cameras.Find(_id);
	AActor* _camera = _cam->GetOwner();
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetViewTarget(_camera);
}

#pragma endregion


