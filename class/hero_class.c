#include <stdio.h>
#include "variables.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"


/*Inicia recursos principais*/

//Inicia Heroi, com seus dados iniciais 
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
	hero_ -> y = SUPER_GROUND - hero_ -> rh ;  
}
//Inicia o menu, estágio antes de começar a jogar
void make_menu()
{
	//Inicia o image_addon 
	//Carrega o background na memória
	menu=al_load_bitmap(GAME_MENU);
	if(!menu)
    {
        fprintf(stderr, "failed to load menu bitmap!\n");
        exit(1);
    }
}
//Puxa o background pra memória
void make_background()
{
	//Carrega o background na memória
	background=al_load_bitmap(BACKGROUND_FILE);
	if(!background)
    {
        fprintf(stderr, "failed to load background bitmap!\n");
        exit(1);
    }
}
void inicia_escadas()
{
	stairs[0] -> stage = 4;
	stairs[0] -> w = 80;
	stairs[0] -> h = 232;
	stairs[0] -> rw = 80;
	stairs[0] -> rh = 232;
	stairs[0] -> x = 150;
	stairs[0] -> y = GROUND - stairs[0] -> rh ;
	stairs[0] -> dy, stairs[0] -> dx = 0;
	stairs[0] -> stage = 4;
}
void hero_updown()
{
	for (int i = 0; i < NUM_STAIRS; i++)
	{	
		if (stage == stairs[i] -> stage)
		{
			/*if(inside_stairs(i))
			{
				printf("eba\n");
			}*/
		}
		else
		{
			//printf("ta nao\n");
		}
		
	}
}

/*Criação da estruturas e monstros*/

void alocador()
{
	obstacles = malloc(NUM_OBS* sizeof(obstacles));
	for (int i = 0; i < NUM_OBS; i++)
		obstacles[i] = malloc(15000*sizeof(obstacles));

	monsters = malloc(NUM_MON*sizeof(monsters));
	for (int i = 0; i < NUM_MON; i++)
		monsters[i] = malloc(3000*sizeof(monsters[i]));

	stairs = malloc(sizeof(stairs));
	stairs[0] = malloc(80*sizeof(stairs));
}
//Cria manualmente os obstaculos do jogo (estruturas físicas)
void create_objects()
{
	obstacles[0] -> using = 1;
	obstacles[0] -> w = 145;
	obstacles[0] -> h = 66;
	obstacles[0] -> rw = 145;
	obstacles[0] -> rh = 66;
	obstacles[0] -> stage = 3;
	obstacles[0] -> x = 800 - obstacles[0] -> w;
	obstacles[0] -> name_file[0] = '\0';
	strcat(obstacles[0] -> name_file, "floor_br.bmp");
	obstacles[0] -> y = 435;
	obstacles[0] -> dx,obstacles[0] -> dy = 0;

	obstacles[1] -> using = 1;
	obstacles[1] -> w = 106;
	obstacles[1] -> h = 106;
	obstacles[1] -> x = 550;
	obstacles[1] -> rw = 50;
	obstacles[1] -> rh = 50;
	obstacles[1] -> stage = 1;
	obstacles[1] -> name_file[0] = '\0';
	strcat(obstacles[1] -> name_file, "crate.bmp");
	obstacles[1] -> y = SUPER_GROUND - obstacles[1] -> rh;
	obstacles[1] -> dx,obstacles[1] -> dy = 0;

	obstacles[2] -> using = 1;
	obstacles[2] -> w = 106;
	obstacles[2] -> h = 106;
	obstacles[2] -> x = 600;
	obstacles[2] -> rw = 50;
	obstacles[2] -> rh = 50;
	obstacles[2] -> stage = 1;
	obstacles[2] -> name_file[0] = '\0';
	strcat(obstacles[2] -> name_file, "crate.bmp");
	obstacles[2] -> y = SUPER_GROUND - obstacles[2] -> rh;
	obstacles[2] -> dx,obstacles[2] -> dy = 0;


	obstacles[3] -> using = 1;
	obstacles[3] -> w = 106;
	obstacles[3] -> h = 106;
	obstacles[3] -> x = 239;
	obstacles[3] -> rw = 50;
	obstacles[3] -> rh = 50;
	obstacles[3] -> stage = 2;
	obstacles[3] -> name_file[0] = '\0';
	strcat(obstacles[3] -> name_file, "crate.bmp");
	obstacles[3] -> y = SUPER_GROUND - obstacles[3] -> rh;
	obstacles[3] -> dx,obstacles[3] -> dy = 0;

	obstacles[4] -> using = 1;
	obstacles[4] -> w = 74;
	obstacles[4] -> h = 129;
	obstacles[4] -> x = 289;
	obstacles[4] -> rw = 74;
	obstacles[4] -> rh = 129;
	obstacles[4] -> stage = 2;
	obstacles[4] -> name_file[0] = '\0';
	strcat(obstacles[4] -> name_file, "brick_4.bmp");
	obstacles[4] -> y = SUPER_GROUND - obstacles[4] -> rh;
	obstacles[4] -> dx,obstacles[4] -> dy = 0;

	obstacles[5] -> using = 1;
	obstacles[5] -> w = 74;
	obstacles[5] -> h = 129;
	obstacles[5] -> x = 363;
	obstacles[5] -> rw = 74;
	obstacles[5] -> rh = 129;
	obstacles[5] -> stage = 2;
	obstacles[5] -> name_file[0] = '\0';
	strcat(obstacles[5] -> name_file, "brick_4.bmp");
	obstacles[5] -> y = SUPER_GROUND - obstacles[5] -> rh;
	obstacles[5] -> dx,obstacles[5] -> dy = 0;

	obstacles[6] -> using = 1;
	obstacles[6] -> w = 74;
	obstacles[6] -> h = 129;
	obstacles[6] -> x = 437;
	obstacles[6] -> rw = 74;
	obstacles[6] -> rh = 129;
	obstacles[6] -> stage = 2;
	obstacles[6] -> name_file[0] = '\0';
	strcat(obstacles[6] -> name_file, "brick_4.bmp");
	obstacles[6] -> y = SUPER_GROUND - obstacles[6] -> rh;
	obstacles[6] -> dx,obstacles[6] -> dy = 0;

	obstacles[7] -> using = 1;
	obstacles[7] -> w = 145;
	obstacles[7] -> h = 66;
	obstacles[7] -> x = 0;
	obstacles[7] -> rw = 145;
	obstacles[7] -> rh = 66;
	obstacles[7] -> stage = 3;
	obstacles[7] -> name_file[0] = '\0';
	strcat(obstacles[7] -> name_file, "floor_br.bmp");
	obstacles[7] -> y = 435;
	obstacles[7] -> dx,obstacles[7] -> dy = 0;


	obstacles[8] -> using = 1;
	obstacles[8] -> w = 66;
	obstacles[8] -> h = 24;
	obstacles[8] -> x = 146;
	obstacles[8] -> rw = 66;
	obstacles[8] -> rh = 24;
	obstacles[8] -> vai = 1;
	obstacles[8] -> stage = 3;
	obstacles[8] -> name_file[0] = '\0';
	strcat(obstacles[8] -> name_file, "brick_5.png");
	obstacles[8] -> y = 435;
	obstacles[8] -> dx,obstacles[8] -> dy = 0;

	obstacles[9] -> using = 1;
	obstacles[9] -> w = 66;
	obstacles[9] -> h = 24;
	obstacles[9] -> x = 150;
	obstacles[9] -> rw = 66;
	obstacles[9] -> rh = 24;
	obstacles[9] -> vai = 1;
	obstacles[9] -> stage = 4;
	obstacles[9] -> name_file[0] = '\0';
	strcat(obstacles[9] -> name_file, "brick_5.png");
	obstacles[9] -> y = 435 - obstacles[9] -> rh;
	obstacles[9] -> dx,obstacles[9] -> dy = 0;

	obstacles[10] -> using = 1;
	obstacles[10] -> w = 250;
	obstacles[10] -> h = 50;
	obstacles[10] -> x = 250;
	obstacles[10] -> rw = 175;
	obstacles[10] -> rh = 35;
	obstacles[10] -> vai = 1;
	obstacles[10] -> stage = 4;
	obstacles[10] -> name_file[0] = '\0';
	strcat(obstacles[10] -> name_file, "brick_big.png");
	obstacles[10] -> y = 200;
	obstacles[10] -> dx,obstacles[10] -> dy = 0;
}
//Cria os monstros do jogo
void cria_monstros_estruturas()
{
	monsters[0] -> using = 1;
	monsters[0] -> type = 1;
	monsters[0] -> live = 1;
	monsters[0] -> life = 1;
	monsters[0] -> w = 315;
	monsters[0] -> h = 329;
	monsters[0] -> x = 550;
	monsters[0] -> rw = 50;
	monsters[0] -> rh = 50;
	monsters[0] -> y = SUPER_GROUND - monsters[0] -> rh;
	monsters[0] -> dx,monsters[0] -> dy = 0;
	monsters[0] -> vai = 0;
	monsters[0] -> x_ini = 300;
	monsters[0] -> x_dest = 550;
	monsters[0] -> y_ini = 0;
	monsters[0] -> y_dest = 0;
	monsters[0] -> stage = 1;

	monsters[1] -> using = 1;
	monsters[1] -> type = 2;
	monsters[1] -> live = 1;
	monsters[1] -> life = 1;
	monsters[1] -> w = 60;
	monsters[1] -> h = 51;
	monsters[1] -> x = 200;
	monsters[1] -> rw = 60;
	monsters[1] -> rh = 51;
	monsters[1] -> y = 200;
	monsters[1] -> dx,monsters[1] -> dy = 0;
	monsters[1] -> vai = 0;
	monsters[1] -> sobe = 0;
	monsters[1] -> x_ini = 0;
	monsters[1] -> x_dest = 800 - monsters[1] -> w;
	monsters[1] -> y_ini = 0;
	monsters[1] -> y_dest = 400;
	monsters[1] -> stage = 1;
	monsters[1] -> checa_sprite = 0;
  	monsters[1] -> num_sprite = 0;

  	monsters[2] -> using = 1;
	monsters[2] -> type = 3;
	monsters[2] -> live = 1;
	monsters[2] -> life = 1;
	monsters[2] -> w = 14;
	monsters[2] -> h = 11;
	monsters[2] -> x = 200;
	monsters[2] -> rw = 28;
	monsters[2] -> rh = 22;
	monsters[2] -> y = 200;
	monsters[2] -> dx,monsters[2] -> dy = 0;
	monsters[2] -> vai = 0;
	monsters[2] -> sobe = 0;
	monsters[2] -> x_ini = 0;
	monsters[2] -> x_dest = 800 - monsters[2] -> rw;
	monsters[2] -> y_ini = 0;
	monsters[2] -> y_dest = 0;
	monsters[2] -> stage = 2;
	monsters[2] -> checa_sprite = 0;
  	monsters[2] -> num_sprite = 0;

  	monsters[3] -> using = 1;
	monsters[3] -> type = 3;
	monsters[3] -> live = 1;
	monsters[3] -> life = 1;
	monsters[3] -> w = 14;
	monsters[3] -> h = 11;
	monsters[3] -> x = 540;
	monsters[3] -> rw = 28;
	monsters[3] -> rh = 22;
	monsters[3] -> y = 100;
	monsters[3] -> dx,monsters[3] -> dy = 0;
	monsters[3] -> vai = 0;
	monsters[3] -> sobe = 0;
	monsters[3] -> x_ini = 0;
	monsters[3] -> x_dest = 800 - monsters[3] -> rw;
	monsters[3] -> y_ini = 0;
	monsters[3] -> y_dest = 0;
	monsters[3] -> stage = 2;
	monsters[3] -> checa_sprite = 0;
  	monsters[3] -> num_sprite = 0;

  	monsters[4] -> using = 1;
	monsters[4] -> type = 3;
	monsters[4] -> live = 1;
	monsters[4] -> life = 1;
	monsters[4] -> w = 14;
	monsters[4] -> h = 11;
	monsters[4] -> x = 540;
	monsters[4] -> rw = 28;
	monsters[4] -> rh = 22;
	monsters[4] -> y = 300;
	monsters[4] -> dx,monsters[4] -> dy = 0;
	monsters[4] -> vai = 0;
	monsters[4] -> sobe = 0;
	monsters[4] -> x_ini = 500;
	monsters[4] -> x_dest = 800 - monsters[4] -> rw;
	monsters[4] -> y_ini = 0;
	monsters[4] -> y_dest = 0;
	monsters[4] -> stage = 2;
	monsters[4] -> checa_sprite = 0;
  	monsters[4] -> num_sprite = 0;

  	monsters[5] -> using = 1;
	monsters[5] -> type = 4;
	monsters[5] -> live = 1;
	monsters[5] -> life = 1;
	monsters[5] -> w = 70;
	monsters[5] -> h = 103;
	monsters[5] -> x = 540;
	monsters[5] -> rw = 70;
	monsters[5] -> rh = 103;
	monsters[5] -> y = 200;
	monsters[5] -> dx,monsters[4] -> dy = 0;
	monsters[5] -> vai = 0;
	monsters[5] -> sobe = 0;
	monsters[5] -> x_ini = 100;
	monsters[5] -> x_dest = 800 - monsters[5] -> rw;
	monsters[5] -> y_ini = 0;
	monsters[5] -> y_dest = 435 - monsters[5] -> rh;
	monsters[5] -> stage = 3;
	monsters[5] -> checa_sprite = 0;
  	monsters[5] -> num_sprite = 0;

  	monsters[6] -> using = 1;
	monsters[6] -> type = 5;
	monsters[6] -> live = 1;
	monsters[6] -> life = 5;
	monsters[6] -> w = 38;
	monsters[6] -> h = 60;
	monsters[6] -> x = 540;
	monsters[6] -> rw = 108;
	monsters[6] -> rh = 156;
	monsters[6] -> y = SUPER_GROUND - monsters[6] -> rh;
	monsters[6] -> dx,monsters[6] -> dy = 0;
	monsters[6] -> vai = 0;
	monsters[6] -> sobe = 0;
	monsters[6] -> x_ini = 300;
	monsters[6] -> x_dest = 800 -100- monsters[6] -> rw;
	monsters[6] -> y_ini = 0;
	monsters[6] -> y_dest = 0;
	monsters[6] -> stage = 4;
	monsters[6] -> checa_sprite = 0;
  	monsters[6] -> num_sprite = 0;

}

int checa_hero(int i)
{
	if ((hero_ -> x + hero_ -> rw >= obstacles[i] -> x + 1) && (hero_ -> x <= obstacles[i] -> x + obstacles[i] -> rw - 1))
		if ((hero_ -> y + hero_ -> rh - 1) ==  obstacles[i] -> y-1) 
			return 1;
	return 0;
}
//Função que gerencia os monstros, apenas ativada nos estágios dos respectivos monstros
void inicia_mobs()
{
	for (int i = 0; i < NUM_MON; i++)
	{
		if ((stage == monsters[i] -> stage) && (monsters[i] -> using))
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
				snprintf(filename, 12, "%d.bmp", num_sprite);
			

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
				monsters[i] -> checa_sprite++;

				if((monsters[i] -> checa_sprite % 3) == 0 )
					monsters[i] -> num_sprite++;

				if (monsters[i] -> num_sprite >= 2)
					monsters[i] -> num_sprite = 0;

				char filename[50] = "";
				snprintf(filename, 12, "%d.bmp", monsters[i] -> num_sprite);
			

				char path[100] = "";
				if (monsters[i] -> vai)
					strcat(path, MOB_FLY_RIGHT);
				else
					strcat(path, MOB_FLY);

				strcat(path, filename);
				mob_2 = al_load_bitmap(path);
				
				if (monsters[i] -> checa_sprite == 100)
					monsters[i] -> checa_sprite = 0;

			}
			else if (monsters[i] -> type == 3)
			{
				monsters[i] -> checa_sprite++;

				if((monsters[i] -> checa_sprite % 3) == 0 )
					monsters[i] -> num_sprite++;

				if (monsters[i] -> num_sprite >= 4)
					monsters[i] -> num_sprite = 0;

				char filename[50] = "";
				snprintf(filename, 12, "%d.png", monsters[i] -> num_sprite);;

				char path[100] = "";
				/*if (monsters[i] -> vai)
					strcat(path, MOB_FLY_RIGHT);
				else*/
					strcat(path, MOB_BAT);

				strcat(path, filename);
				mob_3 = al_load_bitmap(path);
				
				if (monsters[i] -> checa_sprite == 100)
					monsters[i] -> checa_sprite = 0;
			}
			else if (monsters[i] -> type == 4)
			{
				monsters[i] -> checa_sprite++;

				if((monsters[i] -> checa_sprite % 3) == 0 )
					monsters[i] -> num_sprite++;

				if (monsters[i] -> num_sprite >= 9)
					monsters[i] -> num_sprite = 0;

				char filename[50] = "";
				snprintf(filename, 12, "%d.png", monsters[i] -> num_sprite);;

				char path[100] = "";
				if (monsters[i] -> vai)
					strcat(path, GHOST_RIGHT);
				else
					strcat(path, GHOST);

				strcat(path, filename);
				mob_4 = al_load_bitmap(path);
				
				if (monsters[i] -> checa_sprite == 100)
					monsters[i] -> checa_sprite = 0;
			}
			else if (monsters[i] -> type == 5)
			{
				monsters[i] -> checa_sprite++;

				if((monsters[i] -> checa_sprite % 24) == 0 )
					monsters[i] -> num_sprite++;

				if (monsters[i] -> num_sprite >= 2)
					monsters[i] -> num_sprite = 0;

				char filename[50] = "";
				snprintf(filename, 12, "%d.png", monsters[i] -> num_sprite);;

				char path[100] = "";
				if (monsters[i] -> vai)
					strcat(path, MINOTAUR_RIGHT);
				else
					strcat(path, MINOTAUR);

				strcat(path, filename);

				mob_5 = al_load_bitmap(path);
				
				if (monsters[i] -> checa_sprite == 100)
					monsters[i] -> checa_sprite = 0;
			}
		}
	}
	for (int i = 0; i < NUM_OBS; i++)
	{
		if (stage == obstacles[i] -> stage)
			if (i == 8)
			{
				//Muda a direção do deslocamento horizontal
				if (obstacles[i] -> x >= (800 - 146 - obstacles[i] -> w)-1)
					obstacles[i] -> vai = 0;
				else if (obstacles[i] -> x  <=  146)
					obstacles[i] -> vai = 1;

				//Anda pra direita ou esquerda
				if (obstacles[i] -> vai)
					obstacles[i] -> x++;
				else
					obstacles[i] -> x--;


				if (checa_hero(i)){
					if(obstacles[i] -> vai)
						hero_ -> x++;
					else
						hero_ -> x--;
				}
			}
			else if (i == 9)
			{
				//Muda a direção do deslocamento horizontal
				if (obstacles[i] -> y >= SUPER_GROUND - obstacles[i] -> rh)
					obstacles[i] -> vai = 0;
				else if (obstacles[i] -> y  <=  150)
					obstacles[i] -> vai = 1;

				//Anda pra direita ou esquerda
				if (obstacles[i] -> vai)
					obstacles[i] -> y++;
				else
					obstacles[i] -> y--;


				if (checa_hero(i)){
					if(obstacles[i] -> vai)
						hero_ -> y++;
					else
						hero_ -> y--;
				}
			}
		
	}
}

/* Funções usadas para imprimir na tela heroi/estruturas*/

//Função que escreve monstros e estruturas na tela
void write_obstacles()
{
	//Imprime os obstaculos existentes
	for (int i = 0; i < NUM_OBS; i++)
			if ((stage == obstacles[i] -> stage) && (obstacles[i] -> using == 1))
			{	
				char path[100] = "";
				strcat(path, OBJ_FOLDER);
				strcat(path,obstacles[i] -> name_file);
				ALLEGRO_BITMAP *obj = NULL;
				obj = al_load_bitmap(path);
				if (!obj)
				{
					fprintf(stderr, "Problemas na leitura de um bmp!\n" );
					exit(1);
				}
				al_draw_scaled_bitmap(obj,0,0,obstacles[i] -> w,obstacles[i] -> h,obstacles[i] -> x,obstacles[i] -> y,obstacles[i] -> rw,obstacles[i] -> rh,0);
				al_destroy_bitmap(obj);
			}
		
	inicia_mobs();
	for (int i = 0; i < NUM_MON; i++)
	{
		if ((stage == monsters[i] -> stage) && (monsters[i] -> using))
			if (monsters[i] -> live == 1)
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
				else if (monsters[i] -> type == 3)
				{

					al_draw_scaled_bitmap(mob_3,0,0,monsters[i] -> w,monsters[i] -> h,monsters[i] -> x,monsters[i] -> y,monsters[i] -> rw,monsters[i] -> rh,0);
					//al_destroy_bitmap(mob_3);
				}
				else if (monsters[i] -> type == 4)
				{

					al_draw_scaled_bitmap(mob_4,0,0,monsters[i] -> w,monsters[i] -> h,monsters[i] -> x,monsters[i] -> y,monsters[i] -> rw,monsters[i] -> rh,0);
					//al_destroy_bitmap(mob_3);
				}
				else if (monsters[i] -> type == 5)
				{

					al_draw_scaled_bitmap(mob_5,0,0,monsters[i] -> w,monsters[i] -> h,monsters[i] -> x,monsters[i] -> y,monsters[i] -> rw,monsters[i] -> rh,0);
					//al_destroy_bitmap(mob_3);
				}
	}		
}
//Escreve o herói em sua respectiva posição
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
	else if(hero_ -> dx > 0 )
	{
		int chosen = 1;
		if (running <= 6)
			chosen = running;
		else
			running = 1;
		
		char filename[100] = "";
		snprintf(filename, 12, "%d.png", chosen);

		char path[100] = "";

		strcat(path, RUNNING_RIGHT);

		strcat(path, filename);
		stand = al_load_bitmap(path);

		al_draw_scaled_bitmap(stand,0,0,hero_ -> w,hero_ -> h,hero_ -> x,hero_ -> y,hero_ -> rw,hero_ -> rh,0);

		al_destroy_bitmap(stand);
	}
	else {
		int chosen = 1;
		if (running <= 6)
			chosen = running;
		else
			running = 1;
		
		char filename[100] = "";
		snprintf(filename, 12, "%d.png", chosen);

		char path[100] = "";

		strcat(path, RUNNING_LEFT);

		strcat(path, filename);
		stand = al_load_bitmap(path);

		al_draw_scaled_bitmap(stand,0,0,hero_ -> w,hero_ -> h,hero_ -> x,hero_ -> y,hero_ -> rw,hero_ -> rh,0);

		al_destroy_bitmap(stand);
	}
}


/* Funções de movimentação de personagem */

//Decise a direção e velocidade de acordo com o botão pressionado 
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
//Transforma a velocidade em deslocamento
void delta_transform()
{
	//Deslocamento Horizontal
	if (hero_ -> dx != 0)
	{
		if (hero_ -> dx > 0)
		{
			running++;
			hero_ -> x += hero_ -> dx;
			hero_ -> dx -= CONSTANTE_X/6;  
		}
		else
		{
			running++;
			hero_ -> x += hero_ -> dx;
			hero_ -> dx += CONSTANTE_X/6; 
		}
	}
	else
	{
		running = 1;
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

void morrer()
{
	al_stop_samples();
	death_sound = al_load_sample("song/death_sound.wav");
					if (!death_sound) 
					{
						fprintf(stderr, "Could not load death sound!\n");
						exit(1);
					}
					if (!al_play_sample(death_sound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0)) {
					              fprintf(stderr,
					                 "al_play_sample_data failed, perhaps too many sounds\n");
					           }
}
//Simula uma gravidade que puxa o heroi em situações necessárias
void gravity_check()
{
	if (hero_ -> y >= 500){
		hero_ -> live = 0;
		morrer();
	}

	if (hero_ -> dy > 0)
		hero_ -> dy =0;
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
//Atualiza o "chão" do personagem
void UpdateFloor()
{
	int out = 1;
	if (hero_ -> y + hero_ -> rh == FLOOR)
		hero_ -> dy = 0 ;
	if (hero_ -> y + hero_ -> rh > GROUND )
	{	
		hero_ -> y = GROUND - hero_ -> rh;
	}
	for (int i = 0; i < NUM_OBS; i++)
	{
		if ((stage == obstacles[i] -> stage) && obstacles[i] -> using) 
		{
			if ((hero_ -> x + hero_ -> rw >= obstacles[i] -> x) && (hero_ -> x <= obstacles[i] -> x + obstacles[i] -> rw - 1))
			{
				if (((hero_ -> y + hero_ -> rh) <= obstacles[i] -> y ))
					{
						out = 1;
						//Em cima da caixa
						if ((hero_ -> y + hero_ -> rh <=  obstacles[i] -> y ) && (hero_ -> y + hero_ -> rh > obstacles[i] -> y - 5) ) 
						{
							out = 0;
						}
					}
					else if((hero_ -> y > obstacles[i] -> y + obstacles[i] -> rh))
					{
						//printf("xd\n");
						//Em baixo da caixa
						out = 1; 
					}
			}		
		}

		
	}
	if (out)
	{
		FLOOR = GROUND;
		
	}
}

/* Funções de atualização de mundo e localização */

//Imprime o background correto nas fases 
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
//Realiza alterações de acordo com o stage atual
void stages_()
{
	if(stage == 3)
		GROUND = 500 + hero_ -> rh;
	else
		GROUND = 435;
	if (hero_ -> live == 0)
	{
		estado = FIMJOGO;
	}
	if (hero_ -> x > 800){
		stage++;
		if(stage !=  3)
			GROUND = SUPER_GROUND;
		hero_ -> x = 50;
		hero_ -> y = GROUND - hero_ -> rh;
		hero_ -> dy = 0;
		hero_ -> dx = 0;
	}
	if (hero_ -> x < 0 )
	{

		if(stage != 0)
		{
			stage--;
			if(stage !=  3)
				GROUND = SUPER_GROUND;
			hero_ -> x = 750;
			hero_ -> y = GROUND - hero_ -> rh;
			hero_ -> dy = 0;
			hero_ -> dx = 0;
		}
		else
			hero_ -> x = 0;
		
	}
}
//Checa colisão com outras estruturas/monstros
void hit()
{
	for (int i = 0; i < NUM_OBS; i++)
	{
		if ((stage == obstacles[i] -> stage) && (obstacles[i] -> using == 1))
		{
			if ((hero_ -> x + hero_ -> rw >= obstacles[i] -> x + 1) && (hero_ -> x <= obstacles[i] -> x + obstacles[i] -> rw - 1))
			{
				if (((hero_ -> y + hero_ -> rh) <= obstacles[i] -> y + 5))
				{
					int pos =hero_ -> y + hero_ -> rh;
					if ((pos >=  obstacles[i] -> y - 5 ) && (pos <= obstacles[i] -> y + (obstacles[i] -> rh/3))) 
					{
						FLOOR = obstacles[i] -> y;
						hero_ -> dy = 0;
						hero_ -> y = obstacles[i] -> y - hero_ -> rh;
						draw_hero();
					}
				}
				else if((hero_ -> y > obstacles[i] -> y + obstacles[i] -> rh))
				{
					//Em baixo da caixa
					if (hero_ -> y == obstacles[i] -> y + obstacles[i]-> rh)
					{
						hero_ -> y = obstacles[i] -> y + obstacles[i]-> rh - 1;
					}
				}
				else if (!((FLOOR <=  obstacles[i] -> y ) && (FLOOR > obstacles[i] -> y - 5)))
				{
					if (hero_ -> x <=  (((obstacles[i] -> x + obstacles[i] -> x + (obstacles[i] -> rw))/2)))
					{
						hero_ -> x = obstacles[i] -> x - hero_ -> rw;
					}
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
				//Em cima da caixa
				int pos =hero_ -> y + hero_ -> rh;
				if ((pos >= monsters[i] -> y) && (pos <= monsters[i] -> y + (monsters[i]->rh/3))) 
				{
						monsters[i] -> life--;
						if (monsters[i] -> life == 0 )
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
							short type;
							type = monsters[i] -> type;
							if (type == 1 || type == 2 )
								PONTUACAO+=5;
							else if(type == 3)
								PONTUACAO+=2;
							else if(type == 4)
								PONTUACAO+=10;
						}
						else{
							if (monsters[i] -> vai)
								hero_ -> x += monsters[i] -> rw + hero_ -> w;
							else
								hero_ -> x -= monsters[i] -> rw + hero_ -> w;
							
						}
						
				}
				else if((hero_ -> y > monsters[i] -> y + monsters[i] -> rh)){
					//Em baixo da caixa 
				}
				else if(hero_ -> y + hero_ -> rh < monsters[i] -> y - 1){
					//do nothing
				}
				else
				{
					//printf("%d %d\n",hero_ -> y + hero_-> rh, monsters[i] -> y  );
					hero_ -> live = 0;
					morrer();
				}
			}
		}
		
	}
}

void desalocador()
{
	for (int i = 0; i < NUM_MON; i++)
		free(monsters[i]);
	free(monsters);

	for (int i = 0; i < NUM_OBS; i++)
		free(obstacles[i]);
	free(obstacles);
}
/*Funções dos estados do */

void state_serve(ALLEGRO_EVENT *evento)
{	
}
//Estado inicial que procura inicializar recursos do game
void state_init(ALLEGRO_FONT* font)
{
	//Puxa a música e inicia 
	al_stop_samples();

	char filename[100] ="song/forest.wav";
	background_sound = al_load_sample(filename);
	if (!background_sound) 
	{
		fprintf(stderr, "Could not load sample from '%s'!\n", filename);
		exit(1);
	}
	if (!al_play_sample(background_sound, 1.0, 0.5, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL)) {
	              fprintf(stderr,
	                 "al_play_sample_data failed, perhaps too many sounds\n");
	           }
	stage = 0 ;
	PONTUACAO = 0;
	if (!playing)
		alocador();

	create_objects();
	inicia_escadas();
	make_background();
	al_destroy_bitmap(background);
	make_menu();
	al_draw_scaled_bitmap(menu,0,0,800,500,0,0,800,500,0);
	al_destroy_bitmap(menu);
	make_hero(hero_);
	cria_monstros_estruturas();
	al_flip_display();
	FLOOR = SUPER_GROUND;
	estado = SERVINDO;
}
//Estado principal de gameplay
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

	hero_updown();
	//Atualiza floor
	UpdateFloor();
    //Imprime obstaculos
    write_obstacles();
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
	snprintf(fps_demo,25,"%0.f",fps);
	

	//Transforma o delta y/x em deslocamento
	delta_transform();
	if (stage == 0)
	{
		ALLEGRO_BITMAP *board_left = NULL;
		ALLEGRO_BITMAP *board_right = NULL;

		board_left = al_load_bitmap(BOA_LEFT);
		board_right = al_load_bitmap(BOA_RIGHT);

		al_draw_scaled_bitmap(board_left,0,0,70,70,150,GROUND-70,70,70,0);
		al_draw_scaled_bitmap(board_right,0,0,70,70,650,GROUND-70,70,70,0);

		al_destroy_bitmap(board_left);
		al_destroy_bitmap(board_right);
	}
    //Desenha o personagem controlavel
	draw_hero();
	//Checa Hit
	hit();
	al_draw_text(font, al_map_rgb(255, 104, 1), 700,10, 0,text);
	al_draw_text(font, al_map_rgb(255, 104, 1), 100,10, 0,posY);
	al_draw_text(font, al_map_rgb(255, 104, 1), 100,20, 0,posX);
	al_draw_text(font, al_map_rgb(255, 104, 1), 100,30, 0,chao);
	al_draw_text(font, al_map_rgb(255, 104, 1), 700,20, 0,estagio);
	//al_draw_text(font, al_map_rgb(255, 104, 1), 700,30, 0,fps_demo);
	



	al_flip_display();
}
//Estado de fechar o jogo em caso de perda
void state_close()
{
	playing = 1;
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
void show_scores()
{
	ALLEGRO_FONT* font;
	font = al_create_builtin_font();
	if(!font)
	{
    	fprintf(stderr, "Não foi possível iniciar a fonte");
	    exit(1);
	}
	al_clear_to_color(al_map_rgb(0, 0, 0));
	int offset = 10;
	for (int i = 0; i < cont_scores; i++)
	{
		al_draw_text(font, al_map_rgb(255, 104, 1), 400,10+offset, 0,h_score[i] -> nome);

		char score_ac[25];
		snprintf(score_ac,25,"%d", h_score[i] -> score);
		al_draw_text(font, al_map_rgb(255, 104, 1), 700,10+offset, 0,score_ac);
		offset+=20;
	}
	al_destroy_font(font);
	al_flip_display();
}








void recebe_user(ALLEGRO_FONT* font, ALLEGRO_USTR *name)
{
	char nome[100];
	us = malloc(100*sizeof(h_score));
    strcpy(nome, al_cstr(name));
    strcpy(us -> nome, nome);
    us -> score = PONTUACAO;

    char text[100] = "Digite seu nome: ";
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_map_rgb(255, 104, 1), 300,180, 0,text);
	al_draw_text(font, al_map_rgb(255, 104, 1), 300,250, 0,nome);
	al_flip_display();
}
void ler_file_scores()
{
	h_score = malloc(11*sizeof(h_score));
		for (int i = 0; i < 11; i++){
			h_score[i] = malloc(100*sizeof(h_score));
		}
	char c;
	FILE *file_score;
	file_score = fopen("scores","a+");
	while ((c = fgetc(file_score)) != EOF) 
	{
	  fseek(file_score,-1,SEEK_CUR);
	  fscanf(file_score, "%s %d", h_score[cont_scores] -> nome, &h_score[cont_scores] -> score);
	  cont_scores++;
	}


	fclose(file_score);
	//printf("%d\n",cont_scores );
}
int compare(const void *a, const void *b)
{
    const user_score *a1 = *(const user_score **)a;
    const user_score *b1 = *(const user_score **)b;
    if(a1 -> score > b1 -> score)
    	return -1;
    else if(a1 -> score < b1 -> score)
    	return 1;
    else
    	return 0;
}
void escreve_file_scores()
{
	if (cont_scores > 10)
		cont_scores = 10;
	h_score[cont_scores] -> score = us -> score;
	if (strcmp(us -> nome, "") == 0)
		strcpy(us -> nome, "undefined");
	
	strcpy(h_score[cont_scores] -> nome, us -> nome);
	cont_scores++;

	qsort(h_score,cont_scores,sizeof(h_score),compare);

	FILE *file_score;
	file_score = fopen("scores","w+");
	
	for (int i = 0; i < cont_scores; i++)
	{
	 	fprintf(file_score,"%s %d",h_score[i] -> nome,h_score[i] -> score);
	 	if (i < cont_scores-1)
	 		fprintf(file_score,"\n");
	}
	fclose(file_score);

	
}