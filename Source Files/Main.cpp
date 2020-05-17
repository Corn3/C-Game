#include "System.h"
#include <SDL.h>
#include "Session.h"
#include "Sprite.h"
#include "Platform.h"
#include "Character.h"
#include "Timer.h"
#include "Coin.h"
#include "Counter.h"
#include "Icon.h"

using namespace gameengine;


int main(int argc, char** argv) {

	Session ses;
	int x = 0;
	static const int PLATFORM_WIDTH = 200;
	static const int PLATFORM_HEIGHT = 50;
	static const int PLATFORM_Y = 550;

	Platform* p;
	Platform* p1 = Platform::getInstance(200, 500, PLATFORM_WIDTH, PLATFORM_HEIGHT);
	ses.add(p1);
	while (x < sys.SCREEN_WIDTH) {
		p = Platform::getInstance(x, PLATFORM_Y, PLATFORM_WIDTH, PLATFORM_HEIGHT);
		ses.add(p);
		x += PLATFORM_WIDTH;
	}
	Platform* p2 = Platform::getInstance(480, 450, PLATFORM_WIDTH, PLATFORM_HEIGHT);
	ses.add(p2);
	Platform* p3 = Platform::getInstance(530, 210, PLATFORM_WIDTH, PLATFORM_HEIGHT);
	ses.add(p3);
	Platform* p4 = Platform::getInstance(50, 260, PLATFORM_WIDTH, PLATFORM_HEIGHT);
	ses.add(p4);
	Platform* p5 = Platform::getInstance(800, 450, PLATFORM_WIDTH, PLATFORM_HEIGHT);
	ses.add(p5);
	Platform* p6 = Platform::getInstance(1000, 330, 40, 40);
	ses.add(p6);

	Coin* c1 = Coin::getInstance(500, 410, 40, 40);
	ses.add(c1);
	c1 = Coin::getInstance(350, 450, 40, 40);
	ses.add(c1);
	c1 = Coin::getInstance(650, 500, 40, 40);
	ses.add(c1);
	c1 = Coin::getInstance(100, 200, 40, 40);
	ses.add(c1);
	
	Counter* count = Counter::getInstance(0, 0);
	ses.add(count);
	Icon* icon = Icon::getInstance(20, 0, 30, 30);
	ses.add(icon);

	Character* stationary = Character::getInstance(0, 500);
	ses.add(stationary);

	timer.start();

	ses.run();

	return 0;
}