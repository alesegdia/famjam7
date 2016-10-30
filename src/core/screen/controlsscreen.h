#pragma once

#include <alligator/game/iscreen.h>
#include <alligator/camera/camera.h>

class ChechuGame;

class ControlsScreen : public IScreen
{
public:
	ControlsScreen( ChechuGame* game );
	virtual ~ControlsScreen();

	void show();

	void hide();

	void update(double delta);

	void render();

private:
	ChechuGame* m_game;
	Camera m_cam;

};

