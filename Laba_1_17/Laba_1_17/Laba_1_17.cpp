#include "stdafx.h"
#include <iostream>
#include <Windows.h>

#include<vector>

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

RenderWindow window(VideoMode(1920, 1080), L"Моє вікно");

float s1[2] = { 0,0 };
float e[2] = { 1900,1060 };

Point start;
Point en;


void keypressedfunc(S *fig, Event &windowEvent)
{
	fig->setrotatorpos(15.f);
	fig->setrotatorneg(-15.f);


	if (fig->getshow() == true) {

		if (en > fig->getxy())
		{
			fig->move(Point(fig->getmov(), fig->getmov()));
		}
		else if (en >= fig->getxy() && start <= fig->getxy())
		{
			fig->move(Point(-fig->getmov(), -fig->getmov()));
		}
	}

	if (windowEvent.key.code == Keyboard::Equal) {
		if (fig->getmov() < 100)
		{
			fig->setmov(fig->getmov() + 5);
		}
	}
	if (windowEvent.key.code == Keyboard::Hyphen) {
		if (fig->getmov() > 5)
		{
			fig->setmov(fig->getmov() - 5);
		}
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

	

	if (windowEvent.key.code == Keyboard::Backspace) {
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

void drawing(S*fig)
{
	if (fig->getshow() == true)
	{
		fig->Draw(window);
	}
}

enum shapes
{
	CIRCLE,
	TRIANGLE, 
	SQUARE,
	AGGR
};

class Agr : public S
{
private:
	vector<S*> ActiveShapes;

public:
	Agr(initializer_list<S*> ActiveShapes)
	{
		for (const auto &i : ActiveShapes)
		{
			this->ActiveShapes.push_back(i);
		}
	}

	void move(Point xy) override
	{
		for (auto& i : this->ActiveShapes)
		{
			i->move(xy);
		}
	}

	void movebyvalue(Point xy) override
	{
		for (auto& i : this->ActiveShapes)
		{
			i->movebyvalue(xy);
		}
	}

	void setcolour(RGBA Col) override
	{
		for (auto& i : this->ActiveShapes)
		{
			i->setcolour(Col);
		}
	}

	void deformx(float times) override
	{
		for (auto& i : this->ActiveShapes)
		{
			i->deformx(times);
		}
	}

	void deformy(float times) override
	{
		for (auto& i : this->ActiveShapes)
		{
			i->deformy(times);
		}
	}

	void doubledeform(float times) override
	{
		for (auto& i : this->ActiveShapes)
		{
			i->doubledeform(times);
		}
	}


	Point getxy()
	{
		for (auto& i : this->ActiveShapes)
		{
			i->getxy();
		}
	}


	void setxy(Point x1y1)
	{
		for (auto& i : this->ActiveShapes)
		{
			i->setxy(x1y1);
		}
	}

	float getrad()
	{
		for (auto& i : this->ActiveShapes)
		{
			i->getrad();
		}
	}

	float getdeg()
	{
		for (auto& i : this->ActiveShapes)
		{
			i->getdeg();
		}
	}

	Point getscale()
	{
		for (auto& i : this->ActiveShapes)
		{
			i->getscale();
		}
	}

	void setscale(Point x2y2);
	bool getshow();
	void setshow(bool show_1);
	void changecolour_red();
	void changecolour_yellow();
	void changecolour_green();
	void changecolour_blue();
	void changecolour_gray();
	void hide();
	bool getpath();
	void setpath(bool path_1);
	bool gethidepath();
	void sethidepath(bool path_1);
	void setcolour(RGBA Colour) override;
	void setstartcolour(RGBA Colour);
	void returncolor();
	void returnpoint();
	RGBA getstartcolour();
	RGBA getcolour();
	void setdeg(float deg);
	void setstartdeg(float degree);
	float getstartdeg();
	void returndeg();
	RGBA getcurrentcolour();
	void setcurrentcolour(RGBA Colour);
	Point getstartpoint();
	void setstartpoint(Point xy);
	void setstartscale(Point x2y2);
	Point getstartscale();
	void returnscale();
	void setrotatorpos(float rot);
	float getrotatorpos();
	void setrotatorneg(float rot);
	float getrotatorneg();
	float getdeformerx();
	void setdeformerx(float defx);
	float getdeformery();
	void setdeformery(float defy);
	float getdeformer();
	void setdeformer(float def);
	void setmov(int k);
	int getmov();

};

void Functions::out(S* shape) {
	cout << "Центр: (" << shape->getxy().getX() << ";" << shape->getxy().getY() << ")" << endl;
	cout << "Радіус: " << shape->getrad() << endl;
	cout << "Градуси: " << shape->getdeg() << endl;
	cout << "Деформація x: " << shape->getscale().getX() << endl;
	cout << "Деформація y: " << shape->getscale().getY() << endl;
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	

	vector<S*> ActiveShapes
	{
		new Circle(Point(center), radius, RGBA(205,100,200, 200)),
		new Triangle(Point(center), radius, RGBA(128,128,0,200)),
		new Square(Point(center), radius, RGBA(255,0,255,200)),
		//new Agr(new Circle(Point(center), radius, RGBA(205,100,200,200)));
	};
	
	Functions::out(ActiveShapes[CIRCLE]);

	start = s1;
	en = e;

	while (window.isOpen())
	{
		Event windowEvent;

		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == Event::Closed) window.close();

			if (windowEvent.type == Event::KeyReleased)
			{
				

				if (Keyboard::isKeyPressed(Keyboard::Q)) {

					if (windowEvent.key.code == Keyboard::C) {

						ActiveShapes[CIRCLE]->setshow(true);

						ActiveShapes[CIRCLE]->setcolour(ActiveShapes[CIRCLE]->getcurrentcolour());

						ActiveShapes[CIRCLE]->setpath(ActiveShapes[CIRCLE]->gethidepath());

					}
					if (windowEvent.key.code == Keyboard::T) {
						ActiveShapes[TRIANGLE]->setshow(true);

						ActiveShapes[TRIANGLE]->setcolour(ActiveShapes[TRIANGLE]->getcurrentcolour());

						ActiveShapes[TRIANGLE]->setpath(ActiveShapes[TRIANGLE]->gethidepath());

					}
					if (windowEvent.key.code == Keyboard::R) {
						ActiveShapes[SQUARE]->setshow(true);

						ActiveShapes[SQUARE]->setcolour(ActiveShapes[SQUARE]->getcurrentcolour());

						ActiveShapes[SQUARE]->setpath(ActiveShapes[SQUARE]->gethidepath());

					}

				}

				if (Keyboard::isKeyPressed(Keyboard::C)) {

					keypressedfunc(ActiveShapes[CIRCLE], windowEvent);

				}

				if (Keyboard::isKeyPressed(Keyboard::T)) {

					keypressedfunc(ActiveShapes[TRIANGLE], windowEvent);

				}

				if (Keyboard::isKeyPressed(Keyboard::R)) {

					keypressedfunc(ActiveShapes[SQUARE], windowEvent);

				}


				for(auto& i : ActiveShapes)
				{
					drawing(i);
				}

			}

			window.display();

		}
	}

	for (auto& i : ActiveShapes)
	{
		delete(i);
	}
				
	system("pause > NUL");
	return 0;
}
