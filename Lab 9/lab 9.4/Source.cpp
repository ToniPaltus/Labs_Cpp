#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct properties
{
    int m_amount = 0;//����������
    vector <int> m_lines;//������
};

void scan_cpp(const char* file_name, map <string, properties>& identifiers);

vector <string> split(string& line);//������ ������ �� �������� �����
bool is_splitter(char c);
bool is_key_word(string& word);//���������� �������� �� ��� �����

int main()
{
    map <string, properties> identifiers;//������� ������,���������� ���������� � ������ �����

    scan_cpp("Source.cpp", identifiers);

    ofstream f("out.txt");
    for (auto p = identifiers.begin(); p != identifiers.end(); ++p)//������ � ���� � � �������
    {
        cout << "|" << p->first << "| met for " << p->second.m_amount << " times at: ";
        f << "|" << p->first << "| met for " << p->second.m_amount << " times at lines: ";

        for (int i = 0; i < p->second.m_lines.size(); ++i)
        {
            cout << p->second.m_lines[i];
            f << p->second.m_lines[i];
            if (i != p->second.m_lines.size() - 1)
            {
                cout << ", ";
                f << ", ";
            }
        }
        cout << endl;
        f << endl;
    }

    return 0;
}


vector <string> split(string& line)//�������� ��������������
{
    vector <string> result;//������ �� ����
    string tmp;//��������� ������
    int index = 0;
    int wordIndex = 0;

    while (index != line.size())//����� �� ������
    {
        if (is_splitter(line[index]))//���� ������� ������ splitter ���� ������
        {
            index++;
            continue;
        }
        else 
        {
            //���������� �����������
            if (line[index] == '/' && line[index + 1] == '/')
            {
                break;
            }
           
            while (index != line.size() && !is_splitter(line[index]))
            {
                tmp.push_back(line[index++]);
            }
            result.push_back(tmp);
            tmp.clear();
            wordIndex++;
        }
    }
    for (auto i = result.begin(); i != result.end();)
    {
        if (is_key_word(*i)) //���� ������� ����� == ���������
        {
            i = result.erase(i);//�� ������� ���
            continue;
        }
        ++i;
    }
    return result;
}
bool is_splitter(char c)
{
    switch (c)
    {
    case ' ':
    case '<':
    case '>':
    case ';':
    case '{':
    case '}':
    case '=':
    case '(':
    case ')':
    case '*':
    case ',':
    case '&':
    case '!':
    case '.':
    case '[':
    case ']':
    case '+':
    case '-':
    case ':':
        return true;
    default:
        return false;
    }
}
bool is_key_word(string& word)
{
    return  word == "using" || word == "namespace" || word == "int" || word == "void" || word == "const" ||
        word == "char" || word == "bool" || word == "while" || word == "if" || word == "and" || word == "continue" ||
        word == "else" || word == "return" || word == "switch" || word == "case" || word == "default" || word == "true" ||
        word == "false" || word == "for" || word == "struct" || word == "break" || word == "auto" || word == "or" || word == "std" ||
        word == "begin" || word == "cerr" || word == "clear" || word == "cout" || word == "empty" || word == "end" || word == "endl" ||
        word == "eof" || word == "erase" || word == "exit" || word == "first" || word == "string" || word == "ofstream" || word == "ifstream" ||
        word == "main" || word == "vector" || word == "map" || word == "second";
}
void scan_cpp(const char* file_Name, map <string, properties>& identifiers)
{
    ifstream f(file_Name);
    if (!f.is_open())
    {
        cerr << "CANT OPEN FILE" << endl;
        exit(9);
    }

    string bufferLine;
    vector <string> bufferWords;
    properties buffer;
    int lineCounter = 1;

    while (!f.eof())
    {
        getline(f, bufferLine);

        //���� ������ �����, ���� �� ���������
        if (bufferLine.empty()) {
            lineCounter++;
            continue;
        }
        //���� ������ - ��������� �������������, ���� �� ���������
        if (bufferLine[0] == '#')
        {
            lineCounter++;
            continue;
        }
        //���� ������ - �����������, ���� �� ���������
        if (bufferLine[0] == '/')
        {
            lineCounter++;
            continue;
        }
        ////���� ������ ���������� � �����
        //if (bufferLine[0] >= 'A' || bufferLine[0] <= 'Z' && bufferLine[0] >= 'a' || bufferLine[0] <= 'z')
        //{
        //    lineCounter++;
        //    continue;
        //}

        bufferWords = split(bufferLine); //�������� �� ������ ������ ���������������
        for (int w = 0; w < bufferWords.size(); ++w)
        {
            if (identifiers.count(bufferWords[w]) == 0)
            {
                //���� �� ���������, �������������� �� ���������
                buffer.m_amount = 1;
                buffer.m_lines.push_back(lineCounter);
                identifiers[bufferWords[w]] = buffer;
            }
            else
            {
                //� ��������� ������ �������������� ������� �, ���� �����, ��������� � map
                identifiers[bufferWords[w]].m_amount++;
                if (find(identifiers[bufferWords[w]].m_lines.begin(), identifiers[bufferWords[w]].m_lines.end(),
                    lineCounter) == identifiers[bufferWords[w]].m_lines.end())
                {
                    identifiers[bufferWords[w]].m_lines.push_back(lineCounter);
                }
            }
            buffer.m_lines.clear();
        }
        lineCounter++;
    }
}