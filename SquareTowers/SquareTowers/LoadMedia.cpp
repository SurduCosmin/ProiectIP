#include"LoadMedia.h"	


bool loadMedia() 
{
	Background = loadTexture("Images/lumber.png");
	if (Background == NULL)
	{
		printf("Failed to load surface image!\n");
		return false;
	}
	Font = TTF_OpenFont("Fonts/FTSCanblDemo.ttf", 48);
	if (Font == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}
	
	

	for (int i = 0; i < 10; i++)
	{
		MainTitle[i] = loadFromRenderedText("SQUARE TOWERS", textColor[i]);
		if (!MainTitle[i])
		{
			printf("Failed to render text texture!\n");
			return false;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		MainStart[i] = loadFromRenderedText("START GAME", textTitles[i]);
		MainHighscores[i] = loadFromRenderedText("HIGHSCORES", textTitles[i]);
		MainQuitGame[i] = loadFromRenderedText("QUIT GAME", textTitles[i]);
		MainStartSingleplayer[i] = loadFromRenderedText("SINGLEPLAYER", textTitles[i]);
		MainStartMultiplayer[i] = loadFromRenderedText("MULTIPLAYER", textTitles[i]);

		if ((!MainStart[i])|| (!MainHighscores[i])|| (!MainQuitGame	[i])|| (!MainStartSingleplayer[i])|| (!MainStartMultiplayer[i]))
		{
			printf("Failed to render text menu texture!\n");
			return false;
		}
		if (i > 0)continue;
		
		ArrowPointer = loadFromRenderedText("-", textTitles[0]);
		if (!ArrowPointer)
		{
			printf("Failed to render text menu arrow texture!%s\n",IMG_GetError());
			return false;
		}


	}
	return true;
}
