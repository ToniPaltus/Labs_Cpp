#include "Asteroid.h"

void Asteroid::set_diameter(unsigned int diameter) { this->diameter = diameter; };
void Asteroid::set_water(bool water) { this->water = water; };

unsigned int Asteroid::get_diameter() { return this->diameter; };
bool Asteroid::get_water() { return this->water; };

void Asteroid::fill()
{
	Mobile::fill();
	unsigned int diameter = 0;
	cout << "Enter the diameter: ";
	enter(cin, diameter);

	set_diameter(diameter);

	bool water = true;
	short solution = 0;
	bool flag = true;

	while (flag)
	{
		cout << "Choice the presence of water: " << endl
			<< "1. Presence. " << endl
			<< "2. Not presence." << endl;

		cout << "Your solution: ";
		enter(cin, solution);

		if (solution >= 1 && solution <= 2)
		{
			flag = false;
		}

		switch (solution)
		{
		case 1:
			set_water(water);
			break;
		case 2:
			set_water(!water);
			break;
		default:
			cout << "Yoops, your choise isn't correct. Please try again..." << endl;
			break;
		}
	}
}
void Asteroid::print()
{
	cout << "\nAsteroid:" << endl;
	Mobile::print();

	cout << "Diameter: " << get_diameter() << " mil." << endl;
	if (get_water())
	{
		cout << "Water: What luck! Water is here!" << endl;
	}
	else
	{
		cout << "Water: Hmm, it looks like there is no water here..." << endl;
	}
}

Asteroid::Asteroid() : Mobile()
{
	this->diameter = 0;
	this->water = false;
}
Asteroid::Asteroid(int x, int y, int z, unsigned int speed_X, unsigned int speed_Y, unsigned int speed_Z, unsigned int diameter, bool water) : Mobile(x, y, z, speed_X, speed_Y, speed_Z)
{
	this->diameter = diameter;
	this->water = water;
}
Asteroid::Asteroid(Mobile& object_mobile, Asteroid& object) : Mobile(object_mobile)
{
	this->diameter = object.get_diameter();
	this->water = object.get_water();
}
Asteroid::~Asteroid()
{
	//cout << "Asteroid destructor is here!" << endl;
}