#include "selecttrackscreen.h"
#include "../chechugame.h"
#include "../assets.h"
#include "../gameconstants.h"
#include "../trackparams.h"

SelectTrackScreen::SelectTrackScreen( ChechuGame* game )
	: m_game(game)
{
	m_cam.scale( GameConstants::ScaleFactor, GameConstants::ScaleFactor );
}

SelectTrackScreen::~SelectTrackScreen()
{

}

void SelectTrackScreen::show()
{

}

void SelectTrackScreen::hide()
{

}

void SelectTrackScreen::update(double delta)
{
	if( Input::IsKeyDown(ALLEGRO_KEY_ESCAPE) )
	{
		m_game->close();
	}

	if( Input::IsKeyJustPressed(ALLEGRO_KEY_LEFT) )
	{
		m_selectedTrack--;
		if( m_selectedTrack < 0 ) m_selectedTrack = 0;
	}
	if( Input::IsKeyJustPressed(ALLEGRO_KEY_RIGHT) )
	{
		m_selectedTrack++;
		if( m_selectedTrack > 2 ) m_selectedTrack = 2;
	}

	if( Input::IsKeyJustPressed(ALLEGRO_KEY_ENTER) || Input::IsKeyJustPressed(ALLEGRO_KEY_SPACE) )
	{
		if( m_selectedTrack > m_game->m_trackLevel )
		{
			// play ERROR sfx
		}
		else
		{
			// go to track selection
			m_game->setScreen(m_game->m_gameplayScreen);
		}
	}

	seconds += delta;
	if( seconds >= 4 ) seconds = 0;
}

void SelectTrackScreen::render()
{
	m_cam.bind();
	al_clear_to_color( al_map_rgb( 0, 0, 0 ) );
	const int px = 46;
	const int py = 18;

	if( m_selectedTrack > m_game->m_trackLevel )
	{
		switch( int(floor(seconds)) )
		{
		case 0: al_draw_text( m_game->m_font, al_map_rgb(255, 255, 255), 18, 4, 0, "select bike" ); break;
		case 1: case 3: break;
		case 2:
			char buffer[32];
			snprintf(buffer, 32, "earn %d points", TrackParamsHolder::s_tracks[m_selectedTrack].m_ptsToUnlock);
			al_draw_text( m_game->m_font, al_map_rgb(255, 255, 255), 62, 4, ALLEGRO_ALIGN_CENTRE, buffer);
			break;
		}
	}
	else
	{
		al_draw_text( m_game->m_font, al_map_rgb(255, 255, 255), 18, 4, 0, "select track" );
	}

	if( m_selectedTrack < 2 )al_draw_bitmap( Assets::instance->cursord, px + 30, py + 8, 0 );
	if( m_selectedTrack > 0 ) al_draw_bitmap( Assets::instance->cursori, px - 5, py + 8, 0 );

	al_draw_bitmap( Assets::instance->slot, px, py, 0 );
	// draw selected track

	const int ox = 7;
	const int oy = 0;

	al_draw_text( m_game->m_font, al_map_rgb(255, 255, 255), ox + 10, oy + 45, 0, "dist." );
	for( int i = 0; i < TrackParamsHolder::s_tracks[m_selectedTrack].m_maxSpeed; i++ )
	{
		al_draw_bitmap( Assets::instance->iconito, ox + 60 + 8 * i, oy + 47, 0 );
	}

	al_draw_text( m_game->m_font, al_map_rgb(255, 255, 255), ox + 10, oy + 55, 0, "manu." );
	for( int i = 0; i < TrackParamsHolder::s_tracks[m_selectedTrack].m_dist; i++ )
	{
		al_draw_bitmap( Assets::instance->iconito, ox + 60 + 8 * i, oy + 57, 0 );
	}

	if( m_selectedTrack > m_game->m_bikeLevel )
	{
		al_draw_bitmap(Assets::instance->notavailable, px, py, 0);
	}

}
