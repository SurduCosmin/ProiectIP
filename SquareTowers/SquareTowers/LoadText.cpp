#include"LoadText.h"

SDL_Texture* loadFromRenderedText(string TextTitleureText, SDL_Color TextTitleColor)
{
	SDL_Surface* TextSurface = TTF_RenderText_Solid(Font, TextTitleureText.c_str(), TextTitleColor);
	SDL_Texture* newTexture = NULL;
	if (TextSurface == NULL)
		printf("Unable to render TextTitle surface! SDL_ttf Error: %s\n", TTF_GetError());
	else
	{
		newTexture = SDL_CreateTextureFromSurface(Renderer, TextSurface);
		if (newTexture == NULL)
			printf("Unable to create TextTitleure from rendered TextTitle! SDL Error: %s\n", SDL_GetError());

		SDL_FreeSurface(TextSurface);
	}
	return newTexture;
}