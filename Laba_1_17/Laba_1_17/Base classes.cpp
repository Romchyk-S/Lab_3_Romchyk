#include "stdafx.h"
#include "Base classes.h"

Point::Point() = default;

Point::Point(float x1, float y1)
{
	x = x1;
	y = y1;
}

Point::Point(float xy) : Point(xy, xy) {}

Point::~Point() = default;

float Point::getX() const
{
	return x;
}

float Point::getY()
{
	return y;
}

void Point::setX(float value)
{
	x = value;
}

void Point::setY(float value)
{
	y = value;
}

void Point::operator=(float a[])
{
	x = a[0];
	y = a[1];
}

bool Point::operator>(Point p) const
{
	return x > p.getX() && y > p.getY();
}

bool Point::operator<(Point p) const
{
	return x < p.getX() && y < p.getY();
}

bool Point::operator<=(Point p) const
{
	return !this->operator>(p);
}

bool Point::operator>=(Point p) const
{
	return !this->operator<(p);
}

bool Point::operator ==(Point p) const
{ 
	return x == p.getX() && y == p.getY();
}

bool Point::operator !=(Point p) const
{
	return x != p.getX() && y != p.getY();
}

void RGBA::SetCol(float& Color, float Num_Col)
{
	if (Num_Col > 255.f || Num_Col < 0.f)
	{
		Color = 10.f;
	}
	else
	{
		Color = Num_Col;
	}
}


RGBA::RGBA() = default;

RGBA::RGBA(float red, float green, float blue, float alpha)
{
	R = red;
	G = green;
	B = blue;
	A = alpha;
}

float RGBA::getR() const
{
	return R;
}

float RGBA::getG() const
{
	return G;
}

float RGBA::getB() const
{
	return B;
}

float RGBA::getA() const
{
	return A;
}

void RGBA::setR(float red_1)
{
	SetCol(R, red_1);
}

void RGBA::setG(float green_1)
{
	SetCol(G, green_1);
}

void RGBA::setB(float blue_1)
{
	SetCol(B, blue_1);
}

void RGBA::setA(float alpha_1)
{
	SetCol(A, alpha_1);
}

RGBA::~RGBA() = default;