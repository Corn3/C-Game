#ifndef LABELED_H
#define LABELED_H
#include <string>
#include <SDL.h>
#include "Comps.h"

using namespace std;

namespace gameengine {

	class Labeled : public Comps
	{
	public:
		void setText(const string& txt);
		string getText() const;
		~Labeled();
	protected:
		Labeled(int x, int y, const string& text);
		SDL_Texture* getTexture() const { return texture; }
	private:
		string text = nullptr;
		SDL_Texture*  texture;
		SDL_Texture* makeTexture();
	};

}

#endif