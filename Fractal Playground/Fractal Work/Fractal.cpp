#include "Fractal.h"

Callback Fractal::FinishedCallback = nullptr;

Fractal::Fractal(uint width, uint height)
	: Width(width)
	, Height(height)
{
	Buffer.resize(width * height, Color(0));
}

void Fractal::Iterate(uint numPoints, Color color)
{
	double x = ((RandomPointGenerator()) % Width);
	double y = ((RandomPointGenerator()) % Height);

	for(uint i = 0; i < numPoints && Run; ++i)
	{
		Color& col = (*this)[static_cast<uint>(y)][static_cast<uint>(x)];
		col += color;

		double x1 = std::fmod(((1000000 * x) / (color.R * color.R + color.G * color.G + color.B * color.B + x * x + y * y)) + x, Width);
		double y1 = std::fmod(((1000910 * y) / (color.R * color.R + color.G * color.G + color.B * color.B + x * x + y * y)) + y, Height);
		color.R = static_cast<byte>(std::fmod(((300.0 * (color.R + 25)) / (color.R * color.R + color.G * color.G + color.B * color.B + x * x + y * y)) + color.R, 255));
		color.G = static_cast<byte>(std::fmod(((300.0 * (color.G + 25)) / (color.R * color.R + color.G * color.G + color.B * color.B + x * x + y * y)) + color.G, 255));
		color.B = static_cast<byte>(std::fmod(((300.0 * (color.B + 25)) / (color.R * color.R + color.G * color.G + color.B * color.B + x * x + y * y)) + color.B, 255));

		double x2 = std::fmod(10 * sin(x) + x, Width);
		double y2 = std::fmod(12 * sin(y) + y, Height);

		double t = 0.2;
		x = (1 - t) *  x1 + t * x2;
		y = (1 - t) *  y1 + t * y2;

		if (x < 0)
			x += Width;
		if (y < 0)
			y += Height;
	}
}

Color* Fractal::operator[](uint y)
{
	return Buffer.data() + (Width * y);
}
