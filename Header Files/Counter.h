#ifndef COUNTER_H
#define COUNTER_H
#include "Labeled.h"
#include <string>

using namespace std;

namespace gameengine {

	class Counter :public Labeled
	{
	public:
		static Counter* getInstance(int x, int y);
		void draw() const;
		int getCount() const;
		void setCount();
		~Counter();
	protected:
		Counter(int x, int y);
	private:
		int count = 0;
	};

}

#endif