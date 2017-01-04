#pragma once
#ifndef _LOAD_MEDIA_H_
#define _LOAD_MEDIA_H_
#endif
#include"Declarations.h"
#include"LoadTexture.h"
bool loadMedia()
{
	KeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadTexture("Images/press.bmp");
	if (KeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
	{
		printf("Failed to load default image!\n");
		return false;
	}

	KeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadTexture("Images/up.bmp");
	if (KeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
	{
		printf("Failed to load up image!\n");
		return false;
	}

	KeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadTexture("Images/down.bmp");
	if (KeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
	{
		printf("Failed to load down image!\n");
		return false;
	}

	KeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadTexture("Images/left.bmp");
	if (KeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL)
	{
		printf("Failed to load left image!\n");
		return false;
	}

	KeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadTexture("Images/right.bmp");
	if (KeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL)
	{
		printf("Failed to load right image!\n");
		return false;
	}

	Screen = loadTexture("Images/lumber.png");
	if (Screen == NULL)
	{
		printf("Failed to load surface image!\n");
		return false;
	}

	Texture = loadTexture("Images/texture.png");
	if (Texture == NULL)
	{
		printf("Failed to load texture image!\n");
		return false;
	}
	
	//Load Foo' texture
	if (!gFooTexture.loadFromFile("Images/foo.png"))
	{
		printf("Failed to load Foo' texture image!\n");
		return false;
	}
	//Load background texture
	if (!gBackgroundTexture.loadFromFile("Images/background.png"))
	{
		printf("Failed to load background texture image!\n");
		return false;
	}
	return true;
}