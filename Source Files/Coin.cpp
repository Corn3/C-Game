#include "Coin.h"
#include <SDL_image.h>
#include <stdexcept>
#include "System.h"

using namespace std;

namespace gameengine {

	Coin::Coin(int x, int y, int h, int w) : Sprite(x, y, h, w)
	{
		coin = IMG_LoadTexture(sys.getRen(), COIN);
		if (coin == NULL)
			throw runtime_error("Could not find texturefile!");
	}


	Coin::~Coin()
	{
		SDL_DestroyTexture(coin);
	}

	void Coin::draw() const {
		if (SDL_RenderCopy(sys.getRen(), coin, NULL, &getRect()) != 0) {
			throw runtime_error("Could not redraw the coin!");
		}
	}

	Coin* Coin::getInstance(int x, int y, int h, int w) {
		return new Coin(x, y, h, w);
	}

}