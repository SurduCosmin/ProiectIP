#include"SDL_header.h"
#include"Mouse.h"
void MouseTarget(SDL_Event e,SDL_Rect Rectangle)
{
	if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside = true;
		if (x < Rectangle.x)
			inside = false;
		else if (x > Rectangle.x + Rectangle.w)
			inside = false;
		else if (y < Rectangle.y)
			inside = false;
		else if (y > Rectangle.y + Rectangle.h)
			inside = false;
		if (!inside)
				action = BUTTON_MOUSE_OUT;
		else
		{
			switch (e.type)
			{
			case SDL_MOUSEMOTION:
				action = BUTTON_MOUSE_OVER_MOTION;
				break;

			case SDL_MOUSEBUTTONDOWN:
				action = BUTTON_MOUSE_DOWN;
				break;

			case SDL_MOUSEBUTTONUP:
				action = BUTTON_MOUSE_UP;
				break;
			}
		}
	}
}