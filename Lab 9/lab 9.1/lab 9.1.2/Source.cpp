/*
 9.1. �������

 2. ����������� ������� 5.3, ��������� ���������� � ������ ���������������� �������������������� ������ vector �� ����������� ���������� �������� STL.

 5.3
 ��������� ��������� ������� ��� ��������� ������. �������� ������� �
���� ������ �������: ������� ��������� ����� (�������), ������� �������� ���-
���� ����, ������� ��������� �������������� ������.
����� � �������� ������������������ ��������.
����� � �������� ������������������ ����� ��������, ����� ��������-
������������.
����������� � ������������������ ����, ����������� ����� ��� �������-
���� ���������-�������������.
�������-�����������: �������, �.�, �,�, �:�, �;�, �!�, �?�, �-�, �(�, �)�.

3. � �������� ������ ����� ��� �����, ������� ����� ���������� ����� � �����-
�� �� ���������� ������� �������� (������� �������� ����� ���� ������-
���). �������� �� � �������������� ������.
*/
#include"Functions.h"

using namespace std;

int main()
{
	vector<char> str(300, '\n');
	vector<char> seporator{ ',' ,'.','!', '?', ':', ';', '(', ')', '-', ' ' };

	cout << "Enter str:" << endl;
	int size = 0;
	fill_str(str, size);
	show_str(str, size);

	int Count_Of_Words = Getting_Count_Of_Words(str, seporator);
	cout << "Count of Words: " << Count_Of_Words << endl;

	int begin = 0;
	int end = 0;

	const int N = 20;
	vector<vector<char>> Array_Of_Words;
	Array_Of_Words.assign(N, vector<char>(N));
	int Number_Of_Word = 0;

	for (int i = 0; i < Count_Of_Words; ++i)
	{
		Getting_token(str, seporator, begin, end, Array_Of_Words, Number_Of_Word, Count_Of_Words);
	}

	ShowArray(Array_Of_Words);

	int NumberOfWord = 0;

	vector<int> Bool(Count_Of_Words, 0);
	show_str(Bool, Count_Of_Words);
	Bool_Result(Array_Of_Words, Bool, NumberOfWord, Count_Of_Words);

	vector<char> result(100);

	int startpoz = 0;

	for (int i = 0; i < Count_Of_Words; ++i)
	{
		if (Bool[i] == true)
		{
			Getting_Result(result, Array_Of_Words[i], startpoz);
		}
	}

	cout << "Result: " << endl;
	show_str(result, 100);

	return 0;
}