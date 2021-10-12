/*
����������� ����� �������, ������������ �������������� ������� ����������� ������ ������������� ������� � ������������ ��������� ����� ���������.

����������� ��� ���� ������������:
- ��� ����������, +
- �������������, +
- �����������, +
- ����������.+

���������� ������:
- ������� ����������� �������,+
- ����������� ���������� ��������� ��������� �������;+
- ���������� ��������� ������� ���������� �������.+

�����������:
- ���������� ���������� �������������� [], ������������ ���������� �������� �������� (L-value) � �� ���������� (R-value) 
� ��������� ������ �� ������� ����������� ������� (��� ��������� �������� ������� �� ��������� �������, ��������� �������� �������� ������� �� ��������� �������),+
- ���������� ���������� �����/������ �������� ��������� �������.+

���������� �������� ������ � ������������ �����, � ����������� ������� � ������� ������� ��������� � � ��������� ������.
��������� ������� ���������� ������ �������, ����������� �������� ������ �������� ������� 7.1.

��������� �������, ��������� ������������ ��������� ������ ��� ����������� �������. 
���� (� ��������� �����) n>10^9 ����������� ����� (������ ����� <10^4). 
����������� �� ����� ������������ ������ 1 ��. �������� ������ �� ���� �������� ��������� �����:

3. ������������ �� ����������� ����� <10^4, �� ������������� � �������� �����, �� �����������;

*/
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

#define max_for_int 10000
#define min_for_int 0

using namespace std;

template<class Type>
class MyVector
{
private:
	int size;
	Type* vector;
public:
	MyVector();
	MyVector(int size);
	MyVector(MyVector& vector);

	~MyVector();

	int get_size() { return size; };
	void set_size(int count); //�����������

	Type& operator[](const int index);
	Type operator[](const int index) const;

	void fill();
	void print();
};

template<class Type>
ostream& operator <<(ostream& out, MyVector<Type>& vector)
{
	cout << "Your vector:" << endl;
	for (int i = 0; i < vector.get_size(); ++i)
	{
		out << vector[i] << "  ";
	}
	cout << endl;

	return out;
}

template<class Type>
istream& operator >>(istream& in, MyVector<Type>& vect)
{
	for (int i = 0; i < vect.size; i++)
	{
		in >> vect.vector[i];
	}
	cout << endl;
	return in;
}

int input_value(int max)
{
	int test = 0;
	bool flag = true;
	bool invite = false;
	cout << "Enter count: ";
	cin >> test;

	while (flag)
	{
		if (invite)
		{
			cout << "Enter value: ";
			cin >> test;
		}

		if (test >= 1 && test <= max)
		{
			flag = false;
		}
		else
		{
			flag = true;
			invite = true;
			cout << "Your enter is not correct. Please try again..." << endl;
		}
	}

	return test;
}
void Recording_in_file(ofstream& fout, int size)
{
	for (int i = 0; i < size; ++i)
	{
		fout << rand() % (max_for_int - min_for_int) + min_for_int << endl;
	}
}

int calculate_size(ifstream& fin, MyVector<bool>& bool_arr)
{
	int value = 0;

	for (int i = 0; i < bool_arr.get_size(); ++i)
	{
		bool_arr[i] = false;
	}

	while (fin >> value)
	{
		bool_arr[value] = true;
	}

	int j = 0;
	for (int i = 0; i < bool_arr.get_size(); ++i)
	{
		if (bool_arr[i] == false)
		{
			j++;
		}
	}

	return j;
}

template<class Type>
void Fill_array(ifstream& fin, MyVector<Type>& arr, MyVector<bool>& bool_arr)
{
	int value = 0;

	for (int i = 0, j = 0; i < bool_arr.get_size() && j < arr.get_size(); ++i)
	{
		if (bool_arr[i] == false)
		{
			arr[j] = i;
			j++;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	string file_text = "File_text.txt";
	ofstream fout_text;
	fout_text.open(file_text);
	if (!fout_text.is_open())
	{
		cout << "������ �������� ����� file_text ��� ������" << endl;
		return -1;
	}
	cout << "���� file_text ������ ��� ������" << endl;
	int size = 10000;/////////////////////////////////////

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
	MyVector<bool> bool_arr(bool_size);

	int array_size = calculate_size(fin_text, bool_arr);
	cout << "array_size: " << array_size << endl;
	MyVector<int> arr(array_size);
	
	Fill_array(fin_text, arr, bool_arr);
	cout << arr << endl;

	cout << "���� file_text ������ ��� ������" << endl;
	fin_text.close();

	return 0;
}

template<class Type>
MyVector<Type>::MyVector()
{
	size = 0;
	vector = nullptr;
}

template<class Type>
MyVector<Type>::MyVector(int size)
{
	this->size = size;
	vector = new Type[size];
}

template<class Type>
MyVector<Type>::MyVector(MyVector& vec)
{	
	size = vec.size;
	vector = new Type[size];
	for (int i = 0; i < size; ++i)
	{
		vector[i] = vec.vector[i];
	}
}

template<class Type>
MyVector<Type>::~MyVector()
{
	if (vector)
	{
		//cout << "Deconstructor" << endl;
		delete[] vector;
	}
	size = 0;
}

template<class Type>
void MyVector<Type>::set_size(int count)
{
	size = count;
}

template<class Type>
Type& MyVector<Type>::operator[](const int index)
{
	if (index < size && index >= 0)
	{
		return vector[index];
	}
	else
	{
		cout << "Out of bounds of array!" << endl;
		exit(0);
	}
}

template<class Type>
Type MyVector<Type>::operator[](const int index) const
{
	if (index < size)
	{
		return vector[index];
	}
	else
	{
		cout << "Out of bounds of array!" << endl;
		exit(0);
	}

}

template<class Type>
void MyVector<Type>::fill()
{
	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		vector[i] = rand() % (max_for_int - min_for_int) + min_for_int;
	}
}

template<class Type>
void MyVector<Type>::print()
{
	cout << "Your vector:" << endl;
	for (int i = 0; i < get_size(); ++i)
	{
		cout << vector[i] << "  ";
	}
	cout << endl;
}