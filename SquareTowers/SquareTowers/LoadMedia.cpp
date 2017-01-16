#include"LoadMedia.h"	


bool loadMedia() 
{
	Font = TTF_OpenFont("Fonts/FTSCanblDemo.ttf", 48);
	if (Font == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}
	//menu
	Background = loadTexture("Images/lumber.png");
	if (Background == NULL)
	{
		printf("Failed to load surface image!\n");
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

		if ((!MainStart[i]) || (!MainHighscores[i]) || (!MainQuitGame[i]) || (!MainStartSingleplayer[i]) || (!MainStartMultiplayer[i]))
		{
			printf("Failed to render text menu texture!\n");
			return false;
		}
		if (i > 0)continue;

		ArrowPointer = loadFromRenderedText("-", textTitles[0]);
		if (!ArrowPointer)
		{
			printf("Failed to render text menu arrow texture!%s\n", IMG_GetError());
			return false;
		}
	}
	//~menu

	TableBackground = loadTexture("Images/cubes2.png");
	if (TableBackground == NULL)
	{
		printf("Failed to load TableBackground image!\n");
		return false;
	}

	Table = loadTexture("Images/PatternV2.png");
	if (Table == NULL)
	{
		printf("Failed to load surface image!\n");
		return false;
	}
	//Towers
	{
		Towers[0][0] = loadTexture("Images/Towers/B1.png");
		Towers[0][1] = loadTexture("Images/Towers/B2.png");
		Towers[0][2] = loadTexture("Images/Towers/B3.png");
		Towers[0][3] = loadTexture("Images/Towers/B4.png");
		Towers[0][4] = loadTexture("Images/Towers/B5.png");
		Towers[0][5] = loadTexture("Images/Towers/B6.png");
		Towers[0][6] = loadTexture("Images/Towers/B7.png");
		Towers[0][7] = loadTexture("Images/Towers/B8.png");
		Towers[0][8] = loadTexture("Images/Towers/B9.png");
		Towers[0][9] = loadTexture("Images/Towers/B10.png");
		Towers[0][10] = loadTexture("Images/Towers/B11.png");
		Towers[0][11] = loadTexture("Images/Towers/B12.png");
		Towers[0][12] = loadTexture("Images/Towers/B13.png");
		Towers[0][13] = loadTexture("Images/Towers/B14.png");
		Towers[0][14] = loadTexture("Images/Towers/B15.png");
		Towers[0][15] = loadTexture("Images/Towers/B16.png");


		Towers[1][0] = loadTexture("Images/Towers/G1.png");
		Towers[1][1] = loadTexture("Images/Towers/G2.png");
		Towers[1][2] = loadTexture("Images/Towers/G3.png");
		Towers[1][3] = loadTexture("Images/Towers/G4.png");
		Towers[1][4] = loadTexture("Images/Towers/G5.png");
		Towers[1][5] = loadTexture("Images/Towers/G6.png");
		Towers[1][6] = loadTexture("Images/Towers/G7.png");
		Towers[1][7] = loadTexture("Images/Towers/G8.png");
		Towers[1][8] = loadTexture("Images/Towers/G9.png");
		Towers[1][9] = loadTexture("Images/Towers/G10.png");
		Towers[1][10] = loadTexture("Images/Towers/G11.png");
		Towers[1][11] = loadTexture("Images/Towers/G12.png");
		Towers[1][12] = loadTexture("Images/Towers/G13.png");
		Towers[1][13] = loadTexture("Images/Towers/G14.png");
		Towers[1][14] = loadTexture("Images/Towers/G15.png");
		Towers[1][15] = loadTexture("Images/Towers/G16.png");

		Towers[2][0] = loadTexture("Images/Towers/R1.png");
		Towers[1][1] = loadTexture("Images/Towers/R2.png");
		Towers[2][2] = loadTexture("Images/Towers/R3.png");
		Towers[2][3] = loadTexture("Images/Towers/R4.png");
		Towers[2][4] = loadTexture("Images/Towers/R5.png");
		Towers[2][5] = loadTexture("Images/Towers/R6.png");
		Towers[2][6] = loadTexture("Images/Towers/R7.png");
		Towers[2][7] = loadTexture("Images/Towers/R8.png");
		Towers[2][8] = loadTexture("Images/Towers/R9.png");
		Towers[2][9] = loadTexture("Images/Towers/R10.png");
		Towers[2][10] = loadTexture("Images/Towers/R11.png");
		Towers[2][11] = loadTexture("Images/Towers/R12.png");
		Towers[2][12] = loadTexture("Images/Towers/R13.png");
		Towers[2][13] = loadTexture("Images/Towers/R14.png");
		Towers[2][14] = loadTexture("Images/Towers/R15.png");
		Towers[2][15] = loadTexture("Images/Towers/R16.png");

		Towers[3][0] = loadTexture("Images/Towers/Y1.png");
		Towers[1][1] = loadTexture("Images/Towers/Y2.png");
		Towers[3][2] = loadTexture("Images/Towers/Y3.png");
		Towers[3][3] = loadTexture("Images/Towers/Y4.png");
		Towers[3][4] = loadTexture("Images/Towers/Y5.png");
		Towers[3][5] = loadTexture("Images/Towers/Y6.png");
		Towers[3][6] = loadTexture("Images/Towers/Y7.png");
		Towers[3][7] = loadTexture("Images/Towers/Y8.png");
		Towers[3][8] = loadTexture("Images/Towers/Y9.png");
		Towers[3][9] = loadTexture("Images/Towers/Y10.png");
		Towers[3][10] = loadTexture("Images/Towers/Y11.png");
		Towers[3][11] = loadTexture("Images/Towers/Y12.png");
		Towers[3][12] = loadTexture("Images/Towers/Y13.png");
		Towers[3][13] = loadTexture("Images/Towers/Y14.png");
		Towers[3][14] = loadTexture("Images/Towers/Y15.png");
		Towers[3][15] = loadTexture("Images/Towers/Y16.png");

	}
	//~Towers
	return true;
}

