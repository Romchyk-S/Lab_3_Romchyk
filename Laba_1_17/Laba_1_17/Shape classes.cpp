#include "stdafx.h"
#include "Shape classes.h"


	S::S() = default;
	S::~S() = default;

	Circle::Circle() = default;

	Circle::Circle(Point p, float r)
	{
		xy = p;
		radius = r;
		degree = 0.f;
		scale = { 1.f, 1.f };
		Col.setR(205.f);
		Col.setG(100.f);
		Col.setB(200.f);
		Col.setA(200.f);
	}

	Circle::~Circle() = default;

	void Circle::movebyvalue(Point xy)
	{
		this->xy.setX(xy.getX());
		this->xy.setY(xy.getY());
	}

	void Circle::move(Point xy){
		movebyvalue(Point(xy.getX() + this->xy.getX(), xy.getY() + this->xy.getY()));
	}

	void Circle::rottocertain(float deg)
	{
		while (deg >= 360)
		{
			deg -= 360;
		}

		degree = deg;
	}

	void Circle::rot(float deg)
	{
		rottocertain(degree + deg);
	}

	void Circle::deformx(float times)
	{
		scale.setX(times);
	}

	void Circle::deformy(float times)
	{
		scale.setY(times);
	}

	void Circle::doubledeform(float times)
	{
		deformx(times);
		deformy(times);
	}

	void Circle::Draw(RenderWindow& window)
	{
		CircleShape circ(radius);

		circ.setPosition(xy.getX(), xy.getY());
		circ.setScale(scale.getX(), scale.getY());
		circ.setRotation(degree);
		circ.setFillColor(Color(Col.getR(), Col.getG(), Col.getB(), Col.getA()));
		circ.setOutlineColor(Color(Col.getR(), Col.getG(), Col.getB(), Col.getA()));

		window.draw(circ);
	}

	void Circle::setcolour(RGBA Colour)
	{
		Col.setR(Colour.getR());
		Col.setG(Colour.getG());
		Col.setB(Colour.getB());
		Col.setA(Colour.getA());
	};


	void Circle::invert()
	{
		rot(180.f);
	}

	Point Circle::getxy()
	{
		return xy;
	}

	float Circle::getrad()
	{
		return radius;
	}

	float Circle::getdeg()
	{
		return degree;
	}

	Point Circle::getscale()
	{
		return scale;
	}

	
	void Functions::out(Circle* shape) {
		cout << "Центр: (" << shape->getxy().getX() << ";" << shape->getxy().getY() << ")" << endl;
		cout << "Радіус: " << shape->getrad() << endl;
		cout << "Градуси: " << shape->getdeg() << endl;
		cout << "Деформація x: " << shape->getscale().getX() << endl;
		cout << "Деформація y: " << shape->getscale().getY() << endl;
};