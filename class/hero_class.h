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
	int live; //vivo ou morto
	int x,y; //Posição
	short dx, dy;  //Delta x e y 
  	short w, h;//Largura-ALtura
  	short rw,rh;  //Largura-ALtura redimensionados para o jogo
};
struct obs{
	int using;//Esta utilizando ou não
	int x,y;//Posição
	short dx, dy;//Delta x e y
	short stage;  //Estagio onde o objeto pertence  
  	short w, h; //Largura-ALtura
  	short vai;// Indo pra direita ou não
  	short inside;
  	char name_file[100]; //Nome do arquivo
  	short rw,rh; //Largura-ALtura redimensionados para o jogo
};
struct monster
{
	int type;
	int using;
	int live;	//Monstro vivo ou morto
	int life;	//Quantidade de vida
	int x,y;	//Posição
	int vai;	// Indo pra direita ou não
	int sobe;	// Subindo ou nãp
	short stage;	//Estagio onde o monstro pertence 
	int x_ini,x_dest;	//Destino da variação de x
	int y_ini,y_dest;	//Destino da variação de y
	short dx, dy;  	//Delta x e y
  	short w, h; 	//Largura-ALtura
  	short rw,rh;	//Largura-ALtura redimensionados para o jogo
  	int checa_sprite; //Contador de frequencia pra o num_sprite
  	int num_sprite;	//Contador de sprites
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
//Definição das estruturas utlizadas 
typedef struct monster monster;
typedef struct obs obs;
typedef struct hero hero;
typedef struct plataforma plat;
typedef struct user_score user_score;
typedef enum {INICIO = 1, SERVINDO, JOGANDO, FIMPART, FIMJOGO, HIGH_SCORES, HELP, VENCEU, REPAIR, INFO} state ;
state estado;
typedef enum {NONE = 0, ESQUERDA, CIMA, DIREITA, BAIXO} direcao;
double fps;
direcao dir;
int fim;
int god_mode;


void inicia_fontes();
void play_init();
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
int inside_stairs(int i);
void recebe_user(ALLEGRO_FONT* font, ALLEGRO_USTR *name);
void ler_file_scores();
void escreve_file_scores();
void venceu();
void info();




void state_init(ALLEGRO_FONT* font);
void state_serve(ALLEGRO_EVENT *evento);
void state_play(ALLEGRO_FONT* font);
void state_over();
void state_close();
void show_scores();
void help();
void repair();
#endif