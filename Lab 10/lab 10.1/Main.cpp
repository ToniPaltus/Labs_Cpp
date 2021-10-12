/*
* 10. ������������. �����������

10.1. ������������

� ������������ ���� ��������� ����������� ���������� ������. ��� ��:
- ���������� � ������� �������� �������: ����� ������ �� ������-���� �������� ��������, ������������ � ��������� (������������ �������).+
- ��� ������� ������ ������� ����, ��������������� ������, +
 - � ������, ����������� ��������� � �������� �������� ������� �� �����,+
 - �������� �������� ����� �� �����,+
 - � ����� ����������� ������������.+
- ����� �������� ������� � ������������ �������.+
- ������������ � ������ ������ ��������� ��������� �� ������������.+
- ����� ������� ������������ ������� ����������� � �������������� ������������ � ������������ +
(����������� ����� Print(), ������� ���������� �� operator<< �������� ������). +
- ������ ����� ������ ����� �������� � ���� ������ ���� ��� � ����� ����� �������.+
2. �������� ����� � ��������������.+
3. ����������� �������� � ����.+
4. ������� ��������� ��� ������������ ��������� ��������, ��������� � ����������� �������� ���������� ��������� ��������,
� ����� ��������� �������� ���� ��������� �������� �� �����.+
- ��������� ������������� ������� �������� ����������� � ������� �������������.+
���������� 1: ����� ������� ����� �������� ������� ���� ������� ���������, ��������� � � ������������ �������� ������.+
���������� 2: �� ���� ��������� �������������� �� ����� 3 ������� � �������� ������������. +
��� ������ - ���������� � �������� �� ��������� � ������� ��-��������� ��� ������� ������. + 

������� 3

�� ������������ 3D RPG ���� �� ����������� ����.+

� �� ������� ����� ����� ���������� ������������ ������ ��������.
��� ���������� ������ ������ ���� ��� ���������� ����������� �������� ������������ �������+ 
��� ������������� � ��������� ���������� ������������ ������ ��������� � �� �������:+

1. ����������� (������� ��������� � ������ ������ ������� ������������� ������������ ������ ��� ��������� �������): ������, �������
� ��������
� �����������
� ������� ������ �����������, �� ������� ����� ����������

2. �������� - ��������� ������ ������.
� ���������� (X, Y, Z)
� �������� (Vx, Vy, Vz)
� ������������ ������ � �����������

3. ����������� ������� (��� ����������� ������, ��� ����������)
� ���
� ���������� (X, Y, Z)
� �������� (Vx, Vy, Vz)
� ������������ �������� Vmax
� �������� (������� �������� ���������)

4. ������ ���������� ����� �� ��������
� ���������� (X, Y, Z)
� �������� (Vx, Vy, Vz)
� �������� ����������
� �����, �� ������� ������� ����� ������� (� ��������)
*/
#include "Game.h"
#include "Fixed.h"
#include "Mobile.h"
#include "Planet.h"
#include "Star.h"
#include "Asteroid.h"
#include "Spaceship.h"
#include "Rocket.h"

using namespace std;

int main()
{
	Star star;
	cout << "Create star: " << endl;
	star.fill();
	cout << "\nYour star: " << endl;
	star.print();

	Planet planet;
	cout << "\nCreate planet: " << endl;
	planet.fill();
	cout << "\nYour planet: " << endl;
	planet.print();
	
	Asteroid asteroid;
	cout << "\nCreate asteroid: " << endl;
	asteroid.fill();
	cout << "\nYour asteroid: " << endl;
	asteroid.print();

	Spaceship spaceship;
	cout << "\nCreate spaceship: " << endl;
	spaceship.fill();
	cout << "\nYour spaceship: " << endl;
	spaceship.print();

	Rocket rocket;
	cout << "\nCreate rocket: " << endl;
	rocket.fill();
	cout << "\nYour rocket: " << endl;
	rocket.print();

	return 0;
}