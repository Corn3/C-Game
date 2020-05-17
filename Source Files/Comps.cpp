#include "Comps.h"
namespace gameengine {

	Comps::Comps(int x, int y, int w, int h) : rect{ x, y, w, h }
	{
	}


	void Comps::setWH(int w, int h) {
		rect.w = w;
		rect.h = h;
	}

}