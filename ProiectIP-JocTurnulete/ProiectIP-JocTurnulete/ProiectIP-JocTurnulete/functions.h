// Functii Queue ( Turn )
std::default_random_engine generator;
std::uniform_int_distribution<int> Color(1, 4);
std::uniform_int_distribution<int> Value(1, 16);

bool empty(tower *current) {
	return (current == NULL);
}

void pushToQueue(level *current,square addedSquare,int &height) { // Adaugam sus, scoatem jos.
	current->next = new level;
	current->next->currentSquare = addedSquare;
	height++;
}

square popFromQueue(level *current, int &height) { // Scoatem de la baza. Adaugam la final.
	square auxilary = current->currentSquare;
	current = current->next;
	height--;
	return auxilary;

}

// Functiile pentru modificarea tabelei 

square generateSquare() {
	square currentSquare;
	currentSquare.color = Color(generator);
	currentSquare.value = Value(generator);
	return currentSquare;
}

void fillTable(tower gameTable[][TABLE_LENGTH]) {
	for (int index = 0; index < TABLE_LENGTH; ++index) {
		for (int jndex = 0; jndex < TABLE_LENGTH; ++jndex) {
			gameTable[index][jndex].level->currentSquare = generateSquare();
			gameTable[index][jndex].numberOfLevels = 1;
		}
	}
}

void moveTower(position source, position destination) {
	while (!empty(gameTable[source.x][source.y])) {
		pushToQueue(gameTable[destination.x][destination.y],
			popFromQueue(gameTable[source.x][source.y], gameTable[source.x][source.y].numberOfLevels), 
			gameTable[destination.x][destination.y].numberOfLevels);
	}
	pushToQueue(gameTable[source.x][source.y], generateSquare(), gameTable[source.x][source.y].numberOfLevels);
}


bool checkPoint(tower *currentTower) {
	return (currentTower->numberOfLevels >= MAX_TOWER_ALLOWED);
}

void addPoints(square currentSquare) {
	totalScore += currentSquare.value;
}

void reduceTower(tower *currentTower) {
	for (int index = 0; index < MAX_TOWER_ALLOWED; ++index) {
		square currentSquare = popFromQueue(currentTower->level, currentTower->numberOfLevels);
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











