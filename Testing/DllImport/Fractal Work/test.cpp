
#include "test.h"

__declspec(dllexport) void* Oh()
{
	Wow *w = new Wow();
	w->wow = 1234132;
	w->str = "testing mah dude";
	return w;
}

