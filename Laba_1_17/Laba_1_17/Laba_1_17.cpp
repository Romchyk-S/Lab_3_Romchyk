#include "stdafx.h"
#include <iostream>
#include <Windows.h>

#include "Base classes.h"
#include "Interfaces.h"
#include "Shape classes.h"
#include <vector>

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
auto mov = 20.f;
auto path = false;

vector<S> Active_Shapes;
auto v = 0;

RenderWindow window(VideoMode(1920, 1080), L"Моє вікно");

void begin(S*fig)
{
	fig->setstartcolour(fig->getcolour());
	fig->setstartpoint(fig->getxy());
	fig->setstartscale(fig->getscale());
	fig->setstartdeg(fig->getdeg());
	fig->setcurrentcolour(fig->getcolour());
	fig->setpath(false);
	fig->setdeformer(2.f);
	fig->setdeformerx(2.f);
	fig->setdeformery(2.f);
	fig->sethidepath(false);
}

void keypressedfunc(S *fig, Event &windowEvent)
{
	fig->setrotatorpos(15.f);
	fig->setrotatorneg(-15.f);

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

	if (windowEvent.key.code == Keyboard::P) {
		fig->setpath(!(fig->getpath()));
	}

	if (windowEvent.key.code == Keyboard::Num1)
	{
		fig->changecolour_red();
		fig->setcurrentcolour(fig->getcolour());
	}

	if (windowEvent.key.code == Keyboard::Num2)
	{
		fig->changecolour_yellow();
		fig->setcurrentcolour(fig->getcolour());
	}

	if (windowEvent.key.code == Keyboard::Num3)
	{
		fig->changecolour_green();
		fig->setcurrentcolour(fig->getcolour());
	}

	if (windowEvent.key.code == Keyboard::Num4)
	{
		fig->changecolour_blue();
		fig->setcurrentcolour(fig->getcolour());
	}

	if (windowEvent.key.code == Keyboard::Num5)
	{
		fig->changecolour_gray();
		fig->setcurrentcolour(fig->getcolour());
	}

	if (windowEvent.key.code == Keyboard::Num0)
	{
		fig->returncolor();
	}

	

	if (windowEvent.key.code == Keyboard::H) {
		fig->setshow(false);
		fig->sethidepath(fig->getpath());
		fig->setpath(false);
	}

	if (windowEvent.key.code == Keyboard::X) {
		fig->deformx(fig->getdeformerx());
		fig->setdeformerx(fig->getdeformerx() + 1.f);
	}

	if (windowEvent.key.code == Keyboard::Y) {
		fig->deformy(fig->getdeformery());
		fig->setdeformery(fig->getdeformery() + 1.f);
	}

	if (windowEvent.key.code == Keyboard::Z) {
		fig->doubledeform(fig->getdeformer());
		fig->setdeformer(fig->getdeformer() + 1.f);
		fig->setdeformerx(fig->getdeformerx() + 1.f);
		fig->setdeformery(fig->getdeformery() + 1.f);
	}
	
	if (windowEvent.key.code == Keyboard::Left) {
		fig->setdeg(fig->getdeg() + fig->getrotatorpos());
	}

	if (windowEvent.key.code == Keyboard::Right) {
		fig->setdeg(fig->getdeg() + fig->getrotatorneg());
	}

	if (fig->path == false)
	{
		window.clear();
	}
	
	if (windowEvent.key.code == Keyboard::B)
	{
		fig->returncolor();
		fig->returnpoint();
		fig->returnscale();
		fig->returndeg();
		fig->setpath(false);

		fig->setcurrentcolour(fig->getcolour());
	}
}

void drawing(S*fig, Event &windowEvent)
{
	if (fig->getshow() == true)
	{
		fig->Draw(window);
	}
}

void Functions::out(S* shape) {
	cout << "Центр: (" << shape->getxy().getX() << ";" << shape->getxy().getY() << ")" << endl;
	cout << "Радіус: " << shape->getrad() << endl;
	cout << "Градуси: " << shape->getdeg() << endl;
	cout << "Деформація x: " << shape->getscale().getX() << endl;
	cout << "Деформація y: " << shape->getscale().getY() << endl;
};

void createshapes(S* shape)
{
	shape->setshow(true);

	shape->setcolour(shape->getcurrentcolour());

	shape->setpath(shape->gethidepath());

}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	

	Circle c(Point(center, center), radius);
	Triangle t(Point(center, center), radius);
	Square s(Point(center, center), radius);

	begin(&c);
	begin(&t);
	begin(&s);

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

				if (Keyboard::isKeyPressed(Keyboard::Q)) {
						
					if (windowEvent.key.code == Keyboard::C) {
						Active_Shapes.push_back(c);

						v++;

						createshapes(&Active_Shapes[v-1]);

					}
					if (windowEvent.key.code == Keyboard::T) {
						Active_Shapes.push_back(t);

						v++;

						createshapes(&Active_Shapes[v-1]);
	
					}
					if (windowEvent.key.code == Keyboard::R) {
						Active_Shapes.push_back(s);

						v++;

						createshapes(&Active_Shapes[v-1]);
									
					}

				}

				keypressedfunc(&Active_Shapes[v-1], windowEvent);

				if (windowEvent.key.code == Keyboard::BackSpace) {
					Active_Shapes.pop_back();
				}


				drawing(&Active_Shapes[v-1], windowEvent);
			}

			window.display();

		}
	}
				
	//system("pause > NUL");
	return 0;
}
