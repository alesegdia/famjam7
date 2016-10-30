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
	slot = al_load_bitmap("assets/slot.png");
	cursord = al_load_bitmap("assets/cursord.png");
	cursori = al_load_bitmap("assets/cursori.png");
	iconito = al_load_bitmap("assets/iconito.png");
	notavailable = al_load_bitmap("assets/notavailable.png");
	notamovil = al_load_bitmap("assets/notamovil.png");

	rainyterrain = al_load_bitmap("assets/rainyterrain.png");
	grassterrain = al_load_bitmap("assets/grassterrain.png");
	roadterrain = al_load_bitmap("assets/roadterrain.png");

	carabien = al_load_bitmap("assets/carabien.png");

	chechu_all_sheet.reset(new Spritesheet( 6, 2, chechu_all_bitmap ));
	humo_sheet.reset(new Spritesheet( 6, 2, humo_bitmap ));

	chechu_running_anim.reset(new Animation( 0.1f, 6, chechu_all_sheet->getFrames(6, 11) ));
	chechu_dashing_anim.reset(new Animation( 0.1f, 6, chechu_all_sheet->getFrames(0, 5) ));
	humo_running_anim.reset(new Animation( 0.1f, 6, humo_sheet->getFrames(6, 11) ));
	humo_dashing_anim.reset(new Animation( 0.1f, 6, humo_sheet->getFrames(0, 5) ));

	m_currentBikeColor = al_map_rgb(48, 96, 130);

	click.reset( new AudioSample("assets/mover_menu.ogg") );
	wrongclick.reset( new AudioSample("assets/error_bici.ogg") );

	intro.reset( new AudioStream("assets/intro.ogg", ALLEGRO_PLAYMODE_LOOP) );
	theme.reset( new AudioStream("assets/musica.ogg", ALLEGRO_PLAYMODE_LOOP) );

	intro->rewind();
	intro->pause();
	theme->rewind();
	theme->pause();

	tio.reset( new AudioSample( "assets/kasee.ogg" ) );
	mama.reset( new AudioSample( "assets/mama.ogg" ) );
	derrape.reset( new AudioSample( "assets/derrape.ogg" ) );
}

Assets::~Assets()
{
	al_destroy_bitmap(chechu_all_bitmap);
	al_destroy_bitmap(humo_bitmap);
	al_destroy_bitmap(bolita);
	al_destroy_bitmap(speed);
	al_destroy_bitmap(speedrojo);
	al_destroy_bitmap(speednaranja);
	al_destroy_bitmap(chechuface);
	al_destroy_bitmap(slot);
	al_destroy_bitmap(cursord);
	al_destroy_bitmap(cursori);
	al_destroy_bitmap(iconito);
	al_destroy_bitmap(notavailable);
	al_destroy_bitmap(notamovil);
	al_destroy_bitmap(rainyterrain);
	al_destroy_bitmap(grassterrain);
	al_destroy_bitmap(roadterrain);
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
