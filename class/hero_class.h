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
  	short rw,rh;  
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
typedef enum {INICIO = 1, SERVINDO, JOGANDO, FIMPART, FIMJOGO} state ;
state estado;

  
void create_objects();
void make_background();
void make_hero();
void draw_hero();
void write_obstacles();
void hit(int *out);

void move_side(ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_EVENT *event, int *state);
void wait_for_keypress(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state, ALLEGRO_EVENT *event);

void state_init(ALLEGRO_FONT* font);
void state_serve(ALLEGRO_EVENT *evento);
void state_play();
void state_over();
void state_close();
#endif