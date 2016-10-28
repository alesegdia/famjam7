#include "chechugame.h"
#include "assets.h"

ChechuGame::ChechuGame(int sw, int sh)
	: Game( sw, sh )
{

}

ChechuGame::~ChechuGame()
{

}

int ChechuGame::create(int argc, char **argv)
{
	Assets::Initialize();

	m_gameplayScreen.reset(new GameplayScreen(this));

	setScreen(m_gameplayScreen);

	return 0;
}

void ChechuGame::dispose()
{
	Assets::Dispose();
}
