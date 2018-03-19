
#include "FractalWorks.h"
#include <future>
#include "Fractal.h"


Fractal Frac(0,0);

std::vector<std::future<void>> f;

FWAPI void SetBufferSize(uint width, uint height)
{
	Frac = Fractal(width, height);
}

FWAPI uint* GetBuffer()
{
	uint* asdfasd = reinterpret_cast<uint*>(Frac.Buffer.data());
	return asdfasd;
}

static Color colors[] =
{
	Color(0x110000FF),
	Color(0x1100FF00),
	Color(0x1100FFFF),
	Color(0x11FF0000),
	Color(0x11FF00FF),
	Color(0x11FFFF00),
};

static void yes()
{
	for (int i = 0; i < (sizeof(colors)/ sizeof(*colors)) && Frac.Run; ++i)
	{
		Frac.Iterate(10000000, colors[i]);
	}
	if (Frac.Run && Fractal::FinishedCallback)
		Fractal::FinishedCallback();
}

FWAPI void Start() 
{
	Frac.Run = true;

	//bad multi-threading. works, but race conditions are everywhere.
	/*for (int i = 0; i < (sizeof(colors)/ sizeof(*colors)); ++i)
	{
		f.push_back(std::async(std::launch::async, &Fractal::Iterate, &Frac, 50000000, colors[i]));
	}*/
	f.push_back(std::async(std::launch::async, yes));
}

FWAPI void Abort()
{
	Frac.Run = false;
	for (int i = 0; i < f.size(); ++i)
		f[i].wait();
}

FWAPI void SetFinishedCallback(Callback callback)
{
	Fractal::FinishedCallback = callback;
}

