#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
protected:
	sf::Sprite sprite;
	bool bDestroyed{ false };
public:
	virtual void Update() = 0;
	virtual void Draw(sf::RenderWindow& Window) = 0;
	virtual ~Entity() {}

	sf::FloatRect GetBoundingBox() const noexcept;
	sf::Vector2f GetCenter() const noexcept;

	float X() const noexcept;
	float Y() const noexcept;

	float Left() const noexcept;
	float Right() const noexcept;
	float Bottom() const noexcept;
	float Top() const noexcept;

	void Destroy() noexcept;
	bool IsDestroyed() const  noexcept;
};

