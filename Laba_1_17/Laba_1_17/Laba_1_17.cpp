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

const auto center = 100.f;
const auto radius = 50.f;
auto mov = 5.f;
auto path = false;

RenderWindow window(VideoMode(1920, 1080), L"Моє вікно");


void keypressedfunc(S *fig, Event &windowEvent)
{
	if (fig->getshow() && windowEvent.key.code == Keyboard::W) {
		fig->move(Point(0.f, -mov));
	}

	if (fig->getshow() && windowEvent.key.code == Keyboard::A) {
		fig->move(Point(-mov, 0.f));
	}

	if (fig->getshow() == true && windowEvent.key.code == Keyboard::S) {
		fig->move(Point(0.f, mov));
	}

	if (fig->getshow() == true && windowEvent.key.code == Keyboard::D) {
		fig->move(Point(mov, 0.f));
	}



	if (windowEvent.key.code == Keyboard::Num1)
	{
		fig->changecolour_red();
	}
	if (windowEvent.key.code == Keyboard::Num2)
	{
		fig->changecolour_yellow();
	}
	if (windowEvent.key.code == Keyboard::Num3)
	{
		fig->changecolour_green();
	}
	if (windowEvent.key.code == Keyboard::Num4)
	{
		fig->changecolour_blue();
	}
	if (windowEvent.key.code == Keyboard::Num5)
	{
		fig->changecolour_gray();
	}

	if (windowEvent.key.code == Keyboard::Backspace) {
		fig->setshow(false);
	}
}

void drawing(S*fig, Event &windowEvent)
{
	if (fig->getshow() == true)
	{
		fig->Draw(window);

		cout << "FUCK" << endl;
	}
}


void Functions::out(S* fig) {
	cout << "Центр: (" << fig->getxy().getX() << ";" << fig->getxy().getY() << ")" << endl;
	cout << "Радіус: " << fig->getrad() << endl;
	cout << "Градуси: " << fig->getdeg() << endl;
	cout << "Деформація x: " << fig->getscale().getX() << endl;
	cout << "Деформація y: " << fig->getscale().getY() << endl;
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	

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

					drawing(&c, windowEvent);

					cout << "FUCK AGAIN" << endl;
				}
				if (windowEvent.key.code == Keyboard::T) {
					t.setshow(true);
				}
				if (windowEvent.key.code == Keyboard::R) {
					s.setshow(true);
				}
				// за такой простой путь можно получить по *балу от будущих задач
				// при нажатии клавиш, нужно, чтобы нужная фигура добавлялась в вектор фигур
				// а не просто появлялась в единственном экземпляре

				if (windowEvent.key.code == Keyboard::P) {
					path = true;
				}



				if (windowEvent.key.code == Keyboard::C) {

					

					keypressedfunc(&c, windowEvent);


					if (windowEvent.key.code == Keyboard::Num0)
					{
						c.returncolor();
					}

				}

				if (Keyboard::isKeyPressed(Keyboard::T)) {

					drawing(&t, windowEvent);

					keypressedfunc(&t, windowEvent);

					if (windowEvent.key.code == Keyboard::Num0)
					{
						t.returncolor();
					}
				}

				if (Keyboard::isKeyPressed(Keyboard::R)) {

					drawing(&s, windowEvent);

					keypressedfunc(&s, windowEvent);


					if (windowEvent.key.code == Keyboard::Num0)
					{
						s.returncolor();
					}

				}					
				
				
				
				


				if (path == false)
				{
					window.clear();
				}


				// должен быть вектор всех фигур, по которому ты проходишься
				// и выполняешь определёные операции, используя полиморфизм
				// но как вижу, жизнь тебя с полиморфизмом не подружила XD
			}

			window.display();

		}
	}
			
	system("pause > NUL");
	return 0;
}
