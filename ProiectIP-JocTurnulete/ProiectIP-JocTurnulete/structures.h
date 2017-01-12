#define TABLE_LENGTH 4
#define MAX_TOWER_ALLOWED 4
#define MAX_PATTERN 4

long long totalScore;
int obtainedArray[MAX_PATTERN];


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
	level *next=nullptr;
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

tower gameTable[TABLE_LENGTH][TABLE_LENGTH];