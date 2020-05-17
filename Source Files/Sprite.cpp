#include "Sprite.h"
#include <SDL.h>
#include "System.h"

namespace gameengine {

	Sprite::Sprite(int x, int y, int w, int h) : rect{ x, y, w, h }
	{
	}

	void Sprite::setWH(int w, int h) {
		rect.w = w;
		rect.h = h;
	}

	bool Sprite::checkCollision(SDL_Rect* rect1) {
		if (rect1->x >= (getRect().x + getRect().w))
			return false;
		else if (rect1->y >= (getRect().y + getRect().h))
			return false;
		else if ((rect1->x + rect1->w) <= getRect().x)
			return false;
		else if ((rect1->y + rect1->h) <= getRect().y)
			return false;
		return true;
	}


}