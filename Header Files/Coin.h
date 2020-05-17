#ifndef COIN_H
#define COIN_H
#include "Sprite.h"

namespace gameengine {

	class Coin : public Sprite
	{
	public:
		static Coin* getInstance(int x, int y, int w, int h);
		void draw() const;
		~Coin();
	protected:
		Coin(int x, int y, int w, int h);
	private:
		const char* COIN = "C:/Users/narut/source/repos/GameEngine/Images/COIN.png";
		SDL_Texture* coin;
	};

}

#endif