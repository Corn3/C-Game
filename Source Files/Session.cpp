#include "Session.h"
#include <SDL.h>
#include "System.h"
#include <iostream>
#include "Platform.h"
#include "Coin.h"
#include "Counter.h"

namespace gameengine {

	void Session::add(Sprite* s) {
		added.push_back(s);
	}

	void Session::add(Character* ch) {
		character = ch;
	}

	void Session::add(Comps* c) {
		comps.push_back(c);
	}

	void Session::remove(Sprite* c) {
		removed.push_back(c);
	}

	void Session::run() {
		SDL_SetRenderDrawColor(sys.getRen(), 255, 255, 255, 255);
		bool quit = false;
		const Uint8* keyState;
		
		while (!quit) {
			SDL_Event event;

			frameStart = SDL_GetTicks();
			

			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT)
					quit = true;

			}


			keyState = SDL_GetKeyboardState(NULL);
			while (true) {
				if (keyState[SDL_SCANCODE_RIGHT] && keyState[SDL_SCANCODE_LEFT]) {
					break;
				}
				else {
					if (keyState[SDL_SCANCODE_RIGHT]) {
						
						character->setIdle(false);
						right = true;
						break;
					}
					if (keyState[SDL_SCANCODE_LEFT]) {
						character->setIdle(false);
						left = true;
						break;
					}
					if (keyState[SDL_SCANCODE_SPACE]) {
						if (character->getOnPlatform() == false)
							break;
						if (character->getRect().y < character->getJumpHeight()) {
							up = false;
							break;
						}
						character->setIdle(true);
						character->setOnPlatform(false);
						up = true;
						break;
					}
					else {
						character->setIdle(true);
						break;
					}
				}
			}
			if (character->getOnPlatform() == false && up) {
				character->setYVel(-SPEED);
				up = false;
			}
			
			for (auto c : sprites) {
				if (dynamic_cast<Platform*>(c)) {
					if (dynamic_cast<Platform*>(c)->checkCollision(&character->getRect())) {
						if (character->getRect().x + character->getRect().w <= c->getRect().x + 10 && character->getRect().y + character->getRect().h >= c->getRect().y) {
							character->setRect(c->getRect().x - character->getRect().w, character->getRect().y);
							break;
						}
						else if (c->getRect().x + c->getRect().w - 10<= character->getRect().x && character->getRect().y + character->getRect().h >= c->getRect().y) {
							character->setRect(c->getRect().x + c->getRect().w, character->getRect().y);
							break;
						}
						else if (c->getRect().y - c->getRect().h < character->getRect().y) {
							character->setRect(character->getRect().x, c->getRect().y + c->getRect().h);
							break;
						}
						currentPlatform = c;
						last_Platform_Y = c->getRect().y;
						character->setRect(character->getRect().x, last_Platform_Y - character->getRect().h);
						character->setOnPlatform(true);

					}
					else if (currentPlatform != nullptr && !dynamic_cast<Platform*>(c)->checkCollision(&character->getRect()) && (character->getRect().x + character->getRect().w < currentPlatform->getRect().x || character->getRect().x > currentPlatform->getRect().x + currentPlatform->getRect().w)) {
						character->setOnPlatform(false);
					}
				}
				else if (dynamic_cast<Coin*>(c)) {
					if (dynamic_cast<Coin*>(c)->checkCollision(&character->getRect())) {
						remove(c);
						for (auto comp : comps)
							if (dynamic_cast<Counter*>(comp)) {
								dynamic_cast<Counter*>(comp)->setCount();
								break;
							}

					}
				}
			}

			if (!left && right) {
				character->setXVel(SPEED);
				right = false;
				
			}
			if (!right && left) {
				character->setXVel(-SPEED);
				left = false;
				
			}

			character->gravity();
			character->move();

			
			
			if (character->getRect().x < 0)
				character->setRect(0, character->getRect().y);
			if (character->getRect().y < 0)
				character->setRect(character->getRect().x, 0);
			if (character->getRect().x + character->getRect().w > sys.SCREEN_WIDTH)
				character->setRect(sys.SCREEN_WIDTH - character->getRect().w, character->getRect().y);
			if (character->getRect().y + character->getRect().h > sys.SCREEN_HEIGHT) {
				character->setOnPlatform(true);
				character->setRect(character->getRect().x, sys.SCREEN_HEIGHT - character->getRect().h);
			}

			for (auto c : added)
				sprites.push_back(c);
			added.clear();

			for (auto c : removed) {
				for (vector<Sprite*>::iterator i = sprites.begin(); i != sprites.end();) {
					if (*i == c) {
						i = sprites.erase(i);
						delete c;
					}
					else
						i++;
				}
			}
			removed.clear();

			SDL_RenderClear(sys.getRen());
			for (auto c : sprites)
				c->draw();
			character->draw(event);
			for (auto c : comps)
				c->draw();
			SDL_SetRenderDrawColor(sys.getRen(), 0, 0, 255, 255);
			SDL_RenderPresent(sys.getRen());

			frameTime = SDL_GetTicks() - frameStart;
			if (frameDelay > frameTime) {
				SDL_Delay(frameDelay - frameTime);
			}
		} //outer while
	}


	Session::~Session()
	{
		for (auto c : sprites)
			delete c;
		delete character;
	}

}