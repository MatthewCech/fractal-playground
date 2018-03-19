#pragma once

#include <random>
#include <vector>
#include "Types.h"
#include "Color.h"
#include "Point.h"


typedef void(*Callback)();

class Fractal
{
public:
	static Callback FinishedCallback;


	uint Width;
	uint Height;
	std::vector<Color> Buffer;
	bool Run;


	Fractal(uint width, uint height);

	void Iterate(uint numPoints, Color color);

	Color* operator[](uint y);

private:
	std::mt19937 RandomPointGenerator;
	//there needs to be more than one of these for multi-threaded.
	std::mt19937 RandomFunctionSelector;
};

