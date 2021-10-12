/*
* 8.6. ����� ��������� �����λ
�������� ������ ������ ��������� ������. ���������� ��������� ������ � ��� ������.
� ������ ������ ����
- ����������� �� ���������, +
- ����������� � ����������� �����������,+ 
- ����������� ����������� � ����������.+
���������� ������:
� ������������� ������� �������� ���������;+
� ������ � ��������� ������ ��������;+
� �������� �������� (�����);+
� ����� �������� �� ��������� ����� ������ (�������� ��������������� ����);+
� ����� ��������� ������ �� �����;+
� �������� ���� ��������� ������.+
��������� ������� ������ ��������� ������, ����������� �������� ������ �������� ������� 7.7.

7.7. �������� ������ ������
�� �������� ������������������ ��������� ����� ����� ��������� ����-����������� �������� ������ ������ T ��� ������������ ��������� ������. 
��������� ��������� ������� � ������� �������� ������ �� �����. ������� ��������������� ��������� ���������.

3. ������� ������� � ����������� ��������� ���������.
*/
#include"Tree.h"

int main()
{
	const int max_for_size = 100;
	int size = input_value(max_for_size);

	int* arr = new int[size];
	fill_arr(arr, size);
	print_arr(arr, size);

	Tree<int> TREE;
	TREE.input(arr, size);
	TREE.output_right();
	
	TREE.find_and_delete();
	TREE.output_right();

	return 0;
}