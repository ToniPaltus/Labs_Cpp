/*
* ��������� �������, ��������� ������������ ��������� ������ ��� ����������� �������.
���� (� ��������� �����) n>10^9 ����������� ����� (������ ����� <=10^4). 
����������� �� ����� ������������ ������ 1 ��. �������� ������ �� ���� �������� ��������� �����:

3. ������������ �� ����������� ����� <=10^4, �� ������������� � �������� �����, �� �����������;
*/
#include "Functions.h"

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	string file_text = "file_text.txt";
	ofstream fout_text;
	fout_text.open(file_text);
	if (!fout_text.is_open())
	{
		cout << "������ �������� ����� file_text ��� ������" << endl;
		return -1;
	}
	cout << "���� file_text ������ ��� ������" << endl;

	int size = 0;
	cout << "Enter size: ";
	cin >> size;

	Recording_in_file(fout_text, size);

	cout << "���� file_text ������ ��� ������" << endl;
	fout_text.close();

	ifstream fin_text;
	fin_text.open(file_text);
	if (!fin_text.is_open())
	{
		cout << "������ �������� ����� fin_text ��� ������" << endl;
		return -1;
	}
	cout << "���� file_text ������ ��� ������" << endl;

	const int bool_size = 10000;
	int array_size = 0;
	cout << "Enter array_size: ";
	array_size = Integer();

	int* arr = new int[array_size];
	bool bool_arr[bool_size];

	while (!fin_text.eof())
	{
		Fill_array(fin_text, arr, array_size, bool_arr, bool_size);
	}
	
	Show_array(arr, array_size);

	delete[] arr;
	cout << "���� file_text ������ ��� ������" << endl;
	fin_text.close();

	return 0;
}