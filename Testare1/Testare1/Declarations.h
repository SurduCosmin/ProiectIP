#pragma once
#ifndef _DECLARATIONS_H_
#define _DECLARATIONS_H_
#endif
#include"Header.h"
using namespace std;

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 660;
enum KeyPressSurfs
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

SDL_Window* Window = NULL;

SDL_Renderer* Renderer = NULL;

SDL_Rect stretchRect = { SCREEN_WIDTH / 2 - 50,SCREEN_HEIGHT / 2,SCREEN_WIDTH / 4,SCREEN_HEIGHT / 4 };
SDL_Rect fillRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };

SDL_Rect topLeftViewport = { 0,0,SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 };
SDL_Rect topRightViewport = { SCREEN_WIDTH / 2,0,SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 };
SDL_Rect buttomViewport = { 0,SCREEN_HEIGHT / 2,SCREEN_WIDTH,SCREEN_HEIGHT / 2 };


SDL_Texture* Texture = NULL;
SDL_Texture* KeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
SDL_Texture* Screen = NULL;
SDL_Texture* CurrentTexture = NULL;

class LTexture
{
public:
	LTexture();

	~LTexture();

	bool loadFromFile(std::string path);

	void free();

	void render(int x, int y);

	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
}gFooTexture, gBackgroundTexture;


LTexture::LTexture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	free();
}

bool LTexture::loadFromFile(string file)
{
	free();
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(file.c_str());
	if (loadedSurface == NULL)
		printf("Unable to load image %s! SDL_image Error: %s\n", file.c_str(), IMG_GetError());
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		newTexture = SDL_CreateTextureFromSurface(Renderer, loadedSurface);
		if (newTexture == NULL)
			printf("Unable to create texture from %s! SDL Error: %s\n", file.c_str(), SDL_GetError());
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free()
{
	if (mTexture)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render(int x, int y)
{
	SDL_Rect renderQuad = { x,y,mWidth,mHeight };
	SDL_RenderCopy(Renderer, mTexture, 0, &renderQuad);
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}