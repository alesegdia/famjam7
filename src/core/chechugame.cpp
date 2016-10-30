#include "chechugame.h"
#include "assets.h"
#include "gameparams.h"

#include <allegro5/allegro_ttf.h>

ChechuGame::ChechuGame(int sw, int sh)
	: Game( sw, sh )
{

}

ChechuGame::~ChechuGame()
{

}

int ChechuGame::create(int argc, char **argv)
{
	Assets::Initialize();
	BikeParamsHolder::Initialize();
	TrackParamsHolder::Initialize();

	m_gameplayScreen.reset(new GameplayScreen(this));
	m_menuScreen.reset(new MenuScreen(this));
	m_selectBikeScreen.reset(new SelectBikeScreen(this));
	m_selectTrackScreen.reset(new SelectTrackScreen(this));
	m_controlsScreen.reset(new ControlsScreen(this));

	setScreen(m_menuScreen);

	m_font = al_load_ttf_font("assets/Early GameBoy.ttf", 8, 0);
	m_fontBig = al_load_ttf_font("assets/Early GameBoy.ttf", 16, 0);

	FILE* f = fopen("savedash", "rb");
	if( f )
	{
		fread(&m_hiscore, sizeof(m_hiscore), 1, f);
		m_prevHiscore = m_hiscore;
		if( m_hiscore > 9999 )
		{
			m_hiscore = 9999;
			m_prevHiscore = 9999;
		}
		fclose(f);
		recomputePermissions();
	}

	return 0;
}

void ChechuGame::dispose()
{
	al_destroy_font(m_font);
	al_destroy_font(m_fontBig);

	Assets::Dispose();
}
