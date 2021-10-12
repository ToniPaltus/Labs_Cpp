/*
 9.1. �������

 3. ����������� ������� 7.2, ��������� ���������� � ������ ���������������� �������������������� ������ vector �� ����������� ���������� �������� STL.

 7.2+
 ��������� �������, ��������� ������������ ��������� ������ ��� ���������� �������, ����� ���������:
� �������� ��������� ������ ��� ����������, � �������� �������� �������� ������� �� �������� �������;
� �������� ��������� ������ ��� ��������� �� ������ ����������.+

3. ���� ������������ ���������� ������� � ������� n, ������ b � n ����������.
��������� �������, ������� ��������� �������� ������ c = �^2 * b .
*/
#include"Functions.h"

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	int n = 0;                                                  
	n = Input(max_for_n);

	vector<vector<int>> A(n);
	A.assign(n, vector<int>(n));

	Fill(A);
	cout << "A: " << endl;
	Show(A);

	vector<vector<int>> b;
	b.assign(1, vector<int>(n));

	Fill(b);
	cout << "\nVector b:" << endl;
	Show(b);

	vector<vector<int>> A_2;
	A_2.assign(n, vector<int>(n));
	A_2 = Multiplication(A, A);

	cout << "\nA^2: " << endl;
	Show(A_2);

	vector<vector<int>> b_T;
	b_T.assign(1, vector<int>(n));

	b_T = Transpose(b);
	//cout << "\nVector b^T:" << endl;
	//Show(b_T);

	vector<vector<int>> c;
	c.assign(1, vector<int>(n));

	c = Multiplication(A_2, b_T);
	//cout << "\nVector c:" << endl;
	//Show(c);

	vector<vector<int>> �_T;
	�_T.assign(n, vector<int>(1));
	�_T = Transpose(c);

	cout << "\nVector c:" << endl;
	Show(�_T);
	//_______________________________________________________
	vector<int> A2(n * n);

	Fill2(A2);
	cout << "\nA2: " << endl;
	Show2(A2);

	vector<int> b2(n);
	Fill2(b2);
	cout << "\nVector b2:" << endl;
	Show2(b2);

	vector<int> A2_2(n, n);

	A2_2 = Multiplication2(A2, A2);
	cout << "\nA2^2: " << endl;
	Show2(A2_2);

	vector<int> b2_T(1, n);

	b2_T = Transpose2(b2);
	//cout << "\nVector b2^T:" << endl;
	//Show2(b2_T);

	vector<int> c2(1, n);
	c2 = Multiplication2(A2_2, b2_T);
	//cout << "\nVector c2:" << endl;
	//Show2(c2);

	vector<int> c2_T(n);

	c2_T = Transpose2(c2);
	cout << "\nVector c2:" << endl;
	Show2(c2_T);

	return 0;
}