#include "System.h"
#include <stdexcept>
using namespace std;

namespace gameengine {

	System::System()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
			throw runtime_error("Kunde inte initiera programmet!");

		win = SDL_CreateWindow("Platformer_TEMP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
		if (win == NULL)
			throw runtime_error("Kunde inte skapa ett fönster!");

		ren = SDL_CreateRenderer(win, -1, 0);
		if (ren == NULL)
			throw runtime_error("Kunde inte skapa renderaren!");

		TTF_Init();
		font = TTF_OpenFont("c:/Windows/Fonts/arial.ttf", 30);
		if (font == nullptr)
			throw runtime_error("Fontfilen existerar ej!");
	}

	SDL_Renderer* System::getRen() const {
		return ren;
	}

	TTF_Font* System::getFont() const {
		return font;
	}

	System::~System()
	{
		TTF_CloseFont(font);
		TTF_Quit();
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_Quit();
	}



	System sys;

} //gameengine