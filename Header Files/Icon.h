#ifndef ICON_H
#define ICON_H
#include "Comps.h"

using namespace std;

namespace gameengine {

	class Icon :public Comps
	{
	public:
		static Icon* getInstance(int x, int y, int w, int h);
		void draw() const;
		~Icon();
	protected:
		Icon(int x, int y, int w, int h);
	private:
		const char* COIN = "C:/Users/narut/source/repos/GameEngine/Images/COIN.png";
		SDL_Texture* icon;
	};

}

#endif