#include <stdio.h>
#include "hero_class.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

#define BACKGROUND_FILE "img/bg002.png"
#define HERO_FILE 		"img/hero.png"
#define RUN_RIGHT 		"img/run_right.png"
#define RUN_LEFT 		"img/run_left.png"
#define H_LEFT 			"img/hero_left.png"
#define BRICK_FILE 		"img/moss_tile.png"
#define MOB_IMAGE		"img/mob/"
#define GROUND 435
#define CONSTANTE_X 10
#define CONSTANTE_Y 40
#define MAX_WIDTH 1600;

ALLEGRO_BITMAP *background 		= NULL;
ALLEGRO_BITMAP *heroi 			= NULL;
ALLEGRO_BITMAP *heroi_right 	= NULL;
ALLEGRO_BITMAP *heroi_left 		= NULL;
ALLEGRO_BITMAP *heroi_run_right = NULL;
ALLEGRO_BITMAP *heroi_run_left 	= NULL;
ALLEGRO_BITMAP *brick 			= NULL;
ALLEGRO_BITMAP *mob 			= NULL;

int checa_sprite = 0;
int num_sprite = 0;
int old_dx;
int old_dy;
int last_right = 0;
int stage = 0;
hero *hero_     = NULL;
obs **obstacles = NULL;
int FLOOR;
void create_objects()
{
	obstacles = malloc(15* sizeof(obstacles));
	for (int i = 0; i < 15; i++)
	{
		obstacles[i] = malloc(10*sizeof(obstacles));
	}
	obstacles[0] -> using = 1;
	obstacles[0] -> w = 522;
	obstacles[0] -> h = 522;
	obstacles[0] -> x = 200;
	obstacles[0] -> rw = 50;
	obstacles[0] -> rh = 50;
	obstacles[0] -> y =	200 - obstacles[0] -> rh;
	obstacles[0] -> dx,obstacles[0] -> dy = 0;

	obstacles[1] -> using = 1;
	obstacles[1] -> w = 522;
	obstacles[1] -> h = 522;
	obstacles[1] -> x = 600;
	obstacles[1] -> rw = 50;
	obstacles[1] -> rh = 50;
	obstacles[1] -> y = GROUND - obstacles[1] -> rh;
	obstacles[1] -> dx,obstacles[1] -> dy = 0;

}
void inicia_mobs()
{
	checa_sprite++;
	obstacles[2] -> using = 1;
	obstacles[2] -> w = 315;
	obstacles[2] -> h = 329;
	obstacles[2] -> x = 600;
	obstacles[2] -> rw = 50;
	obstacles[2] -> rh = 50;
	obstacles[2] -> y = GROUND - obstacles[2] -> rh;
	obstacles[2] -> dx,obstacles[0] -> dy = 0;

	if((checa_sprite % 2) == 0 )
		num_sprite++;

	char filename[100] = "";
	snprintf(filename, 12, "%d.png", num_sprite);

	char path[100] = "";
	strcat(path, MOB_IMAGE);
	strcat(path, filename);
	mob = al_load_bitmap(path);
	if (num_sprite == 42)
		num_sprite = 0;
	if (checa_sprite == 999)
		checa_sprite = 0;


}
void make_hero()
{
	hero_ = malloc(sizeof(hero));
	hero_ -> dx = 0;
	hero_ -> dy = 0;   
  	hero_ -> w = 20;
  	hero_ -> h = 29;
  	hero_ -> rw = 45;
  	hero_ -> rh = 65;
  	hero_ -> x = 700;
	hero_ -> y = GROUND - hero_ -> rh ;  
	heroi_right 	= al_load_bitmap(HERO_FILE);
	heroi_run_right = al_load_bitmap(RUN_RIGHT);
	heroi_run_left	= al_load_bitmap(RUN_LEFT);
	heroi_left 		= al_load_bitmap(H_LEFT);
	brick = al_load_bitmap(BRICK_FILE);
	if (!brick)
	{
		fprintf(stderr, "Não leu o brick file" );
		exit(1);
	}
	heroi = heroi_right;

  	if(!heroi)
    {
        fprintf(stderr, "failed to load hero bitmap!\n");
        exit(1);
    }
    al_draw_scaled_bitmap(heroi,0,0,hero_ -> w,hero_-> h,hero_ -> x,hero_ -> y,hero_ -> rw,hero_ -> rh,0);
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
    //Imprime o background no fundo da tela
    al_draw_scaled_bitmap(background,0,0,800,500,0,0,800,500,0);
}
void state_init(ALLEGRO_FONT* font)
{
	create_objects();
	make_background();
	make_hero(hero_);
	al_draw_text(font, al_map_rgb(0, 104, 1), 280,100, 0, "PRESSIONE ENTER PARA JOGAR");
	al_flip_display();
	FLOOR = GROUND;
	estado = SERVINDO;
}
void state_serve(ALLEGRO_EVENT *evento)
{	
}

void draw_hero()
{
	if(last_right)
		heroi = heroi_right;
	else
		heroi = heroi_left;
	if (old_dx == 0)
		al_draw_scaled_bitmap(heroi,0,0,hero_ -> w,hero_ -> h,hero_ -> x,hero_ -> y,hero_ -> rw,hero_ -> rh,0);
	else if(old_dx > 0 )
		al_draw_scaled_bitmap(heroi_run_right,0,0,hero_ -> w,hero_ -> h,hero_ -> x,hero_ -> y,hero_ -> rw,hero_ -> rh,0);
	else 
		al_draw_scaled_bitmap(heroi_run_left,0,0,hero_ -> w,hero_ -> h,hero_ -> x,hero_ -> y,hero_ -> rw,hero_ -> rh,0);
}
void hit()
{
	for (int i = 0; i < 2; i++)
	{
		if ((hero_ -> x + hero_ -> rw >= obstacles[i] -> x) && (hero_ -> x <= obstacles[i] -> x + obstacles[i] -> rw - 1))
		{
			//printf("%d\n",hero_ -> y );
			if (((hero_ -> y + hero_ -> rh) <= obstacles[i] -> y ))
			{
				//Em cima da caixa
				if (hero_ -> y + hero_ -> rh == obstacles[i] -> y -2)
				{
					//FLOOR = obstacles[i] -> y-2;
					//hero_ -> y = FLOOR;
					//hero_ -> x = (((obstacles[i] -> x + obstacles[i] -> x + (obstacles[i] -> rw))/2));
					//Pisando na caixa
					//muda o floor
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
void move_side()
{
	if (dir != NONE)
	{
		if(dir == ESQUERDA){
			hero_ -> dx -= CONSTANTE_X;
			last_right = 0;
		}
		else if(dir == CIMA)
			hero_ -> dy -= CONSTANTE_Y;
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
	if (hero_ -> dx != 0)
	{
		if (hero_ -> dx > 0)
		{
			hero_ -> x += hero_ -> dx * 2;
			hero_ -> dx -= CONSTANTE_X;  
		}
		else
		{
			hero_ -> x += hero_ -> dx * 2;
			hero_ -> dx += CONSTANTE_X; 
		}
	}
	if (hero_ -> dy != 0)
	{
		if (hero_ -> dy < 0)
		{
			hero_ -> y += hero_ -> dy * 2;
		}
		
	}
}
void write_obstacles()
{
	//Imprime os obstaculos existentes
	if (stage == 0)
		for (int i = 0; i < 2; i++)
			al_draw_scaled_bitmap(brick,0,0,522,522,obstacles[i] -> x,obstacles[i] -> y,obstacles[i] -> rw,obstacles[i] -> rh,0);
	if (stage == 1){
		inicia_mobs();
		al_draw_scaled_bitmap(mob,0,0,obstacles[2] -> w,obstacles[2] -> h,obstacles[2] -> x,obstacles[2] -> y,obstacles[2] -> rw,obstacles[2] -> rh,0);
		al_destroy_bitmap(mob);
	}


}
void gravity_check()
{
	/*int out = 1;
	for (int i = 0; i < 15; i++)
	{
		
	}*/
	if (hero_ -> y < (FLOOR - hero_ -> rh))
	{
		hero_ -> y -= hero_ -> dy * 2 ;
		hero_ -> dy += 2;
	}
}
void CameraUpdate()
{

	al_draw_scaled_bitmap(background,0,0,800,500,0,0,800,500,0);

}
//Fũnção principal de gameplay
void state_play()
{
	if (hero_ -> x > 800){
		stage++;
		hero_ -> x = 50;
		hero_ -> y = GROUND - hero_ -> rh;
		hero_ -> dy = 0;
		hero_ -> dx = 0;
	}
	//Limpa a tela
	al_clear_to_color(al_map_rgb(0, 0, 0));
	//Imprime o background
	CameraUpdate();
    //Imprime obstaculos
    write_obstacles();
	//Checagem da gravidade
	gravity_check();
	//Altera o variação de velocidade do personagem
	move_side();

	//Transforma o delta y/x em deslocamento
	delta_transform();
    //Desenha o personagem controlavel
	draw_hero();
	//Checa Hit
	hit();


	al_flip_display();
}	
void state_close()
{

}