#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#define RANK 256

using namespace std;

int input_value(int max);
void fill_arr(int*& arr, int size);
void print_arr(int* arr, int size);

string fill_degree(int osn, int degree);

void sum(int* result, int* current, int size);
void convert_to_string(string& result_str, int* arr, int size);

unsigned long long convert_dec_to_bin(int dec);
//�����������
string convert_dec_to_bin(string dec);

class Number
{
private:
	static const int m_rank = 256;
	int* m_arr;
public:
	Number();//+
	Number(int dec);//��� ������
	Number(string dec);//�����������
	Number(Number& odject);//+
	~Number();//+

	void set_m_arr(int* arr, int size);//+

	int* get_m_arr();//+
	int get_m_rank() { return m_rank; }//+

	void fill();//��� >> +
	void clear();//+

	void print();//��� ������ +
	void print_reverse();//��� << +

	void shift_left(int n);//��� > +
	void shift_right(int n);//��� < +

	void operator <(int n);//+
	void operator >(int n);//+

	friend ostream& operator <<(ostream& out, Number& num);//+
	friend istream& operator >>(istream& in, Number& num);//+

	int& operator[] (const int index);//+
	int operator[](const int index) const;//+

	string convert_bin_to_dec();//+
};