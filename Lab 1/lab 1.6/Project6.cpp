﻿/*
3. Задано число n в формате signed char. Вывести на экран значения 0-го,
3-го и 7-го битов представления в ЭВМ этого числа. Объяснить результат. Инвер-
тировать биты 3, 6. Вывести и объяснить результат.
*/
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Пастушенко Антон, 7 группа, 1 курс. Решение задания 6, Б-часть, 3 вариант \n" << endl;

	signed char n, copy;

	cout << "Введите число n: " << endl;
	cin >> n;
	copy = n;

	int bit0 = (n >> 0) & 1;
	int bit3 = (n >> 3) & 1;
	int bit7 = (n >> 7) & 1;

	cout << "Нулевой бит равен: " << bit0 << endl;
	cout << "Третий бит равен: " << bit3 << endl;
	cout << "Седьмой бит равен: " << bit7 << endl;

	/*n ^= 1 << 3;
	n ^= 1 << 6;
	cout << n;*/

	return 0;
}