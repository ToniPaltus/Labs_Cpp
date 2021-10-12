#pragma once
#include <map>
#include "Game.h"
#include "Fixed.h"
#include "Mobile.h"
#include "Planet.h"
#include "Star.h"
#include "Asteroid.h"
#include "Spaceship.h"
#include "Rocket.h"

class ObjectFactory //����� ������� ������� ������ ��� ������
{
private:
	map<string, Game*>	OBJECTS;//������, ������� ������ 2 ��������(�������� ������ � ��������� �� ������ ������)
	void Add_object_type(Game* obj)//��������� ������ ���������
	{
		OBJECTS.try_emplace(obj->get_Type(), obj);//push_back ��� map
	}
public:
	ObjectFactory()//��������� ��� ������� � map
	{
		Add_object_type(new Star());
		Add_object_type(new Planet());
		Add_object_type(new Asteroid());
		Add_object_type(new Spaceship());
		Add_object_type(new Rocket());
	}
	~ObjectFactory()
	{
		for (map<string, Game*>::iterator it = OBJECTS.begin(); it != OBJECTS.end(); ++it)
		{
			delete it->second;
		}
		OBJECTS.clear();//������� map
	}

	Game* create(const char* typeName)//���� ������ ��� ������ ������
	{
		map<string, Game*>::iterator it = OBJECTS.find(typeName);//��������, ������� ���� ������ � ����� ���������
		if (it == OBJECTS.end())//���� �� �����
		{
			return nullptr;
		}
		return it->second->Clone();//���������� ������������� ������ ��� ������
	}
};