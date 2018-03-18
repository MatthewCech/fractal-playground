#pragma once

#include <random>
#include <vector>
#include "Types.h"
#include "Pixel.h"


typedef void(*Callback)();

class Fractal
{
public:
	static Callback FinishedCallback;


	uint Width;
	uint Height;
	std::vector<Pixel> Buffer;
	bool Run;


	Fractal(uint width, uint height);

	void Seed(uint seed);
	void Iterate(uint numPoints);

	Pixel* operator[](uint y);

private:
	uint LastSeed;
	std::mt19937 RandomPointGenerator;
	//there needs to be more than one of these for multi-threaded.
	std::mt19937 RandomFunctionSelector;
};

