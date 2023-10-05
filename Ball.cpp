#include "Ball.h"
#include "Properites.h"

sf::Texture Ball::BallTexture;

Ball::Ball(float x, float y)
{
	BallTexture.loadFromFile("C:\\Users\\pavel\\Desktop\\C++Apps\\TestSmfl\\ball.png");
	sprite.setTexture(BallTexture);
	sprite.setPosition(x, y);
	Velocity = { Constants::BallSpeed, Constants::BallSpeed };
}

void Ball::Update()
{
	sprite.move(Velocity);

	//if x <0, the velocity is negative, the ball is moving to the left and it should change dir for right
	if (X() < 0) {
		Velocity.x = -Velocity.x;
	}
	//Means that the ball is in the right side of the screen and should change dir for left
	if (X() > Constants::WindowWidth){
		Velocity.x = -Velocity.x;
	}

	//when y <0, the ball is on the top of the screen, so it should change dir for down
	if (Y() < 0) {
		Velocity.y = -Velocity.y;
	}
	//The ball is on the bottom side of the screen and it should change dir for up
	if (Y() > Constants::WindowHeight) {
		//Velocity.y = -Velocity.y;
		Destroy();
	}
}

void Ball::Draw(sf::RenderWindow& Window)
{
	Window.draw(sprite);
}

void Ball::ResetPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

void Ball::MoveUp() noexcept
{
	Velocity.y = -Constants::BallSpeed;
}

void Ball::MoveLeft() noexcept
{
	Velocity.x = -Constants::BallSpeed;
}

void Ball::MoveRight() noexcept
{
	Velocity.x = Constants::BallSpeed;
}

void Ball::MoveDown() noexcept
{
	Velocity.y = Constants::BallSpeed;
}
