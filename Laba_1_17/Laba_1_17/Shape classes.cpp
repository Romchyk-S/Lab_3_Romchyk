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
		scale = { 1.f, 1.f };
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