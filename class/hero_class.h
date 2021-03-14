#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_ttf.h"

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
	int life;
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
struct plataforma
{
	int x,y;
	short stage;
	short dx, dy;  
  	short w, h; 
  	short rw,rh;
};
struct user_score
{
	char nome[100];
	int score;
};
typedef struct monster monster;
typedef struct obs obs;
typedef struct hero hero;
typedef struct plataforma plat;
typedef struct user_score user_score;
typedef enum {INICIO = 1, SERVINDO, JOGANDO, FIMPART, FIMJOGO, HIGH_SCORES, HELP, VENCEU} state ;
state estado;
typedef enum {NONE = 0, ESQUERDA, CIMA, DIREITA, BAIXO} direcao;
double fps;
direcao dir;
int fim;
int god_mode;


void inicia_fontes();
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
int  checa_hero(int i);
void inicia_escadas();
void hero_updown();
int inside_stairs(int i);
void recebe_user(ALLEGRO_FONT* font, ALLEGRO_USTR *name);
void ler_file_scores();
void escreve_file_scores();
void venceu();



void state_init(ALLEGRO_FONT* font);
void state_serve(ALLEGRO_EVENT *evento);
void state_play(ALLEGRO_FONT* font);
void state_over();
void state_close();
void show_scores();
void help();
#endif