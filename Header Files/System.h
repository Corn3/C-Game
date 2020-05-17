#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include <SDL_ttf.h>

namespace gameengine {
	class System
	{
	public:
		System();
		~System();
		SDL_Renderer* getRen() const;
		TTF_Font* getFont() const;
		const float SCREEN_WIDTH = 1100;
		const float SCREEN_HEIGHT = 600;
	private:
		SDL_Window* win;
		SDL_Renderer* ren;
		TTF_Font* font;
	};

	extern System sys;

}//gameengine

#endif