
#pragma once

#include <memory>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include <alligator/game/game.h>

#include "screen/gameplayscreen.h"
#include "screen/menuscreen.h"
#include "screen/selectbikescreen.h"
#include "screen/selecttrackscreen.h"
#include "screen/controlsscreen.h"

class ChechuGame : public Game {

public:

	ChechuGame ( int sw, int sh );
	virtual ~ChechuGame();

	int create( int argc, char** argv ) override ;
	void dispose() override ;

	// all screens
	std::shared_ptr<GameplayScreen> m_gameplayScreen;
	std::shared_ptr<MenuScreen> m_menuScreen;
	std::shared_ptr<SelectBikeScreen> m_selectBikeScreen;
	std::shared_ptr<SelectTrackScreen> m_selectTrackScreen;
	std::shared_ptr<ControlsScreen> m_controlsScreen;

	ALLEGRO_FONT* m_font = nullptr;
	ALLEGRO_FONT* m_fontBig = nullptr;
	int m_bikeLevel = 0;
	int m_trackLevel = 0;

	void recomputePermissions()
	{
		for( int i = 0; i < 3; i++ )
		{
			if( TrackParamsHolder::s_tracks[i].realPtsToUnlock < m_hiscore )
			{
				m_trackLevel = i;
			}
			if( BikeParamsHolder::s_bikes[i].realPtsToUnlock < m_hiscore )
			{
				m_bikeLevel = i;
			}
		}

		if( m_hiscore > m_prevHiscore )
		{
			m_prevHiscore = m_hiscore;
			FILE* f = fopen("savedash", "wb");
			if( f )
			{
				fwrite(&m_hiscore, sizeof(m_hiscore), 1, f);
				fclose(f);
			}
		}
	}

	int m_hiscore = 0;

	int m_prevHiscore = 0;


};

