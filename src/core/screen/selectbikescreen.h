#pragma once

#include <alligator/game/iscreen.h>
#include <alligator/camera/camera.h>

class ChechuGame;

class SelectBikeScreen : public IScreen
{
public:
	SelectBikeScreen( ChechuGame* game );
	virtual ~SelectBikeScreen();

	void show();

	void hide();

	void update(double delta);

	void render();

private:
	ChechuGame* m_game;
	Camera m_cam;
	int m_selectedBike = 0;
	double seconds = 0;

};

