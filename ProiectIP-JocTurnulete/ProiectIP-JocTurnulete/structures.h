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
	level *next=NULL;
};
struct tower {
	int numberOfLevels;
	level *level;
};

struct position {
	// Pozitie din tabla de joc initiala de 4x4
	int x;
	int y;
};

