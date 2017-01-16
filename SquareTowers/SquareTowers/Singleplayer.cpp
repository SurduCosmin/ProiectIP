#include"Singleplayer.h"
void Singleplayer( )
{
	while (Running2) {
		SDL_Event event;
		
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				Running =Running2= false;
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				Running2 = false;
				return;
			}
		}
	//	SDL_Delay(1000);
		{
			SDL_RenderCopy(Renderer, TableBackground, 0, 0);
			SDL_RenderCopy(Renderer, Table, 0, &TableRect);
		//	int i = 0, j = 0;
			if (Clip)
			{
				Clipping();
				Clip = false;

			}
			SDL_RenderCopy(Renderer, Towers[0][15], 0, &SpriteClips[0]);
			SDL_RenderCopy(Renderer, Towers[2][4], 0, &SpriteClips[1]);
			SDL_RenderCopy(Renderer, Towers[1][12], 0, &SpriteClips[2]);
			SDL_RenderCopy(Renderer, Towers[0][0], 0, &SpriteClips[3]);
			SDL_RenderCopy(Renderer, Towers[3][6], 0, &SpriteClips[4]);
			SDL_RenderCopy(Renderer, Towers[3][5], 0, &SpriteClips[5]);
			SDL_RenderCopy(Renderer, Towers[1][2], 0, &SpriteClips[6]);
			SDL_RenderCopy(Renderer, Towers[0][3], 0, &SpriteClips[7]);
			SDL_RenderCopy(Renderer, Towers[2][8], 0, &SpriteClips[8]);
			SDL_RenderCopy(Renderer, Towers[2][9], 0, &SpriteClips[9]);
			SDL_RenderCopy(Renderer, Towers[0][8], 0, &SpriteClips[10]);
			SDL_RenderCopy(Renderer, Towers[2][15], 0, &SpriteClips[11]);
			SDL_RenderCopy(Renderer, Towers[1][4], 0, &SpriteClips[12]);
			SDL_RenderCopy(Renderer, Towers[3][2], 0, &SpriteClips[13]);
			SDL_RenderCopy(Renderer, Towers[3][0], 0, &SpriteClips[14]);
			SDL_RenderCopy(Renderer, Towers[0][0], 0, &SpriteClips[15]);


			SDL_RenderPresent(Renderer);
		}
	}
}
