#ifndef PLATFORM_H
#define PLATFORM_H

#include "Sprite.h"

namespace gameengine {

	class Platform : public Sprite
	{
	public:
		static Platform* getInstance(int x, int y, int w, int h);
		void draw() const;
		~Platform();
	protected:
		Platform(int x, int y, int w, int h);
	private:
		const char* GRASS_PLATFORM = "C:/Users/narut/source/repos/GameEngine/Images/Grass_Platform.png";
		SDL_Texture* platform;
	};

}

#endif