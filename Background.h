#pragma once
#include "Entity.h"

class Background : public Entity
{
	static sf::Texture texture;
public:
	Background(float x, float y);

	void Update() override;
	void Draw(sf::RenderWindow& Window) override;

};

