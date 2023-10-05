#pragma once

#include<random>
#include <SFML/Graphics.hpp>

/*
* RANDOM WALK GENERATOR
*/

class Creature
{
	static std::mt19937 mt;
	static std::bernoulli_distribution bd;
	
	float vx{ 4.0f };
	float vy{ 4.0f };
	sf::Vector2f Velocity;
	sf::CircleShape Circle; 
public:
	Creature(float x, float y) {
		Velocity = { vx, vy };
		Circle.setPosition(x, y);
		Circle.setRadius(10.0f);
		Circle.setFillColor(sf::Color::Blue);
	}

	void Draw(sf::RenderWindow& Window)
	{
		Window.draw(Circle);
	}

	void Update()
	{
		vx = bd(mt) ? vx : -vx;
		vy = bd(mt) ? vy : -vy;
		Circle.move({ vx, vy });
	}
};
std::mt19937 Creature::mt;
std::bernoulli_distribution Creature::bd;