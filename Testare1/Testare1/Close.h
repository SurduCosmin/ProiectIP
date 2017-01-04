#pragma once
#ifndef _CLOSE_H_
#define _CLOSE_H_
#endif
#include"Declarations.h"
void Close()
{
	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i)
	{
		SDL_DestroyTexture(KeyPressSurfaces[i]);
		KeyPressSurfaces[i] = NULL;
	}
	SDL_DestroyTexture(Texture);
	Texture = NULL;
	SDL_DestroyTexture(Screen);
	Screen = NULL;
	SDL_DestroyTexture(CurrentTexture);
	CurrentTexture = NULL;

	SDL_DestroyRenderer(Renderer);
	gFooTexture.free();
	gBackgroundTexture.free();
	Renderer = NULL;

	SDL_DestroyWindow(Window);
	Window = NULL;

	IMG_Quit();
	SDL_Quit();
}