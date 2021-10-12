#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

static string twodigit = "<=>===!=&&";//������ ����� ��������

int string_to_int(string value);//��������� ������ � ���
bool is_digit(char ch);//������� �� �������

class Line
{
private:
	vector<string> expression;//��� ���������
	stack<string> operation;//������ �������� � �����
	stack<int> arguments;//������ ������� � �����

public:
	Line() {};
	Line(string line);//����������� � ����������

	bool is_number(int i);//�������� �� �������
	bool is_logical(int i);//�������� �� ���������� ��������
	bool is_brkt(int i);//�������� �� ��������

	void Convertation();//������� ��������� ����������
	bool Operate(int& a, int& b, string& operat);//������� ���������� ��������������� ��������
	bool Operate(int& a);//�������������� ����������
	void COUT();//�����
};