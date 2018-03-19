#pragma once

#include "Types.h"

struct Color
{
public:
	byte B, G, R, A;

	Color(uint color = 0xFFFFFFFF);
	Color(byte r, byte g, byte b, byte a = 255);

	explicit operator uint() const;

	Color operator*(const Color& rhs) const;
	Color operator+(const Color& rhs) const;
	Color operator-(const Color& rhs) const;
	Color& operator*=(const Color& rhs);
	Color& operator+=(const Color& rhs);
	Color& operator-=(const Color& rhs);

	Color operator*(const uint& rhs) const;
	Color operator+(const uint& rhs) const;
	Color operator-(const uint& rhs) const;
	Color& operator*=(const uint& rhs);
	Color& operator+=(const uint& rhs);
	Color& operator-=(const uint& rhs);
};

