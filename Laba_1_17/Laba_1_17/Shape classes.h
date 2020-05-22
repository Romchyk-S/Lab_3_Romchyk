#pragma once

#include "Interfaces.h"
#include "Base classes.h"

using namespace sf;
using namespace std;

class S : public iMove, public iColour, public iScaling, public iDraw
{
public:
	S();
	virtual ~S(); 

	
	Point xy;
	float radius{};
	float degree{};
	Point scale;
	bool path;
	bool hidepath;
	RGBA Col;
	RGBA Startcol;
	RGBA Current_colour;
	bool show;
	Point startpoint;
	Point startscale;
	float startdegree;
	float rotatorpos;
	float rotatorneg;
	float deformerx;
	float deformery;
	float ddeformer;


	Point getxy();
	void setxy(Point x1y1);
	float getrad();
	float getdeg();
	Point getscale();
	void setscale(Point x2y2);
	bool getshow();
	void setshow(bool show_1);
	void changecolour_red();
	void changecolour_yellow();
	void changecolour_green();
	void changecolour_blue();
	void changecolour_gray();
	void hide();
	bool getpath();
	void setpath(bool path_1);
	bool gethidepath();
	void sethidepath(bool path_1);
	void setcolour(RGBA Colour) override;
	void setstartcolour(RGBA Colour);
	void returncolor();
	void returnpoint();
	RGBA getstartcolour();
	RGBA getcolour();
	void setdeg(float deg);
	void setstartdeg(float degree);
	float getstartdeg();
	void returndeg();
	RGBA getcurrentcolour();
	void setcurrentcolour(RGBA Colour);
	Point getstartpoint();
	void setstartpoint(Point xy);
	void setstartscale(Point x2y2);
	Point getstartscale();
	void returnscale();
	void setrotatorpos(float rot);
	float getrotatorpos();
	void setrotatorneg(float rot);
	float getrotatorneg();
	float getdeformerx();
	void setdeformerx(float defx);
	float getdeformery();
	void setdeformery(float defy);
	float getdeformer();
	void setdeformer(float def);
};

class Circle : public S
{

private:

public:
	Circle();

	Circle(Point p, float r);

	~Circle();
	
	void movebyvalue(Point xy) override;
	void move(Point xy) override;
	void deformx(float times) override;
	void deformy(float times) override;
	void doubledeform(float times) override;
	void Draw(RenderWindow& window) override;
};

class Triangle : public S
{
private:
	
public:
	Triangle();

	Triangle(Point p, float r);

	~Triangle();

	void move(Point xy) override;
	void movebyvalue(Point xy) override;
	void deformx(float times) override;
	void deformy(float times) override;
	void doubledeform(float times) override;
	void Draw(RenderWindow& window) override;
};

class Square : public S
{
private:
	
public:
	Square();

	Square(Point p, float r);

	~Square();

	void move(Point xy) override;
	void movebyvalue(Point xy) override;
	void deformx(float times) override;
	void deformy(float times) override;
	void doubledeform(float times) override;
	void Draw(RenderWindow& window) override;
};

struct Functions {
	Functions() = delete;
	~Functions() = delete;
	static void out(S* shape);
};