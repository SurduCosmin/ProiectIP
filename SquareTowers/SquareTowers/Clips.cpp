#include"Clips.h"
void ClipsInit(int tower,int position)
{
	SpriteClips[position].y = SpriteClips[position].y - (tower * 10 / 3);
	SpriteClips[position].h = SpriteClips[position].h + tower * 10 / 3;
}

void Clipping()
{
	ClipsInit(15, 0);
	ClipsInit(4, 1);
	ClipsInit(12, 2);
	ClipsInit(0, 3);
	ClipsInit(6, 4);
	ClipsInit(5, 5);
	ClipsInit(2, 6);
	ClipsInit(3, 7);
	ClipsInit(7, 8);
	ClipsInit(9, 9);
	ClipsInit(8, 10);
	ClipsInit(15, 11);
	ClipsInit(4, 12);
	ClipsInit(2, 13);
	ClipsInit(0, 14);
	ClipsInit(0, 15);
}