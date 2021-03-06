/*
Найти область допустимых значений функции и написать программу, вычис-
ляющую значение функции для заданных начальных данных (s, t - целые, x - веще-
ственное), обеспечив варианты: ввода данных с клавиатуры, инициализации дан-
ных в программе, вывода результата на экран.
Для тестирования исходные данные задавать как целые, вещественные с
фиксированной точкой, плавающей точкой.
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	cout << "Решение примера 1, Б-часть, 3 вариант" << endl;

	int s, t;
	double x, y;

	cout << "Введите целое число s: " << endl;
	cin >> s;

	cout << "Введите целое число t: " << endl;
	cin >> t;

	cout << "Введите вещественное число x: " << endl;
	cin >> x;

	double d = pow(x, t);

	if (d > 0 && x + s * log(d) > 0)
	{
		y = (exp(x / 2)) / (sqrt(x + s * log(d)));

		cout << "Значение функции y = " << y << endl;
	}
	else
	{
		cout << "Введенные значения не удовлетворяют области определения функции!" << endl;
	}

	return 0;
}