/*
3. ������ ����� n � ������� signed char. ������� �� ����� �������� 0-��,
3-�� � 7-�� ����� ������������� � ��� ����� �����. ��������� ���������. �����-
�������� ���� 3, 6. ������� � ��������� ���������.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "���������� �����, 7 ������, 1 ����. ������� ������� 6, �-�����, 3 ������� \n" << endl;

	signed char n;
	int m;
	cout << "������� n: " << endl;
	cin >> m;
	n = m;

	int bit0 = n & 1;
	int bit3 = (n >> 3) & 1;
	int bit7 = (n >> 7) & 1;

	cout << "������� ��� �����: " << bit0 << endl;
	cout << "������ ��� �����: " << bit3 << endl;
	cout << "������� ��� �����: " << bit7 << endl;

	n = n ^ (1 << 3);
	n = n ^ (1 << 6);

	cout << "��������������� �������� �����: " << int(n) << endl;

	return 0;
}