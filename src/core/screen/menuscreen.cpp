#include "menuscreen.h"

#include "../chechugame.h"
#include "../assets.h"
#include "../gameconstants.h"

MenuScreen::MenuScreen(ChechuGame *game)
	: m_game(game)
{
	m_cam.scale( GameConstants::ScaleFactor, GameConstants::ScaleFactor );
	m_x1 = 6;
	m_x2 = 38;
	m_x3 = 66;
	m_x4 = 25;
	m_x5 = -100;
	m_t1 = m_t2 = m_t3 = m_t4 = m_t5 = 0;
}

MenuScreen::~MenuScreen()
{

}

void MenuScreen::show()
{

}

void MenuScreen::hide()
{

}

void MenuScreen::update(double delta)
{
	if( Input::IsKeyDown(ALLEGRO_KEY_ESCAPE) )
	{
		m_game->close();
	}

	if( Input::IsKeyDown(ALLEGRO_KEY_SPACE) || Input::IsKeyDown(ALLEGRO_KEY_ENTER) )
	{
		m_transitioning = true;
	}

	if( m_transitioning && m_t4 < 1 )
	{
		m_t1 += delta * 0.75f;
		m_t2 += delta * 0.75f;
		m_t3 += delta * 0.75f;
		m_t4 += delta * 0.75f;
		m_t5 += delta * 0.75f;
		if( m_t4 >= 1 )
		{
			m_selecting = true;
			m_transitioning = false;
		}
	}

	m_x1 = lerp(6, 120, m_t1);
	m_x2 = lerp(38, -100, m_t2);
	m_x3 = lerp(66, -50, m_t3);
	m_x4 = lerp(25, -5, m_t4);
	m_x5 = lerp(-100, 20, m_t5);

	if( m_selecting ) {
		if( Input::IsKeyJustPressed(ALLEGRO_KEY_UP) )
		{
			m_selected--;
			if( m_selected < 0 ) m_selected = 0;
		}
		else if( Input::IsKeyJustPressed(ALLEGRO_KEY_DOWN) )
		{
			m_selected++;
			if( m_selected > 2 ) m_selected = 2;
		}

		if( Input::IsKeyJustPressed(ALLEGRO_KEY_ENTER) || Input::IsKeyJustPressed(ALLEGRO_KEY_SPACE) )
		{
			if( m_selected == 0 )
			{
				m_game->setScreen(m_game->m_selectBikeScreen);
			}
		}
	}

}

void MenuScreen::render()
{
	al_clear_to_color( al_map_rgb( 0, 0, 0 ) );

	printf("%f\n", m_t4);
	fflush(0);
	m_cam.bind();
	al_draw_text(m_game->m_fontBig, al_map_rgba(255, 255, 255, (1.f-m_t4)*255.f), m_x1, 1, 0, "dash");
	al_draw_text(m_game->m_fontBig, al_map_rgba(255, 255, 255, (1.f-m_t4)*255.f), m_x2, 20, 0, "maker");
	al_draw_text(m_game->m_font, al_map_rgba(255, 255, 255, (1.f-m_t4)*255.f), 10, m_x3, 0, "© derrapeteam");
	al_draw_bitmap( Assets::instance->chechuface, 28, m_x4, 0);

	al_draw_text( m_game->m_font, al_map_rgb(255, 255, 255), m_x5 + 20, 42, 0, "start");
	al_draw_text( m_game->m_font, al_map_rgb(255, 255, 255), m_x5 + 8, 52, 0, "controls");
	al_draw_text( m_game->m_font, al_map_rgb(255, 255, 255), m_x5 + 23, 62, 0, "exit");

	if( m_selecting ) {
		al_draw_text( m_game->m_font, al_map_rgb(255, 255, 255), 20, 42 + m_selected * 10, 0, "~");
	}
}
