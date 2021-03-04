#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#ifndef __HEROR__
#define __HEROR__


struct hero{
	int live;
	int x,y;
	short sx, sy ;   
  	short w, h ; 
};
struct floor{
	int x;
	int y;
	int size_x;
};
struct wall{
	int x;
	int y;
	int size_x;
};
struct gem{
	int x;
	int y;
	int size_x;
};

struct border{
	int x;
	int y;
};
typedef struct hero hero;
void make_background();
hero *make_hero(hero *sarah);
void wait_for_keypress(int *state);
void state_init(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state, hero *sarah);
void state_serve(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state, hero *sarah);
void state_play();
void state_over();
void state_close();
#endif