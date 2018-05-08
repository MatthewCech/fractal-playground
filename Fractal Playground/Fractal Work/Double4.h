#pragma once

#include "Types.h"

struct Double4
{
public:
	double X, Y, Z, W;

	Double4(double x = 0, double y = 0, double z = 0, double w = 0);

	Double4 operator*(double rhs) const;
	Double4 operator/(double rhs) const;
	Double4 operator+(const Double4& rhs) const;
	Double4 operator-(const Double4& rhs) const;
	Double4 operator-() const;

	Double4& operator*=(double rhs);
	Double4& operator/=(double rhs);
	Double4& operator+=(const Double4& rhs);
	Double4& operator-=(const Double4& rhs);

	double& operator[](uint index);
	double operator[](uint index) const;
};

