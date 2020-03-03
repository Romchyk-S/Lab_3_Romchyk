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
	bool square = false;
	bool path = false;
	bool del = false;

	RenderWindow window(VideoMode(1920, 1080), L"Моє вікно");

	Circle c(Point(center, center), radius);
	Triangle t(Point(center, center), radius);
	Square s(Point(center, center), radius);
	

	Functions::out(&t);

	while (window.isOpen())
	{
		Event windowEvent;

		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == Event::Closed) window.close();

			if (windowEvent.type == sf::Event::KeyReleased)
			{

				if (windowEvent.key.code == sf::Keyboard::Equal) {
					if (mov < 100)
					{
						mov += 5;
					}
				}
				if (windowEvent.key.code == sf::Keyboard::Hyphen) {
					if (mov > 5)
					{
						mov -= 5;
					}
				}

				if (windowEvent.key.code == sf::Keyboard::Backspace) {
					del = true;
				}

				if (windowEvent.key.code == sf::Keyboard::C) {
					circle = true;
					del = false;
				}
				if (windowEvent.key.code == sf::Keyboard::T) {
					triangle = true;
					del = false;
				}
				if (windowEvent.key.code == sf::Keyboard::R) {
					square = true;
					del = false;
				}
				if (windowEvent.key.code == sf::Keyboard::P) {
					path = !path;
				}


			}

			
			if (circle == true && windowEvent.key.code == sf::Keyboard::A) {
				c.move(Point(-mov, 0.f));
			}
			if (triangle == true && windowEvent.key.code == sf::Keyboard::A) {
				t.move(Point(-mov, 0.f));
			}
			if (square == true && windowEvent.key.code == sf::Keyboard::A) {
				s.move(Point(-mov, 0.f));
			}

			if (circle == true && windowEvent.key.code == sf::Keyboard::D) {
				c.move(Point(mov, 0.f));
			}
			if (triangle == true && windowEvent.key.code == sf::Keyboard::D) {
				t.move(Point(mov, 0.f));
			}
			if (square == true && windowEvent.key.code == sf::Keyboard::D) {
				s.move(Point(mov, 0.f));
			}

			if (circle == true && windowEvent.key.code == sf::Keyboard::W) {
				c.move(Point(0.f, -mov));
			}
			if (triangle == true && windowEvent.key.code == sf::Keyboard::W) {
				t.move(Point(0.f, -mov));
			}
			if (square == true && windowEvent.key.code == sf::Keyboard::W) {
				s.move(Point(0.f, -mov));
			}

			if (circle == true &&windowEvent.key.code == sf::Keyboard::S) {
				c.move(Point(0.f, mov));
			}
			if (triangle == true && windowEvent.key.code == sf::Keyboard::S) {
				t.move(Point(0.f, mov));
			}
			if (square == true && windowEvent.key.code == sf::Keyboard::S) {
				s.move(Point(0.f, mov));
			}
		}

	if (path != true)
	{
		window.clear();
	}
	
	if (circle != false && del != true)
	{
		c.Draw(window);
	}


	if (triangle != false && del != true)
	{
		t.Draw(window);
	}

	if (square != false && del != true)
	{
		s.Draw(window);
	}

	window.display();
	}

	system("pause > NUL");
	return 0;
}
