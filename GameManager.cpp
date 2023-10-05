#include "GameManager.h"


GameManager::GameManager()
{
	MainWindow.setFramerateLimit(60);

	font.loadFromFile("C:\\Windows\\Fonts\\Georgia.ttf");
	TextGameState.setFont(font);
	TextGameState.setPosition(Constants::WindowWidth / 2.0f-100.0f , Constants::WindowHeight / 2.0f-100.0f );
	TextGameState.setCharacterSize(35);
	TextGameState.setFillColor(sf::Color::Magenta);
	TextGameState.setString("Paused");

	

	LivesText.setFont(font);
	LivesText.setPosition(Constants::WindowWidth / 2.0f - 65.0f, Constants::WindowHeight / 2.0f - 50.0f);
	LivesText.setCharacterSize(35);
	LivesText.setFillColor(sf::Color::Magenta);
	LivesText.setString("Lives "+std::to_string(Lives));
}

void GameManager::Reset()
{
	Lives = Constants::PlayerLives;
	GameStatus = EGameState::EGS_Paused;

	Manager.Clear();
	Manager.Create<Background>(0.0f, 0.0f);
	Manager.Create<Ball>(Constants::WindowWidth / 2.0f, Constants::WindowHeight / 2.0f);
	Manager.Create<Paddle>(Constants::WindowWidth / 2.0f, Constants::WindowHeight - Constants::PaddleHeight);

	for (int i = 0; i < Constants::BrickColumns; ++i) {
		for (int j = 0; j < Constants::BrickRows; ++j) {
			float x = Constants::BrickOffset + (i + 1) * Constants::BrickWidth;
			float y = (j + 1) * Constants::BrickHeight;

			//Make the brick obejct directly in the vector
			Manager.Create<Brick>(x, y);
		}
	}
	MainWindow.setFramerateLimit(60);
}

void GameManager::Run()
{
	bool bPauseButton = false;

	while (MainWindow.isOpen()) {
		MainWindow.clear(sf::Color::Black);

		sf::Event event;

		while (MainWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				MainWindow.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
				MainWindow.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
				if (!bPauseButton) {
					if (GameStatus == EGameState::EGS_Paused)
						GameStatus = EGameState::EGS_Running;
					else
						GameStatus = EGameState::EGS_Paused;
				}
				bPauseButton = true;
			}
			else {
				bPauseButton = false;
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
				Reset();
			}

			if (GameStatus == EGameState::EGS_Paused)
				Manager.Draw(MainWindow);
		}
		if (GameStatus != EGameState::EGS_Running) {

			switch (GameStatus)
			{
			case EGameState::EGS_Paused:
				TextGameState.setString("Paused...");
				break;
			case EGameState::EGS_GameOver:
				TextGameState.setString("Game over!");
				break;
			case EGameState::EGS_GameWon:
				TextGameState.setString("Win!!");
				break;
			default:
				break;
			}
			MainWindow.draw(TextGameState);
			MainWindow.draw(LivesText);

		}
		else {
			if (Manager.GetAll<Ball>().empty()) {
				Manager.Create<Ball>(Constants::WindowWidth / 2.0f, Constants::WindowHeight / 2.0f);
				--Lives;
				GameStatus = EGameState::EGS_Paused;
			}
			if (Manager.GetAll<Brick>().empty()) {
				GameStatus = EGameState::EGS_GameWon;
			}
			if (Lives <= 0)
				GameStatus = EGameState::EGS_GameOver;

			LivesText.setString("Lives " + std::to_string(Lives));
			Manager.Update();

				Manager.ApplyAll<Ball>([this](auto& theBall) {
				Manager.ApplyAll<Brick>([&theBall](auto& theBrick) {HandleCollision(theBall, theBrick); });
			});

			//interaction with the paddle
			Manager.ApplyAll<Ball>([this](auto& theBall) {
				Manager.ApplyAll<Paddle>([&theBall](auto& pad) {
					HandleCollision(theBall, pad);
					});
			});
			Manager.Refresh();
			Manager.Draw(MainWindow);
		}
		
		MainWindow.display();
	}
}
