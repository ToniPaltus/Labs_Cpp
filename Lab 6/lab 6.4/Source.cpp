/*
���������� ����������� � �������� ������ ��� ������������� �������� ����������. ������� ������� ������ ����� �� �����. ������������� ���������
������ ����� ��������. ������������� �������� ������� ����������� �������� std::sort. ����� ������������� �������� � ������� �� �� �����:

3.������������ ��� unsigned short ��� �������� ��������� ������� �����, ������� ����: ��� (0..11), ������ (0..59), ������� (0..59).
*/
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
using namespace std;

union Clock
{
	unsigned short Time;
	struct
	{
		unsigned short sec : 6;
		unsigned short min : 6;
		unsigned short hrs : 4;
	};
};

void showdata(Clock T)
{
	cout << T.hrs << "." << T.min << "." << T.sec << endl;
}

void getdata(Clock** arr, int n)
{
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		(*arr)[i].Time = rand();
	}
}

bool comparing(const Clock& time1, const Clock& time2)
{
	return (time1.Time < time2.Time);
}

int main()
{
	setlocale(LC_ALL, "rus");

	int num = 0;
	cout << "������� ������ �������: ";
	cin >> num;

	Clock* arr = new Clock[num];

	getdata(&arr, num);

	cout << "�������� ������:\n";
	for (int i = 0; i < num; i++)
	{
		showdata(arr[i]);
	}

	sort(&arr[0], &arr[num], comparing);
	cout << endl;

	cout << "��������������� ������:\n";
	for (int i = 0; i < num; i++)
	{
		showdata(arr[i]);
	}

	return 0;
}
