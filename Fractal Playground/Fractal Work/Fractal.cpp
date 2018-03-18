#include "Fractal.h"

Callback Fractal::FinishedCallback = nullptr;

Fractal::Fractal(uint width, uint height)
	: Width(width)
	, Height(height)
{
	Buffer.resize(width * height, Pixel(0));
}

void Fractal::Seed(uint seed)
{
	RandomFunctionSelector.seed(seed);
	RandomPointGenerator.seed(seed);
	LastSeed = seed;
}

void Fractal::Iterate(uint numPoints)
{
	double x = (RandomPointGenerator()) % Width;
	double y = (RandomPointGenerator()) % Height;
	double xorg = x;
	double yorg = y;

	for(uint i = 0; i < numPoints && Run; ++i)
	{
		(*this)[static_cast<uint>(y)][static_cast<uint>(x)] += 0x05FFFFFF;

		x = std::fmod(((700 * x) / (x * x + y * y)) + x + xorg, Width);
		y = std::fmod(((1600 * y) / (x * x + y * y)) + y + yorg, Height);

	}

	if (Run && Fractal::FinishedCallback)
		Fractal::FinishedCallback();
}

Pixel* Fractal::operator[](uint y)
{
	return Buffer.data() + (Width * y);
}
