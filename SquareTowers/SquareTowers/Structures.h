#pragma once
#include"Vars.h"
#define TABLE_LENGTH 4

struct square {
	int color;
	// 1-Albastru
	// 2-Verde
	// 3-Rosu 
	// 4-Galben
	int value;
};

struct level {
	square currentSquare;
	level *next = nullptr;
};

struct tower {
	int numberOfLevels;
	level *base;
	level *top;
};

struct position {
	// Pozitie din tabla de joc initiala de 4x4
	int x;
	int y;
};

extern tower gameTable[TABLE_LENGTH][TABLE_LENGTH];

struct player {
	char name[30];
	int totalScore = 0;
};

player scoreboard[11];