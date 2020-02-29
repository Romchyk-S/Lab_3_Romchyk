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
	const float radius = 50.f;
	float mov = 5.f;
	bool circle = false;
	bool triangle = false;
	bool del = false;

	RenderWindow window(VideoMode(1920, 1080), L"Моє вікно");

	Circle c(Point(center, center), radius);
	Triangle t(Point(center, center), radius);
	

	Functions::out(&t);

	while (window.isOpen())
	{
		Event windowEvent;

		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == Event::Closed) window.close();
			if (Keyboard::isKeyPressed(Keyboard::Key::Equal)) {
				if (mov < 100)
				{
					mov += 5;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Hyphen)) {
				if (mov > 5)
				{
					mov -= 5;
				}	
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Backspace)) {
				del = true;
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::C)) {
				circle = true;
				del = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::T)) {
				triangle = true;
				del = false;
			}
			if (circle == true && (Keyboard::isKeyPressed(Keyboard::Key::Left)||Keyboard::isKeyPressed(Keyboard::Key::A))) {
				c.move(Point(-mov, 0.f));
			}
			if (triangle == true && (Keyboard::isKeyPressed(Keyboard::Key::Left) || Keyboard::isKeyPressed(Keyboard::Key::A))) {
				t.move(Point(-mov, 0.f));
			}
			if (circle == true && (Keyboard::isKeyPressed(Keyboard::Key::Right)||Keyboard::isKeyPressed(Keyboard::Key::D))) {
				c.move(Point(mov, 0.f));
			}
			if (triangle == true && (Keyboard::isKeyPressed(Keyboard::Key::Right) || Keyboard::isKeyPressed(Keyboard::Key::D))) {
				t.move(Point(mov, 0.f));
			}
			if (circle == true && (Keyboard::isKeyPressed(Keyboard::Key::Up)||Keyboard::isKeyPressed(Keyboard::Key::W))) {
				c.move(Point(0.f, -mov));
			}
			if (triangle == true && (Keyboard::isKeyPressed(Keyboard::Key::Up) || Keyboard::isKeyPressed(Keyboard::Key::W))) {
				t.move(Point(0.f, -mov));
			}
			if (circle == true && (Keyboard::isKeyPressed(Keyboard::Key::Down)||Keyboard::isKeyPressed(Keyboard::Key::S))) {
				c.move(Point(0.f, mov));
			}
			if (triangle == true && (Keyboard::isKeyPressed(Keyboard::Key::Down) || Keyboard::isKeyPressed(Keyboard::Key::S))) {
				t.move(Point(0.f, mov));
			}
		}
	window.clear();
	
	if (circle != false && del != true)
	{
		c.Draw(window);
	}


	if (triangle != false && del != true)
	{
		t.Draw(window);
	}


	window.display();
	}

	system("pause > NUL");
	return 0;
}
