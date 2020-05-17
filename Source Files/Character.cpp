#include "Character.h"
#include "System.h"
#include <SDL_image.h>
#include <iostream>
#include "Timer.h"
using namespace std;

namespace gameengine {

	const char* CHAR_STATIONARY = "C:/Users/narut/source/repos/GameEngine/Images/TEMP_CHARACTER.png";
	const char* CHAR_RIGHT = "C:/Users/narut/source/repos/GameEngine/Images/TEMP_CHARACTER_RIGHT.png";
	const char* CHAR_LEFT = "C:/Users/narut/source/repos/GameEngine/Images/TEMP_CHARACTER_LEFT.png";

	Character* Character::getInstance(float x, float y) {
		return new Character(x, y);
	}

	void Character::gravity() {
		if (onPlatform) {
			yVel = 0;
			jump_height = charRect.y - CHAR_MAX_JUMP_HEIGHT;
		}
		else {
			yVel += 3;
		}

	}

	void Character::setYVel(float d) {
		yVel = d;
	}

	inline float Character::getYVel() const {
		return yVel;
	}

	void Character::setXVel(float d) {
		xVel = d;
	}

	inline float Character::getXVel() const {
		return xVel;
	}

	void Character::setOnPlatform(bool x) {
		onPlatform = x;
	}

	bool Character::getOnPlatform() const {
		return onPlatform;
	}

	void Character::move() {
		if (idle)
			xVel = 0;
		if (!onPlatform) {
			charRect.y += yVel / 15;
		}
		charRect.x += xVel / 15;
	}

	Character::Character(float x, float y)
	{
		charSurfStationary = IMG_Load(CHAR_STATIONARY);
		charStationary = SDL_CreateTextureFromSurface(sys.getRen(), charSurfStationary);
		charRect = { (int)x, (int)y, charSurfStationary->w, charSurfStationary->h };
		SDL_FreeSurface(charSurfStationary);

		charSurfRight = IMG_Load(CHAR_RIGHT);
		charRight = SDL_CreateTextureFromSurface(sys.getRen(), charSurfRight);
		SDL_FreeSurface(charSurfRight);

		charSurfLeft = IMG_Load(CHAR_LEFT);
		charLeft = SDL_CreateTextureFromSurface(sys.getRen(), charSurfLeft);
		SDL_FreeSurface(charSurfLeft);
	}

	void Character::draw(const SDL_Event& event) const {
		if (idle == false && event.key.keysym.sym == SDLK_LEFT)
			SDL_RenderCopy(sys.getRen(), charLeft, NULL, &charRect);
		else if (idle == false && event.key.keysym.sym == SDLK_RIGHT)
			SDL_RenderCopy(sys.getRen(), charRight, NULL, &charRect);
		//else if (idle == false && event.key.keysym.sym == SDLK_SPACE)
			//SDL_RenderCopy(sys.getRen(), charStationary, NULL, &charRect);
		else
			SDL_RenderCopy(sys.getRen(), charStationary, NULL, &charRect);
	}

	Character::~Character()
	{
		SDL_DestroyTexture(charStationary);
		SDL_DestroyTexture(charRight);
		SDL_DestroyTexture(charLeft);
	}

}