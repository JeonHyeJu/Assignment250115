#pragma once
#include <EngineCore/GameMode.h>

class ATestLevel : public AGameMode
{
public:
	ATestLevel();
	~ATestLevel();

	ATestLevel(const ATestLevel& _other) = delete;
	ATestLevel(ATestLevel&& _other) noexcept = delete;
	ATestLevel& operator=(const ATestLevel& _other) = delete;
	ATestLevel& operator=(ATestLevel&& _other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class MyCustomRenderer> Renderer = nullptr;
};
