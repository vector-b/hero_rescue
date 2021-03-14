#include <stdio.h>
#include "hero_class.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_ttf.h"

#ifndef __VAR__
#define __VAR__

#define FONT_PIX		"fonts/pixeboy.ttf"
//Imagens de Fundo
#define BACKGROUND_FILE "img/bg002.bmp"
#define BRIDGE 			"img/bridge.bmp"
#define BRIDGE_STAGE	"img/stage_3/back_stage_3.bmp"
#define END_GAME_IMAGE 	"img/end_game.png"
#define GAME_MENU 		"img/hero_adventure.png"
#define BOA_RIGHT 		"img/death.png"
#define BOA_LEFT        "img/safety.png"
#define HELP_IMAGE		"img/help.png"
#define HOUSE			"img/house_2.png"

#define HERO_FILE 		"img/hero.png"
#define RUN_RIGHT 		"img/run_right.png"
#define RUN_LEFT 		"img/run_left.png"
#define H_LEFT 			"img/hero_left.png"

#define STREET_FOLDER	"img/sf_png/"
#define OBJ_FOLDER 		"img/objects/"
#define MOB_IMAGE		"img/mob/"
#define MOB_IMAGE_RIGHT	"img/mob_right/"
#define MOB_FLY			"img/fly/"
#define MOB_FLY_RIGHT	"img/fly_right/"
#define GHOST			"img/ghost/"
#define GHOST_RIGHT		"img/ghost_right/"
#define MINOTAUR 		"img/minotaur/"
#define MINOTAUR_RIGHT	"img/minotaur_right/"
#define GHOST_RIGHT		"img/ghost_right/"
#define MOB_BAT			"img/bat/"
#define FLOOR_STG3		"img/stage_3/floor_bridge.png"

#define RUNNING_LEFT	"img/hero_left/running/"
#define RUNNING_RIGHT	"img/hero/running/"
#define JUMP_LEFT		"img/hero_left/jump/"
#define JUMP			"img/hero/jump/"
#define FALL_LEFT		"img/hero_left/fall/"
#define FALL			"img/hero/fall/"

#define HERO_IMAGE		"img/hero/"
#define HERO_IMAGE_LEFT	"img/hero_left/"

#define SUPER_GROUND 435

#define CONSTANTE_X 10
#define CONSTANTE_Y 160
#define CONSTANTE_G 10
#define MAX_WIDTH 1600;
#define NUM_OBS 11
#define NUM_MON 8 
#define NUM_STAIRS 1


int conta_background = 0;
int checa_wp = 0;
int OVO = 0;
int GROUND = 435;
int PONTUACAO = 0;
int cont_saltos = 0; 
int jumping = 0;
int running = 1;
int playing = 0;
int checa_sprite = 0;
int num_sprite = 0;
int checa_sprite_hero =0;
int num_sprite_hero = 1;
int old_dx;
int old_dy;
int last_right = 1;
int stage = 3;
int cont_scores = 0;


int FLOOR;


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
ALLEGRO_BITMAP *mob_3			= NULL;
ALLEGRO_BITMAP *mob_4			= NULL;
ALLEGRO_BITMAP *mob_5			= NULL;
ALLEGRO_BITMAP *house 			= NULL;


ALLEGRO_BITMAP *stand 			= NULL;
ALLEGRO_SAMPLE *background_sound;
ALLEGRO_SAMPLE *ipanema			= NULL;
ALLEGRO_SAMPLE *som_pulo 		= NULL;
ALLEGRO_SAMPLE *kill_sound		= NULL;
ALLEGRO_SAMPLE *death_sound		= NULL;

ALLEGRO_FONT* title_font		= NULL;
ALLEGRO_FONT* score_font		= NULL;
ALLEGRO_FONT* name_font			= NULL;

hero 	*hero_     				= NULL;
obs 	**obstacles 			= NULL;
monster **monsters 				= NULL;
plat 	**stairs 				= NULL;
user_score **h_score			= NULL;
user_score *us   				= NULL;


#endif