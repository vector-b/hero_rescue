#include <stdio.h>
#include "hero_class.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#define BACKGROUND_FILE "bg001.png"
#define HERO_FILE "sarah_frontet.png"

void make_background()
{
	ALLEGRO_BITMAP  *background=NULL;
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

hero *make_hero(hero *sarah)
{
	sarah = malloc(sizeof(hero));
	sarah -> x = 10;
	sarah -> y = 393;
	sarah -> sx, sarah -> sy = 0;   
  	sarah -> w, sarah -> h = 67 ; 
  	ALLEGRO_BITMAP *heroi = NULL;
	heroi = al_load_bitmap(HERO_FILE);

  	if(!heroi)
    {
        fprintf(stderr, "failed to load hero bitmap!\n");
        exit(1);
    }
    al_draw_scaled_bitmap(heroi,0,0,67,67,sarah -> x,sarah -> y,67,67,0);
    //al_draw_bitmap(heroi,0,450,0);

	return sarah;
}
void state_init(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state, hero *sarah)
{
	al_init_image_addon();

	make_background();

	sarah = make_hero(sarah);
	
    *state = 2;

    al_draw_text(font, al_map_rgb(255, 104, 1), 275,150, 0, "PRESSIONE ENTER PARA JOGAR");
    al_flip_display();

}
void wait_for_keypress(int *state)
{
	/*al_wait_for_event(queue, &event);
    	if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    		if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
    			break;*/
}
void state_serve(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state, hero *sarah)
{
	wait_for_keypress(state);
}
void state_play()
{

}
void state_over()
{

}
void state_close()
{

}