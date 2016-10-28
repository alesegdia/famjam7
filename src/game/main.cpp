#include "../core/chechugame.h"
#include "../core/gameconstants.h"

int main(int argc, char** argv) {
	ChechuGame tsr( GameConstants::WindowWidth * GameConstants::ScaleFactor, GameConstants::WindowHeight * GameConstants::ScaleFactor );
	tsr.exec(argc, argv);
	return 0;
}
