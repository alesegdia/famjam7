#pragma once

#include <memory>
#include <allegro5/allegro.h>

#include <alligator/graphics/spritesheet.h>
#include <alligator/graphics/animation.h>

class Assets
{
public:

	// singleton interface
	static Assets* instance;
	static void Initialize();
	static void Dispose();

	Assets();
	~Assets();

	ALLEGRO_BITMAP* chechu_running_bitmap;
	ALLEGRO_BITMAP* chechu_dashing_bitmap;

	Spritesheet::SharedPtr chechu_running_sheet;
	Spritesheet::SharedPtr chechu_dashing_sheet;

	Animation::SharedPtr chechu_running_anim;
	Animation::SharedPtr chechu_dashing_anim;

};
