#pragma once
#include "MovingEntity.h"
class Ball : public MovingEntity
{
	static sf::Texture BallTexture;
public:
	Ball(float x, float y);
	void Update() override;
	void Draw(sf::RenderWindow& Window) override;

	void ResetPosition(float x, float y);

	void MoveUp()  noexcept override;
	void MoveLeft() noexcept override;
	void MoveRight() noexcept override;
	void MoveDown() noexcept override;
};

