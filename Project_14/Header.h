#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

class Project14_1 {
private:
	class String
	{
		char* value;

	public:
		String()
		{
			value = nullptr;
		}
		String(char* source)
		{
			cout << "�������� ����������� �������\n";
			setCharArray(value, source);
		}
		~String()
		{
			remove();
		}
		void write()
		{
			cout << value << endl;
		}
		void setCharArray(char*& dest, char* source)
		{
			int strSize = strlen(source) + 1;
			dest = new char[strSize];
			strcpy_s(dest, strSize, source);
			cout << "��������� ������� ������� \n";
		}
		void remove()
		{
			if (value != nullptr)
			{
				delete[] value;
				cout << "�������� ���������� �������" << endl;
			}
		}
		String& operator= (String& name)
		{
			// ���������� ��������� ������������ 
			cout << "���������� ��������� ������������ \n ";
			// ������� ��������������� 
			if (this == &name)
				return *this;
			else {
				// ���� ��� ���� ��������, �� ������� ��� ��������
				remove();
				// ��������� �������� �����������
				setCharArray(value, name.value);
				// ���������� ������� ������
				return *this;
			}

		}
	};

public:
	void main()
	{
		cout << "\n ������� 1: �������� � ��� ������������ ����� String ����������� ��������, �������� ������������ ��������.\n";

		char value[10]{ "valik" };

		String name_2;
		String name_1(value);
		cout << "name_1 = ";
		name_1.write();
		name_2 = name_1;
		cout << "name_2 = ";
		name_2.write();
	}
};
class Array_Project14 {
public:
	int size;
	int* arr;
	Array_Project14(int = 10);
	Array_Project14(Array_Project14&);
	~Array_Project14();
	const Array_Project14& operator=(const Array_Project14&);
	int& operator[](int);
	int operator[](int) const;
};

Array_Project14::Array_Project14(int aSize)
	: size{ aSize }, arr{ new int[size] {} }
{
	cout << "�������� �����������\n";
}
Array_Project14::Array_Project14(Array_Project14& a)
	: size{ a.size }, arr{ new int[size] }
{

	cout << "�������� ����������� ��������\n";
	for (int i = 0; i < size; ++i)
	{
		arr[i] = a.arr[i];
	}
}
Array_Project14::~Array_Project14()
{
	cout << "�������� ����������\n";
	delete[] arr;
}

const Array_Project14& Array_Project14::operator=(const Array_Project14& a)
{
	cout << "�������� �������� ������������\n";
	if (&a != this)
	{
		if (size != a.size)
		{
			delete[] arr;
			size = a.size;
			arr = new int[size];
		}
		for (int i = 0; i < size; ++i)
		{
			arr[i] = a.arr[i];
			cout << arr[i] << " ";
		}cout << endl;
	}
	return *this;
}

Array_Project14 operator+(const Array_Project14& A1, const int A2)
{
	Array_Project14 A;
	int n;
	n = A1.size;
	for (int i = 0; i < n; i++)
	{
		A.arr[i] = A1.arr[i] + A2;
	}
	return A;
}
int& Array_Project14::operator[](int index)
{
	if (index >= 0 || index <= size)return arr[index];
}
int Array_Project14::operator[](int index) const
{
	if (index >= 0 || index <= size)return arr[index];
}
class Project14_2 {
public:
	void main() {
		cout << "\n ������� 2: �������� � ��� ������������ ����� Array ����������� ��������, �������� ������������ ��������.\n";

		Array_Project14 array1, array2;
		for (int i = 0; i < 10; i++)
		{
			array1[i] = i;
		}
		array2 = array1;

	}
};
class Project14_3 {
public:
	void main() {
		cout << "\n ������� 3: ���������� ����� Array ������� ������� ����������\n";
		cout << " ���������� �������������� ������������ ����������,\n";
		cout << "��� ��� ��������.����� ���� ����������(���������\n";
		cout << "������������� ����������) �������� ���� :\n";
		cout << "����� + ������_������.\n";
		Array_Project14 array1, array2, array3, array4, array5;
		for (int i = 0; i < 10; i++)
		{
			array1[i] = i;
		}
		array2 = array1;
		array3 = array2 + 2;
	}
};
