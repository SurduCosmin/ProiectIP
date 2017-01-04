#pragma once
#ifndef _LOAD_TEXTURE_H_
#define _LOAD_TEXTURE_H_
#endif
#include"Declarations.h"

SDL_Texture* loadTexture(string file)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(file.c_str());
	if (loadedSurface == NULL)
		printf("Unable to load image %s! SDL_image Error: %s\n", file.c_str(), IMG_GetError());
	else
	{
		newTexture = SDL_CreateTextureFromSurface(Renderer, loadedSurface);
		if (newTexture == NULL)
			printf("Unable to create texture from %s! SDL Error: %s\n", file.c_str(), SDL_GetError());
	}
	SDL_FreeSurface(loadedSurface);

	return newTexture;
}