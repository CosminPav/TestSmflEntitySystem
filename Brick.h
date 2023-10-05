#pragma once
#include "Entity.h"
#include "Properites.h"
class Brick : public Entity
{
	static sf::Texture BrickTexture;

	int Strenght{ Constants::BrickStrenght };
public:
	Brick(float x, float y);

	void Update() override;
	void Draw(sf::RenderWindow& Window) override;

	void SetStrength(int s) noexcept;
	void Weaken() noexcept;
	bool bIsTooWeak() const noexcept;
};

