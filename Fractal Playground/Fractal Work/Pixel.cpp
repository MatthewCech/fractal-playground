#include "Pixel.h"
#include <cmath>

Color::Color(uint color)
{
	*reinterpret_cast<uint*>(&A) = color;
}

Color::Color(byte r, byte g, byte b, byte a): A(a), R(r), G(g), B(b) {}

Color::operator uint&()
{
	return *reinterpret_cast<uint*>(&A);
}

Color::operator uint() const
{
	return *reinterpret_cast<const uint*>(&A);
}

Color Color::operator*(const Color& rhs) const
{
	Color p(*this);
	return p *= rhs;
}

Color Color::operator+(const Color& rhs) const
{
	Color p(*this);
	return p += rhs;
}

Color Color::operator-(const Color& rhs) const
{
	Color p(*this);
	return p -= rhs;
}

Color& Color::operator*=(const Color& rhs)
{
	A = static_cast<byte>(std::roundf((A / 255.0f) * (rhs.A / 255.0f)));
	R = static_cast<byte>(std::roundf((R / 255.0f) * (rhs.R / 255.0f)));
	G = static_cast<byte>(std::roundf((G / 255.0f) * (rhs.G / 255.0f)));
	B = static_cast<byte>(std::roundf((B / 255.0f) * (rhs.B / 255.0f)));

	return *this;
}

Color& Color::operator+=(const Color& rhs)
{
	short a = A + static_cast<short>(rhs.A);
	A = static_cast<byte>(a > 255 ? 255 : a);

	short r = R + static_cast<short>(rhs.R);
	R = static_cast<byte>(r > 255 ? 255 : r);

	short g = G + static_cast<short>(rhs.G);
	G = static_cast<byte>(g > 255 ? 255 : g);

	short b = B + static_cast<short>(rhs.B);
	B = static_cast<byte>(b > 255 ? 255 : b);

	return *this;
}

Color& Color::operator-=(const Color& rhs)
{
	short a = A - static_cast<short>(rhs.A);
	A = static_cast<byte>(a < 0 ? 0 : a);

	short r = R - static_cast<short>(rhs.R);
	R = static_cast<byte>(r < 0 ? 0 : r);

	short g = G - static_cast<short>(rhs.G);
	G = static_cast<byte>(g < 0 ? 0 : g);

	short b = B - static_cast<short>(rhs.B);
	B = static_cast<byte>(b < 0 ? 0 : b);

	return *this;
}

Color Color::operator*(const uint & rhs) const
{
	return *this * Color(rhs);
}

Color Color::operator+(const uint & rhs) const
{
	return *this + Color(rhs);
}

Color Color::operator-(const uint & rhs) const
{
	return *this - Color(rhs);
}

Color & Color::operator*=(const uint & rhs)
{
	return *this *= Color(rhs);
}

Color & Color::operator+=(const uint & rhs)
{
	return *this += Color(rhs);
}

Color & Color::operator-=(const uint & rhs)
{
	return *this -= Color(rhs);
}

