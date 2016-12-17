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

level popFromQueue(level *current, int &height) { // Scoatem de la baza. Adaugam la final.
	level *auxilary = current;
	current = current->next;
	delete(auxilary);
	height--;
}

// Functiile pentru modificarea tabelei 

void generateSquare(square currentSquare) {
	currentSquare.color = Color(generator);
	currentSquare.value = Value(generator);
}

void fillTable(tower gameTable[][4]) {
	for (int index = 0; index < 4; ++index) {
		for (int jndex = 0; jndex < 4; ++jndex) {
			generateSquare(gameTable[index][jndex].level->currentSquare);
			gameTable[index][jndex].numberOfLevels = 1;
		}
	}
}







