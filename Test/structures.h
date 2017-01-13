#define TABLE_LENGTH 4
#define MAX_TOWER_ALLOWED 4
#define MAX_PATTERN 4



#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


struct player
{
    int score;
};
struct position {
	// Pozitie din tabla de joc initiala de 4x4
	int x ,y ;
};
position startPlayer1;
position startPlayer2;
