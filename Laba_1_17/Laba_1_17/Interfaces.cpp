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
