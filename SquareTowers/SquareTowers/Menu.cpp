#include"Menu.h"
void MainMenu(SDL_Event mainEvent)
{
	int flag[5] = { 0 }; 
	MouseTarget(mainEvent, TextStart);
	{
		if (action == BUTTON_MOUSE_OVER_MOTION)
			flag[0] = 1;
		else
			flag[0] = 0;
		if (action == BUTTON_MOUSE_UP)
		{
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
				MainStartSingleplayer[0] = MainStartSingleplayer[1];
				CloseMenu();
				Running2 = true;
				
			//	ClipsInit(8, 3);
				SDL_RenderClear(Renderer);
				SDL_RenderPresent(Renderer);
				Singleplayer();

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
			MainQuitGame[0] = MainQuitGame[1];
			Running = false;
		}
	}
	SDL_RenderClear(Renderer);
	SDL_RenderCopy(Renderer, Background, 0, 0);
	SDL_RenderCopy(Renderer, MainTitle[frame /10], 0, &TextTitle);
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
	flagMainStart = 0;
	Background = loadTexture("Images/lumber.png");
	for (int i = 0; i < 10; i++)
	{
		MainTitle[i] = loadFromRenderedText("SQUARE TOWERS", textColor[i]);
		if (i > 1)continue;
		MainStart[i] = loadFromRenderedText("START GAME", textTitles[i]);
		MainHighscores[i] = loadFromRenderedText("HIGHSCORES", textTitles[i]);
		MainQuitGame[i] = loadFromRenderedText("QUIT GAME", textTitles[i]);
		MainStartSingleplayer[i] = loadFromRenderedText("SINGLEPLAYER", textTitles[i]);
		MainStartMultiplayer[i] = loadFromRenderedText("MULTIPLAYER", textTitles[i]);
		if (i > 0)continue;
		ArrowPointer = loadFromRenderedText("-", textTitles[0]);
		
	}
}