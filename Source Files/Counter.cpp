#include "Counter.h"
#include "System.h"
#include <SDL_image.h>
#include <stdexcept>

namespace gameengine {

	Counter::Counter(int x, int y): Labeled(x, y, " ")
	{
		setText("0");
	}

	Counter* Counter::getInstance(int x, int y) {
		return new Counter(x, y);

	}

	void Counter::draw() const {
		SDL_RenderCopy(sys.getRen(), getTexture(), NULL, &getRect());

	}

	void Counter::setCount() {
		count++;
		setText(to_string(count));
	}

	int Counter::getCount() const {
		return count;
	}



	Counter::~Counter()
	{
	}

}