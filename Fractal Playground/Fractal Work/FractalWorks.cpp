
#include "FractalWorks.h"
#include <future>
#include "Fractal.h"


Fractal Frac(0,0);

std::future<void> f;

FWAPI void SetBufferSize(uint width, uint height)
{
	Frac = Fractal(width, height);
}

FWAPI uint* GetBuffer()
{
	uint* asdfasd = reinterpret_cast<uint*>(Frac.Buffer.data());
	return asdfasd;
}

FWAPI void Start()
{
	Frac.Seed(127);
	Frac.Run = true;
	f = std::async(std::launch::async, &Fractal::Iterate, &Frac, 20000000);
}

FWAPI void Abort()
{
	Frac.Run = false;
	f.wait();
}

FWAPI void SetFinishedCallback(Callback callback)
{
	Fractal::FinishedCallback = callback;
}

