#include <stdio.h>

#include "class/hero_class.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#define RESERVED_SAMPLES   16
#define MAX_SAMPLE_DATA    10
#define WIDTH 800
#define HEIGHT 500

int main()
{
  fim = 0;
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
	timer = al_create_timer(1/ 60.0);
	if(!timer)
	{
	    printf("couldn't initialize timer\n");
	    exit(1);
	}
	
	if (!al_install_audio()) 
	{
	   fprintf(stderr, "Could not init sound!\n");
	   return 1;
	}
	if (!al_init_acodec_addon())
	{
		fprintf(stderr, "Could not init sound!\n");
	   	return 1;
	}
	if (!al_reserve_samples(RESERVED_SAMPLES)) 
	{
      fprintf(stderr, "Could not set up voice and mixer.\n");
      return 1;
  }
  if(!al_init_image_addon())
  {
      fprintf(stderr,"couldn't initialize image addon\n");
      return 1;
  }

    

    //Inicia o Display
    disp = al_create_display(WIDTH, HEIGHT);
    if(!disp)
	{
    	fprintf(stderr, "Não foi possível iniciar a tela");
	    return 1;
	}
	//Inicia a fonte
	font = al_create_builtin_font();
	if(!font)
	{
    	fprintf(stderr, "Não foi possível iniciar a fonte");
	    return(1);
	}
	queue = al_create_event_queue();
	if(!queue)
	{
	    printf("couldn't initialize queue\n");
	    exit(1);
	}

	//Registra os eventos do programa
	al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_timer_event_source(timer));
  al_register_event_source(queue, al_get_display_event_source(disp));




    estado = INICIO;
    al_start_timer(timer);


    //Início do Loop Principal do programa
    while(!fim)
    {
      double old_time = al_get_time();

      double new_time = al_get_time();
      double delta = new_time - old_time;
      fps = 1/(delta*1000);
      old_time = new_time;
      ALLEGRO_EVENT evento;

        al_wait_for_event(queue, &evento);

      
    	if(evento.type == ALLEGRO_EVENT_TIMER)
    	{
          	switch(estado)
          	{
          		case INICIO:
          			state_init(font);break;
          		case 2:
          			state_serve(&evento);break;
          		case 3:
          			state_play(font);break;
          		case 4:
          			state_init(font);break;
          		case 5:
          			state_close();break;
          		default: break ;
          	}
        }
        else if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if(evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                break;
            else if((evento.keyboard.keycode == ALLEGRO_KEY_ENTER) && (estado == SERVINDO))
            	estado = JOGANDO;
            else if(estado == JOGANDO)
            {
              if(evento.keyboard.keycode == ALLEGRO_KEY_LEFT)
                dir = ESQUERDA;
              else if (evento.keyboard.keycode == ALLEGRO_KEY_UP)
                dir = CIMA;
              else if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT)
                dir = DIREITA;
              else if (evento.keyboard.keycode == ALLEGRO_KEY_DOWN)
                dir = BAIXO;
            }
            else if (estado == FIMJOGO)
            {
              if(evento.keyboard.keycode == ALLEGRO_KEY_R)
                estado = INICIO;
            }
        }
        else if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        	break;

    }
   

    char nome[100];

    ALLEGRO_USTR *name;
    name = al_ustr_new("o nome do bixa é -> ");


    while(1)
    {
      recebe_user(font);
      ALLEGRO_EVENT ev;
      al_wait_for_event(queue , &ev);
      switch(ev.type)
      {
        case ALLEGRO_EVENT_KEY_CHAR:
          if (ev.keyboard.unichar >= 32){
             al_ustr_append_chr(name, ev.keyboard.unichar);
          }
          break;
        case ALLEGRO_EVENT_KEY_DOWN:
          if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            break;
          break;
      }
     
    }
  
    printf("dale\n");
    strcpy(nome, al_cstr(name));
    printf("%s\n",nome );
    al_destroy_timer(timer);
    al_destroy_display(disp);
    al_destroy_event_queue(queue);

	return 0;
}