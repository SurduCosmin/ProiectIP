#include"SDL_header.h"
#include<iostream>

#include"functions.h"
#include"Close.h"
#include"Init.h"
#include"LoadMedia.h"
#include"Mouse.h"
#include"Menu.h"


int main(int argc,char* argv[]) 
{
	
	if (!Init())
		printf("Failed to initialize!\n");
	else if (!loadMedia())
		printf("Failed to load media!\n");
	else
	{
		SDL_Event mainEvent;
		while (Running)
		{
			while (SDL_PollEvent(&mainEvent))
			{
				if (mainEvent.type == SDL_QUIT)  
					Running = false;
				MainMenu(mainEvent);
				if (mainEvent.key.keysym.sym == SDLK_ESCAPE)
				{
					ResetMenu(); MainMenu(mainEvent);
				}
			
			
			
				
				
			}	
		}
	}

	Close();

	fillTable(gameTable);
	for (int i = 0; i < TABLE_LENGTH; ++i) {
		for (int j = 0; j < TABLE_LENGTH; ++j) {
			cout << gameTable[i][j].base->currentSquare.color << '-';
			cout << gameTable[i][j].base->currentSquare.value << '%';
			cout << gameTable[i][j].numberOfLevels << "     ";
		}
		cout << "\n\n\n";
	}

	position a, b;
	a.x = 0;
	a.y = 0;
	b.x = 0;
	b.y = 1;
	moveTower(a, b);
	moveTower(b, a);
	b.y = 3;
	moveTower(b, a);
	moveTower(a, b);
	a.y = 2;
	moveTower(b, a);
	cout << "tabla modificata" << endl;
	for (int i = 0; i < TABLE_LENGTH; ++i) {
		for (int j = 0; j < TABLE_LENGTH; ++j) {
			cout << gameTable[i][j].base->currentSquare.color << '-';
			cout << gameTable[i][j].base->currentSquare.value << '%';
			cout << gameTable[i][j].numberOfLevels << "     ";
		}
		cout << "\n\n\n";
	}

	//system("pause");
	return 0;
}
