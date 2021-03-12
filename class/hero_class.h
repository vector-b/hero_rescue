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
	short stage;  
  	short w, h; 
  	short vai;
  	short inside;
  	char name_file[100];
  	short rw,rh; //Valores após resize
};
struct monster
{
	int type;
	int using;
	int live;
	int x,y;
	int vai;
	int sobe;
	short stage;
	int x_ini,x_dest;
	int y_ini,y_dest;
	short dx, dy;  
  	short w, h; 
  	short rw,rh;
  	int checa_sprite;
  	int num_sprite;

};

typedef struct monster monster;
typedef struct obs obs;
typedef struct hero hero;
typedef enum {INICIO = 1, SERVINDO, JOGANDO, FIMPART, FIMJOGO} state ;
state estado;
typedef enum {NONE = 0, ESQUERDA, CIMA, DIREITA, BAIXO} direcao;
double fps;
direcao dir;
int fim;

  
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
void cria_monstros_estruturas();
void UpdateFloor();
void stages_();
void desalocador();
int checa_hero();


void state_init(ALLEGRO_FONT* font);
void state_serve(ALLEGRO_EVENT *evento);
void state_play(ALLEGRO_FONT* font);
void state_over();
void state_close();
#endif