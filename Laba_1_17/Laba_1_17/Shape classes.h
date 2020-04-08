#pragma once

#include "Interfaces.h"
#include "Base classes.h"

using namespace sf;
using namespace std;

class S : public iMove, public iRotate, public iColour, public iScaling, public iDraw
{
public:
	S();
	virtual ~S(); 

	bool show;
	Point xy;
	float radius{};
	float degree{};
	Point scale;
	bool path;

	Point getxy();
	float getrad();
	float getdeg();
	Point getscale();
	bool getshow();
	void setshow(bool show_1);
	void changecolour_red();
	void changecolour_yellow();
	void changecolour_green();
	void changecolour_blue();
	void changecolour_gray();
	bool getpath();
	void setpath(bool path_1);
};

class Circle : public S
{
private:
	RGBA Col;

public:
	Circle();

	Circle(Point p, float r);

	~Circle();

	void invert();
	
	void movebyvalue(Point xy) override;
	void move(Point xy) override;
	void rottocertain(float deg) override;
	void rot(float deg) override;
	void deformx(float times) override;
	void deformy(float times) override;
	void doubledeform(float times) override;
	void Draw(RenderWindow& window) override;
	void setcolour(RGBA Colour) override;
	void returncolor();
};

class Triangle : public S
{
private:
	RGBA Col;
	
public:
	Triangle();

	Triangle(Point p, float r);

	~Triangle();

	void invert();

	void move(Point xy) override;
	void movebyvalue(Point xy) override;
	void rottocertain(float deg) override;
	void rot(float deg) override;
	void deformx(float times) override;
	void deformy(float times) override;
	void doubledeform(float times) override;
	void Draw(RenderWindow& window) override;
	void setcolour(RGBA Colour) override;
	void returncolor();
};

class Square : public S
{
private:
	RGBA Col;
	
public:
	Square();

	Square(Point p, float r);

	~Square();

	void invert();

	void move(Point xy) override;
	void movebyvalue(Point xy) override;
	void rottocertain(float deg) override;
	void rot(float deg) override;
	void deformx(float times) override;
	void deformy(float times) override;
	void doubledeform(float times) override;
	void Draw(RenderWindow& window) override;
	void setcolour(RGBA Colour) override;
	void returncolor();
};

struct Functions { // давай попробуем лучше так, окей?
	Functions() = delete;
	~Functions() = delete;
	static void out(S* shape); // почему именно триангл, а не S*? апкаст, видимо, для слабаков
};