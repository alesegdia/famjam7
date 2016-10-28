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
};
