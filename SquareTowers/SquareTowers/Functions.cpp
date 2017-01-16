#include"Functions.h"
#include<iostream>

long long totalScore = 0;
int obtainedArray[MAX_PATTERN];
int patternArray[MAX_PATTERN];


bool empty(tower current) {
	return (current.base == NULL);
}

void pushToQueue(tower &current, square addedSquare) { // Adaugam sus, scoatem jos.
	if (empty(current)) {
		current.base = new level;
		current.base->currentSquare = addedSquare;
		current.top = current.base;
		current.numberOfLevels++;
		current.top->next = nullptr;

	}
	else {
		current.top->next = new level;
		current.top = current.top->next;
		current.top->currentSquare = addedSquare;
		current.numberOfLevels++;
		current.top->next = nullptr;
	}
}

square popFromQueue(tower &current) { // Scoatem de la baza. Adaugam la final.
	square auxilary = current.base->currentSquare;
	level *aux = current.base;
	current.base = current.base->next;
	delete(aux);
	current.numberOfLevels--;
	return auxilary;

}

// Functiile pentru modificarea tabelei 

square generateSquare() {
	square currentSquare;
	currentSquare.color = Color(generator);
	currentSquare.value = Value(generator);
	return currentSquare;
}

void fillTable(tower gameTable[MAX_PATTERN][MAX_PATTERN]) {
	for (int index = 0; index < TABLE_LENGTH; ++index) {
		for (int jndex = 0; jndex < TABLE_LENGTH; ++jndex) {
			gameTable[index][jndex].base = new level;
			gameTable[index][jndex].base->currentSquare = generateSquare();
			gameTable[index][jndex].top = gameTable[index][jndex].base;
			gameTable[index][jndex].numberOfLevels = 1;
			gameTable[index][jndex].top->next = nullptr;
		}
	}
	generatePattern(patternArray);
}

void moveTower(position source, position destination) {
	if (gameTable[source.x][source.y].base->currentSquare.value < gameTable[destination.x][destination.y].top->currentSquare.value)
	{
		while (!empty(gameTable[source.x][source.y])) {
			pushToQueue(gameTable[destination.x][destination.y],
				popFromQueue(gameTable[source.x][source.y]));
		}
		pushToQueue(gameTable[source.x][source.y], generateSquare());
		if (checkPoint(gameTable[destination.x][destination.y]))
			reduceTower(gameTable[destination.x][destination.y]);
	}
	else
		return;
}


bool checkPoint(tower currentTower) {
	return (currentTower.numberOfLevels >= MAX_TOWER_ALLOWED);
}

void addPoints(square currentSquare) {
	totalScore += currentSquare.value;
}

void reduceTower(tower &currentTower) {
	for (int index = 0; index < MAX_TOWER_ALLOWED; ++index) {
		square currentSquare = popFromQueue(currentTower);
		addPoints(currentSquare);
		obtainedArray[index] = currentSquare.color;
	}
	if (checkPattern(patternArray, obtainedArray)) {
		totalScore += 100;
		generatePattern(patternArray);
	}
	if (currentTower.numberOfLevels == 0) {
		pushToQueue(currentTower, generateSquare());
	}
}


void generatePattern(int patternArray[]) {
	for (int index = 0; index < MAX_PATTERN; ++index) {
		patternArray[index] = Color(generator);
	}
}

bool checkPattern(int patternArray[], int obtainedArray[]) {
	for (int index = 0; index < MAX_PATTERN; ++index) {
		if (patternArray[index] != obtainedArray[index])
			return false;
	}
	return true;
}

// Scoreboard 

void addScoreboard(player current) {
	int count;
	for (int i = 0; i <= 10; ++i) {
		if (scoreboard[i].totalScore == 0) {
			count = i;
			break;
		}
	}
	for (int i = 0; i < count; ++i) {
		if (scoreboard[i].totalScore > current.totalScore && current.totalScore >= scoreboard[i + 1].totalScore) {
			for (int j = count; j > i; j--) {
				scoreboard[j] = scoreboard[j - 1];
			}
			scoreboard[i + 1] = current;
			break;
		}
	}
	scoreboard[10].totalScore = 0;
}