#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#ifndef __HEROR__
#define __HEROR__


struct hero{
	int live;
	int x,y;
	short dx, dy;   
  	short w, h;
  	short rw,rh;  
};
struct obs{
	int using;
	int x,y;
	short dx, dy;  
  	short w, h; 
  	short inside;
  	short rw,rh; //Valores após resize
};
typedef struct obs obs;
typedef struct hero hero;
typedef enum {INICIO = 1, SERVINDO, JOGANDO, FIMPART, FIMJOGO} state ;
state estado;
typedef enum {NONE = 0, ESQUERDA, CIMA, DIREITA, BAIXO} direcao;
direcao dir;

  
void create_objects();
void make_background();
void make_hero();
void draw_hero();
void write_obstacles();
void hit();
void delta_transform();
void move_side();
void gravity_check();
void CameraUpdate();


void state_init(ALLEGRO_FONT* font);
void state_serve(ALLEGRO_EVENT *evento);
void state_play();
void state_over();
void state_close();
#endif