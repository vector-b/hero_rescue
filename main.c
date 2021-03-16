#include <stdio.h>

#include "class/hero_class.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_ttf.h"
#define RESERVED_SAMPLES   16
#define MAX_SAMPLE_DATA    10
#define WIDTH 800
#define HEIGHT 500
int old_state;
int main()
{
  god_mode = 0;
  ler_file_scores();
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
  if (!al_init_font_addon())
  {
      fprintf(stderr,"couldn't initialize ttf addon\n");
      return 1;
  }
  if (!al_init_ttf_addon())
  {
      fprintf(stderr,"couldn't initialize ttf addon\n");
      return 1;
  }
  inicia_fontes();

  //Inicia o Display
  disp = al_create_display(WIDTH, HEIGHT);
  if(!disp)
	{
    	fprintf(stderr, "Não foi possível iniciar a tela");
	    return 1;
	}
  al_set_window_title(disp, "Hero Adventure");
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




    //Muda o estado para inicio e inicia o timer 
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
      //Aguarda um evento 
       al_wait_for_event(queue, &evento);
       //Quando timer for ativado o evento do jogo funciona
    	if(evento.type == ALLEGRO_EVENT_TIMER)
    	{
        //Swithc ente estados
          	switch(estado)
          	{
          		case INICIO:
          			state_init(font);break;
          		case 2:
          			state_serve(&evento);break;
          		case 3:
          			state_play(font);break;
          		case 5:
          			state_close();break;
              case 6:
                show_scores();break;
              case 7:
                help();break;
              case 8:
                venceu();
                break;
              case 9:
                repair();
                break;
              case 10:
                info();
                break;
          		default: break ;
          	}

        }
        //Mudar de KEY_DOWN para KEY_CHAR pra ver o hero se tornar o flash
        else if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
        {
          //Ifs para a mudança de estados
            if(evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                break;
            else if((evento.keyboard.keycode == ALLEGRO_KEY_ENTER) &&(estado == SERVINDO))
            	estado = JOGANDO;
            else if((evento.keyboard.keycode == ALLEGRO_KEY_S) && (estado == SERVINDO))
               estado = HIGH_SCORES;
            else if((evento.keyboard.keycode == ALLEGRO_KEY_M))
               estado = INICIO;
            else if((evento.keyboard.keycode == ALLEGRO_KEY_H) && (estado == SERVINDO))
               estado = INFO;
            else if((evento.keyboard.keycode == ALLEGRO_KEY_F1) && (estado != 6))
            {
              if (estado != SERVINDO)
              {
                if (estado != HELP){
                  old_state = estado;
                  estado = HELP;
                }
                else
                  estado = old_state;
              }
             
            }
            else if ((evento.keyboard.keycode == ALLEGRO_KEY_G))
            {
              if (god_mode)
                god_mode = 0;
              else
                god_mode = 1;
            }
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
   

   
    //Destroi as estruturas allegro utilizadas
    al_destroy_timer(timer);
    al_destroy_display(disp);
    al_destroy_event_queue(queue);
    desalocador();
    return 0;
}