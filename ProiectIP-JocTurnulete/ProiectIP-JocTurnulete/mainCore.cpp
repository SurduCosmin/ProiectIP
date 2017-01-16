#include<iostream>
#include<random>
#include "structures.h" 
#include "functions.h" 
#include<random>

using namespace std;

// Functii Queue ( Turn )
std::default_random_engine generator;
std::uniform_int_distribution<int> Color(1, 4);
std::uniform_int_distribution<int> Value(1, 16);

bool empty(tower current) {
	return (current.base == NULL);
}

void pushToQueue(tower &current, square addedSquare) { // Adaugam sus, scoatem jos.
	if (empty(current)) {
		current.base = new level;
		current.base->currentSquare = addedSquare;
		current.top = current.base;
		current.numberOfLevels++;	
	}
	else {
		current.top->next = new level;
		current.top = current.top->next;
		current.top->currentSquare = addedSquare;
		current.numberOfLevels++;
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

void fillTable() {
	for (int index = 0; index < TABLE_LENGTH; ++index) {
		for (int jndex = 0; jndex < TABLE_LENGTH; ++jndex) {
			gameTable[index][jndex].base = new level;
			gameTable[index][jndex].base->currentSquare = generateSquare();
			gameTable[index][jndex].top = gameTable[index][jndex].base;
			gameTable[index][jndex].numberOfLevels = 1;
		}
	}
}

void moveTower(position source, position destination) {
	while (!empty(gameTable[source.x][source.y])) {
		pushToQueue(gameTable[destination.x][destination.y],
			popFromQueue(gameTable[source.x][source.y]));
	}
	pushToQueue(gameTable[source.x][source.y], generateSquare());
}


bool checkPoint(tower currentTower) {
	return (currentTower.numberOfLevels >= MAX_TOWER_ALLOWED);
}

void addPoints(square currentSquare) {
	totalScore += currentSquare.value;
}

void reduceTower(tower currentTower) {
	for (int index = 0; index < MAX_TOWER_ALLOWED; ++index) {
		square currentSquare = popFromQueue(currentTower);
		addPoints(currentSquare);
		obtainedArray[index] = currentSquare.color;
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


int main(void) {
	fillTable();
	for (int i = 0; i < TABLE_LENGTH; ++i) {
		for (int j = 0; j < TABLE_LENGTH; ++j) {
			cout << gameTable[i][j].base->currentSquare.color << '-';
			cout << gameTable[i][j].base->currentSquare.value << ' ';
		}
		cout << '\n';
	}
	
	position a, b;
	a.x = 0;
	a.y = 0;
	b.x = 0;
	b.y = 1;
	moveTower(a, b);

	return 0;
}
