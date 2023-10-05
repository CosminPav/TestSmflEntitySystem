#pragma once
#include "Entity.h"


class MovingEntity : public Entity
{
protected:
	sf::Vector2f Velocity;

	virtual void MoveUp()  noexcept = 0;
	virtual void MoveLeft() noexcept = 0;
	virtual void MoveRight() noexcept = 0;
	virtual void MoveDown() noexcept = 0;

};

