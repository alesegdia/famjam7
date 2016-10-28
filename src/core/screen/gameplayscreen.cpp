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

	if( m_gameState == GameState::Stopped || m_gameState == GameState::Running )
	{
		doZXStep();
		if( Input::IsKeyJustPressed(ALLEGRO_KEY_SPACE) )
		{
			m_gameState = GameState::Dashing;
		}
	}

	switch( m_gameState )
	{
	case GameState::Stopped: break;
	case GameState::Running:
		Assets::instance->chechu_running_anim->updateData( m_playerAnimData );
		break;
	case GameState::Dashing:
		Assets::instance->chechu_dashing_anim->updateData( m_playerAnimData );
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

	const float portion = 5;
	const float portion_height = GameConstants::WindowHeight / portion;
	const ALLEGRO_COLOR bands_color = al_map_rgb(0, 0, 0);
	al_draw_filled_rectangle(0, 0, GameConstants::WindowWidth, portion_height, bands_color);
	al_draw_filled_rectangle(0, portion_height * (portion-1), GameConstants::WindowWidth, portion_height * portion, bands_color);

	switch( m_gameState )
	{
	case GameState::Stopped:
		al_draw_bitmap( Assets::instance->chechu_running_sheet->getFrame(0), m_playerPos.x(), m_playerPos.y(), 0 );
		break;
	case GameState::Running:
	case GameState::Dashing:
		m_playerAnimData.render(10, 30);
		break;
	case GameState::Crushed: break;
	case GameState::Success: break;
	}

}

void GameplayScreen::hide()
{

}

void GameplayScreen::doZXStep()
{
	if( ( m_zxCounter && Input::IsKeyJustPressed(ALLEGRO_KEY_Z)) || (!m_zxCounter && Input::IsKeyJustPressed(ALLEGRO_KEY_X)) )
	{
		printf("zxstep\n");

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

