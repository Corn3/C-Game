#include "Icon.h"
#include "System.h"
#include <SDL_image.h>
#include <stdexcept>

namespace gameengine {

	Icon::Icon(int x, int y, int w, int h) : Comps(x, y, w, h)
	{
		icon = IMG_LoadTexture(sys.getRen(), COIN);
		if (icon == NULL)
			throw runtime_error("Could not find the texturefile!");
	}

	Icon* Icon::getInstance(int x, int y, int w, int h) {
		return new Icon(x, y, w, h);

	}

	void Icon::draw() const {
		if (SDL_RenderCopy(sys.getRen(), icon, NULL, &getRect()) != 0) {
			throw runtime_error("Could not create renderer!");
		}

	}


	Icon::~Icon()
	{
		SDL_DestroyTexture(icon);
	}

}