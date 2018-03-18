#include "Fractal.h"

Callback Fractal::FinishedCallback = nullptr;

Fractal::Fractal(uint width, uint height)
	: Width(width)
	, Height(height)
{
	Buffer.resize(width * height, Color(0));
}

void Fractal::Seed(uint seed)
{
	RandomFunctionSelector.seed(seed);
	RandomPointGenerator.seed(seed);
	LastSeed = seed;
}

void Fractal::Iterate(uint numPoints, Color color)
{
	double x = ((RandomPointGenerator()) % Width);
	double y = ((RandomPointGenerator()) % Height);
	double xorg = x;
	double yorg = y;

	for(uint i = 0; i < numPoints && Run; ++i)
	{
		(*this)[static_cast<uint>(y)][static_cast<uint>(x)] += color;

		x = std::fmod(((100000 * x) / (x * x + y * y)) + x + xorg, Width);
		y = std::fmod(((100910 * y) / (x * x + y * y)) + y + yorg, Height);

	}
}

Color* Fractal::operator[](uint y)
{
	return Buffer.data() + (Width * y);
}
