#include "controlsscreen.h"
#include "../chechugame.h"
#include "../assets.h"
#include "../gameconstants.h"

ControlsScreen::ControlsScreen( ChechuGame* game )
	: m_game(game)
{
	m_cam.scale( GameConstants::ScaleFactor, GameConstants::ScaleFactor );
}

ControlsScreen::~ControlsScreen()
{

}


void ControlsScreen::show()
{

}

void ControlsScreen::hide()
{

}

void ControlsScreen::update(double delta)
{
	if( Input::IsKeyJustPressed(ALLEGRO_KEY_SPACE) || Input::IsKeyJustPressed(ALLEGRO_KEY_ENTER) )
	{
		Assets::instance->click->play();
		m_game->setScreen(m_game->m_menuScreen);
	}
}

void ControlsScreen::render()
{
	al_clear_to_color( al_map_rgb( 0, 0, 0 ) );
	al_draw_text(m_game->m_fontBig, al_map_rgb(255,255,255), 6,4,0, "control");
	al_draw_textf(m_game->m_font, al_map_rgb(255,255,255), 10, 24, 0, "alternate");

	al_draw_textf(m_game->m_font, al_map_rgb(255,255,255), 10, 34, 0, "z and x keys");
	al_draw_textf(m_game->m_font, al_map_rgb(255,255,255), 10, 44, 0, "to run");

	al_draw_text(m_game->m_font, al_map_rgb(255,255,255), 10, 60, 0, "space to dash");
}
