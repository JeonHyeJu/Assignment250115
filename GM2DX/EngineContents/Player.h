#pragma once
#include <EngineCore/Actor.h>

class Player : public AActor
{
public:
	Player();
	~Player();

	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

protected:
	void BeginPlay();
	void Tick(float _deltaTime);

private:
	std::shared_ptr<class MyCustomRenderer> Renderer = nullptr;
};

