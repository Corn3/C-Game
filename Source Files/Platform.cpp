#include "Platform.h"
#include <SDL_image.h>
#include "System.h"
#include <stdexcept>

using namespace std;

namespace gameengine {

	Platform* Platform::getInstance(int x, int y, int w, int h) {
		return new Platform(x, y, w, h);
	}

	Platform::Platform(int x, int y, int w, int h) : Sprite(x, y, w, h)
	{
		platform = IMG_LoadTexture(sys.getRen(), GRASS_PLATFORM);
		if (platform == NULL)
			throw runtime_error("Could not find the texturefile!");
	}

	void Platform::draw() const {
		if (SDL_RenderCopy(sys.getRen(), platform, NULL, &getRect()) != 0) {
			throw runtime_error("Could not draw the platform!");
		}
	}


	Platform::~Platform()
	{
		SDL_DestroyTexture(platform);
	}

}