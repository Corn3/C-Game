#include "Labeled.h"
#include <SDL_ttf.h>
#include "System.h"

namespace gameengine {

	Labeled::Labeled(int x, int y, const string& t) : Comps(x, y, 0, 0), text(t)
	{
		makeTexture();
	}

	SDL_Texture* Labeled::makeTexture() {
		if (texture != nullptr)
			SDL_DestroyTexture(texture);
		SDL_Surface* surf = TTF_RenderText_Solid(sys.getFont(), text.c_str(), { 0,0,0 });
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);
		setWH(surf->w, surf->h);
		SDL_FreeSurface(surf);
		return texture;
	}

	string Labeled::getText() const {
		return text;
	}

	void Labeled::setText(const string& t) {
		text = t;
		makeTexture();
	}


	Labeled::~Labeled()
	{
		SDL_DestroyTexture(texture);
	}

}