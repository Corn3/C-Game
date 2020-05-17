#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include "Sprite.h"
#include "Character.h"
#include "Comps.h"

using namespace std;

namespace gameengine {
	class Session
	{
	public:
		void add(Sprite*);
		void add(Character*);
		void add(Comps*);
		void remove(Sprite*);
		void remove(Character*);
		void run();
		~Session();
	private:
		bool collisionRight = false, collisionLeft = false, up = false, down = false, left = false, right = false;
		vector<Sprite*> sprites;
		vector<Sprite*> added, removed;
		vector<Comps*> comps;
		Character* character;
		Sprite* currentPlatform;
		int last_Platform_Y = GROUNDLEVEL_Y;
		const float SPEED = 100;
		static const int GROUNDLEVEL_Y = 550;
		const int FPS = 60;
		const int frameDelay = 1000 / 60;
		Uint32 frameStart;
		int frameTime;
	};

}

#endif