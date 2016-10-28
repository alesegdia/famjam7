
#pragma once

#include <memory>

#include <alligator/game/game.h>
#include <allegro5/allegro.h>

#include "screen/gameplayscreen.h"

class ChechuGame : public Game {

public:

	ChechuGame ( int sw, int sh );
	virtual ~ChechuGame();

	int create( int argc, char** argv ) override ;
	void dispose() override ;

	// all screens
	std::shared_ptr<GameplayScreen> m_gameplayScreen;

};

