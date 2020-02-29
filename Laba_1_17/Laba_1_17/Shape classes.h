#pragma once

#include "Interfaces.h"
#include "Base classes.h"

#include <iostream>

using namespace sf;
using namespace std;

class S : public iMove, public iRotate, public iColour, public iScaling, public iDraw
{
public:
	S();
	virtual ~S();
};

class Circle : public S
{
private:
	Point xy;
	float radius;
	float degree;
	Point scale;
	RGBA Col;

public:
	Circle();

	Circle(Point p, float r);

	~Circle();

	void movebyvalue(Point xy) override;
	void move(Point xy) override;
	void rottocertain(float deg) override;
	void rot(float deg) override;
	void deformx(float times) override;
	void deformy(float times) override;
	void doubledeform(float times) override;
	void Draw(RenderWindow& window) override;
	void setcolour(RGBA Colour) override;
	void invert();
	Point getxy();
	float getrad();
	float getdeg();
	Point getscale();
};

class Triangle : public S
{
private:
	Point xy;
	float radius;
	float degree;
	Point scale;
	RGBA Col;

public:
	Triangle();

	Triangle(Point p, float r);

	~Triangle();

	void invert();
	Point getxy();
	float getdeg();
	float getrad();
	Point getscale();
	void move(Point xy) override;
	void movebyvalue(Point xy) override;
	void rottocertain(float deg) override;
	void rot(float deg) override;
	void deformx(float times) override;
	void deformy(float times) override;
	void doubledeform(float times) override;
	void Draw(RenderWindow& window) override;
	void setcolour(RGBA Colour) override;
};

class Functions {
	Functions() = delete;
	~Functions() = delete;

public:
	static void out(Triangle* shape);
};