#ifndef CONTROL_HPP
#define CONTROL_HPP

#include "Map.h"
#define CONSOLE_KEY_QUIT 81

class Control{
private:

public:
	bool isPossible(int x, int y, Map*);
	void catchEvents(Map*);
};


#endif

