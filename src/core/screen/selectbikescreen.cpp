#include "selectbikescreen.h"
#include "../chechugame.h"
#include "../assets.h"
#include "../gameconstants.h"
#include "../gameparams.h"

SelectBikeScreen::SelectBikeScreen( ChechuGame* game )
	: m_game(game)
{
	m_cam.scale( GameConstants::ScaleFactor, GameConstants::ScaleFactor );
}

SelectBikeScreen::~SelectBikeScreen()
{

}

void SelectBikeScreen::show()
{
}

void SelectBikeScreen::hide()
{

}

void SelectBikeScreen::update(double delta)
{
	Assets::instance->playintro();

	if( Input::IsKeyDown(ALLEGRO_KEY_ESCAPE) )
	{
		m_game->close();
	}

	if( Input::IsKeyJustPressed(ALLEGRO_KEY_LEFT) )
	{
		Assets::instance->click->play();
		m_selectedBike--;
		if( m_selectedBike < 0 ) m_selectedBike = 0;
		Assets::instance->set_bike_color(m_selectedBike);
	}
	if( Input::IsKeyJustPressed(ALLEGRO_KEY_RIGHT) )
	{
		Assets::instance->click->play();
		m_selectedBike++;
		if( m_selectedBike > 2 ) m_selectedBike = 2;
		Assets::instance->set_bike_color(m_selectedBike);
	}

	if( Input::IsKeyJustPressed(ALLEGRO_KEY_ENTER) || Input::IsKeyJustPressed(ALLEGRO_KEY_SPACE) )
	{
		if( m_selectedBike > m_game->m_bikeLevel )
		{
			// play ERROR sfx
			Assets::instance->wrongclick->play();
		}
		else
		{
			Assets::instance->click->play();

			// go to track selection
			m_game->setScreen(m_game->m_selectTrackScreen);
			m_game->m_gameplayScreen->setBike(m_selectedBike);
		}
	}

	if( int(floor(seconds)) % 2 == 1 )
	{
		seconds += delta * 2;
	}
	else
	{
		seconds += delta;
	}
	if( seconds >= 4 ) seconds = 0;
}

void SelectBikeScreen::render()
{
	m_cam.bind();
	al_clear_to_color( al_map_rgb( 0, 0, 0 ) );
	const int px = 46;
	const int py = 18;

	if( m_selectedBike > m_game->m_bikeLevel )
	{
		switch( int(floor(seconds)) )
		{
		case 0: al_draw_text( m_game->m_font, al_map_rgb(255, 255, 255), 18, 4, 0, "select bike" ); break;
		case 1: case 3: break;
		case 2:
			char buffer[32];
			snprintf(buffer, 32, "earn %d points", BikeParamsHolder::s_bikes[m_selectedBike].realPtsToUnlock);
			al_draw_text( m_game->m_font, al_map_rgb(255, 255, 255), 62, 4, ALLEGRO_ALIGN_CENTRE, buffer);
			break;
		}
	}
	else
	{
		al_draw_text( m_game->m_font, al_map_rgb(255, 255, 255), 18, 4, 0, "select bike" );
	}

	if( m_selectedBike < 2 )al_draw_bitmap( Assets::instance->cursord, px + 30, py + 8, 0 );
	if( m_selectedBike > 0 ) al_draw_bitmap( Assets::instance->cursori, px - 5, py + 8, 0 );

	al_draw_bitmap( Assets::instance->slot, px, py, 0 );
	al_draw_bitmap( Assets::instance->chechu_all_sheet->getFrame(6), px-1, py, 0 );

	const int ox = 7;
	const int oy = 0;

	al_draw_text( m_game->m_font, al_map_rgb(255, 255, 255), ox + 10, oy + 45, 0, "speed" );
	for( int i = 0; i < BikeParamsHolder::s_bikes[m_selectedBike].indicatorMaxSpeed; i++ )
	{
		al_draw_bitmap( Assets::instance->iconito, ox + 60 + 8 * i, oy + 47, 0 );
	}

	al_draw_text( m_game->m_font, al_map_rgb(255, 255, 255), ox + 10, oy + 55, 0, "accel" );
	for( int i = 0; i < BikeParamsHolder::s_bikes[m_selectedBike].indicatorAccel; i++ )
	{
		al_draw_bitmap( Assets::instance->iconito, ox + 60 + 8 * i, oy + 57, 0 );
	}

	al_draw_text( m_game->m_font, al_map_rgb(255, 255, 255), ox + 10, oy + 65, 0, "slide" );
	for( int i = 0; i < BikeParamsHolder::s_bikes[m_selectedBike].indicatorSlide; i++ )
	{
		al_draw_bitmap( Assets::instance->iconito, ox + 60 + 8 * i, oy + 67, 0 );
	}

	if( m_selectedBike > m_game->m_bikeLevel )
	{
		al_draw_bitmap(Assets::instance->notavailable, px, py, 0);
	}

}
