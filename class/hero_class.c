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
#define GROUND 435

ALLEGRO_BITMAP *background 		= NULL;
ALLEGRO_BITMAP  *heroi 			= NULL;
ALLEGRO_BITMAP *heroi_right 	= NULL;
ALLEGRO_BITMAP *heroi_left 		= NULL;
ALLEGRO_BITMAP *heroi_run_right = NULL;
ALLEGRO_BITMAP *heroi_run_left 	= NULL;

hero *hero_= NULL;

void make_hero()
{
	hero_ = malloc(sizeof(hero));
	hero_ -> sx = 0;
	hero_ -> sy = 0;   
  	hero_ -> w = 20;
  	hero_ -> h = 29;
  	hero_ -> rw = 45;
  	hero_ -> rh = 65;
  	hero_ -> x = 100;
	hero_ -> y = GROUND - hero_ -> rh ;  
	heroi_right 	= al_load_bitmap(HERO_FILE);
	heroi_run_right = al_load_bitmap(RUN_RIGHT);
	heroi_run_left	= al_load_bitmap(RUN_LEFT);
	heroi_left 		= al_load_bitmap(H_LEFT);
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
	make_background();
	make_hero(hero_);
	al_draw_text(font, al_map_rgb(0, 104, 1), 280,100, 0, "PRESSIONE ENTER PARA JOGAR");
	al_flip_display();

	estado = SERVINDO;
}
void state_serve(ALLEGRO_EVENT *evento)
{
	
}
void draw_hero()
{
	if (hero_ -> sx == 0)
		al_draw_scaled_bitmap(heroi,0,0,hero_ -> w,hero_ -> h,hero_ -> x,hero_ -> y,hero_ -> rw,hero_ -> rh,0);
	else if(hero_ -> sx > 0 )
		al_draw_scaled_bitmap(heroi_run_right,0,0,hero_ -> w,hero_ -> h,hero_ -> x,hero_ -> y,hero_ -> rw,hero_ -> rh,0);
	else 
		al_draw_scaled_bitmap(heroi_run_left,0,0,hero_ -> w,hero_ -> h,hero_ -> x,hero_ -> y,hero_ -> rw,hero_ -> rh,0);
}

void state_play()
{
	//Limpa a tela
	al_clear_to_color(al_map_rgb(0, 0, 0));
	//Imprime o background
    al_draw_scaled_bitmap(background,0,0,800,500,0,0,800,500,0);
    //Desenha o personagem controlavel
	draw_hero();
	al_flip_display();
}	
void state_close()
{

}