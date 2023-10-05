#include "Brick.h"

sf::Texture Brick::BrickTexture;

const sf::Color BrickColor_S1{ 0, 255, 0 , 255};
const sf::Color BrickColor_S2{ 0, 0, 255, 255 };
const sf::Color BrickColor_S3{ 255, 0, 0, 255 };

Brick::Brick(float x, float y) : Entity()
{
	BrickTexture.loadFromFile("C:\\Users\\pavel\\Desktop\\C++Apps\\TestSmfl\\brick01.png");
	sprite.setTexture(BrickTexture);

	sprite.setColor(BrickColor_S3);

	sprite.setPosition(x, y);

	sprite.setOrigin(GetCenter());
}

void Brick::Update()
{
	switch (Strenght)
	{
	case 1:
	{
		sprite.setColor(BrickColor_S1);
		break;
	}
	case 2:
	{
		sprite.setColor(BrickColor_S2);
		break;
	}
	case 3:
	{
		sprite.setColor(BrickColor_S3);
		break;
	}
	default:
		break;
	}
}

void Brick::Draw(sf::RenderWindow& Window)
{
	Window.draw(sprite);
}

void Brick::SetStrength(int s) noexcept
{
	Strenght = s;
}

void Brick::Weaken() noexcept
{
	--Strenght;
}

bool Brick::bIsTooWeak() const noexcept
{
	return Strenght<=0;
}
