/*
* �������� ��������� ��� ������ � ����� ������, ���������� ������ �� ���������� � ���������:
���, �������, ���, ����, ������������, � ������� ������ ����������� ��������� ��������:
� �������� �����
� �������� �����
��������� ������� ��� ���������� � ��������� ������.

3. �� ��������� ����� ���������� ���� ���������, ��� ������� ���������� �� �������� �����. ������������ ���� �� ���� ���������.
*/
#include"Functions.h"

struct student
{
	string surname = "";
	string name = "";
	string fathername = "";
	int age = 0;
	string gender = "";
	int course = 0;
	double progress = 0;
};

int main()
{
	setlocale(LC_ALL, "ru");

	bool flag_bin = false;

	string file_text = "file_text.txt";
	ofstream fout_text;
	fout_text.open(file_text);
	if (!fout_text.is_open())
	{
		cout << "������ �������� ����� file_text ��� ������" << endl;
		return -1;
	}
	cout << "���� file_text ������ ��� ������" << endl;

	student person;
	int members = 0;
	cout << "Enter count of members: ";
	members = Integer(30);

	for (int i = 0; i < members; ++i)
	{
		cout << i + 1 << ") " << "Enter student: " << endl;
		Fill(person);
		Recording(flag_bin, person, fout_text);
	}
	cout << "���� file_text ������ ��� ������" << endl;
	fout_text.close();

	ifstream fin_file_text;
	fin_file_text.open(file_text);
	if (!fin_file_text.is_open())
	{
		cout << "�� ������� ������� ���� file_text ��� ������" << endl;
		return -1;
	}
	cout << "���� file_text ������ ��� ������" << endl;

	string file_text_result = "file_text_result.txt";
	ofstream fout_text_result;
	fout_text_result.open(file_text_result);

	if (!fout_text_result.is_open())
	{
		cout << "�� ������� ������� ���� file_text_result ��� ������" << endl;
		return -1;
	}
	cout << "���� file_text_result ������ ��� ������" << endl;

	char simbol;
	simbol = Simbol();
	cout << "simbol: " << simbol << endl;

	while (!fin_file_text.eof())
	{
		Recording_in_result(flag_bin, fin_file_text, fout_text_result, person, simbol);
	}
	cout << "���� file_text_result ������ ��� ������" << endl;
	fout_text_result.close();

	cout << "���� file_text ������ ��� ������" << endl;
	fin_file_text.close();
	//______________________________________________________________________________________________Bin
	flag_bin = true;
	cout << "\n Bin_file" << endl << endl;
	string file_bin = "file_bin.bin";
	ofstream fout_bin(file_bin, ios::binary);
	if (!fout_bin.is_open())
	{
		cout << "������ �������� ����� file_bin ��� ������" << endl;
		return -1;
	}
	cout << "���� file_bin ������ ��� ������" << endl;

	student person_bin;
	members = 0;
	cout << "Enter count of members: ";
	members = Integer(30);

	for (int i = 0; i < members; ++i)
	{
		cout << i + 1 << ") " << "Enter student: " << endl;
		Fill(person_bin);
		Recording(flag_bin, person_bin, fout_bin);
	}
	cout << "���� file_bin ������ ��� ������" << endl;
	fout_bin.close();

	ifstream fin_bin(file_bin);
	if (!fin_bin.is_open())
	{
		cout << "������ �������� ����� file_bin ��� ������" << endl;
		return -1;
	}
	cout << "���� file_bin ������ ��� ������" << endl;

	string file_bin_result = "file_bin_result.bin";
	ofstream fout_bin_result(file_bin_result, ios::binary);
	if (!fout_bin_result.is_open())
	{
		cout << "������ �������� ����� file_bin_result ��� ������" << endl;
		return -1;
	}
	cout << "���� file_bin_result ������ ��� ������" << endl;

	char simbol_bin;
	simbol_bin = Simbol();
	cout << "simbol: " << simbol_bin << endl;

	while (!fin_bin.eof())
	{
		Recording_in_result(flag_bin, fin_bin, fout_bin_result, person_bin, simbol_bin);
	}
	cout << "���� file_bin_result ������ ��� ������" << endl;
	fout_bin_result.close();
	cout << "���� file_bin ������ ��� ������" << endl;
	fin_bin.close();

	return 0;
}