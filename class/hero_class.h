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
void make_hero();
void move_side(ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_EVENT *event);
void wait_for_keypress(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state, ALLEGRO_EVENT *event);
void state_init(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state);
void state_serve(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state,  ALLEGRO_EVENT *event);
void state_play(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state,  ALLEGRO_EVENT *event);
void state_over();
void state_close();
#endif