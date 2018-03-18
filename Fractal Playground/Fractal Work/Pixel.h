#pragma once

#include "Types.h"

struct Pixel
{
public:
	byte A, R, G, B;

	Pixel(uint color = 0xFFFFFFFF);
	Pixel(byte r, byte g, byte b, byte a = 255);

	explicit operator uint&();
	explicit operator uint() const;

	Pixel operator*(const Pixel& rhs) const;
	Pixel operator+(const Pixel& rhs) const;
	Pixel operator-(const Pixel& rhs) const;
	Pixel& operator*=(const Pixel& rhs);
	Pixel& operator+=(const Pixel& rhs);
	Pixel& operator-=(const Pixel& rhs);

	Pixel operator*(const uint& rhs) const;
	Pixel operator+(const uint& rhs) const;
	Pixel operator-(const uint& rhs) const;
	Pixel& operator*=(const uint& rhs);
	Pixel& operator+=(const uint& rhs);
	Pixel& operator-=(const uint& rhs);
};

