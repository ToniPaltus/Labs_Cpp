#pragma once
#include "List.h"

template <class T>
void enter(istream& in, T& data)//������� �����
{
	while (true)
	{
		in >> data;

		if (in.fail())
		{
			in.clear();
			in.ignore(INT_MAX, '\n');

			cout << "An incorrect value. Please try again:" << endl;

			continue;
		}
		else
		{
			break;
		}
	}
}

template <class T>
class Graf
{
private:
	template <class T>
	class Node_graf
	{
	public:
		T data;
		Node_graf<T>* next;

		List<T> vertexes;//������ ����������

		Node_graf(T data = T(), Node_graf<T>* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};

	int size;
	Node_graf<T>* head;

	void pop_front();

public:
	Graf();
	Graf(int size, T data);
	Graf(const Graf<T>& graf);
	~Graf();

	Graf<T>& operator =(const Graf<T>& graf);

	void add_connect(int size);
	void input(int size);
	void push(T data);
	void remove(T data);
	void clear();
	void output();

	int get_size() const;

	bool check_graf(T ver1, T ver2);
	int search_way(const List<T>& vertexes, T ver2);
	void one_to_other(T ver1, T ver2);
};

template<class T>
void Graf<T>::pop_front()
{
	Node_graf<T>* temp = head;
	head = head->next;

	temp->vertexes.clear();
	delete temp;

	size--;
}

template<class T>
Graf<T>::Graf()
{
	this->size = 0;
	this->head = nullptr;
}
template<class T>
Graf<T>::Graf(int size, T data)
{
	this->size = 0;
	this->head = nullptr;

	for (int i = 0; i < size; ++i)
	{
		push(data);
	}
}
template<class T>
Graf<T>::Graf(const Graf<T>& graf)
{
	size = 0;
	head = nullptr;

	Node_graf<T>* current = graf.head;
	while (current)
	{
		push(current->data);
		current = current->next;
	}

	add_connect(size);
}
template<class T>
Graf<T>::~Graf()
{
	clear();
}

template<class T>
Graf<T>& Graf<T>::operator=(const Graf<T>& graf)
{
	if (this != &graf)
	{
		clear();

		Node_graf<T>* current_graf = graf.head;
		Node_graf<T>* current_this = nullptr;

		while (current_graf)
		{
			push(current_graf->data);

			if (current_this)
			{
				current_this = current_this->next;
			}
			else
			{
				current_this = head;
			}

			if (&current_this->vertexes != &current_graf->vertexes)
			{
				Node_list<T>* current_list = current_graf->vertexes.head;
				while (current_list)
				{
					current_this->vertexes.push_back(current_list->data);
					current_list = current_list->pNext;
				}
			}

			current_graf = current_graf->next;
		}
	}

	return *this;
}

template<class T>
void Graf<T>::add_connect(int size)//��������� �����
{
	srand((time(NULL)));

	int k_min = 2;//���������� ������
	int k_max = 4;

	Node_graf<T>* current = head;
	while (current)
	{
		int k_cunnect = k_min + rand() % k_max;//���������� ������ �� ������� �������

		for (int i = 0; i < k_cunnect; ++i)
		{
			int rand_num_graf = rand() % size;//����� ����� ������� ������ ����� �������� � �����
			Node_graf<T>* rand_graf = head;
			for (int j = 0; j < rand_num_graf; ++j)//������� ������� ��� ���� �������
			{
				rand_graf = rand_graf->next;
			}

			if (!current->vertexes.is_exist(rand_graf->data))//���� ������� ��� ����, �� �� ���������
			{
				current->vertexes.push_back(rand_graf->data);
			}
		}
		current = current->next;
	}
}

template<class T>
void Graf<T>::input(int size)
{
	for (int i = 0; i < size; ++i)
	{
		T data = T();
		cout << "Enter vertex: ";
		enter(cin, data);
		push(data);
	}

	add_connect(size);
}
template<class T>
void Graf<T>::push(T data)
{
	if (!head)
	{
		head = new Node_graf<T>(data);
	}
	else
	{
		Node_graf<T>* current = this->head;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new Node_graf<T>(data);
	}

	size++;
}

template<class T>
void Graf<T>::remove(T data)//�������� �������� �� �����
{
	if (!head)
	{
		return;
	}

	Node_graf<T>* in_current = head;
	while (in_current)//����������� �� ������
	{
		in_current->vertexes.remove(data);//������� 
		in_current = in_current->next;
	}

	Node_graf<T>* current = head;
	Node_graf<T>* previous = head;
	while (current && current->data != data)//������� ���������� �����
	{
		previous = current;
		current = current->next;
	}

	if (previous == head && head->data == data)
	{
		head = head->next;
		delete previous;
		size--;
		return;
	}
	current = previous->next;
	if (!current)
	{
		return;
	}

	previous->next = current->next;//������ �����
	delete current;
	size--;
}
template<class T>
void Graf<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<class T>
void Graf<T>::output()
{
	Node_graf<T>* current = head;
	while (current)
	{
		cout << current->data << ": ";
		current->vertexes.output();
		current = current->next;
	}
}

template<class T>
int Graf<T>::get_size() const
{
	return this->size;
}

template<class T>
bool Graf<T>::check_graf(T ver1, T ver2)//��������� ���� �� �� �����, ������� � ���� ���������
{
	//���� ������� 1
	bool flag1 = true;
	Node_graf<T>* graf1 = head;
	if (graf1)
	{
		while (graf1)//����������� �� �����
		{
			if (graf1->data == ver1)//����� �������
			{
				break;
			}
			else if (graf1->data != ver1 && !graf1->next)//����� �� �������
			{
				flag1 = false;
				cout << "The first entered graf wasnt found!" << endl;
			}
			graf1 = graf1->next;//��������� � ����������
		}
	}
	else
	{
		flag1 = false;
		cout << "The first entered graf wasnt found!" << endl;
	}

	//���� ������� 2, �=��� �� ��� � � ������ ������
	bool flag2 = true;
	Node_graf<T>* graf2 = head;
	if (graf2)
	{
		while (graf2)
		{
			if (graf2->data == ver2)
			{
				break;
			}
			else if (graf2->data != ver2 && !graf2->next)
			{
				flag2 = false;
				cout << "The second entered graf wasnt found!" << endl;
			}
			graf2 = graf2->next;
		}
	}
	else
	{
		flag2 = false;
		cout << "The second entered graf wasnt found!" << endl;
	}

	return flag1 && flag2;
}
template<class T>
int Graf<T>::search_way(const List<T>& vertexes, T ver2)//������� ���� �� ������ � �������
{
	Node_list<T>* current = vertexes.head;//����� �� ������

	while (current)//���� � ������ ������� 2
	{
		if (current->data == ver2)// ������� - ����������
		{
			return current->data;
		}
		current = current->pNext;
	}

	current = vertexes.head;
	while (current)//����� �� ��������� �������
	{
		Node_graf<T>* find_graf = head;
		while (find_graf && find_graf->data != current->data)
		{
			find_graf = find_graf->next;
		}

		Node_list<T>* top = find_graf->vertexes.head;
		while (top)
		{
			if (top->data == ver2)//���� �������
			{
				return top->data * 10 + find_graf->data;//������������ ��� ���� � ���� ��������������� �����
			}
			top = top->pNext;
		}
		current = current->pNext;
	}

	cerr << "There is no connection!" << endl;
	exit(0);
}
template<class T>
void Graf<T>::one_to_other(T ver1, T ver2)//���� ���� �� ������� 1 � ������� 2
{
	Node_graf<T>* graf1 = head;
	while (graf1)//���� ������� 1 � ����� 1
	{
		if (graf1->data == ver1)
		{
			break;
		}
		graf1 = graf1->next;
	}

	int way = search_way(graf1->vertexes, ver2);

	way = way * 10 + ver1;//������� ���� � �������� �������� ��� ������

	while (way / 10)//�������� ���� �������
	{
		cout << way % 10;
		cout << " -> ";
		way /= 10;
	}

	cout << way % 10;
	cout << endl;
}