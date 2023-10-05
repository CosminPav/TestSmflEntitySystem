#include "Paddle.h"
#include "Properites.h"

sf::Texture Paddle::PaddleTexture;

Paddle::Paddle(float x, float y)
{
	PaddleTexture.loadFromFile("C:\\Users\\pavel\\Desktop\\C++Apps\\TestSmfl\\paddle.png");
	sprite.setTexture(PaddleTexture);
	sprite.setPosition(x, y);
	Velocity = { 0.0f, 0.0f };
	//sprite.setOrigin(GetCenter());
}

void Paddle::Update()
{
	ProcessInput();
	sprite.move(Velocity);
}

void Paddle::Draw(sf::RenderWindow& Window)
{
	Window.draw(sprite);
}

void Paddle::MoveUp() noexcept
{
}

void Paddle::MoveLeft() noexcept
{
	Velocity.x = -Constants::PaddleSpeed;
}

void Paddle::MoveRight() noexcept
{
	Velocity.x = Constants::PaddleSpeed;
}

void Paddle::MoveDown() noexcept
{
}

void Paddle::ProcessInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (X() >= 0) {
			Velocity.x = -Constants::PaddleSpeed;
		}
		else {
			Velocity.x = 0.0f;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
		if (X() <= Constants::WindowWidth - Constants::PaddleWidth) {
			Velocity.x = Constants::PaddleSpeed;
		}
		else {
			Velocity.x = 0.0f;
		}
	}
	else {
		Velocity.x = 0.0f;
	}
}

