/*
��������� ������� ��� �������� ������ ��������, ��������� C-������ ���
������������� ������.

����� � �������� ������������������ ��������.

����� � �������� ������������������ ����� ��������, ����� ��������-
������������.

����������� � ������������������ ����, ����������� ����� ��� �������-
���� ���������-�������������.

�������-�����������: �������, �.�, �,�, �:�, �;�, �!�, �?�, �-�, �(�, �)�.

3. �������� � ����� ������ ��� �������������� �����, ������� ����� ������
�����.
*/
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	const int SIZE = 300;

	char str[SIZE];
	char STR[SIZE];

	char delimetor[] = { " .,:;!?-()" };

	cin.getline(str, SIZE);

	char* word = strtok(str, delimetor);

	int Pos = 0;

	while (word)
	{
		bool noSimmetric = false; //����������� ��� ����� �����������

		int length = strlen(word);

		if (length % 2 == 0) //�������� �� ��������
		{
			for (int i = 0, j = length - 1; i < j; ++i, --j)
			{
				if (word[i] != word[j])    //�������� �� �����������
				{
					noSimmetric = true;
					break;
				}
			}
		}

		if (noSimmetric)   //���������� ����� � ����� ������
		{
			for (int i = 0; i < length; ++i, ++Pos)
			{
				STR[Pos] = word[i];
			}

			STR[Pos++] = ' ';
		}

		word = strtok(nullptr, delimetor);   //������� ��������� �����
	}

	STR[Pos] = '\0';

	cout << STR;

	return 0;
}