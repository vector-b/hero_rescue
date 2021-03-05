#include <stdio.h>
#include "hero_class.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#define BACKGROUND_FILE "bg001.png"
#define HERO_FILE "sarah_frontet.png"
ALLEGRO_BITMAP  *background=NULL;
ALLEGRO_BITMAP *heroi = NULL;
hero *sarah = NULL;
enum {LEFT = 1, UP, RIGHT, DOWN} direction ;

void make_background()
{
	
	if(!al_init_image_addon())
	{
	    printf("couldn't initialize image addon\n");
	}
	background=al_load_bitmap(BACKGROUND_FILE);
	if(!background)
    {
        fprintf(stderr, "failed to load background bitmap!\n");
        exit(1);
    }
    al_draw_scaled_bitmap(background,0,0,905,703,0,0,800,500,0);

}

void make_hero()
{
	sarah = malloc(sizeof(hero));
	sarah -> x = 10;
	sarah -> y = 393;
	sarah -> sx = 0;
	sarah -> sy = 0;   
  	sarah -> w, sarah -> h = 67 ; 
	heroi = al_load_bitmap(HERO_FILE);

  	if(!heroi)
    {
        fprintf(stderr, "failed to load hero bitmap!\n");
        exit(1);
    }
    al_draw_scaled_bitmap(heroi,0,0,67,67,sarah -> x,sarah -> y,67,67,0);
    //al_draw_bitmap(heroi,0,450,0);
}
void state_init(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state)
{
	al_init_image_addon();

	make_background();

	make_hero(sarah);
	
    *state = 2;

    al_draw_text(font, al_map_rgb(255, 104, 1), 275,150, 0, "PRESSIONE ENTER PARA JOGAR");
    al_flip_display();

}
void wait_for_keypress(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state, ALLEGRO_EVENT *event)
{
	al_wait_for_event(queue, event);
    	if (event -> type == ALLEGRO_EVENT_KEY_DOWN)
    		if(event -> keyboard.keycode == ALLEGRO_KEY_ENTER)
    			*state = 3;
}
void state_serve(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state, ALLEGRO_EVENT *event)
{
	wait_for_keypress(timer,queue,disp,font,state,event);
}
void move_side(ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_EVENT *event)
{
	al_wait_for_event(queue, event);
    	if (event -> type == ALLEGRO_EVENT_KEY_DOWN)
    		if(event -> keyboard.keycode == ALLEGRO_KEY_RIGHT)
    		{
    			sarah -> sx+=2;
    			sarah -> x+= sarah -> sx * 2;
    		}
    		else if(event -> keyboard.keycode == ALLEGRO_KEY_LEFT)
    		{
    			if (sarah -> sx > 0)
	    			sarah -> sx = -1;
    			else
    				sarah -> sx--;

    			sarah -> x+= sarah -> sx * 3;
    		}	
    			
}
void state_play(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state, ALLEGRO_EVENT *event)
{
	if (sarah -> sx < 0)
		sarah -> sx++;
	else if (sarah -> sx > 0)
		sarah -> sx--;

	//printf("%d\n",sarah -> sx );

	al_clear_to_color(al_map_rgb(0, 0, 0));
	make_background();
	al_draw_scaled_bitmap(heroi,0,0,67,67,sarah -> x,sarah -> y,67,67,0);
    move_side(queue, event);
    al_flip_display();
    
}
void state_over()
{

}
void state_close()
{

}