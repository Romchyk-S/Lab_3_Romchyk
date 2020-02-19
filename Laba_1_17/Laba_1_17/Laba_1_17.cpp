#include "stdafx.h"
#include <iostream>
#include <Windows.h>

#include "Base classes.h"
#include "Interfaces.h"
#include "Shape classes.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Config.hpp>
#include <SFML/GpuPreference.hpp>
#include <SFML/Main.hpp>

using namespace sf;
using namespace std;



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const float center = 100.f;
	const float radius = 5.f;
	const float mov = 5.f;

	RenderWindow window(VideoMode(1920, 1080), L"Моє вікно");

	Circle c(Point(center, center), radius);

	Functions::out(&c);

	while (window.isOpen())
	{
		Event windowEvent;

		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == Event::Closed) window.close();
			if (Keyboard::isKeyPressed(Keyboard::Key::Left)||Keyboard::isKeyPressed(Keyboard::Key::A)) {
				c.move(Point(-mov, 0.f));
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Right)||Keyboard::isKeyPressed(Keyboard::Key::D)) {
				c.move(Point(mov, 0.f));
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Up)||Keyboard::isKeyPressed(Keyboard::Key::W)) {
				c.move(Point(0.f, -mov));
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Down)||Keyboard::isKeyPressed(Keyboard::Key::S)) {
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
