/*
10.2. �����������. ����������� ������

����������� ����� ����������� ������������ ������ �� ��������-��������, ��������� � 10.1�.

����������� ��������� ������:
� �������� �������;+
� ��������� ������� � ������;+
� �������� ������� �� �������;+
� ����� �� ����� ��������� ������� � ���������������� ������ ��� ������� �������;+
� �������� �������.+

����������:
- �����������,+
- ����������� �����������,+
- ����������,+
- ����������� ������.+
- ��������� ������������ ���������� �������.+
*/
#include "Vector.h"

using namespace std;

int main()
{
	Vector objects;
	objects.fill();
	objects.print();
	objects.pop_back();
	objects.print();

	return 0;
}