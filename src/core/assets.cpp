#include "assets.h"
#include <iostream>

Assets* Assets::instance = nullptr;

Assets::Assets()
{
	chechu_running_bitmap = al_load_bitmap("assets/chechu-running-sheet.png");
	chechu_dashing_bitmap = al_load_bitmap("assets/chechu-dashing-sheet.png");

	chechu_running_sheet.reset(new Spritesheet( 6, 1, chechu_running_bitmap ));
	chechu_dashing_sheet.reset(new Spritesheet( 6, 1, chechu_dashing_bitmap ));

	chechu_running_anim.reset(new Animation( 0.1f, 6, chechu_running_sheet->getAllFrames() ));
	chechu_dashing_anim.reset(new Animation( 0.1f, 6, chechu_dashing_sheet->getAllFrames() ));
}

Assets::~Assets()
{
	al_destroy_bitmap(chechu_running_bitmap);
	al_destroy_bitmap(chechu_dashing_bitmap);
}

void Assets::Initialize()
{
	Assets::instance = new Assets();
}

void Assets::Dispose()
{
	delete instance;
}
