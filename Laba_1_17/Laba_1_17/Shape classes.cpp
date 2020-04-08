#include "stdafx.h"
#include "Shape classes.h"


	S::S() = default;
	S::~S() = default;

	bool S::getshow()
	{
		return show;
	}

	void S::setshow(bool show_1)
	{
		show = show_1;
	}

	Point S::getxy()
	{
		return xy;
	}

	float S::getrad()
	{
		return radius;
	}

	float S::getdeg()
	{
		return degree;
	}

	Point S::getscale()
	{
		return scale;
	}

	void S::changecolour_red()
	{
		setcolour(RGBA(255.f, 0.f, 0.f, 200.f));
	}

	void S::changecolour_yellow()
	{
		setcolour(RGBA(255.f, 255.f, 0.f, 200.f));
	}

	void S::changecolour_green()
	{
		setcolour(RGBA(0.f, 128.f, 0.f, 200.f));
	}

	void S::changecolour_blue()
	{
		setcolour(RGBA(0.f, 0.f, 255.f, 200.f));
	}

	void S::changecolour_gray()
	{
		setcolour(RGBA(128.f, 128.f, 128.f, 200.f));
	}






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

	void Circle::invert()
	{
		rot(180.f);
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

	void Circle::movebyvalue(Point xy)
	{
		this->xy.setX(xy.getX());
		this->xy.setY(xy.getY());
	}

	void Circle::move(Point xy){
		if (xy.getX() + this->xy.getX() < 1920 && xy.getX() + this->xy.getX() > 0 && xy.getY() + this->xy.getY() < 1080 && xy.getY() + this->xy.getY() > 0)
		{
			movebyvalue(Point(xy.getX() + this->xy.getX(), xy.getY() + this->xy.getY()));
		}
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

	void Circle::setcolour(RGBA Colour)
	{
		Col.setR(Colour.getR());
		Col.setG(Colour.getG());
		Col.setB(Colour.getB());
		Col.setA(Colour.getA());
	};

	void Circle::returncolor()
	{
		Col.setR(205.f);
		Col.setG(100.f);
		Col.setB(200.f);
		Col.setA(200.f);
		// *адский полный боли крик
		// а что если фигура изначально будет иметь не этот цвет?
	}






	Triangle::Triangle() = default;


	Triangle::Triangle(Point p, float r)
	{
		xy = p;
		radius = r;
		degree = 0.f;
		scale = { 1.f, 1.f };
		Col.setR(128.f);
		Col.setG(128.f);
		Col.setB(0.f);
		Col.setA(200.f);
	}

	Triangle::~Triangle() = default;

	void Triangle::movebyvalue(Point xy)
	{
		this->xy.setX(xy.getX());
		this->xy.setY(xy.getY());
	}

	void Triangle::move(Point xy) {
		if (xy.getX() + this->xy.getX() < 1830 && xy.getX() + this->xy.getX() > 0 && xy.getY() + this->xy.getY() < 1080 && xy.getY() + this->xy.getY() > 0)
		{
			movebyvalue(Point(xy.getX() + this->xy.getX(), xy.getY() + this->xy.getY()));
		}	
	}

	void Triangle::rottocertain(float deg)
	{
		while (deg >= 360)
		{
			deg -= 360;
		}

		degree = deg;

		
	}

	void Triangle::rot(float deg)
	{
		rottocertain(degree + deg);
	}

	void Triangle::deformx(float times)
	{
		scale.setX(times);
	}

	void Triangle::deformy(float times)
	{
		scale.setY(times);
	}

	void Triangle::doubledeform(float times)
	{
		deformx(times);
		deformy(times);
	}

	void Triangle::Draw(RenderWindow& window)
	{
		CircleShape triang(radius, 3);

		triang.setPosition(xy.getX(), xy.getY());
		triang.setScale(scale.getX(), scale.getY());
		triang.setRotation(degree);
		triang.setFillColor(Color(Col.getR(), Col.getG(), Col.getB(), Col.getA()));
		triang.setOutlineColor(Color(Col.getR(), Col.getG(), Col.getB(), Col.getA()));

		window.draw(triang);
	}

	void Triangle::setcolour(RGBA Colour)
	{
		Col.setR(Colour.getR());
		Col.setG(Colour.getG());
		Col.setB(Colour.getB());
		Col.setA(Colour.getA());
	};

	void Triangle::returncolor()
	{
		Col.setR(128.f);
		Col.setG(128.f);
		Col.setB(0.f);
		Col.setA(200.f);
	}

	void Triangle::invert()
	{
		rot(180.f);
	}









	Square::Square() = default;


	Square::Square(Point p, float r)
	{
		xy = p;
		radius = r;
		degree = 0.f;
		scale = { 1.f, 1.f };
		Col.setR(255.f);
		Col.setG(0.f);
		Col.setB(255.f);
		Col.setA(200.f);
	}

	Square::~Square() = default;

	void Square::movebyvalue(Point xy)
	{
		this->xy.setX(xy.getX());
		this->xy.setY(xy.getY());
	}

	void Square::move(Point xy) {
		if (xy.getX() + this->xy.getX() < 1830 && xy.getX() + this->xy.getX() > 0 && xy.getY() + this->xy.getY() < 1080 && xy.getY() + this->xy.getY() > 0)
		{
			movebyvalue(Point(xy.getX() + this->xy.getX(), xy.getY() + this->xy.getY()));
		}
	}

	void Square::rottocertain(float deg)
	{
		while (deg >= 360)
		{
			deg -= 360;
		}

		degree = deg;
	}

	void Square::rot(float deg)
	{
		rottocertain(degree + deg);
	}

	void Square::deformx(float times)
	{
		scale.setX(times);
	}

	void Square::deformy(float times)
	{
		scale.setY(times);
	}

	void Square::doubledeform(float times)
	{
		deformx(times);
		deformy(times);
	}

	void Square::Draw(RenderWindow& window)
	{
		CircleShape triang(radius, 4);

		triang.setPosition(xy.getX(), xy.getY());
		triang.setScale(scale.getX(), scale.getY());
		triang.setRotation(degree);
		triang.setFillColor(Color(Col.getR(), Col.getG(), Col.getB(), Col.getA()));
		triang.setOutlineColor(Color(Col.getR(), Col.getG(), Col.getB(), Col.getA()));

		window.draw(triang);
	}

	void Square::setcolour(RGBA Colour)
	{
		Col.setR(Colour.getR());
		Col.setG(Colour.getG());
		Col.setB(Colour.getB());
		Col.setA(Colour.getA());
	};

	void Square::returncolor()
	{
		Col.setR(255.f);
		Col.setG(0.f);
		Col.setB(255.f);
		Col.setA(200.f);
	}

	void Square::invert()
	{
		rot(180.f);
	}