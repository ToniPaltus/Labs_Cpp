/*
���� �������������� ����� � (0 < x <= 1). ��������� �������� ����� � �����-
���� EPS = 10�6 � ������� ���������� ���������. �������, ��� ��������� ���-
����� ����������, ���� ��������� ��������� �� ����������� �������� ������
EPS:
����������. � ��������� �� ������������ �������������� ������� �� ���-
������� math.h.
*/
#include <iostream>
using namespace std;

int main()
{
	double const EPS = 1e-6;
	double x;

	cout << "Enter the x: ";
	cin >> x;

	if (x > 0 && x <= 1)
	{
		int znak = 1,
			denominator = 0,
			fact = 1,
			k = 1,
			iter = 0;
		double numerator = x,
			slag = 1,
			sum = 0;
		double x4 = x * x * x * x;

		while (abs(slag) >= EPS)
		{
			znak = -znak;
			numerator *= x4;
			denominator = (4 * k + 1);            
			fact *= (2 * k) * ((2 * k) - 1);                        

			slag = (znak * numerator) / (denominator * fact);
			sum += slag;

			k++;
			iter++;
		}
		cout << "sum = " << sum << endl;
		cout << "Iterations: " << iter << endl;
	}
	else
	{
		cout << "Error 404" << endl;
	}
	return 0;
}

