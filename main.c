#include <stdio.h>
#include "class/hero_class.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
//enum {INICIO = 1, SERVINDO, JOGANDO, FIMPART, FIMJOGO} state ;
int state;
int main()
{
	ALLEGRO_TIMER* timer;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_DISPLAY* disp;
	ALLEGRO_FONT* font;

	if(!al_init())
	{
	    printf("couldn't initialize allegro\n");
	    exit(1);
	}
	if(!al_install_keyboard())
	{
	    printf("couldn't initialize keyboard\n");
	    exit(1);
	}
	timer = al_create_timer(1.0 / 30.0);
	if(!timer)
	{
	    printf("couldn't initialize timer\n");
	    exit(1);
	}
	queue = al_create_event_queue();
	if(!queue)
	{
	    printf("couldn't initialize queue\n");
	    exit(1);
	}
	int height, width;
	width = 800; // 38 blocos de terra + 2 border
	height = 500; //10 pixels header 
	disp = al_create_display(width, height);

	
	if(!disp)
	{
	    printf("couldn't initialize display\n");
	    exit(1);
	}
	font = al_create_builtin_font();
	if(!font)
	{
	    printf("couldn't initialize font\n");
	    exit(1);
	}

	/*Maquina de Estados
	
		Inicia - standby
			Zera pontuacao
			Inicia posição jogador
			Carrega sprites
			Musica inicial
			Inicia tipo jogador e pedras
		Jogo - Serve
			Pontuacao
			2 fases
			gravidade das pedras
			gera bombas
		Fim de jogo
			2 fases
			3 vidas 
			jogar novament
			volta pra serve
	*/
	hero *sarah;
	state = 1;
	al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);
 
    while(1)
    {
    	al_wait_for_event(queue, &event);
    	if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    		if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
    			break;

        switch (state)
        {
        	case 1 : state_init (timer,queue,disp,font,&state,sarah) ;  break ;
        	case 2 : state_serve (timer,queue,disp,font,&state,sarah) ; break ;
         	case 3 : state_play () ;  break ;
          	case 4 : state_over () ;  break ;
          	case 5 : state_close () ; break ;
          	default: break ;
        }
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    return 0;
}
/*enum {INICIO, SERVINDO, JOGANDO, FIMPART, FIMJOGO} state ;
int main(int argc, char const *argv[])
{



	state_init ();
	state = INICIO ;
	  for (;;)
	    switch (state)
	    {
	      case INICIO  : state_init (state);  break ;
	      case SERVINDO   : exit(1);
	    }
	return 0;
}*/

