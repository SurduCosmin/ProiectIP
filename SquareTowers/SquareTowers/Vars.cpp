#include"Vars.h"
#include<SDL.h>

int SCREEN_WIDTH= 1280;
int SCREEN_HEIGHT = 720;

bool Running = true;
bool flagMainStart = 0;
SDL_Window* Window = NULL;

SDL_Renderer* Renderer = NULL;

SDL_Rect TextTitle = { SCREEN_WIDTH / 2 - 175,50,350,125};
SDL_Rect TextStart = { SCREEN_WIDTH / 6,SCREEN_HEIGHT /4,225,75 };
SDL_Rect TextHighscores= { SCREEN_WIDTH / 6,SCREEN_HEIGHT *2/ 4,225,75 };
SDL_Rect TextQuitGame= { SCREEN_WIDTH / 6,SCREEN_HEIGHT *3/ 4,225,75 };
SDL_Rect TextArrow[2] = { SCREEN_WIDTH / 6+300,170,75,100 ,SCREEN_WIDTH / 6 + 300,SCREEN_HEIGHT / 5+125,75,100 };
SDL_Rect TextSMPlayer[2] = { SCREEN_WIDTH / 6 + 400,SCREEN_HEIGHT / 4,225,75 ,SCREEN_WIDTH / 6 + 400,SCREEN_HEIGHT / 5 + 135,225,75 };


SDL_Texture* MainTitle[10] = { NULL };
SDL_Texture* MainStart[2] = { NULL };
SDL_Texture* MainStartSingleplayer[2] = { NULL };
SDL_Texture* MainStartMultiplayer[2] = { NULL };
SDL_Texture* MainHighscores[2] = { NULL };
SDL_Texture* MainQuitGame[2] = { NULL };
SDL_Texture* ArrowPointer = NULL;
SDL_Texture* MenuAuxiliar[5] = { NULL };//{ MainStart[0],MainHighscores[0],MainQuitGame[0],MainStartSingleplayer[0],MainStartMultiplayer[0]};

SDL_Texture* Background = NULL;
TTF_Font *Font = NULL;

SDL_Color textColor[10] = { 255, 204, 0 ,255,255, 204, 0 ,255,255, 204, 0 ,255,255, 209, 26 ,255,255, 214, 51 ,255,255, 219, 77 ,255,255, 219, 77 ,255,255, 214, 51 ,255,255, 209, 26 ,255,255, 204, 0 ,255 };
SDL_Color textTitles[2] = { 255, 204, 0 ,255 ,255,0,0,255 };

std::default_random_engine generator;//For debugging
									 //std::default_random_engine generator(time(0));
std::uniform_int_distribution<int> Color(1, 4);
std::uniform_int_distribution<int> Value(1, 16);

tower gameTable[TABLE_LENGTH][TABLE_LENGTH];

ButtonMouse action;