#include"Menu.h"
void MainMenu(SDL_Event mainEvent)
{
	int flag[5] = { 0 };
	int frame = 0;
	MouseTarget(mainEvent, TextStart);
	{
		if (action == BUTTON_MOUSE_OVER_MOTION)
			flag[0] = 1;
		else
			flag[0] = 0;
		if (action == BUTTON_MOUSE_UP)
		{
			MenuAuxiliar[0] = MainStart[0];
			MainStart[0]= MainStart[1];
			flagMainStart = 1;
		}
		MouseTarget(mainEvent, TextSMPlayer[0]);
		{
			if (action == BUTTON_MOUSE_OVER_MOTION)
				flag[3] = 1;
			else
				flag[3] = 0;
			if (action == BUTTON_MOUSE_UP)
			{
				MenuAuxiliar[3] = MainStartSingleplayer[0];
				MainStartSingleplayer[0] = MainStartSingleplayer[1];
				//Here will be the singleplayer
			}
		}
		MouseTarget(mainEvent, TextSMPlayer[1]);
		{
			if (action == BUTTON_MOUSE_OVER_MOTION)
				flag[4] = 1;
			else
				flag[4] = 0;
			if (action == BUTTON_MOUSE_UP)
			{
				MenuAuxiliar[4] = MainStartMultiplayer[0];
				MainStartMultiplayer[0] = MainStartMultiplayer[1];
				//Here will be the multiplayer
			}
		}
	}
	MouseTarget(mainEvent, TextHighscores);
	{
		if (action == BUTTON_MOUSE_OVER_MOTION)
			flag[1] = 1;
		else
			flag[1] = 0;
		if (action == BUTTON_MOUSE_UP)
		{
			MenuAuxiliar[1] = MainHighscores[0];
			MainHighscores[0] = MainHighscores[1];
			//Here will be the highscore
		}
	}
	MouseTarget(mainEvent, TextQuitGame);
	{
		if (action == BUTTON_MOUSE_OVER_MOTION)
			flag[2] = 1;
		else
			flag[2] = 0;
		if (action == BUTTON_MOUSE_UP)
		{
			MenuAuxiliar[2] = MainQuitGame[0];
			MainQuitGame[0] = MainQuitGame[1];
			Running = false;
		}
	}

	SDL_RenderClear(Renderer);

	SDL_RenderCopy(Renderer, Background, 0, 0);
	SDL_RenderCopy(Renderer, MainTitle[frame / 10], 0, &TextTitle);
	SDL_RenderCopy(Renderer, MainStart[flag[0]], 0, &TextStart);
	SDL_RenderCopy(Renderer, MainHighscores[flag[1]], 0, &TextHighscores);
	SDL_RenderCopy(Renderer, MainQuitGame[flag[2]], 0, &TextQuitGame);
	if (flagMainStart)
	{
		SDL_RenderCopy(Renderer, ArrowPointer, 0, &TextArrow[0]);
		SDL_RenderCopy(Renderer, ArrowPointer, 0, &TextArrow[1]);
		SDL_RenderCopy(Renderer, MainStartSingleplayer[flag[3]], 0, &TextSMPlayer[0]);
		SDL_RenderCopy(Renderer, MainStartMultiplayer[flag[4]], 0, &TextSMPlayer[1]);
	}
	SDL_RenderPresent(Renderer);
	++frame;
	if (frame / 10 >= 10)
		frame = 0;
}
void ResetMenu()
{
	/*int frame = 0;

	MainStart[0]=MenuAuxiliar[0] ;
	MainHighscores[0]=MenuAuxiliar[1];
	MainQuitGame[0]=MenuAuxiliar[2];
	MainStartSingleplayer[0] = MenuAuxiliar[3];
	MainStartMultiplayer[0]= MenuAuxiliar[4];

	SDL_RenderClear(Renderer);

	SDL_RenderCopy(Renderer, Background, 0, 0);
	SDL_RenderCopy(Renderer, MainTitle[0], 0, &TextTitle);
	SDL_RenderCopy(Renderer, MainStart[0], 0, &TextStart);
	SDL_RenderCopy(Renderer, MainHighscores[0], 0, &TextHighscores);
	SDL_RenderCopy(Renderer, MainQuitGame[0], 0, &TextQuitGame);
	if (flagMainStart)
	{
		SDL_RenderCopy(Renderer, ArrowPointer, 0, &TextArrow[0]);
		SDL_RenderCopy(Renderer, ArrowPointer, 0, &TextArrow[1]);
		SDL_RenderCopy(Renderer, MainStartSingleplayer[0], 0, &TextSMPlayer[0]);
		SDL_RenderCopy(Renderer, MainStartMultiplayer[0], 0, &TextSMPlayer[1]);
	}
	SDL_RenderPresent(Renderer);
	++frame;
	if (frame / 10 >= 10)
		frame = 0;*/

	flagMainStart = 0;
	MainStart[0] = loadFromRenderedText("START GAME", textTitles[0]);
	MainHighscores[0] = loadFromRenderedText("HIGHSCORES", textTitles[0]);
	MainQuitGame[0] = loadFromRenderedText("QUIT GAME", textTitles[0]);
	MainStartSingleplayer[0] = loadFromRenderedText("SINGLEPLAYER", textTitles[0]);
	MainStartMultiplayer[0] = loadFromRenderedText("MULTIPLAYER", textTitles[0]);
}
