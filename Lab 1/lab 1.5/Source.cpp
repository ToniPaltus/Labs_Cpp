/*
???? a, b, c, d, e, f, g, h ? ???????????? ?????. ????? (a, b), (c, d) ?? ?????
?? ?????? l, ?????????? ????? ????? (e, f), (g, h). ?????? l ????????? ????????? ??
??? ?????????????. ??????????, ??????????? ?? ???????? ????? (a, b), (c, d) ???-
??? ??????????????.
*/
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "?????????? ?????, 7 ??????, 1 ????. ??????? ??????? 5, ?-?????, 3 ??????? \n" << endl;

	double a, b, c, d, e, f, g, h, K, B;

	cout << "??????? ?????????? ????? ?:\na = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "??????? ?????????? ????? ?:\nc = ";
	cin >> c;
	cout << "d = ";
	cin >> d;
	cout << "??????? o??? ?? ????? ?????? l:\ne = ";
	cin >> e;
	cout << "f = ";
	cin >> f;
	cout << "??????? ?????? ?? ????? ?????? l:\ng = ";
	cin >> g;
	cout << "h = ";
	cin >> h;
	
	K = (e - h) / (f - g);
	B = (e + h - K * (f + g)) / 2;

	if (((b > (K * a + B)) && (d < (K * c + B))) || ((b < (K* a + B)) && (d > (K * c + B))))
	{
		cout << "????? ??????????? ?????? ??????????????.";
	}
	else
	{
		cout << "????? ?? ??????????? ?????? ??????????????.";
	}
	return 0;
}

  