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

	ALLEGRO_BITMAP* humo_bitmap;
	ALLEGRO_BITMAP* chechu_all_bitmap;
	ALLEGRO_BITMAP* bolita;
	ALLEGRO_BITMAP* speed;
	ALLEGRO_BITMAP* speedrojo;
	ALLEGRO_BITMAP* speednaranja;
	ALLEGRO_BITMAP* chechuface;
	ALLEGRO_BITMAP* slot;
	ALLEGRO_BITMAP* cursord;
	ALLEGRO_BITMAP* cursori;
	ALLEGRO_BITMAP* iconito;
	ALLEGRO_BITMAP* notavailable;
	ALLEGRO_BITMAP* rainyterrain;
	ALLEGRO_BITMAP* grassterrain;
	ALLEGRO_BITMAP* roadterrain;

	ALLEGRO_COLOR m_currentBikeColor;
	void set_bike_color(int bike_type );

	Spritesheet::SharedPtr chechu_all_sheet;
	Spritesheet::SharedPtr humo_sheet;

	Animation::SharedPtr chechu_running_anim;
	Animation::SharedPtr chechu_dashing_anim;
	Animation::SharedPtr humo_running_anim;
	Animation::SharedPtr humo_dashing_anim;

};
