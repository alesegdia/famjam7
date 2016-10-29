
#pragma once

#include <memory>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include <alligator/game/game.h>

#include "screen/gameplayscreen.h"
#include "screen/menuscreen.h"

class ChechuGame : public Game {

public:

	ChechuGame ( int sw, int sh );
	virtual ~ChechuGame();

	int create( int argc, char** argv ) override ;
	void dispose() override ;

	// all screens
	std::shared_ptr<GameplayScreen> m_gameplayScreen;
	std::shared_ptr<MenuScreen> m_menuScreen;

	ALLEGRO_FONT* m_font = nullptr;
	ALLEGRO_FONT* m_fontBig = nullptr;


};

