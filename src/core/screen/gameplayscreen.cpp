#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <alligator/input/input.h>
#include <alligator/util/matrix.h>
#include <iostream>

#include "gameplayscreen.h"
#include "../chechugame.h"
#include "../assets.h"
#include "../gameconstants.h"

GameplayScreen::GameplayScreen( ChechuGame* g )
	: m_game(g)
{
	m_cam.scale( GameConstants::ScaleFactor, GameConstants::ScaleFactor );
}

GameplayScreen::~GameplayScreen()
{

}

void GameplayScreen::show()
{

}

void GameplayScreen::update(double delta)
{
	//m_player->update(delta);
	if( Input::IsKeyDown(ALLEGRO_KEY_ESCAPE) )
	{
		m_game->close();
	}

	m_playerAnimData.update(delta * m_playerSpeed);
	m_humoAnimData.update(delta);

	if( m_gameState == GameState::Stopped || m_gameState == GameState::Running )
	{
		doZXStep();
		if( Input::IsKeyJustPressed(ALLEGRO_KEY_SPACE) )
		{
			m_gameState = GameState::Dashing;
		}
	}

	if( Input::IsKeyJustPressed(ALLEGRO_KEY_Q) ) Assets::instance->set_bike_color(0);
	if( Input::IsKeyJustPressed(ALLEGRO_KEY_W) ) Assets::instance->set_bike_color(1);
	if( Input::IsKeyJustPressed(ALLEGRO_KEY_E) ) Assets::instance->set_bike_color(2);


	switch( m_gameState )
	{
	case GameState::Stopped: break;
	case GameState::Running:
		Assets::instance->chechu_running_anim->updateData( m_playerAnimData );
		Assets::instance->humo_running_anim->updateData( m_humoAnimData );
		break;
	case GameState::Dashing:
		Assets::instance->chechu_dashing_anim->updateData( m_playerAnimData );
		Assets::instance->humo_dashing_anim->updateData( m_humoAnimData );
		m_playerSpeed -= 0.01;
		if( m_playerSpeed <= 0 )
		{
			m_playerSpeed = 0;
		}
		break;
	case GameState::Crushed: break;
	case GameState::Success: break;
	}

}

void GameplayScreen::render()
{
	al_clear_to_color( al_map_rgb( 95, 205, 228 ) );
	m_cam.bind();

	printf("%f\n", m_playerSpeed);fflush(0);
	const float portion = 5;
	const float portion_height = GameConstants::WindowHeight / portion;
	const ALLEGRO_COLOR bands_color = al_map_rgb(0, 0, 0);
	al_draw_filled_rectangle(0, 0, GameConstants::WindowWidth, portion_height, bands_color);
	al_draw_filled_rectangle(0, portion_height * (portion-1), GameConstants::WindowWidth, portion_height * portion, bands_color);

	switch( m_gameState )
	{
	case GameState::Stopped:
		al_draw_bitmap( Assets::instance->chechu_all_sheet->getFrame(6), m_playerPos.x(), m_playerPos.y(), 0 );
		break;
	case GameState::Running:
		m_playerAnimData.render(10, 30);
		if( m_playerSpeed > 0.5f ) {
			m_humoAnimData.render(10, 30);
		}
		break;
	case GameState::Dashing:
		m_playerAnimData.render(10, 30);
		if( m_playerSpeed > 0.2f ) {
			m_humoAnimData.render(10, 30);
		}
		break;
	case GameState::Crushed: break;
	case GameState::Success: break;
	}
	al_draw_text(m_game->m_font, al_map_rgb(255, 255, 255), 4, 3, 0, "speed");
	for( int i = 0; i < 11; i++ )
	{
		ALLEGRO_BITMAP* bm;
		if( i < 5 ) bm = Assets::instance->speed;
		else if( i < 9 ) bm = Assets::instance->speednaranja;
		else bm = Assets::instance->speedrojo;

		al_draw_bitmap( bm, 50 + 6 * i, 5, 0);
	}

	al_draw_text(m_game->m_font, al_map_rgb(255, 255, 255), 4, 67, 0, "dist.");
	al_draw_line( 46, 72, 114, 72, al_map_rgb(255, 255, 255), 1);

	al_draw_bitmap( Assets::instance->bolita, 70, 69, 0);
}

void GameplayScreen::hide()
{

}

void GameplayScreen::doZXStep()
{
	if( ( m_zxCounter && Input::IsKeyJustPressed(ALLEGRO_KEY_Z)) || (!m_zxCounter && Input::IsKeyJustPressed(ALLEGRO_KEY_X)) )
	{
		m_playerSpeed += 0.01;
		m_zxCounter = !m_zxCounter;
		m_gameState = GameState::Running;
	}
	else
	{
		m_playerSpeed -= 0.001;
		if( m_playerSpeed < 0 )
		{
			m_playerSpeed = 0;
			m_gameState = GameState::Stopped;
		}
	}
}


void GameplayScreen::setTrack(int track)
{
	m_selectedTrack = track;
}

void GameplayScreen::setBike(int bike)
{
	m_selectedBike = bike;
}
