#ifndef TIMER_H
#define TIMER_H

namespace gameengine {

	class Timer
	{
	public:
		Timer();
		void start();
		void stop();
		void pause();
		void unpause();
		int getTicks();
		bool getStarted();
		bool getPaused();
	private:
		int startTick, pauseTick;
		bool paused, started;
	};

	extern Timer timer;

}//gameengine

#endif