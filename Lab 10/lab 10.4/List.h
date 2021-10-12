/*
10.4. �����������. ����������� ������

������� ������ ������ ������������ ������ ���������� � ������ ��������� (���������������� �������� �� ������� 8.4).
������������ ��� ��� �������� ���������� ��������-��������, ��������� � 10.1. ��� ������� ������ ����������� ��������� ������:

� ������������� ������;+
� ���������� ������� � ������;+
� ���������� �������� (� ��������� �������, �� ������� �� ���������);+
� �������� ��������� ������ � ����� �� ����� ��������� ������ � ���������������� ������ ��� ������� �������;+
� �������� ���� ���������, ���������� � ������ (� ��������� ��������).+
- �������� ����� �������.+

����������:
- �����������,+
- ����������� �����������,+
- �������� �����������,+
- ����������,+
- ��������� ������������ ���������� �������.+
*/

#pragma once
#include <iostream>
#include <string>
#include "Game.h"
#include "Fixed.h"
#include "Mobile.h"
#include "Planet.h"
#include "Star.h"
#include "Asteroid.h"
#include "Spaceship.h"
#include "Rocket.h"

using namespace std;

template<class T>
class List
{
private:
	template<class T>
	class Node
	{
	public:
		T* data;
		Node<T>* next_node;

		Node(T* data = nullptr, Node<T>* next_node = nullptr)
		{
			this->data = data;
			this->next_node = next_node;
		}
	};

	int size;
	Node<T>* head;

public:

	List();
	List(List<T>& list);
	~List();

	int get_size();

	void push_back();
	void push_back(T* data);
	void push_front();

	void pop_back();
	void pop_front();
	void removeAt(int index);

	void fill();
	void print();
	void clear();

	void operator=(List<T>& list);
};

template<class T>
List<T>::List()
{
	this->size = 0;
	this->head = nullptr;
}
template<class T>
List<T>::List(List<T>& list)
{
	Node<T>* current_node = list.head;
	while (current_node)
	{
		push_back(current_node->data);
		current_node = current_node->next_node;
	}
}
template<class T>
List<T>::~List()
{
	clear();
}

template<class T>
int List<T>::get_size() { return this->size; };

template<class T>
void List<T>::push_back()
{
	Node<T>* new_node = new Node<T>;

	cout << "\nChoice the new object: " << endl
		<< "1. Star." << endl
		<< "2. Planet." << endl
		<< "3. Asteroid." << endl
		<< "4. Spaceship." << endl
		<< "5. Rocket." << endl;

	int solution = 0;
	bool flag = true;
	while (flag)
	{
		cout << "Your choice: ";
		cin >> solution;
		if (solution >= 1 && solution <= 5)
		{
			flag = false;
		}

		switch (solution)
		{
		case 1:
		{
			cout << "\nStar!" << endl;
			Star *star = new Star;
			star->fill();
			*new_node = star;
		}
		break;
		case 2:
		{
			cout << "\nPlanet!" << endl;
			Planet *planet = new Planet;
			planet->fill();
			*new_node = planet;
		}
		break;
		case 3:
		{
			cout << "\nAsteroid!" << endl;
			Asteroid *asteroid = new Asteroid;
			asteroid->fill();
			*new_node = asteroid;
		}
		break;
		case 4:
		{
			cout << "\nSpaceship!" << endl;
			Spaceship* spaceship = new Spaceship;
			spaceship->fill();
			*new_node = spaceship;
		}
		break;
		case 5:
		{
			cout << "\nRocket!" << endl;
			Rocket *rocket = new Rocket;
			rocket->fill();
			*new_node = rocket;
		}
		break;
		}
	}

	if (head == nullptr)
	{
		head = new_node;
	}
	else
	{
		Node<T>* current_node = head;
		while (current_node->next_node != nullptr)
		{
			current_node = current_node->next_node;
		}
		current_node->next_node = new_node;
	}

	this->size++;
}
template<class T>
void List<T>::push_back(T* data)
{
	Node<T>* new_node = new Node<T>;
	*new_node = data;

	if (head == nullptr)
	{
		head = new_node;
	}
	else
	{
		Node<T>* current_node = head;
		while (current_node->next_node != nullptr)
		{
			current_node = current_node->next_node;
		}
		current_node->next_node = new_node;
	}

	this->size++;
}
template<class T>
void List<T>::push_front()
{
	Node<T>* new_node = new Node<T>;

	cout << "\nChoice the new object: " << endl
		<< "1. Star." << endl
		<< "2. Planet." << endl
		<< "3. Asteroid." << endl
		<< "4. Spaceship." << endl
		<< "5. Rocket." << endl;

	int solution = 0;
	bool flag = true;
	while (flag)
	{
		cout << "Your choice: ";
		cin >> solution;
		if (solution >= 1 && solution <= 5)
		{
			flag = false;
		}

		switch (solution)
		{
		case 1:
		{
			cout << "\nStar!" << endl;
			Star* star = new Star;
			star->fill();
			*new_node = star;
		}
		break;
		case 2:
		{
			cout << "\nPlanet!" << endl;
			Planet* planet = new Planet;
			planet->fill();
			*new_node = planet;
		}
		break;
		case 3:
		{
			cout << "\nAsteroid!" << endl;
			Asteroid* asteroid = new Asteroid;
			asteroid->fill();
			*new_node = asteroid;
		}
		break;
		case 4:
		{
			cout << "\nSpaceship!" << endl;
			Spaceship* spaceship = new Spaceship;
			spaceship->fill();
			*new_node = spaceship;
		}
		break;
		case 5:
		{
			cout << "\nRocket!" << endl;
			Rocket* rocket = new Rocket;
			rocket->fill();
			*new_node = rocket;
		}
		break;
		}
	}

	//new_node->data = data;
	//new_node->next_node = nullptr;

	new_node->next_node = head;
	head = new_node;

	this->size++;
}

template<class T>
void List<T>::pop_back()
{
	Node<T>* current_node = head;
	Node<T>* previous_node = head;

	while (current_node->next_node != nullptr)
	{
		previous_node = current_node;
		current_node = current_node->next_node;
	}
	previous_node->next_node = nullptr;
	delete current_node;

	this->size--;
}
template<class T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->next_node;

	delete temp;
	size--;
}
template<class T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous_node = head;

		for (int i = 0; i < index - 1; ++i)
		{
			previous_node = previous_node->next_node;
		}

		Node<T>* toDelete = previous_node->next_node;
		previous_node->next_node = toDelete->next_node;
		delete toDelete;

		size--;
	}
}

template<class T>
void List<T>::fill()
{
	int CountOfMembers = 0;
	cout << "Enter counnt of members: ";
	cin >> CountOfMembers;

	for (int i = 0; i < CountOfMembers; ++i)
	{
		push_back();
	}
}
template<class T>
void List<T>::print()
{
	Node<T>* current_node = head;

	cout << "\nVirtual: " << endl;
	while (current_node != nullptr)
	{
		current_node->data->print();
		current_node = current_node->next_node;
	}
	cout << endl << endl;
}
template<class T>
void List<T>::clear()
{
	while (size)
	{
		pop_back();
	}
}

template<class T>
void List<T>::operator=(List<T>& list)
{
	List(list);
}