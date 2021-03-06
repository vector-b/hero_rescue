#include <stdio.h>
#include "hero_class.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

#define BACKGROUND_FILE "img/bg001.png"
#define HERO_FILE 		"img/hero.png"
#define RUN_RIGHT 		"img/run_right.png"
#define RUN_LEFT 		"img/run_left.png"
#define BRICK_1			"img/brick_1.png"
#define FLOOR 407
#define TRUE_FLOOR 456

ALLEGRO_BITMAP *background 		= NULL;
ALLEGRO_BITMAP *heroi 			= NULL;
ALLEGRO_BITMAP *heroi_run_right = NULL;
ALLEGRO_BITMAP *heroi_run_left 	= NULL;
ALLEGRO_BITMAP *brickone 		= NULL;


obs **obstacles;
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
	sarah -> y = FLOOR;
	sarah -> sx = 0;
	sarah -> sy = 0;   
  	sarah -> w = 70;
  	sarah -> h = 51 ; 
	heroi = al_load_bitmap(HERO_FILE);
	heroi_run_right = al_load_bitmap(RUN_RIGHT);
	heroi_run_left = al_load_bitmap(RUN_LEFT);

	brickone = al_load_bitmap(BRICK_1);
  	if(!heroi)
    {
        fprintf(stderr, "failed to load hero bitmap!\n");
        exit(1);
    }
    al_draw_scaled_bitmap(heroi,0,0,50,37,sarah -> x,sarah -> y,sarah -> w,sarah -> h,0);
    //al_draw_bitmap(heroi,0,450,0);
}
void create_objects()
{
	obstacles = malloc(15* sizeof(obstacles));
	for (int i = 0; i < 15; i++)
		obstacles[i] = malloc(sizeof(obstacles[i]));
	obstacles[0] -> w = 654;
	obstacles[0] -> h = 611;
	obstacles[0] -> x = 600;
	obstacles[0] -> rw = 40;
	obstacles[0] -> rh = 36;
	obstacles[0] -> y =	TRUE_FLOOR-36;
	obstacles[0] -> sx,obstacles[0] -> sy = 0;



}
void state_init(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state)
{
	al_init_image_addon();

	make_background();

	make_hero(sarah);

	create_objects();
	
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
void move_side(ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_EVENT *event, int *state)
{
	al_wait_for_event(queue, event);
    	if (event -> type == ALLEGRO_EVENT_KEY_DOWN)
    		if(event -> keyboard.keycode == ALLEGRO_KEY_RIGHT)
    		{
    			if (sarah -> sx < 0)
	    			sarah -> sx = 3;
    			else
    				sarah -> sx+=3;
    		}
    		else if(event -> keyboard.keycode == ALLEGRO_KEY_LEFT)
    		{
    			if (sarah -> sx > 0)
	    			sarah -> sx = -3;
    			else
    				sarah -> sx-=3;
    		}
    		else if(event -> keyboard.keycode == ALLEGRO_KEY_UP)
    		{
    			if(sarah -> sy == 0){
    				sarah -> sy -= 14;
    				sarah -> y += sarah -> sy * 5;
    			}

    		}
    		else if(event -> keyboard.keycode == ALLEGRO_KEY_ESCAPE)
    			*state = 5;

    		sarah -> x += sarah -> sx * 7;		
}
void draw_hero()
{
	if (sarah -> sx == 0)
		al_draw_scaled_bitmap(heroi,0,0,50,37,sarah -> x,sarah -> y,sarah -> w,sarah -> h,0);
	else if(sarah -> sx > 0 )
		al_draw_scaled_bitmap(heroi_run_right,0,0,50,37,sarah -> x,sarah -> y,sarah -> w,sarah -> h,0);
	else 
		al_draw_scaled_bitmap(heroi_run_left,0,0,50,37,sarah -> x,sarah -> y,sarah -> w,sarah -> h,0);


}
void hit()
{
	if((obstacles[0] -> x <= sarah -> x ) && (sarah -> x <= obstacles[0] -> x + obstacles[0] -> w))
		sarah -> y = obstacles[0] -> y - sarah -> h;
}
void state_play(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state, ALLEGRO_EVENT *event)
{
	if (sarah -> sx < 0)
		sarah -> sx++;
	else if (sarah -> sx > 0)
		sarah -> sx--;

	if (sarah -> sy < 0)
	{
		sarah -> sy +=1;
		sarah -> y += 1 * 5;
	}

	hit();

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_scaled_bitmap(background,0,0,905,703,0,0,800,500,0);
	al_draw_scaled_bitmap(brickone,0,0,654,611,obstacles[0] -> x,obstacles[0] -> y,obstacles[0] -> rw,obstacles[0] -> rh,0);

	draw_hero();
    move_side(queue, event,state);
    al_flip_display();
    
}
void state_over()
{

}
void state_close(ALLEGRO_TIMER* timer,ALLEGRO_EVENT_QUEUE* queue,ALLEGRO_DISPLAY* disp,ALLEGRO_FONT* font, int *state)
{
	/*al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);*/
}