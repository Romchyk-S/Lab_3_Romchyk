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

	const auto center = 100.f;
	const auto radius = 50.f;
	auto mov = 5.f;
	auto path = false;

	RenderWindow window(VideoMode(1920, 1080), L"ћоЇ в≥кно");

	Circle c(Point(center, center), radius);
	Triangle t(Point(center, center), radius);
	Square s(Point(center, center), radius);
	
	// где вектор фигур?

	Functions::out(&t);

	while (window.isOpen())
	{
		Event windowEvent;

		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == Event::Closed) window.close();

			if (windowEvent.type == Event::KeyReleased)
			{
				if (windowEvent.key.code == Keyboard::Equal) {
					if (mov < 100)
					{
						mov += 5;
					}
				}
				if (windowEvent.key.code == Keyboard::Hyphen) {
					if (mov > 5)
					{
						mov -= 5;
					}
				}


				if (windowEvent.key.code == Keyboard::C) {
					c.setshow(true);
				}
				if (windowEvent.key.code == Keyboard::T) {
					t.setshow(true);
				}
				if (windowEvent.key.code == Keyboard::R) {
					s.setshow(true);
				}
				// за такой простой путь можно получить по *балу от будущих задач
				// при нажатии клавиш, нужно, чтобы нужна€ фигура добавл€лась в вектор фигур
				// а не просто по€вл€лась в единственном экземпл€ре
				if (windowEvent.key.code == Keyboard::P) {
					path = true;
				}



				if (Keyboard::isKeyPressed(Keyboard::C)) { // Ќј’*я


					if (c.getshow()&& windowEvent.key.code == Keyboard::W) {
						c.move(Point(0.f, -mov));
					}

					if (c.getshow() && windowEvent.key.code == Keyboard::A) {
						c.move(Point(-mov, 0.f));
					}

					if (c.getshow() == true && windowEvent.key.code == Keyboard::S) {
						c.move(Point(0.f, mov));
					}

					if (c.getshow() == true && windowEvent.key.code == Keyboard::D) {
						c.move(Point(mov, 0.f));
					}



					if (windowEvent.key.code == Keyboard::Num1)
					{
						c.changecolour_red();
					}
					if (windowEvent.key.code == Keyboard::Num2)
					{
						c.changecolour_yellow();
					}
					if (windowEvent.key.code == Keyboard::Num3)
					{
						c.changecolour_green();
					}
					if (windowEvent.key.code == Keyboard::Num4)
					{
						c.changecolour_blue();
					}
					if (windowEvent.key.code == Keyboard::Num5)
					{
						c.changecolour_gray();
					}
					if (windowEvent.key.code == Keyboard::Num0)
					{
						c.returncolor();
					}

					if (windowEvent.key.code == Keyboard::Backspace) {
						c.setshow(false);
					}

				}

				if (Keyboard::isKeyPressed(Keyboard::T)) { // —“ќЋ№ ќ


					if (t.getshow() == true && windowEvent.key.code == Keyboard::W) {
						t.move(Point(0.f, -mov));
					}

					if (t.getshow() == true && windowEvent.key.code == Keyboard::A) {
						t.move(Point(-mov, 0.f));
					}

					if (t.getshow() == true && windowEvent.key.code == Keyboard::S) {
						t.move(Point(0.f, mov));
					}

					if (t.getshow() == true && windowEvent.key.code == Keyboard::D) {
						t.move(Point(mov, 0.f));
					}



					if (windowEvent.key.code == Keyboard::Num1)
					{
						t.changecolour_red();
					}
					if (windowEvent.key.code == Keyboard::Num2)
					{
						t.changecolour_yellow();
					}
					if (windowEvent.key.code == Keyboard::Num3)
					{
						t.changecolour_green();
					}
					if (windowEvent.key.code == Keyboard::Num4)
					{
						t.changecolour_blue();
					}
					if (windowEvent.key.code == Keyboard::Num5)
					{
						t.changecolour_gray();
					}
					if (windowEvent.key.code == Keyboard::Num0)
					{
						t.returncolor();
					}

					if (windowEvent.key.code == Keyboard::Backspace) {
						t.setshow(false);
					}
				}

				if (Keyboard::isKeyPressed(Keyboard::R)) { // ѕќ¬“ќ–яёў≈√ќ—я

					if (s.getshow() == true && windowEvent.key.code == Keyboard::W) {
						s.move(Point(0.f, -mov));
					}

					if (s.getshow() == true && windowEvent.key.code == Keyboard::A) {
						s.move(Point(-mov, 0.f));
					}

					if (s.getshow() == true && windowEvent.key.code == Keyboard::S) {
						s.move(Point(0.f, mov));
					}

					if (s.getshow() == true && windowEvent.key.code == Keyboard::D) {
						s.move(Point(mov, 0.f));
					}

					if (windowEvent.key.code == Keyboard::Num1)
					{
						s.changecolour_red();
					}
					if (windowEvent.key.code == Keyboard::Num2)
					{
						s.changecolour_yellow();
					}
					if (windowEvent.key.code == Keyboard::Num3)
					{
						s.changecolour_green();
					}
					if (windowEvent.key.code == Keyboard::Num4)
					{
						s.changecolour_blue();
					}
					if (windowEvent.key.code == Keyboard::Num5)
					{
						s.changecolour_gray();
					}
					if (windowEvent.key.code == Keyboard::Num0)
					{
						s.returncolor();
					}

					if (windowEvent.key.code == Keyboard::Backspace) {
						s.setshow(false);
					}
				}					
				



				if (path == false)
				{
					window.clear();
				}


				if (c.getshow() == true) //  ќƒј!!!!!!!!!!!!!!!
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

				// должен быть вектор всех фигур, по которому ты проходишьс€
				// и выполн€ешь определЄные операции, использу€ полиморфизм
				// но как вижу, жизнь теб€ с полиморфизмом не подружила XD
			}

			window.display();

		}
	}
		


			
	system("pause > NUL");
	return 0;
}
