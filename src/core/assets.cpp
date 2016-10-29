#include "assets.h"
#include <iostream>

Assets* Assets::instance = nullptr;

Assets::Assets()
{
	humo_bitmap = al_load_bitmap("assets/humo-sheet.png");
	chechu_all_bitmap = al_load_bitmap("assets/chechu-all-sheet.png");
	bolita = al_load_bitmap("assets/boladist.png");
	speed = al_load_bitmap("assets/speed.png");
	speedrojo = al_load_bitmap("assets/speedrojo.png");
	speednaranja = al_load_bitmap("assets/speednaran.png");
	chechuface = al_load_bitmap("assets/caraparte.png");

	chechu_all_sheet.reset(new Spritesheet( 6, 2, chechu_all_bitmap ));
	humo_sheet.reset(new Spritesheet( 6, 2, humo_bitmap ));

	chechu_running_anim.reset(new Animation( 0.1f, 6, chechu_all_sheet->getFrames(6, 11) ));
	chechu_dashing_anim.reset(new Animation( 0.1f, 6, chechu_all_sheet->getFrames(0, 5) ));
	humo_running_anim.reset(new Animation( 0.1f, 6, humo_sheet->getFrames(6, 11) ));
	humo_dashing_anim.reset(new Animation( 0.1f, 6, humo_sheet->getFrames(0, 5) ));

	m_currentBikeColor = al_map_rgb(48, 96, 130);
}

Assets::~Assets()
{
	al_destroy_bitmap(chechu_all_bitmap);
}

void Assets::set_bike_color(int bike_type)
{
	ALLEGRO_COLOR new_bike_color;
	switch( bike_type )
	{
	case 0: new_bike_color = al_map_rgb(48, 96, 130); break;
	case 1: new_bike_color = al_map_rgb(200, 200, 48); break;
	case 2: new_bike_color = al_map_rgb(130, 48, 96); break;
	default: assert(0);
	}

	int x, y;
	x = al_get_bitmap_width(chechu_all_bitmap);
	y = al_get_bitmap_height(chechu_all_bitmap);

	al_set_target_bitmap(chechu_all_bitmap);

	for( int i = 0; i < x; i++ )
	{
		for( int j = 0; j < y; j++ )
		{
			ALLEGRO_COLOR c;
			c = al_get_pixel( chechu_all_bitmap, i, j );
			if( memcmp(&c, &m_currentBikeColor, sizeof(ALLEGRO_COLOR)) == 0 )
			{
				al_put_pixel( i, j, new_bike_color );
			}
		}
	}
	m_currentBikeColor = new_bike_color;
	al_set_target_bitmap(nullptr);
}

void Assets::Initialize()
{
	Assets::instance = new Assets();
}

void Assets::Dispose()
{
	delete instance;
}
