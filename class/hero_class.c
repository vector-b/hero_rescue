#include <stdio.h>
#include "hero_class.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#define NUM_OBS 3
#define NUM_MON 3 
//Imagens de Fundo
#define BACKGROUND_FILE "img/bg002.bmp"
#define BRIDGE 			"img/bridge.bmp"
#define BRIDGE_STAGE	"img/bridge_stage.png"
#define END_GAME_IMAGE 	"img/end_game.png"
#define GAME_MENU 		"img/hero_adventure.png"

#define HERO_FILE 		"img/hero.png"
#define RUN_RIGHT 		"img/run_right.png"
#define RUN_LEFT 		"img/run_left.png"
#define H_LEFT 			"img/hero_left.png"
#define BRICK_FILE 		"img/moss_tile.png"
#define MOB_IMAGE		"img/mob/"
#define MOB_IMAGE_RIGHT	"img/mob_right/"
#define MOB_SPACE		"img/space_ship/space_ship_rsz.png"


#define JUMP_LEFT		"img/hero_left/jump/"
#define JUMP			"img/hero/jump/"
#define FALL_LEFT		"img/hero_left/fall/"
#define FALL			"img/hero/fall/"

#define HERO_IMAGE		"img/hero/"
#define HERO_IMAGE_LEFT	"img/hero_left/"

#define GROUND 435
#define CONSTANTE_X 10
#define CONSTANTE_Y 160
#define CONSTANTE_G 10
#define MAX_WIDTH 1600;

int PONTUACAO = 0;
int cont_saltos = 0; 
int jumping = 0;
ALLEGRO_BITMAP *background 		= NULL;
ALLEGRO_BITMAP *menu 			= NULL;

ALLEGRO_BITMAP *end_game 		= NULL;
ALLEGRO_BITMAP *heroi 			= NULL;
ALLEGRO_BITMAP *heroi_right 	= NULL;
ALLEGRO_BITMAP *heroi_left 		= NULL;
ALLEGRO_BITMAP *heroi_run_right = NULL;
ALLEGRO_BITMAP *heroi_run_left 	= NULL;
ALLEGRO_BITMAP *brick 			= NULL;
ALLEGRO_BITMAP *mob 			= NULL;
ALLEGRO_BITMAP *mob_2			= NULL;
ALLEGRO_BITMAP *stand 			= NULL;

ALLEGRO_SAMPLE *som_pulo 		= NULL;
ALLEGRO_SAMPLE *kill_sound		= NULL;

int checa_sprite = 0;
int num_sprite = 0;

int checa_sprite_hero =0;
int num_sprite_hero = 1;
int old_dx;
int old_dy;
int last_right = 1;
int stage = 0;
hero *hero_     	= NULL;
obs **obstacles 	= NULL;
monster **monsters 	= NULL;
int FLOOR;
void create_objects()
{
	obstacles = malloc(NUM_OBS* sizeof(obstacles));
	for (int i = 0; i < NUM_OBS; i++)
		obstacles[i] = malloc(15*sizeof(obstacles));
	monsters = malloc(NUM_MON*sizeof(monsters));
	for (int i = 0; i < NUM_MON; i++)
		monsters[i] = malloc(15*sizeof(monsters[i]));

	obstacles[0] -> using = 1;
	obstacles[0] -> w = 522;
	obstacles[0] -> h = 522;
	obstacles[0] -> x = 200;
	obstacles[0] -> rw = 50;
	obstacles[0] -> rh = 50;
	obstacles[0] -> stage = 0;
	obstacles[0] -> y =	200 - obstacles[0] -> rh;
	obstacles[0] -> dx,obstacles[0] -> dy = 0;

	obstacles[1] -> using = 1;
	obstacles[1] -> w = 522;
	obstacles[1] -> h = 522;
	obstacles[1] -> x = 600;
	obstacles[1] -> rw = 50;
	obstacles[1] -> rh = 50;
	obstacles[1] -> stage = 0;
	obstacles[1] -> y = GROUND - obstacles[1] -> rh;
	obstacles[1] -> dx,obstacles[1] -> dy = 0;
}
void cria_monstros_estruturas()
{
	monsters[0] -> using = 1;
	monsters[0] -> type = 1;
	monsters[0] -> live = 1;
	monsters[0] -> w = 315;
	monsters[0] -> h = 329;
	monsters[0] -> x = 600;
	monsters[0] -> rw = 50;
	monsters[0] -> rh = 50;
	monsters[0] -> y = GROUND - monsters[0] -> rh;
	monsters[0] -> dx,monsters[0] -> dy = 0;
	monsters[0] -> vai = 0;
	monsters[0] -> x_ini = 300;
	monsters[0] -> x_dest = 600;
	monsters[0] -> y_ini = 0;
	monsters[0] -> y_dest = 0;
	monsters[0] -> stage = 1;

	monsters[1] -> using = 1;
	monsters[1] -> type = 2;
	monsters[1] -> live = 1;
	monsters[1] -> w = 60;
	monsters[1] -> h = 41;
	monsters[1] -> x = 200;
	monsters[1] -> rw = 60;
	monsters[1] -> rh = 41;
	monsters[1] -> y = 200;
	monsters[1] -> dx,monsters[1] -> dy = 0;
	monsters[1] -> vai = 0;
	monsters[1] -> sobe = 0;
	monsters[1] -> x_ini = 0;
	monsters[1] -> x_dest = 800 - monsters[1] -> w;
	monsters[1] -> y_ini = 0;
	monsters[1] -> y_dest = 400;
	monsters[1] -> stage = 1;
/*
	monsters[2] -> using = 1;
	monsters[2] -> type = 1;
	monsters[2] -> live = 1;
	monsters[2] -> w = 315;
	monsters[2] -> h = 329;
	monsters[2] -> x = 600;
	monsters[2] -> rw = 50;
	monsters[2] -> rh = 50;
	monsters[2] -> y = GROUND - monsters[0] -> rh;
	monsters[2] -> dx,monsters[0] -> dy = 0;
	monsters[2] -> vai = 0;
	monsters[2] -> x_ini = 300;
	monsters[2] -> x_dest = 600;
	monsters[2] -> y_ini = 0;
	monsters[2] -> y_dest = 0;
	monsters[2] -> stage = 2;*/


}
void inicia_mobs()
{
	for (int i = 0; i < NUM_MON; i++)
	{
		//Muda a direção do deslocamento horizontal
		if (monsters[i] -> x > monsters[i] -> x_dest)
			monsters[i] -> vai = 0;
		else if (monsters[i] -> x < monsters[i] -> x_ini)
			monsters[i] -> vai = 1;

		//Anda pra direita ou esquerda
		if(monsters[i] -> vai)
			monsters[i] -> x++;
		else
			monsters[i] -> x--;

		if (monsters[i] -> y_ini != 0 || monsters[i] -> y_dest != 0)
		{
			//Muda a direção do deslocamento vertical
			if (monsters[i] -> y > monsters[i] -> y_dest)
				monsters[i] -> sobe = 0;
			else if (monsters[i] -> y < monsters[i] -> y_ini)
				monsters[i] -> sobe = 1;

			//Anda pra cima ou baixo 
			if(monsters[i] -> sobe)
				monsters[i] -> y++;
			else
				monsters[i] -> y--;
		}
		
		if (monsters[i] -> type == 1)
		{
			checa_sprite++;

			if((checa_sprite % 2) == 0 )
				num_sprite++;

			char filename[100] = "";
			snprintf(filename, 12, "%d.png", num_sprite);
		

			char path[100] = "";
			if (monsters[i] -> vai)
				strcat(path, MOB_IMAGE_RIGHT);
			else
				strcat(path, MOB_IMAGE);
			strcat(path, filename);
			mob = al_load_bitmap(path);
			if (num_sprite == 42)
				num_sprite = 0;
			if (checa_sprite == 999)
				checa_sprite = 0;
		}
		else if (monsters[i] -> type == 2)
		{
			mob_2 = al_load_bitmap(MOB_SPACE);

		}
	}
}
void make_hero()
{
	hero_ = malloc(sizeof(hero));
	hero_ -> live = 1;
	hero_ -> dx = 0;
	hero_ -> dy = 0;   
  	hero_ -> w = 20;
  	hero_ -> h = 29;
  	hero_ -> rw = 45;
  	hero_ -> rh = 65;
  	hero_ -> x = 10;
	hero_ -> y = GROUND - hero_ -> rh ;  

	brick = al_load_bitmap(BRICK_FILE);
	if (!brick)
	{
		fprintf(stderr, "Não leu o brick file" );
		exit(1);
	}
}
void make_menu()
{
	//Inicia o image_addon 
	if(!al_init_image_addon())
	{
	    printf("couldn't initialize image addon\n");
	}
	//Carrega o background na memória
	menu=al_load_bitmap(GAME_MENU);
	if(!menu)
    {
        fprintf(stderr, "failed to load menu bitmap!\n");
        exit(1);
    }
}
void make_background()
{
	//Inicia o image_addon 
	if(!al_init_image_addon())
	{
	    printf("couldn't initialize image addon\n");
	}
	//Carrega o background na memória
	background=al_load_bitmap(BACKGROUND_FILE);
	if(!background)
    {
        fprintf(stderr, "failed to load background bitmap!\n");
        exit(1);
    }
}
void state_serve(ALLEGRO_EVENT *evento)
{	
}
void draw_hero()
{
	if (jumping)
	{
		int chosen = 1;
		if (hero_ -> y  > FLOOR + (hero_ -> dy/4))
		{
			chosen = 1;
		}
		else if(hero_ -> y  > FLOOR + (hero_ -> dy/2))
		{
			chosen = 2;
		}
		else
		{
			chosen = 3;
		}
		char filename[100] = "";
		snprintf(filename, 12, "%d.png", chosen);

		char path[100] = "";
		if (last_right)
			strcat(path, JUMP);
		else
			strcat(path, JUMP_LEFT);

		strcat(path, filename);
		stand = al_load_bitmap(path);

		al_draw_scaled_bitmap(stand,0,0,hero_ -> w,hero_ -> h,hero_ -> x,hero_ -> y,hero_ -> rw,hero_ -> rh,0);

		al_destroy_bitmap(stand);
	}
	else if (hero_ -> dy < 0)
	{
		char filename[100] = "";
		snprintf(filename, 12, "%d.png", 0);

		char path[100] = "";
		if(last_right)
			strcat(path, FALL);
		else
			strcat(path, FALL_LEFT);

		strcat(path, filename);
		stand = al_load_bitmap(path);

		al_draw_scaled_bitmap(stand,0,0,hero_ -> w,hero_ -> h,hero_ -> x,hero_ -> y,hero_ -> rw,hero_ -> rh,0);

		al_destroy_bitmap(stand);
	}
	else if (hero_ -> dx == 0)
	{
		checa_sprite_hero++;
		if((checa_sprite_hero % 25) == 0 )
			num_sprite_hero++;

		char filename[100] = "";
		snprintf(filename, 12, "%d.png", num_sprite_hero);

		char path[100] = "";
		if(last_right)
			strcat(path, HERO_IMAGE);
		else
			strcat(path, HERO_IMAGE_LEFT);
		strcat(path, filename);
		stand = al_load_bitmap(path);

		
		if (num_sprite_hero >= 4)
			num_sprite_hero = 1;
		if (checa_sprite_hero == 500)
			checa_sprite_hero = 0;


		al_draw_scaled_bitmap(stand,0,0,hero_ -> w,hero_ -> h,hero_ -> x,hero_ -> y,hero_ -> rw,hero_ -> rh,0);

		al_destroy_bitmap(stand);
	}
	else if(hero_ -> dx > 0 ){
		heroi_run_right = al_load_bitmap(RUN_RIGHT);
		al_draw_scaled_bitmap(heroi_run_right,0,0,hero_ -> w,hero_ -> h,hero_ -> x,hero_ -> y,hero_ -> rw,hero_ -> rh,0);
		al_destroy_bitmap(heroi_run_right);
	}
	else {
		heroi_run_left	= al_load_bitmap(RUN_LEFT);
		al_draw_scaled_bitmap(heroi_run_left,0,0,hero_ -> w,hero_ -> h,hero_ -> x,hero_ -> y,hero_ -> rw,hero_ -> rh,0);
		al_destroy_bitmap(heroi_run_left);
	}
}
void hit()
{
	for (int i = 0; i < 2; i++)
	{
		if (stage == obstacles[i] -> stage)
		{
			if ((hero_ -> x + hero_ -> rw >= obstacles[i] -> x) && (hero_ -> x <= obstacles[i] -> x + obstacles[i] -> rw - 1))
			{
				//printf("%d\n",hero_ -> y );
				if (((hero_ -> y + hero_ -> rh) <= obstacles[i] -> y ))
				{
					//Em cima da caixa
					if ((hero_ -> y + hero_ -> rh <=  obstacles[i] -> y ) && (hero_ -> y + hero_ -> rh > obstacles[i] -> y - 5) ) 
					{
						FLOOR = obstacles[i] -> y;
						hero_ -> dy = 0;
						hero_ -> y = obstacles[i] -> y - hero_ -> rh;
					}
				}
				else if((hero_ -> y > obstacles[i] -> y + obstacles[i] -> rh))
				{
					//Em baixo da caixa 
				}
				else if (FLOOR != obstacles[i] -> y -2)
				{
					if (hero_ -> x + hero_ -> rw <=  (((obstacles[i] -> x + obstacles[i] -> x + (obstacles[i] -> rw))/2)))
						hero_ -> x = obstacles[i] -> x - hero_ -> rw;
					else
						hero_ -> x = obstacles[i] -> x + obstacles[i] -> rw;
				}
			}
		}
	}
	for (int i = 0; i < NUM_MON; i++)
	{
		if (monsters[i] -> live == 1 && stage == monsters[i]-> stage)
		{
			if ((hero_ -> x + hero_ -> rw >= monsters[i] -> x) && (hero_ -> x <= monsters[i] -> x + monsters[i] -> rw - 1))
			{
				//printf("%d %d \n", hero_ -> y + hero_ -> rh, monsters[i] -> y );
				if (((hero_ -> y + hero_ -> rh) <= monsters[i] -> y ))
				{
					//Em cima da caixa
					if ((hero_ -> y + hero_ -> rh <=  monsters[i] -> y ) && (hero_ -> y + hero_ -> rh > monsters[i] -> y - 5) ) 
					{
						monsters[i] -> live = 0;
						kill_sound = al_load_sample("song/kill.wav");
						if (!kill_sound) 
						{
							fprintf(stderr, "Could not load kill sound!\n");
							exit(1);
						}
						if (!al_play_sample(kill_sound, 1.0, 0.5, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL)) {
						              fprintf(stderr,
						                 "al_play_sample_data failed, perhaps too many sounds\n");
						           }
						PONTUACAO+=5;
					}
				}
				else if((hero_ -> y > monsters[i] -> y + monsters[i] -> rh))
				{
					//Em baixo da caixa 
				}
				else
				{
					hero_ -> live = 0;
				}
			}
		}
		
	}
}
void move_side()
{
	if (dir != NONE)
	{
		if(dir == ESQUERDA){
			hero_ -> dx -= CONSTANTE_X;
			last_right = 0;
		}
		else if(dir == CIMA){
			if (!jumping)
			{
				hero_ -> dy -= CONSTANTE_Y;
				som_pulo = al_load_sample("song/jump.wav");
				if (!som_pulo) 
				{
					fprintf(stderr, "Could not load jump sound!\n");
					exit(1);
				}
				if (!al_play_sample(som_pulo, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0)) {
				              fprintf(stderr,
				                 "al_play_sample_data failed, perhaps too many sounds\n");
				           }
			}
			
		}
		else if(dir == DIREITA){
			hero_ -> dx += CONSTANTE_X;
			last_right = 1;
		}
		else if(dir == BAIXO)
			hero_ -> dy += CONSTANTE_Y;
	}
	dir = NONE;
}
void delta_transform()
{
	//Deslocamento Horizontal
	if (hero_ -> dx != 0)
	{
		if (hero_ -> dx > 0)
		{
			hero_ -> x += hero_ -> dx * 2;
			hero_ -> dx -= CONSTANTE_X/6;  
		}
		else
		{
			hero_ -> x += hero_ -> dx * 2;
			hero_ -> dx += CONSTANTE_X/6; 
		}
	}
	//Deslocamento Vertical
	if (hero_ -> dy != 0)
	{
		if (hero_ -> dy < 0 && cont_saltos < 20)
		{
			jumping = 1;
			hero_ -> y += hero_ -> dy/20;
			cont_saltos++;
		}
		else
			jumping = 0;
	}
}
void gravity_check()
{
	// PENSAR NUMA SOLUÇÃO PARA GRAVIDADE
	int distancia_floor_hero = 0;
	distancia_floor_hero = FLOOR - hero_ -> rh;

	if ((hero_ -> y  + hero_ -> rh < FLOOR) && jumping == 0)
	{
		hero_ -> y += CONSTANTE_G;
		hero_ -> dy += CONSTANTE_G;
	}
	if (hero_ -> y == FLOOR - hero_ -> rh)
		cont_saltos = 0;
}
void write_obstacles()
{
	//Imprime os obstaculos existentes
	if (stage == 0)
		for (int i = 0; i < NUM_OBS; i++)
			al_draw_scaled_bitmap(brick,0,0,522,522,obstacles[i] -> x,obstacles[i] -> y,obstacles[i] -> rw,obstacles[i] -> rh,0);
	inicia_mobs();
	for (int i = 0; i < NUM_MON; i++)
	{
		if (stage == monsters[i] -> stage)
		{
			if (monsters[i] -> live == 1)
			{
				if (monsters[i] -> type == 1)
				{
					al_draw_scaled_bitmap(mob,0,0,monsters[i] -> w,monsters[i] -> h,monsters[i] -> x,monsters[i] -> y,monsters[i] -> rw,monsters[i] -> rh,0);
					al_destroy_bitmap(mob);
				}
				else if (monsters[i] -> type == 2)
				{
					al_draw_scaled_bitmap(mob_2,0,0,monsters[i] -> w,monsters[i] -> h,monsters[i] -> x,monsters[i] -> y,monsters[i] -> rw,monsters[i] -> rh,0);
					al_destroy_bitmap(mob_2);
				}
			}
		}
		
	}
		
}
void CameraUpdate()
{
	if (stage != 3)
	{
		background=al_load_bitmap(BACKGROUND_FILE);
		al_draw_scaled_bitmap(background,0,0,800,500,0,0,800,500,0);
		al_destroy_bitmap(background);
	}
	else{
		ALLEGRO_BITMAP *bridge_back = NULL;
		bridge_back = al_load_bitmap(BRIDGE_STAGE);
		al_draw_scaled_bitmap(bridge_back,0,0,800,500,0,0,800,500,0);
		al_destroy_bitmap(bridge_back);
	}
	
}
void UpdateFloor()
{
	int out = 1;
	if (hero_ -> y + hero_ -> rh == FLOOR)
		hero_ -> dy = 0 ;
	for (int i = 0; i < 2; i++)
	{
		if ((hero_ -> x + hero_ -> rw >= obstacles[i] -> x) && (hero_ -> x <= obstacles[i] -> x + obstacles[i] -> rw - 1))
		{
			out = 0;
		}		
	}
	if (out)
	{
		FLOOR = GROUND;
		
	}
}
void stages_()
{
	if (hero_ -> live == 0)
	{
		estado = FIMJOGO;
	}
	if (hero_ -> x > 800){
		stage++;
		hero_ -> x = 50;
		hero_ -> y = GROUND - hero_ -> rh;
		hero_ -> dy = 0;
		hero_ -> dx = 0;
	}
}
//Função dos states
void state_init(ALLEGRO_FONT* font)
{
	create_objects();
	make_background();
	al_destroy_bitmap(background);
	make_menu();
	al_draw_scaled_bitmap(menu,0,0,800,500,0,0,800,500,0);
	al_destroy_bitmap(menu);
	make_hero(hero_);
	//cria_monstros_estruturas();
	al_flip_display();
	FLOOR = GROUND;
	estado = SERVINDO;
}

//Função principal de gameplay
void state_play(ALLEGRO_FONT* font)
{
	
	//Limpa a tela
	al_clear_to_color(al_map_rgb(0, 0, 0));
	stages_();
	//Imprime score
	char score[25] = "";
	snprintf(score, 25, "%d", PONTUACAO);
	char text[10] = "SCORE: ";
	strcat(text,score);
	//printf("%s\n",text);
	//Imprime o background
	CameraUpdate();
	//Atualiza floor
	UpdateFloor();
    //Imprime obstaculos
    //write_obstacles();
	//Checagem da gravidade
	gravity_check();
	//Altera o variação de velocidade do personagem
	move_side();
	//printf("%d e %d\n",hero_ -> y, hero_ ->dy );
	char posY[50];
	snprintf(posY,25,"Y: %d / DY: %d",hero_ -> y, hero_ -> dy);
	char posX[50];
	snprintf(posX,25,"X: %d / DX: %d",hero_ -> x, hero_ -> dx);
	char chao[50];
	snprintf(chao,25,"FLOOR: %d",FLOOR);
	char estagio[20];
	snprintf(estagio,20,"STAGE: %d",stage);
	char fps_demo[50];
	snprintf(fps_demo,25,"%f",fps);
	

	//Transforma o delta y/x em deslocamento
	delta_transform();
    //Desenha o personagem controlavel
	draw_hero();
	//Checa Hit
	//hit();
	al_draw_text(font, al_map_rgb(255, 104, 1), 700,10, 0,text);
	al_draw_text(font, al_map_rgb(255, 104, 1), 100,10, 0,posY);
	al_draw_text(font, al_map_rgb(255, 104, 1), 100,20, 0,posX);
	al_draw_text(font, al_map_rgb(255, 104, 1), 100,30, 0,chao);
	al_draw_text(font, al_map_rgb(255, 104, 1), 700,20, 0,estagio);
	//al_draw_text(font, al_map_rgb(255, 104, 1), 700,30, 0,fps_demo);
	if (stage == 3)
	{
		ALLEGRO_BITMAP *bridge_img = NULL;
		bridge_img = al_load_bitmap(BRIDGE);
		al_draw_scaled_bitmap(bridge_img,0,0,800,500,0,0,800,500,0);
		al_destroy_bitmap(bridge_img);
	}



	al_flip_display();
}	
void state_close()
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	end_game =al_load_bitmap(END_GAME_IMAGE);
	if(!end_game)
    {
        fprintf(stderr, "failed to load end_game bitmap!\n");
        exit(1);
    }
	al_draw_scaled_bitmap(end_game,0,0,800,500,0,0,800,500,0);
	al_destroy_bitmap(end_game);
	al_flip_display();
}