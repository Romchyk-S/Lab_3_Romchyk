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
	bool path = false;

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


				if (windowEvent.key.code == sf::Keyboard::C) {
					c.setshow(true);
				}
				if (windowEvent.key.code == sf::Keyboard::T) {
					t.setshow(true);
				}
				if (windowEvent.key.code == sf::Keyboard::R) {
					s.setshow(true);
				}
				if (windowEvent.key.code == sf::Keyboard::P) {
					path = true;
				}



				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {


					if (c.getshow() == true && windowEvent.key.code == sf::Keyboard::W) {
						c.move(Point(0.f, -mov));
					}

					if (c.getshow() == true && windowEvent.key.code == sf::Keyboard::A) {
						c.move(Point(-mov, 0.f));
					}

					if (c.getshow() == true && windowEvent.key.code == sf::Keyboard::S) {
						c.move(Point(0.f, mov));
					}

					if (c.getshow() == true && windowEvent.key.code == sf::Keyboard::D) {
						c.move(Point(mov, 0.f));
					}



					if (windowEvent.key.code == sf::Keyboard::Num1)
					{
						c.changecolour_red();
					}
					if (windowEvent.key.code == sf::Keyboard::Num2)
					{
						c.changecolour_yellow();
					}
					if (windowEvent.key.code == sf::Keyboard::Num3)
					{
						c.changecolour_green();
					}
					if (windowEvent.key.code == sf::Keyboard::Num4)
					{
						c.changecolour_blue();
					}
					if (windowEvent.key.code == sf::Keyboard::Num5)
					{
						c.changecolour_gray();
					}
					if (windowEvent.key.code == sf::Keyboard::Num0)
					{
						c.returncolor();
					}

					if (windowEvent.key.code == sf::Keyboard::Backspace) {
						c.setshow(false);
					}

				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {


					if (t.getshow() == true && windowEvent.key.code == sf::Keyboard::W) {
						t.move(Point(0.f, -mov));
					}

					if (t.getshow() == true && windowEvent.key.code == sf::Keyboard::A) {
						t.move(Point(-mov, 0.f));
					}

					if (t.getshow() == true && windowEvent.key.code == sf::Keyboard::S) {
						t.move(Point(0.f, mov));
					}

					if (t.getshow() == true && windowEvent.key.code == sf::Keyboard::D) {
						t.move(Point(mov, 0.f));
					}



					if (windowEvent.key.code == sf::Keyboard::Num1)
					{
						t.changecolour_red();
					}
					if (windowEvent.key.code == sf::Keyboard::Num2)
					{
						t.changecolour_yellow();
					}
					if (windowEvent.key.code == sf::Keyboard::Num3)
					{
						t.changecolour_green();
					}
					if (windowEvent.key.code == sf::Keyboard::Num4)
					{
						t.changecolour_blue();
					}
					if (windowEvent.key.code == sf::Keyboard::Num5)
					{
						t.changecolour_gray();
					}
					if (windowEvent.key.code == sf::Keyboard::Num0)
					{
						t.returncolor();
					}

					if (windowEvent.key.code == sf::Keyboard::Backspace) {
						t.setshow(false);
					}
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {

					if (s.getshow() == true && windowEvent.key.code == sf::Keyboard::W) {
						s.move(Point(0.f, -mov));
					}

					if (s.getshow() == true && windowEvent.key.code == sf::Keyboard::A) {
						s.move(Point(-mov, 0.f));
					}

					if (s.getshow() == true && windowEvent.key.code == sf::Keyboard::S) {
						s.move(Point(0.f, mov));
					}

					if (s.getshow() == true && windowEvent.key.code == sf::Keyboard::D) {
						s.move(Point(mov, 0.f));
					}

					if (windowEvent.key.code == sf::Keyboard::Num1)
					{
						s.changecolour_red();
					}
					if (windowEvent.key.code == sf::Keyboard::Num2)
					{
						s.changecolour_yellow();
					}
					if (windowEvent.key.code == sf::Keyboard::Num3)
					{
						s.changecolour_green();
					}
					if (windowEvent.key.code == sf::Keyboard::Num4)
					{
						s.changecolour_blue();
					}
					if (windowEvent.key.code == sf::Keyboard::Num5)
					{
						s.changecolour_gray();
					}
					if (windowEvent.key.code == sf::Keyboard::Num0)
					{
						s.returncolor();
					}

					if (windowEvent.key.code == sf::Keyboard::Backspace) {
						s.setshow(false);
					}
				}					
				



				if (path == false)
				{
					window.clear();
				}


				if (c.getshow() == true)
				{
					c.Draw(window);
				}

				if (t.getshow() == true)
				{
					t.Draw(window);
				}

				if (s.getshow() == true)
				{
					s.Draw(window);
				}
				
			}

			window.display();

		}
}
		


			
	system("pause > NUL");
	return 0;
}
