#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#ifndef __HEROR__
#define __HEROR__


struct hero{
	int live;
	int x,y;
	short sx, sy;   
  	short w, h; 
};
struct obs{
	int using;
	int x,y;
	short sx, sy;  
  	short w, h; 
  	short rw,rh; //Valores após resize
};
typedef struct obs obs;
typedef struct hero hero;
typedef enum {LEFT = 1, UP, RIGHT, DOWN} direction ;

  
void create_objects();
void make_background();
void make_hero();
void draw_hero();
void hit();

void move_side(ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_EVENT *event, int *state);
int search_hit(direction d);
void wait_for_keypress(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state, ALLEGRO_EVENT *event);

void state_init(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state);
void state_serve(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state,  ALLEGRO_EVENT *event);
void state_play(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state,  ALLEGRO_EVENT *event);
void state_over();
void state_close(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state);
#endif