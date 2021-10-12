/*
 9.1. �������

 1. ����������� ������� 7.1, ��������� ���������� � ������ ���������������� �������������������� ������ vector �� ����������� ���������� �������� STL.

 7.1+
 ��������� �������, ��������� ������������ ��������� ������ ��� ����-������� �������.
 ���� (� ��������� �����) n>10^9 ����������� ����� (������ ����� <10^4).
 ����������� �� ����� ������������ ������ 1 ��. �������� ������ �� ���� �������� ��������� �����:

 3. ������������ �� ����������� ����� <10^4, �� ������������� � �������� �����, �� �����������;

*/
#include"Functions.h"

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	string file_text = "File_text.txt";  
	ofstream fout_text;

	fout_text.open(file_text);
	if (!fout_text.is_open())
	{
		cout << "������ �������� ����� file_text ��� ������" << endl;
		return -1;
	}
	//cout << "���� file_text ������ ��� ������" << endl;

	int size = 10000;/////////////////////////////////////

	Recording_in_file(fout_text, size);
	//cout << "���� file_text ������ ��� ������" << endl;

	fout_text.close();
	ifstream fin_text;

	fin_text.open(file_text);
	if (!fin_text.is_open())
	{
		cout << "������ �������� ����� fin_text ��� ������" << endl;
		return -1;
	}
	//cout << "���� file_text ������ ��� ������" << endl;

	const int bool_size = 10000;//////////////////////

	vector<bool> bool_arr(bool_size);
	int array_size = calculate_size(fin_text, bool_arr);

	//cout << "array_size: " << array_size << endl;
	vector<int> arr(array_size);

	Fill_array(fin_text, arr, bool_arr);
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << "  ";
	}

	//cout << "���� file_text ������ ��� ������" << endl;
	fin_text.close();

	return 0;
}