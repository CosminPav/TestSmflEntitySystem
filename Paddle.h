#pragma once
#include "MovingEntity.h"
class Paddle :public MovingEntity
{
	static sf::Texture PaddleTexture;
public:
	Paddle(float x, float y);

	void Update() override;
	void Draw(sf::RenderWindow& Window) override;

	void MoveUp()  noexcept override;
	void MoveLeft() noexcept override;
	void MoveRight() noexcept override;
	void MoveDown() noexcept override;

private:
	void ProcessInput();

};

