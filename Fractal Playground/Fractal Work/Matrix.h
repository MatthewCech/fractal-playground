#pragma once

#include "Types.h"

struct Double4; //forward declaration

struct Matrix
{
public:
	double* operator[](uint y);
	const double* operator[](uint y) const;

	Matrix operator*(const Matrix& rhs) const;
	Matrix operator*(double rhs) const;
	Matrix operator-() const;
	Matrix& operator*=(const Matrix& rhs);
	Matrix& operator*=(double rhs);

	Double4 operator*(const Double4& rhs) const;
	friend static Double4& operator*=(Double4& lhs, const Matrix& rhs);
private:
	double Array[16];
};

