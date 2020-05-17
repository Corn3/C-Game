#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>

namespace gameengine {
	class Sprite
	{
	public:

		virtual ~Sprite() {}

		virtual void draw() const = 0;

		bool checkCollision(SDL_Rect*);

		SDL_Rect getRect() const { return rect; }

	protected:
		Sprite(int x, int y, int w, int h);
		void setWH(int w, int h);
	private:
		SDL_Rect rect;
		Sprite(const Sprite&) = delete;
		const Sprite& operator = (const Sprite&) = delete;
	};

}

#endif