#include"Vars.h"
#include<SDL.h>

int SCREEN_WIDTH= 1280;
int SCREEN_HEIGHT = 720;

bool Running = true;
bool Running2 = true;
bool Clip = true;

bool flagMainStart = 0;
int frame = 0;

SDL_Window* Window = NULL;

SDL_Renderer* Renderer = NULL;

SDL_Rect TextTitle = { SCREEN_WIDTH / 2 - 175,50,350,125};
SDL_Rect TextStart = { SCREEN_WIDTH / 6,SCREEN_HEIGHT /4,225,75 };
SDL_Rect TextHighscores= { SCREEN_WIDTH / 6,SCREEN_HEIGHT *2/ 4,225,75 };
SDL_Rect TextQuitGame= { SCREEN_WIDTH / 6,SCREEN_HEIGHT *3/ 4,225,75 };
SDL_Rect TextArrow[2] = { SCREEN_WIDTH / 6+300,170,75,100 ,SCREEN_WIDTH / 6 + 300,SCREEN_HEIGHT / 5+125,75,100 };
SDL_Rect TextSMPlayer[2] = { SCREEN_WIDTH / 6 + 400,SCREEN_HEIGHT / 4,225,75 ,SCREEN_WIDTH / 6 + 400,SCREEN_HEIGHT / 5 + 135,225,75 };
SDL_Rect TableRect = { 0,100,1366,768 };
SDL_Rect Test = { 120+12,440 - 33-7,300 / 4,227 / 4, };
SDL_Rect SpriteClips[16] = {
120,440 ,300/3,227/3,//0
305,340 ,300/3,227/3,//1
480,245 ,300/3,227/3,//2
660,150 ,300/3,227/3,//3
270,520 ,300/3,227/3,//4
445,420 ,300/3,227/3,//5
625,325 ,300/3,227/3,//6
795,225 ,300/3,227/3,//7
405,600 ,300/3,227/3,//8
590,500 ,300/3,227/3,//9
760,400 ,300/3,227/3,//10
940,305 ,300/3,227/3,//11
555,675 ,300/3,227/3,//12
725,575 ,300/3,227/3,//13
905,480 ,300/3,227/3,//14
1075,380 ,300/3,227/ 3 };//15


SDL_Texture* MainTitle[10] = { NULL };
SDL_Texture* MainStart[2] = { NULL };
SDL_Texture* MainStartSingleplayer[2] = { NULL };
SDL_Texture* MainStartMultiplayer[2] = { NULL };
SDL_Texture* MainHighscores[2] = { NULL };
SDL_Texture* MainQuitGame[2] = { NULL };
SDL_Texture* ArrowPointer = NULL;
SDL_Texture* Table = NULL;
SDL_Texture* Towers[4][16] = { NULL };
SDL_Texture* TableBackground = NULL;;

SDL_Texture* Background = NULL;
TTF_Font *Font = NULL;

SDL_Color textColor[10] = { 255, 204, 0 ,255,255, 204, 0 ,255,255, 204, 0 ,255,255, 209, 26 ,255,255, 214, 51 ,255,255, 219, 77 ,255,255, 219, 77 ,255,255, 214, 51 ,255,255, 209, 26 ,255,255, 204, 0 ,255 };
SDL_Color textTitles[2] = { 255, 204, 0 ,255 ,255,0,0,255 };

std::default_random_engine generator;//For debugging
									 //std::default_random_engine generator(time(0));
std::uniform_int_distribution<int> Color(1, 4);
std::uniform_int_distribution<int> Value(1, 16);

Uint32 startTime = SDL_GetTicks();
Uint32 Time()
{
	return SDL_GetTicks() - startTime;
}

tower gameTable[TABLE_LENGTH][TABLE_LENGTH];

ButtonMouse action;