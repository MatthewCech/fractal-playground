#include "Matrix.h"
#include "Double4.h"

double * Matrix::operator[](uint y)
{
	return &(Array[y * 4]);
}

const double * Matrix::operator[](uint y) const
{
	return &(Array[y * 4]);
}

Matrix Matrix::operator*(const Matrix & rhs) const
{
	Matrix mat;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			double val;
			for (int k = 0; k < 4; ++k)
			{
				val += (*this)[i][k] * rhs[k][j];
			}
			mat[i][j] = val;
		}
	}

	return mat;
}

Matrix Matrix::operator*(double rhs) const
{
	Matrix mat;

	for (int i = 0; i < 16; ++i)
		mat.Array[i] = Array[i] * rhs;

	return mat;
}

Matrix Matrix::operator-() const
{
	Matrix mat;

	for (int i = 0; i < 16; ++i)
		mat.Array[i] = -Array[i];

	return mat;
}

Matrix & Matrix::operator*=(const Matrix & rhs)
{
	*this = *this * rhs;
	return *this;
}

Matrix & Matrix::operator*=(double rhs)
{
	for (int i = 0; i < 16; ++i)
		Array[i] *= rhs;
	return *this;
}

Double4 Matrix::operator*(const Double4 & rhs) const
{
	Double4 d;

	for (int i = 0; i < 4; ++i)
	{
		double val;
		for (int k = 0; k < 4; ++k)
		{
			val += (*this)[i][k] * rhs[k];
		}
		d[i] = val;
	}

	return d;
}

Double4 & operator*=(Double4 & lhs, const Matrix & rhs)
{
	lhs = rhs * lhs;
	return lhs;
}
