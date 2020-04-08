#pragma once

#include "stdafx.h"
#include "Base classes.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Config.hpp>
#include <SFML/GpuPreference.hpp>
#include <SFML/Main.hpp>

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

