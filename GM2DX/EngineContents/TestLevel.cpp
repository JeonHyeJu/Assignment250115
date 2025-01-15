#include "PreCompile.h"
#include "TestLevel.h"
#include "MyCustomRenderer.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EnginePlatform/EngineInput.h>

ATestLevel::ATestLevel()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	const float SIZE = 100.f;
	Renderer = CreateDefaultSubObject<MyCustomRenderer>();
	Renderer->SetScale3D({ SIZE, SIZE, SIZE });
	Renderer->SetOrder(0);
	Renderer->SetupAttachment(RootComponent);

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

	Renderer->AddWorldRotation({ 0.f, 0.f, 30.f * _DeltaTime });
}
