#ifndef CHARACTER_H
#define CHARACTER_H
#include "Sprite.h"
#include <string>

namespace gameengine {

	class Character
	{
	public:
		static Character* getInstance(float x, float y);
		void draw(const SDL_Event& events) const;
		SDL_Rect getRect() const { return charRect; }
		void setRect(float x, float y) { charRect.x = x, charRect.y = y; }
		void setIdle(bool b) { idle = b; }
		void move();
		void setYVel(float);
		void setXVel(float);
		float getYVel() const;
		float getXVel() const;
		bool getOnPlatform() const;
		void setOnPlatform(bool);
		void gravity();
		float getJumpHeight() { return jump_height; }
		~Character();
	protected:
		Character(float x, float y);
	private:
		bool idle = true, onPlatform = true;
		float xVel = 0, yVel = 0;
		SDL_Surface* charSurfStationary, *charSurfRight, *charSurfLeft;
		SDL_Texture* charStationary, *charRight, *charLeft;
		SDL_Rect charRect;
		static const int CHAR_MAX_JUMP_HEIGHT = 100;
		float jump_height;
	};

}

#endif