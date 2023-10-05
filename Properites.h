#pragma once


struct Constants
{
	static constexpr int WindowWidth{ 1024 };
	static  constexpr int WindowHeight{768};
	static constexpr float BallSpeed{ 6.0f };
	static constexpr float PaddleWidth{ 60.0f };
	static constexpr float PaddleHeight{ 20.0f };
	static constexpr float PaddleSpeed{ 8.0f };

	static constexpr float BrickHeight{ 20.0f };
	static constexpr float BrickWidth{ 43.0f };
	static constexpr float BrickOffset{ BrickWidth/2.0f };

	static constexpr int BrickColumns{ 20 };
	static constexpr int BrickRows{ 8 };
	static constexpr int BrickStrenght{ 3 };

	static constexpr int PlayerLives{ 3 };
};

enum class EGameState 
{
	EGS_Paused,
	EGS_Running,
	EGS_GameOver,
	EGS_GameWon
};
