#include "Timer.h"
#include <SDL.h>

namespace gameengine {

	Timer::Timer()
	{
		startTick = 0;
		pauseTick = 0;
		started = false;
		paused = false;
	}

	void Timer::stop() {
		started = false;
		paused = false;
	}

	void Timer::start() {
		started = true;
		paused = false;
		startTick = SDL_GetTicks();
	}

	void Timer::pause() {
		if ((paused == false) && (started)) {
			paused = true;
			pauseTick = SDL_GetTicks() - startTick;
		}

	}

	void Timer::unpause() {
		if (paused) {
			paused = false;
			startTick = SDL_GetTicks() - pauseTick;
			pauseTick = 0;
		}
	}

	int Timer::getTicks() {
		if (started) {
			if (paused)
				return pauseTick;
			else
				return SDL_GetTicks() - startTick;
		}

	}

	bool Timer::getStarted() {
		return started;
	}

	bool Timer::getPaused() {
		return paused;
	}

	Timer timer;

} //gameengine