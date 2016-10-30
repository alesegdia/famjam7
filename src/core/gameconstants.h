#pragma once

class GameConstants
{
public:
	static constexpr int WindowWidth = 120;
	static constexpr int WindowHeight = 80;
	static constexpr int ScaleFactor = 6;

	static constexpr int TileSize = 4;
	static constexpr int MapTilesWidth = WindowWidth / TileSize;
	static constexpr int MapTilesHeight = WindowHeight / TileSize;

	static constexpr float DashReduceSpeed = 0.5f;
	static constexpr float FrictionReduceSpeed = 0.01f;

	static constexpr float PlayerAnimScale = 0.05f;
	static constexpr float HumoAnimScale = 8e-1f;

	static constexpr float SpeedFeelingDownScaler = 5;

};
