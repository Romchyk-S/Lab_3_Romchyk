#include "stdafx.h"
#include <iostream>
#include <Windows.h>

#include <SFML/Graphics.hpp>

#include "Basic classes.h"
#include "Interfaces.h"
#include "Shape classes.h"

using namespace sf;
using namespace std;



int main()
{
	const float center = 100.f;
	const float radius = 5.f;
	const float mov = 5.f;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	RenderWindow window(VideoMode(1920, 1080), L"�� ����");

	Circle c(Point(center, center), radius);

	Functions::out(&c);

	while (window.isOpen())
	{
		Event windowEvent;

		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == Event::Closed) window.close();
			if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
				c.move(Point(-mov, 0.f));
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
				c.move(Point(mov, 0.f));
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
				c.move(Point(0.f, -mov));
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
				c.move(Point(0.f, mov));
			}
		}
	window.clear();
	
	c.Draw(window);

	window.display();
	}

	system("pause > NUL");
	return 0;
}
