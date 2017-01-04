#include "Header.h"

#include "Init.h"
#include "LoadMedia.h"
#include "Close.h"

/*
Uint32 startTime=SDL_GetTicks();
Uint32 Time()
{
	return SDL_GetTicks() - startTime;
}*/
int main(int argc, char* args[])
{
	if (!init())
		printf("Failed to initialize!\n");
	else
		if (!loadMedia())
			printf("Failed to load media!\n");
		else
		{
			bool running = true;
			SDL_Event event;
			CurrentTexture = KeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
			while (running)
			{
				while (SDL_PollEvent(&event))
				{
					if ((event.type == SDL_QUIT) || (event.key.keysym.sym == SDLK_q) || (event.key.keysym.sym == SDLK_ESCAPE))
					{
						running = false;
						break;
					}
					if (event.type == SDL_KEYDOWN)
						switch (event.key.keysym.sym)
						{
							case SDLK_w:
							case SDLK_UP:
								CurrentTexture = KeyPressSurfaces[KEY_PRESS_SURFACE_UP];
								break;
							case SDLK_s:
							case SDLK_DOWN:
								CurrentTexture = KeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
								break;

							case SDLK_a:
							case SDLK_LEFT:
								CurrentTexture = KeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
								break;

							case SDLK_d:
							case SDLK_RIGHT:
								CurrentTexture = KeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
								break;

							default:
								CurrentTexture = KeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
								break;
						} 
					
				}

				SDL_RenderClear(Renderer);
				SDL_RenderSetViewport(Renderer, 0);
				SDL_RenderCopy(Renderer, Screen, 0, 0);

				SDL_RenderCopy(Renderer, CurrentTexture, 0, &fillRect);

				SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0x00, 0xFF);
				for (int i = 0; i < 5; i++)
				{
					SDL_RenderDrawLine(Renderer, SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6 + SCREEN_HEIGHT / 6 * i, SCREEN_WIDTH * 5 / 6, SCREEN_HEIGHT / 6 + SCREEN_HEIGHT / 6 * i);
					SDL_RenderDrawLine(Renderer, SCREEN_WIDTH / 6+SCREEN_WIDTH/6*i, SCREEN_HEIGHT / 6, SCREEN_WIDTH / 6 + SCREEN_WIDTH / 6 * i, SCREEN_HEIGHT * 5 / 6);
				}
				
			
				SDL_RenderSetViewport(Renderer, 0);
			
				//gBackgroundTexture.render(0, 0);

				//Render Foo' to the screen
				gFooTexture.render(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

				SDL_RenderPresent(Renderer);
			}
	}

	Close();

	return 0;
}