#pragma once

#include <alligator/game/iscreen.h>
#include <alligator/input/input.h>
#include <alligator/util/matrix.h>
#include <alligator/camera/camera.h>
#include <alligator/graphics/animation.h>

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

private:

	void doZXStep();

	ChechuGame* m_game;
	Camera m_cam;

	Vec2i m_playerPos = Vec2i( 10, 30 );
	double m_playerSpeed;
	AnimationData m_playerAnimData;
	AnimationData m_humoAnimData;
	GameState m_gameState = GameState::Stopped;

	bool m_zxCounter = false;

};
