#pragma once

class Point
{
private:
	float x;
	float y;

public:
	Point();

	Point(float x1, float y1);
	Point(float xy);
	~Point();
	float getX() const;
	float getY();
	void setX(float value);
	void setY(float value);

	void operator=(float a[]);
	bool operator<(Point p) const;
	bool operator>(Point p) const;
	bool operator<=(Point p) const;
	bool operator>=(Point p) const;
	bool operator==(Point p) const;
	bool operator!=(Point p) const;

};

class RGBA
{
private:
	float R{};
	float G{};
	float B{};
	float A{};

	static void SetCol(float& Color, float Num_Col);

public:
	RGBA();

	RGBA(float red, float green, float blue, float alpha);
	float getR() const;
	float getG() const;
	float getB() const;
	float getA() const;
	void setR(float red_1);
	void setG(float green_1);
	void setB(float blue_1);
	void setA(float alpha_1);

	bool operator== (const RGBA & other)
	{
		return !(this->R == other.R || this->G == other.G || this->B == other.B || this->A == other.A);
	}

	bool operator!= (const RGBA & other)
	{
		return !(this->R == other.R || this->G == other.G || this->B == other.B || this->A == other.A);
	}

	~RGBA();
};

