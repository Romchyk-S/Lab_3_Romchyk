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

	bool Circle::getshow()
	{
		return show;
	}

	void Circle::setshow(bool show_1)
	{
		show = show_1;
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

	void Circle::changecolour_red()
	{
		Col.setR(255.f);
		Col.setG(0.f);
		Col.setB(0.f);
		Col.setA(200.f);
	}

	void Circle::changecolour_yellow()
	{
		Col.setR(255.f);
		Col.setG(255.f);
		Col.setB(0.f);
		Col.setA(200.f);
	}

	void Circle::changecolour_green()
	{
		Col.setR(0.f);
		Col.setG(128.f);
		Col.setB(0.f);
		Col.setA(200.f);
	}

	void Circle::changecolour_blue()
	{
		Col.setR(0.f);
		Col.setG(0.f);
		Col.setB(255.f);
		Col.setA(200.f);
	}

	void Circle::changecolour_gray()
	{
		Col.setR(128.f);
		Col.setG(128.f);
		Col.setB(128.f);
		Col.setA(200.f);
	}

	void Circle::returncolor()
	{
		Col.setR(205.f);
		Col.setG(100.f);
		Col.setB(200.f);
		Col.setA(200.f);
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

	void Triangle::changecolour_red()
	{
		Col.setR(255.f);
		Col.setG(0.f);
		Col.setB(0.f);
		Col.setA(200.f);
	}

	void Triangle::changecolour_yellow()
	{
		Col.setR(255.f);
		Col.setG(255.f);
		Col.setB(0.f);
		Col.setA(200.f);
	}

	void Triangle::changecolour_green()
	{
		Col.setR(0.f);
		Col.setG(128.f);
		Col.setB(0.f);
		Col.setA(200.f);
	}

	void Triangle::changecolour_blue()
	{
		Col.setR(0.f);
		Col.setG(0.f);
		Col.setB(255.f);
		Col.setA(200.f);
	}

	void Triangle::changecolour_gray()
	{
		Col.setR(128.f);
		Col.setG(128.f);
		Col.setB(128.f);
		Col.setA(200.f);
	}

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

	Point Triangle::getxy()
	{
		return xy;
	}

	float Triangle::getrad()
	{
		return radius;
	}

	float Triangle::getdeg()
	{
		return degree;
	}

	Point Triangle::getscale()
	{
		return scale;
	}

	bool Triangle::getshow()
	{
		return show;
	}

	void Triangle::setshow(bool show_1)
	{
		show = show_1;
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

	void Square::changecolour_red()
	{
		Col.setR(255.f);
		Col.setG(0.f);
		Col.setB(0.f);
		Col.setA(200.f);
	}

	void Square::changecolour_yellow()
	{
		Col.setR(255.f);
		Col.setG(255.f);
		Col.setB(0.f);
		Col.setA(200.f);
	}

	void Square::changecolour_green()
	{
		Col.setR(0.f);
		Col.setG(128.f);
		Col.setB(0.f);
		Col.setA(200.f);
	}

	void Square::changecolour_blue()
	{
		Col.setR(0.f);
		Col.setG(0.f);
		Col.setB(255.f);
		Col.setA(200.f);
	}

	void Square::changecolour_gray()
	{
		Col.setR(128.f);
		Col.setG(128.f);
		Col.setB(128.f);
		Col.setA(200.f);
	}

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

	Point Square::getxy()
	{
		return xy;
	}

	float Square::getrad()
	{
		return radius;
	}

	float Square::getdeg()
	{
		return degree;
	}

	Point Square::getscale()
	{
		return scale;
	}

	bool Square::getshow()
	{
		return show;
	}

	void Square::setshow(bool show_1)
	{
		show = show_1;
	}
	
	void Functions::out(Triangle* shape) {
		cout << "Центр: (" << shape->getxy().getX() << ";" << shape->getxy().getY() << ")" << endl;
		cout << "Радіус: " << shape->getrad() << endl;
		cout << "Градуси: " << shape->getdeg() << endl;
		cout << "Деформація x: " << shape->getscale().getX() << endl;
		cout << "Деформація y: " << shape->getscale().getY() << endl;
};