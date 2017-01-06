#pragma once
#include"Structures.h"
// Functii Queue ( Turn )
extern long long totalScore;
extern int obtainedArray[MAX_PATTERN];
extern int patternArray[MAX_PATTERN];

bool empty(tower current);

void pushToQueue(tower &current, square addedSquare);
square popFromQueue(tower &current);

// Functiile pentru modificarea tabelei 

square generateSquare();

void fillTable();

void moveTower(position source, position destination);

bool checkPoint(tower currentTower);

void addPoints(square currentSquare);

void reduceTower(tower &currentTower);

void generatePattern(int patternArray[]);

bool checkPattern(int patternArray[], int obtainedArray[]);




