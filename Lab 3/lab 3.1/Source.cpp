/*
��� ������ ����� �����, ���������� n ���������. ��� ������������ �����-
�������� ����������� �������� �������� ������� ��������� �������: ���
�������� � ��������������, ����������� �������� (� ��� ����� ���������), ���
������ ����������� ��������.

3. �������� �� ���� �������� ������ �(�), ������������� �� �����������,
����� ������� �������� A(N) � B(M), ������������� �� �����������
(K = N + M).
*/
#include<iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	const int A = 10;
	const int B = 10;

	int N = 10;
	int M = 10;

	int arr_A[A] = { -13, -7, -3, 0, 1, 2, 6, 11, 36, 56 };
	int arr_B[B] = { -17, -5, -4, 0, 2, 3, 8, 17, 22, 45 };

	cout << "�������� ������ ������� �������� �(N) � �(M):\n" << endl;
	cout << "1.������ �(N) � �(M) ��� ������������������� ��� ��������." << endl
		<< "2.������� �(N) � �(M) �������� ������� �������������." << endl
		<< "3.������� �(N) � �(M) ����������� ���������� �������." << endl;

	int solution;
	
	cout << "\n��� �������: ";
	cin >> solution;
	
	switch (solution)
	{
		case 1:
		{
			int fixSize = 10;
			cout << "\n1.������ �(N) � �(M) ��� ������������������� ��� �������� (N � M ����� 10):" << endl;			

			cout << "\n\tA" << endl;

			for (int i = 0; i < fixSize; i++)
			{
				cout << "| " << "arr_A[" << i << "] = " << arr_A[i] << endl;
			}

			cout << "\n\tB" << endl;

			for (int i = 0; i < fixSize; i++)
			{
				cout << "| " << "arr_B[" << i << "] = " << arr_B[i] << endl;
			}
		}
		break;

		case 2:
		{
			cout << "\n2.������� �(N) � �(M) �������� ������� �������������:" << endl;

			cout << "\n������� ������ ������� � (�� 0 �� 10): ";
			cin >> N;

			cout << "\n\tA" << endl;

			for (int i = 0; i < N; i++)
			{
				cout << "|" << "arr_A[" << i << "] = ";
				cin >> arr_A[i];
			}

			cout << "\n������� ������ ������� B (�� 0 �� 10): ";
			cin >> M;

			cout << "\n\tB" << endl;

			for (int i = 0; i < M; i++)
			{
				cout << "|" << "arr_B[" << i << "] = ";
				cin >> arr_B[i];
			}
		}
		break;

		case 3:
		{
			cout << "\n3.������� �(N) � �(M) ����������� ���������� �������:" << endl;
			
			cout << "\n������� ������ ������� � (�� 0 �� 10): ";
			cin >> N;

			cout << "\n\tA" << endl;

			for (int i = 0; i < N; i++)
			{
				arr_A[i] = rand() % 50;
				cout << "|" << "arr_A[" << i << "] = "<< arr_A[i] << endl;
			}

			int box1; 

			for (int i = 0; i < N - 1; i++) 
			{
				for (int j = 0; j < N - i - 1; j++)
				{
					if (arr_A[j] > arr_A[j + 1]) 
					{
						box1 = arr_A[j];
						arr_A[j] = arr_A[j + 1];
						arr_A[j + 1] = box1;
					}
				}
			}

			cout << "\n\tA^" << endl;

			for (int i = 0; i < N; i++) 
			{
				cout << "|" << "arr_A^[" << i << "] = " << arr_A[i] << endl;
			}

			cout << "\n������� ������ ������� B (�� 0 �� 10): ";
			cin >> M;

			cout << "\n\tB" << endl;

			for (int i = 0; i < M; i++)
			{
				arr_B[i] = rand() % 50;
				cout << "|" << "arr_B[" << i << "] = " << arr_B[i] << endl;
			}

			int box2; 

			for (int i = 0; i < M - 1; i++) 
			{
				for (int j = 0; j < M - i - 1; j++)
				{
					if (arr_B[j] > arr_B[j + 1]) 
					{
						box2 = arr_B[j];
						arr_B[j] = arr_B[j + 1];
						arr_B[j + 1] = box2;
					}
				}
			}

			cout << "\n\tB^" << endl;

			for (int i = 0; i < M; i++) 
			{
				cout << "|" << "arr_B^[" << i << "] = " << arr_B[i] << endl;
			}

		}
		break;

		default:
		{
			cout << "\n� ��������� ��� ������� �������� �������� ����������!" << endl;
		}
		break;

	}

	int arr_C[A + B] = { 0 };

	if (solution == 1 ||
		solution == 2 ||
		solution == 3)
	{
		for (int i = 0, j = 0, k = 0; k < N + M; k++)
		{
			// ���� � ���������� ������
			if (i >= N && j < M) 
			{
				arr_C[k] = arr_B[j];
				j++;
			}
			// ���� � ���������� ������
			if (j >= M && i < N) 
			{
				arr_C[k] = arr_A[i];
				i++;
			}
			// ���� ���������
			if (i < N && j < M) 
			{
				if (arr_A[i] < arr_B[j])
				{
					arr_C[k] = arr_A[i];
					i++;
				}
				else
				{
					arr_C[k] = arr_B[j];
					j++;
				}
			}
		}

		cout << "\n\t�" << endl;

		for (int k = 0; k < N + M; k++)
		{
			cout << "|" << "arr_C[" << k << "] = " << arr_C[k] << endl;
		}
	}
	return 0;
}