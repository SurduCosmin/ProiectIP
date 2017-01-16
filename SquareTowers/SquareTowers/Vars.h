#pragma once
#include<random>
#include<time.h>
#include"SDL_header.h"
#include"Structures.h"
#define MAX_TOWER_ALLOWED 4
#define MAX_PATTERN 4

extern  int SCREEN_WIDTH;
extern  int SCREEN_HEIGHT;
extern  int frame;
extern bool Running, Running2;
extern bool flagMainStart;
extern bool Clip;

extern default_random_engine generator;//For debugging
//std::default_random_engine generator(time(0));
extern uniform_int_distribution<int> Color;
extern uniform_int_distribution<int> Value;

extern SDL_Window* Window;

extern SDL_Renderer* Renderer;

extern SDL_Color textColor[10];
extern SDL_Color textTitles[2];

extern TTF_Font *Font;

extern SDL_Texture* Background;
extern SDL_Texture* MainTitle[10];
extern SDL_Texture* MainStart[2];
extern SDL_Texture* MainHighscores[2];
extern SDL_Texture* MainQuitGame[2];
extern SDL_Texture* MainStartSingleplayer[2];
extern SDL_Texture* MainStartMultiplayer[2];
extern SDL_Texture* ArrowPointer;
extern SDL_Texture* Table;
extern SDL_Texture* Towers[4][16];
extern SDL_Texture* TableBackground;


extern SDL_Rect TextTitle;
extern SDL_Rect TextStart;
extern SDL_Rect TextHighscores;
extern SDL_Rect TextQuitGame;
extern SDL_Rect TextArrow[2];
extern SDL_Rect TextSMPlayer[2];
extern SDL_Rect SpriteClips[16];
extern SDL_Rect Test;
extern SDL_Rect TableRect;

extern Uint32 startTime ;
extern Uint32 Time();

enum ButtonMouse
{
	BUTTON_MOUSE_OUT = 0,
	BUTTON_MOUSE_OVER_MOTION = 1,
	BUTTON_MOUSE_DOWN = 2,
	BUTTON_MOUSE_UP = 3,
	BUTTON_TOTAL = 4
};

extern ButtonMouse action;

