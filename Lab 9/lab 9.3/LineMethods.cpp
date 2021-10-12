#include"Line.h"

//��������� ������ � ���
int string_to_int(string value)
{
	if (value == "true")
	{
		return 1;
	}
	if (value == "false")
	{
		return 0;
	}

	int result = 0;
	for (int i = value.size() - 1; i >= 0; --i)
	{
		result += (value[i] - '0') * pow(10, value.size() - 1 - i);//������� � ����������.
	}

	return result;
}
//�������� �������� �� ��������
bool is_digit(char ch)
{
	if (ch - '0' >= 0 && ch - '0' < 10)
	{
		return true;
	}

	return false;
}

//����������� � ����������
Line::Line(string line)
{
	bool number = false;//����� ��� �� �����
	int length = 0;//����� ���������
	int start;//������� � ���������

	for (int i = 0; i < line.size(); ++i)//���� �� ����� ���������
	{
		if (is_digit(line[i]))//���� �����
		{
			length++;//����������� �����

			if (!number)//������� ��������� �������
			{
				start = i;
				number = true;
			}
		}
		else
		{
			if (number)
			{
				expression.push_back(line.substr(start, length));//��������� � ��������� �������
				number = false;//�������� ��������� 
				length = 0;
			}

			if (((line[i] == '>' || line[i] == '<' || line[i] == '!') && line[i + 1] != '=') || line[i] == '(' || line[i] == ')')
			{
				expression.push_back(line.substr(i, 1));//��������� � ��������� ����
			}

			else if (twodigit.find(line.substr(i, 2)) != string::npos)// npos -��� ����������� ������������ ��������, �������� ���������� ��� ��� -1 (�������� �������������), ������� �� ���������� ������� �������.
			{
				expression.push_back(line.substr(i, 2));//��������� � ��������� ��������� 
				i++;
			}

			else if (line[i] == 't')
			{
				expression.push_back("1");//��������� � ��������� true
				i += 3;
			}

			else if (line[i] == 'f')
			{
				expression.push_back("0");//��������� � ��������� false
				i += 4;
			}
		}
	}
}

//�������� �� �����
bool Line::is_number(int i)
{
	if ((expression[i][0] - '0' >= 0 && expression[i][0] - '0' < 10) || expression[i] == "true" || expression[i] == "false")
	{
		return true;
	}

	return false;
}
//�������� �� ���������� ��������
bool Line::is_logical(int i)
{
	if (expression[i] == "&&" || expression[i] == "||")
	{
		return true;
	}

	return false;
}
//�������� �� ��������
bool Line::is_brkt(int i)
{
	if (expression[i] == "(" || expression[i] == ")")
	{
		return true;
	}

	return false;
}

void Line::Convertation()
{
	int i = 0;//������� ��� ������� �� ���������
	bool Cbrkt = false;//�������� ���
	expression.push_back(";");

	do
	{
		if (expression[i] == ")")
		{
			Cbrkt = true; //������� ��������
		}

		if (this->is_number(i))//���� �������
		{
			arguments.push(string_to_int(expression[i]));//�� ��������� �� � ���������
		}

		else if (this->is_logical(i) || Cbrkt || expression[i] == ";")//���� �������� ��� �������� ��� ;
		{
			while (operation.size() > 0 && operation.top() != "(")//���� ��������� � ������� ������� ���������� �� ��������
			{
				int a = arguments.top();//����������� � � ������� ��������

				if (operation.top() == "!")//���� ��
				{
					arguments.top() = Operate(a);//�� ������������
				}
				else//�����
				{
					arguments.pop();//������� ������� ������� ����� ����������
					int b = arguments.top();//���������� ��������� � b
					arguments.top() = Operate(a, b, operation.top());//��������� �������� � � � b
				}

				operation.pop();//������� ��� �������� �� ����� �������
			}
			if (operation.size() > 0 && Cbrkt && operation.top() == "(")//������� ��������  (
			{
				operation.pop();// ������� ��� �������� �� ����� ��������
				Cbrkt = false;
			}

			if (!this->is_brkt(i) && expression[i] != ";")
			{
				operation.push(expression[i]);//��������� �������� � �����
			}
		}
		else
		{
			operation.push(expression[i]);//��������� ���������
		}

		i++;
	} while (i < expression.size());

	cout << "\nResult: " << arguments.top();
}
//���������� ��������������� ����������
bool Line::Operate(int& a, int& b, string& operat)
{
	if (operat == "<=")
		return a >= b;
	else if (operat == ">=")
		return a <= b;
	else if (operat == ">")
		return a < b;
	else if (operat == "<")
		return a > b;
	else if (operat == "!=")
		return a != b;
	else if (operat == "==")
		return a == b;
	else if (operat == "&&")
		return a && b;
	else if (operat == "||")
		return a || b;
}
//��������� �������������� �
bool Line::Operate(int& a)
{
	return !a;
}
//����� ���������
void Line::COUT()
{
	//cout << "Expression length: " << expression.size() << endl;
	for (int i = 0; i < expression.size(); i++)
	{
		cout << expression[i];
	}
}