#pragma once
#include "Properites.h"
#include "Background.h"
#include "Ball.h"
#include "Paddle.h"
#include "Interaction.h"
#include "Brick.h"
#include <vector>
#include "EnittyManager.h"



class GameManager
{
	sf::RenderWindow MainWindow{ {Constants::WindowWidth, Constants::WindowHeight}, "Mark Davis Window" };
	//Background bg{ 0.0f, 0.0f };
	//Ball ball{ Constants::WindowWidth / 2.0f, Constants::WindowHeight / 2.0f };
	//Paddle pad{ Constants::WindowWidth / 2.0f, Constants::WindowHeight - Constants::PaddleHeight };

	//std::vector<Brick> bricks;

	EGameState GameStatus{ EGameState::EGS_Running };

	EnittyManager Manager;

	sf::Font font;
	sf::Text TextGameState, LivesText;

	int Lives{ Constants::PlayerLives };
public:
	GameManager();

	void Reset();
	void Run();

};

