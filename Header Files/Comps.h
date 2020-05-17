#ifndef COMPS_H
#define COMPS_H
#include <SDL.h>

namespace gameengine {

	class Comps
	{
	public:
		virtual ~Comps() {};
		virtual void draw() const = 0;
		SDL_Rect getRect() const { return rect; }
	protected:
		Comps(int x, int y, int w, int h);
		void setWH(int w, int h);
	private:
		SDL_Rect rect;
		Comps(const Comps&) = delete;
		const Comps& operator=(const Comps&) = delete;
	};

}

#endif