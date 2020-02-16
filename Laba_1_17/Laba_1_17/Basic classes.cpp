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