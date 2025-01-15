#include "PreCompile.h"
#include "Player.h"
#include "MyCustomRenderer.h"
#include <EngineCore/DefaultSceneComponent.h>

Player::Player()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	const float SIZE = 100.f;
	Renderer = CreateDefaultSubObject<MyCustomRenderer>();
	Renderer->SetScale3D({ SIZE, SIZE, SIZE });
	Renderer->SetOrder(0);
	Renderer->SetupAttachment(RootComponent);
}

Player::~Player()
{
}

void Player::BeginPlay()
{
	AActor::BeginPlay();
}

void Player::Tick(float _deltaTime)
{
	AActor::Tick(_deltaTime);
}
