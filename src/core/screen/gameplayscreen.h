#pragma once

#include <alligator/game/iscreen.h>
#include <alligator/input/input.h>
#include <alligator/util/matrix.h>
#include <alligator/camera/camera.h>
#include <alligator/graphics/animation.h>

#include "../gameparams.h"

class ChechuGame;

enum class GameState {
	Stopped,
	// not moving and still have not done the dash

	Running,
	// moving

	Dashing,
	// dashing

	Success,
	// dashed and stopped before eating the railing

	Crushed
	// dashed and dove the railing

};

class GameplayScreen : public IScreen {
public:
	GameplayScreen(ChechuGame* g);
	virtual ~GameplayScreen();

	void show() override;
	void update(double delta) override;
	void render() override;
	void hide() override;

	void setTrack( int track );

	void setBike( int bike );

private:

	void doZXStep();
	const BikeParams& currentBikeParams()
	{
		return BikeParamsHolder::s_bikes[m_selectedBike];
	}

	const TrackParams& currentTrackParams()
	{
		return TrackParamsHolder::s_tracks[m_selectedTrack];
	}

	ChechuGame* m_game;
	Camera m_cam;

	Vec2i m_playerPos = Vec2i( 10, 30 );
	double m_playerSpeed;
	AnimationData m_playerAnimData;
	AnimationData m_humoAnimData;
	GameState m_gameState = GameState::Stopped;

	int m_selectedTrack = 0 ;
	int m_selectedBike  = 0 ;

	bool m_zxCounter = false;

	float m_currentPos = 0;
	float m_trackLength;

};
