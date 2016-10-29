#pragma once

#include <alligator/game/iscreen.h>
#include <alligator/camera/camera.h>

class ChechuGame;

class SelectTrackScreen : public IScreen
{
public:
	SelectTrackScreen( ChechuGame* game );
	virtual ~SelectTrackScreen();

	void show();

	void hide();

	void update(double delta);

	void render();

private:
	ChechuGame* m_game;
	Camera m_cam;
	int m_selectedTrack = 0;
	double seconds = 0;
};

