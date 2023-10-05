#include "Background.h"

sf::Texture Background::texture;

Background::Background(float x, float y) : Entity()
{
	texture.loadFromFile("C:\\Users\\pavel\\Desktop\\C++Apps\\TestSmfl\\SFML_BackgorundTexture.jpg"); //C:\\Users\\pavel\\Desktop\\C++Apps\\TestSmfl
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

void Background::Update()
{
}

void Background::Draw(sf::RenderWindow& Window)
{
	Window.draw(sprite);
}
