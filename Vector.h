#pragma once
#include <cmath>
class Vector
{
public:
	int x;
	int y;
	double length;
	Vector() {
		x = 0;
		y = 0;
	}
	Vector(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	double  Scalar(Vector a, Vector b)
	{
		return a.x * b.x + a.y * b.y;
	}

	double GetLength()
	{
		return sqrt((x * x) + (y * y));
	}

};

