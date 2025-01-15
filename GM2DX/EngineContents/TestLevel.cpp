#include "PreCompile.h"
#include "TestLevel.h"
#include "Player.h"
#include <EngineCore/CameraActor.h>
#include <EnginePlatform/EngineInput.h>

ATestLevel::ATestLevel()
{
	Actor = GetWorld()->SpawnActor<Player>();

	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.f, 0.f, -1000.f });
}

ATestLevel::~ATestLevel()
{
}

void ATestLevel::BeginPlay()
{
	AGameMode::BeginPlay();
}

void ATestLevel::Tick(float _DeltaTime)
{
	AGameMode::Tick(_DeltaTime);

	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	if (UEngineInput::IsDown('P'))
	{
		Camera->FreeCameraSwitch();
	}

	Actor->AddActorRotation({ 0.f, 0.f, 30.f * _DeltaTime });
}
