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
	float getX();
	float getY();
	void setX(float value);
	void setY(float value);
};

class RGBA
{
private:
	float R;
	float G;
	float B;
	float A;

	void SetCol(float& Color, float Num_Col);

public:
	RGBA();

	RGBA(float red, float green, float blue, float alpha);
	float getR();
	float getG();
	float getB();
	float getA();
	void setR(float red_1);
	void setG(float green_1);
	void setB(float blue_1);
	void setA(float alpha_1);

	~RGBA();
};

