#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <alligator/game/iscreen.h>
#include <alligator/camera/camera.h>

class ChechuGame;

class MenuScreen : public IScreen
{
public:
	MenuScreen( ChechuGame* game);

	virtual ~MenuScreen();

	void show();
	void hide();
	void update(double delta);
	void render();

private:
	ChechuGame* m_game;
	Camera m_cam;
	bool m_transitioning = false;

	float m_x1, m_x2, m_x3, m_x4, m_x5;
	float m_t1, m_t2, m_t3, m_t4, m_t5;

	bool m_selecting = false;
	int m_selected = 0;

};

#endif // MENUSCREEN_H
