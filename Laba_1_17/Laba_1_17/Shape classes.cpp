#include "stdafx.h"
#include "Shape classes.h"


	S::S()
	{
		this->begin();
	};

	S::S(Point p, float r, RGBA Colour_)
	{
		xy = p;
		radius = r;
		degree = 0.f;
		scale = { 1.f, 1.f };
		this->begin();
	}

	S::~S() = default;


	bool S::getshow()
	{
		return show;
	}

	void S::hide()
	{
		setcolour(RGBA(0.f, 0.f, 0.f, 200.f));
	}

	void S::setmov(int k)
	{
		mov = k;
	}

	int S::getmov()
	{
		return mov;
	}

	void S::setshow(bool show_1)
	{
		show = show_1;

		if (show == false)
		{
			hide();
		}
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

	Point S::getxy()
	{
		return xy;
	}

	void S::setxy(Point x1y1)
	{
		xy = x1y1;
	}

	void S::setstartpoint(Point x1y1)
	{
		startpoint = x1y1;
	};

	Point S::getstartpoint()
	{
		return startpoint;
	};

	void S::returnpoint()
	{
		setxy(getstartpoint());
	};

	float S::getrad()
	{
		return radius;
	}

	float S::getdeg()
	{
		return degree;
	}

	void S::setdeg(float deg)
	{
		degree = deg;
	}

	void S::setstartdeg(float degree)
	{
		startdegree = degree;
	};

	float S::getstartdeg()
	{
		return startdegree;
	};

	void S::returndeg()
	{
		setdeg(getstartdeg());
	};

	Point S::getscale()
	{
		return scale;
	}

	void S::setscale(Point x2y2)
	{
		scale = x2y2;
	}

	void S::setstartscale(Point x2y2)
	{
		startscale = x2y2;
	};

	Point S::getstartscale()
	{
		return startscale;
	};

	void S::returnscale()
	{
		setscale(getstartscale());
	};

	bool S::getpath()
	{
		return path;
	}

	void S::setpath(bool path_1)
	{
		path = path_1;
	}

	bool S::gethidepath()
	{
		return hidepath;
	}

	void S::sethidepath(bool path_1) 
	{
		hidepath = path_1;
	}

	void S::setcolour(RGBA Colour)
	{
		Col.setR(Colour.getR());
		Col.setG(Colour.getG());
		Col.setB(Colour.getB());
		Col.setA(Colour.getA());
	};

	RGBA S::getcolour()
	{
		return Col;
	};

	void S::returncolor()
	{
		setcolour(Startcol);
	};

	void S::setstartcolour(RGBA Colour)
	{
		Startcol.setR(Colour.getR());
		Startcol.setG(Colour.getG());
		Startcol.setB(Colour.getB());
		Startcol.setA(Colour.getA());
	};

	RGBA S::getstartcolour()
	{
		return Startcol;
	};

	RGBA S::getcurrentcolour()
	{
		return Current_colour;
	};

	void S::setcurrentcolour(RGBA Colour)
	{
		Current_colour = Colour;
	};

	void S::setrotatorpos(float rot)
	{
		rotatorpos = rot;
	}

	float S::getrotatorpos()
	{
		return rotatorpos;
	}

	void S::setrotatorneg(float rot)
	{
		rotatorneg = rot;
	}

	float S::getrotatorneg()
	{
		return rotatorneg;
	}

	float S::getdeformerx() 
	{
		return deformerx;
	}

	void S::setdeformerx(float defx)
	{
		deformerx = defx;
	}

	float S::getdeformery()
	{
		return deformery;
	}

	void S::setdeformery(float defy)
	{
		deformery = defy;
	}

	float S::getdeformer()
	{
		return ddeformer;
	}

	void S::setdeformer(float def)
	{
		ddeformer = def;
	}

	void S::begin()
	{
		this->setstartcolour(this->getcolour());
		this->setstartpoint(this->getxy());
		this->setstartscale(this->getscale());
		this->setstartdeg(this->getdeg());
		this->setcurrentcolour(this->getcolour());
		this->setpath(false);
		this->setdeformer(2.f);
		this->setdeformerx(2.f);
		this->setdeformery(2.f);
		this->sethidepath(false);
	}

	Circle::Circle() = default;

	Circle::Circle(Point p, float r, RGBA Colour_) : S(p,r, Colour_)
	{
		
	}

	Circle::~Circle() = default;


	void Circle::movebyvalue(Point xy)
	{
		this->xy.setX(xy.getX());
		this->xy.setY(xy.getY());
	};

	void Circle::move(Point xy){
		if (xy.getX() + this->xy.getX() < 1920 && xy.getX() + this->xy.getX() > 0 && xy.getY() + this->xy.getY() < 1080 && xy.getY() + this->xy.getY() > 0)
		{
			movebyvalue(Point(xy.getX() + this->xy.getX(), xy.getY() + this->xy.getY()));
		}
	};

	void Circle::deformx(float times)
	{
		scale.setX(times);
	};

	void Circle::deformy(float times)
	{
		scale.setY(times);
	};

	void Circle::doubledeform(float times)
	{
		deformx(times);
		deformy(times);
	};

	void Circle::Draw(RenderWindow& window)
	{
		CircleShape circ(radius);
		
		circ.setPosition(xy.getX(), xy.getY());
		circ.setScale(scale.getX(), scale.getY());
		circ.setRotation(degree);
		circ.setFillColor(Color(Col.getR(), Col.getG(), Col.getB(), Col.getA()));
		circ.getFillColor();
		circ.setOutlineColor(Color(Col.getR(), Col.getG(), Col.getB(), Col.getA()));

		window.draw(circ);
	};






	Triangle::Triangle() = default;


	Triangle::Triangle(Point p, float r, RGBA Colour_) : S(p, r, Colour_)
	{
	
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







	Square::Square() = default;


	Square::Square(Point p, float r, RGBA Colour_) : S(p, r, Colour_)
	{
	
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
		triang.rotate(degree);
		triang.setFillColor(Color(Col.getR(), Col.getG(), Col.getB(), Col.getA()));
		triang.setOutlineColor(Color(Col.getR(), Col.getG(), Col.getB(), Col.getA()));

		window.draw(triang);
	}