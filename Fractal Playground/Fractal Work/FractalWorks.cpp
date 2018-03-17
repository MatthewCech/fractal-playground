
#include "FractalWorks.h"

__declspec(dllexport) void SetFinishedCallback(Callback callback)
{
	callback(0, nullptr);
}

