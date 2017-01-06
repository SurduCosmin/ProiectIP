#include"SDL_header.h"
#include"Close.h"
void Close()
{
	SDL_DestroyWindow(Window);
	Window = NULL;
	SDL_DestroyRenderer(Renderer);
	Renderer = NULL;
	SDL_DestroyTexture(Background);
	Background = NULL;
	SDL_DestroyTexture(ArrowPointer);
	ArrowPointer = NULL;
	TTF_CloseFont(Font);
	Font = NULL;
	for (int i = 0; i < 10; i++)
	{
		SDL_DestroyTexture(MainTitle[i]);
		MainTitle[i] = NULL;
		if (i > 5) continue;
		SDL_DestroyTexture(MenuAuxiliar[i]);
		MenuAuxiliar[i] = NULL;
		if (i > 1)continue;
		SDL_DestroyTexture(MainStart[i]);
		SDL_DestroyTexture (MainHighscores[i]);
		SDL_DestroyTexture (MainQuitGame[i]);
		SDL_DestroyTexture (MainStartSingleplayer[i]);
		SDL_DestroyTexture (MainStartMultiplayer[i]);
		MainStart[i] = NULL;
		MainStartSingleplayer[i] = NULL;
		MainStartMultiplayer[i] = NULL;
		MainHighscores[i] = NULL;
		MainQuitGame[i] = NULL;
	}

	IMG_Quit();
	SDL_Quit();
}