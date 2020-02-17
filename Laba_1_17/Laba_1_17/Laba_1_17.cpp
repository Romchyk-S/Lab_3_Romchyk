#include"stdafx.h"
#include <iostream>
#include<Windows.h>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Config.hpp>
#include <SFML/GpuPreference.hpp>
#include <SFML/Main.hpp>

using namespace sf;
using namespace std;


class Point
{
private:
	float x;
	float y;

public:
	Point() = default;

	Point(float x1, float y1)
	{
		x = x1;
		y = y1;
	}

	Point(float xy) : Point(xy, xy) {}

	~Point() = default;

	float getX()
	{
		return x;
	}

	float getY()
	{
		return y;
	}

	void setX(float value)
	{
		x = value;
	}

	void setY(float value)
	{
		y = value;
	}
};

class RGBA
{
private:
	float R;
	float G;
	float B;
	float A;

	void SetCol(float& Color, float Num_Col)
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

public:
	RGBA() = default;

	RGBA(float red, float green, float blue, float alpha)
	{
		R = red;
		G = green;
		B = blue;
		A = alpha;
	}

	float getR()
	{
		return R;
	}

	float getG()
	{
		return G;
	}

	float getB()
	{
		return B;
	}

	float getA()
	{
		return A;
	}

	void setR(float red_1)
	{
		SetCol(R, red_1);
	}

	void setG(float green_1)
	{
		SetCol(G, green_1);
	}

	void setB(float blue_1)
	{
		SetCol(B, blue_1);
	}

	void setA(float alpha_1)
	{
		SetCol(A, alpha_1);
	}

	~RGBA() = default;
 };

__interface iMove 
{
	void move(Point xy);
	void movebyvalue(Point xy);
};

__interface iRotate
{
	void rot(float deg);
	void rottocertain(float deg);
	void invert();
};

__interface iColour
{
	void setcolour(RGBA Col);
};

__interface iScaling
{
	void deformx(float times);
	void deformy(float times);
	void doubledeform(float times);
};

__interface iDraw
{
	void Draw(RenderWindow& window);
};




class S : public iMove, public iRotate, public iColour, public iScaling, public iDraw
{
public:
	S() = default;
	virtual ~S() = default;
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
	Circle() = default;

	Circle(Point p, float r)
	{
		xy = p;
		radius = r;
		degree = 0.f;
		scale = {1.f, 1.f};
		Col.setR(205.f);
		Col.setG(100.f);
		Col.setB(200.f);
		Col.setA(200.f);
	}

	~Circle() = default;

	void movebyvalue(Point xy) override
	{
		this->xy.setX(xy.getX());
		this->xy.setY(xy.getY());
	}

	void move(Point xy) override {
		movebyvalue(Point(xy.getX() + this->xy.getX(), xy.getY() + this->xy.getY()));
	}

	void rottocertain(float deg) override
	{
		while (deg >= 360)
		{
			deg -= 360;
		}

		degree = deg;
	}

	void rot(float deg) override
	{
		rottocertain(degree + deg);
	}

	void deformx(float times) override
	{
		scale.setX(times);
	}

	void deformy(float times) override
	{
		scale.setY(times);
	}

	void doubledeform(float times) override
	{
		deformx(times);
		deformy(times);
	}

	void Draw(RenderWindow& window) override
	{
		CircleShape circ(radius);

		circ.setPosition(xy.getX(), xy.getY());
		circ.setScale(scale.getX(), scale.getY());
		circ.setRotation(degree);
		circ.setFillColor(Color(Col.getR(), Col.getG(), Col.getB(), Col.getA()));
		circ.setOutlineColor(Color(Col.getR(), Col.getG(), Col.getB(), Col.getA()));

		window.draw(circ);
	}

	void setcolour(RGBA Colour) override
	{
		Col.setR(Colour.getR());
		Col.setG(Colour.getG());
		Col.setB(Colour.getB());
		Col.setA(Colour.getA());
	};


	void invert()
	{
		rot(180.f);
	}

	Point getxy()
	{
		return xy;
	}

	float getrad()
	{
		return radius;
	}

	float getdeg()
	{
		return degree;
	}

	Point getscale()
	{
		return scale;
	}
};

class Functions {
	Functions() = delete;
	~Functions() = delete;

public:	
	static void out(Circle* shape) {
		cout << "Центр: (" << shape->getxy().getX() << ";" << shape->getxy().getY() << ")" << endl;
		cout << "Радіус: " << shape->getrad() << endl;
		cout << "Градуси: " << shape->getdeg() << endl;
		cout << "Деформація x: " << shape->getscale().getX() << endl;
		cout << "Деформація y: " << shape->getscale().getY() << endl;
	}
};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	RenderWindow window(VideoMode(1920, 1080), L"Моє вікно");

	Circle c(Point(100.f, 100.f), 5.f);

	Functions::out(&c);

	while (window.isOpen())
	{
		Event windowEvent;

		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == Event::Closed) window.close();
			if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
				c.move(Point(-5.f, 0.f));
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
				c.move(Point(5.f, 0.f));
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
				c.move(Point(0.f, -5.f));
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
				c.move(Point(0.f, 5.f));
			}
		}
	window.clear();
	
	c.Draw(window);

	window.display();
	}

	system("pause > NUL");
	return 0;
}
