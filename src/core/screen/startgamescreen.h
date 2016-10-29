#ifndef STARTGAMESCREEN_H
#define STARTGAMESCREEN_H

#include <alligator/game/iscreen.h>
#include <alligator/camera/camera.h>

class ChechuGame;

class StartGameScreen : public IScreen
{
public:
	StartGameScreen( ChechuGame* game );
	virtual ~StartGameScreen();

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

#endif // STARTGAMESCREEN_H
