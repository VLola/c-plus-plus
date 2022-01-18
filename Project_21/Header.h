#pragma once
#include <iostream>
#include <cassert>
#include <fstream>
using namespace std;
template <typename T>
struct Elem
{
	// ����� ������
	T data;
	Elem* next, * prev;
};
template <typename T>
class List
{
	// ������ �����
	Elem<T>* Head, * Tail;
	int Count;
public:
	List();
	List(const List&);
	~List();
	int GetCount();
	Elem<T>* GetElem(int);
	void DelAll();
	void Del(int);
	void Del();
	void AddTail();
	void AddTail(T);
	void AddHead(T);
	void AddHead();
	void Print();
	void Print(int pos);
	List& operator = (const List&);
	List operator + (const List&);
	bool operator == (const List&);
	bool operator != (const List&);
	bool operator <= (const List&);
	bool operator >= (const List&);
	bool operator < (const List&);
	bool operator > (const List&);
	List operator - ();
};
template <typename T>
List<T>::List()
{
	Head = Tail = 0;
	Count = 0;
}
template <typename T>
List<T>::List(const List& L)
{
	Head = Tail = 0;
	Count = 0;
	Elem<T>* temp = L.Head;
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}
template <typename T>
List<T>::~List()
{
	DelAll();
}
template <typename T>
Elem<T>* List<T>::GetElem(int pos)
{
	try {
		if (pos < 1 || pos > Count) throw "�������� �������!";
		Elem<T>* temp = Head;
		int i = 1;
		while (i < pos && temp != 0)
		{
			temp = temp->next;
			i++;
		}
		if (temp == 0)
			return 0;
		else
			return temp;
	}
	catch (const char* s) {
		cout << s << endl;
	}
}
template <typename T>
void List<T>::AddHead()
{
	Elem<T>* temp = new Elem<T>;
	temp->prev = 0;
	int n;
	cout << "Input new number: ";
	cin >> n;
	temp->data = n;
	temp->next = Head;
	if (Head != 0)
		Head->prev = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Head = temp;
	Count++;
}
template <typename T>
void List<T>::AddHead(T n)
{
	Elem<T>* temp = new Elem<T>;
	temp->prev = 0;
	temp->data = n;
	temp->next = Head;
	if (Head != 0)
		Head->prev = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Head = temp;
	Count++;
}
template <typename T>
void List<T>::AddTail()
{
	Elem<T>* temp = new Elem<T>;
	temp->next = 0;
	int n;
	cout << "Input new number: ";
	cin >> n;
	temp->data = n;
	temp->prev = Tail;
	if (Tail != 0)
		Tail->next = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Tail = temp;
	Count++;
}
template <typename T>
void List<T>::AddTail(T n)
{
	Elem<T>* temp = new Elem<T>;
	temp->next = 0;
	temp->data = n;
	temp->prev = Tail;
	if (Tail != 0)
		Tail->next = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Tail = temp;
	Count++;
}
template <typename T>
void List<T>::Del()
{
	int n;
	cout << "Input position: ";
	cin >> n;
	try {
		if (n < 1 || n > Count) throw "�������� �������!";
		int i = 1;
		Elem<T>* Del = Head;
		while (i <= n)
		{
			//������� �� ��������, ������� ���������
			Del = Del->next;
			i++;
		}
		//������� �� ��������, ������� ������������
		//����������
		Elem<T>* PrevDel = Del->prev;
		//������� �� ��������, ������� ������� �� ���������
		Elem<T>* AfterDel = Del->next;
		if (PrevDel != 0 && Count != 1)
			PrevDel->next = AfterDel;
		if (AfterDel != 0 && Count != 1)
			AfterDel->prev = PrevDel;
		if (n == 1)
			Head = AfterDel;
		if (n == Count)
			Tail = PrevDel;
		delete Del;
		Count--;
	}
	catch (const char* s) {
		cout << s << endl;
	}
}
template <typename T>
void List<T>::Del(int n)
{
	try {
		if (n < 1 || n > Count) throw "�������� �������!";

		int i = 1;
		Elem<T>* Del = Head;
		while (i < n)
		{
			//������� �� ��������, ������� ���������
			Del = Del->next;
			i++;
		}
		//������� �� ��������, ������� ������������
		//����������
		Elem<T>* PrevDel = Del->prev;
		//������� �� ��������, ������� ������� ��
		//���������
		Elem<T>* AfterDel = Del->next;
		if (PrevDel != 0 && Count != 1)
			PrevDel->next = AfterDel;
		if (AfterDel != 0 && Count != 1)
			AfterDel->prev = PrevDel;
		if (n == 1)
			Head = AfterDel;
		if (n == Count)
			Tail = PrevDel;
		delete Del;
		Count--;
	}
	catch (const char* s) {
		cout << s << endl;
	}
}
template <typename T>
void List<T>::Print(int pos)
{
	try {
		if (pos < 1 || pos > Count) throw "�������� �������!";
		Elem<T>* temp;
		//���������� � ����� �������
		//������� ���������
		if (pos <= Count / 2)
		{
			//������ � ������
			temp = Head;
			int i = 1;
			while (i < pos)
			{
				// ��������� �� ������� ��������
				temp = temp->next;
				i++;
			}
		}
		else
		{
			//������ � ������
			temp = Tail;
			int i = 1;
			while (i <= Count - pos)
			{
				//��������� �� ������� ��������
				temp = temp->prev;
				i++;
			}
		}
		//����� ��������
		cout << pos << " element: ";
		cout << temp->data << "\n";
	}
	catch (const char* s) {
		cout << s << endl;
	}

}
template <typename T>
void List<T>::Print()
{
	try {
		if (Count == 0) throw "������ ����!";
		Elem<T>* temp = Head;
		while (temp != 0)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	catch (const char* s) {
		cout << s << endl;
	}
}
template <typename T>
void List<T>::DelAll()
{
	while (Count != 0)
		Del(1);
}
template <typename T>
int List<T>::GetCount()
{
	return Count;
}
template <typename T>
List<T>& List<T>::operator = (const List<T>& L)
{
	if (this == &L)
		return *this;
	this->~List();
	Elem<T>* temp = L.Head;
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
	return *this;
}
template <typename T>
List<T> List<T>::operator + (const List<T>& L)
{
	List Result(*this);
	Elem<T>* temp = L.Head;
	while (temp != 0)
	{
		Result.AddTail(temp->data);
		temp = temp->next;
	}
	return Result;
}
template <typename T>
bool List<T>::operator == (const List<T>& L)
{
	if (Count != L.Count)
		return false;
	Elem<T>* t1, * t2;
	t1 = Head;
	t2 = L.Head;
	while (t1 != 0)
	{
		if (t1->data != t2->data)
			return false;
		t1 = t1->next;
		t2 = t2->next;
	}
	return true;
}
template <typename T>
bool List<T>::operator != (const List& L)
{
	if (Count != L.Count)
		return true;
	Elem<T>* t1, * t2;
	t1 = Head;
	t2 = L.Head;
	while (t1 != 0)
	{
		if (t1->data != t2->data)
			return true;
		t1 = t1->next;
		t2 = t2->next;
	}
	return false;
}
template <typename T>
bool List<T>::operator >= (const List& L)
{
	if (Count > L.Count)
		return true;
	if (*this == L)
		return true;
	return false;
}
template <typename T>
bool List<T>::operator <= (const List& L)
{
	if (Count < L.Count)
		return true;
	if (*this == L)
		return true;
	return false;
}
template <typename T>
bool List<T>::operator > (const List& L)
{
	if (Count > L.Count)
		return true;
	return false;
}
template <typename T>
bool List<T>::operator < (const List& L)
{
	if (Count < L.Count)
		return true;
	return false;
}
template <typename T>
List<T> List<T>::operator - ()
{
	List Result;
	Elem<T>* temp = Head;
	while (temp != 0)
	{
		Result.AddHead(temp->data);
		temp = temp->next;
	}
	return Result;
}

class Project21_1 {
public:
	void main()
	{
		cout << "\n������� 1. �������� � ����� ����������� ������ �������� ��������� ����������.�� ��� ����� ����������� ����������\n";
		cout << "� ������ ������.��������, �������� ������, �������\n";
		cout << "�������� �� ������� ������ � �.�.\n\n";
		List <int> L;
		const int n = 10;
		int a[n] = { 0,1,2,3,4,5,6,7,8,9 };
		//�������� ������� �����
		L.Print();
		for (int i = 0; i < n; i++)
			if (i % 2 == 0)
				L.AddHead(a[i]);
			else
				L.AddTail(a[i]);

		cout << "List L:\n";
		L.Print();
		cout << "\n\n";
		//�������� �������������� �������
		L.Print(11);
		cout << "List L:\n";
		L.Print();
		L.Print(2);
		L.Print(8);
		List <int> T;
		T = L;
		cout << "List T:\n";
		T.Print();
		cout << "List Sum:\n";
		List <int> Sum = -L + T;
		Sum.Print();
	}
};
class Exeption
{
public:
	string message;
	Exeption() { message = "������!!!\n"; }
	Exeption(string mes) { message = "����������� ������:\n"; message += mes; }
};

class Exeption_mathematic : public Exeption
{
public:
	Exeption_mathematic(string mes) { message = "������ ���������:\n"; message += mes; }
};

class Exeption_file : public Exeption
{
public:
	Exeption_file(string mes) { message = "������ �������� �������:\n"; message += mes; }
};
class Urovneniya {
public:

	double a;
	double b;
	double c;

	virtual int Start() = 0;
	void getA(double A) {
		a = A;
	}
	void getB(double B) {
		b = B;
	}
	void getC(double C) {
		c = C;
	}

};

class Line : public Urovneniya {
public:
	int Start() {
		try
		{
			if (a == 0) throw Exeption_mathematic("� ��������� �� ����� ���� ������! ��� ��� a = 0");
			fstream txt;
			txt.open("Valik.txt", ios::app);
			if (!txt.is_open()) throw Exeption_file("���� �� ��������!");
			txt << "x = " << -b * a << "\n";
			txt.close();
		}
		catch (Exeption_mathematic& exeption)
		{
			cout << exeption.message;
		}
		catch (Exeption_file& exeption)
		{
			cout << exeption.message;
		}
		catch (Exeption& exeption)
		{
			cout << exeption.message;
		}

	}

};

class Kvadratn : public Urovneniya {
public:
	int Start() {

		try
		{
			if (a == 0) throw Exeption_mathematic("� ��������� �� ����� ���� ������! ��� ��� a = 0");
			fstream txt;
			txt.open("Valik.txt", ios::app);
			if (!txt.is_open()) throw Exeption_file("���� �� ��������!");

			double d = b * b - 4 * a * c;
			if (d > 0) {

				txt << "x = " << ((-b + sqrt(d)) / 2 * a) << endl;
				txt << "x = " << ((-b - sqrt(d)) / 2 * a) << endl;
			}
			else if (d == 0) {
				txt << "x = " << -b / 2 * a;
			}
			else if (d < 0) {
				txt << "������ ���!\n";
			}
			txt.close();
		}
		catch (Exeption_mathematic& exeption)
		{
			cout << exeption.message;
		}
		catch (Exeption_file& exeption)
		{
			cout << exeption.message;
		}
		catch (Exeption& exeption)
		{
			cout << exeption.message;
		}
	}
};
class Project21_2 {
public:
	void main() {
		cout << "������� 2. �������� �������� ���������������� ������� - ����������.\n";
		cout << "� ��� ������ ���� ������ ��� ������ ��������.� �������� ���������� ������� ����������� ����\n";
		cout << "������������ � �������� �������.��������, ������.\n";
		cout << "�������������� ������ ��� ��������� ������������.\n";
		cout << "�������������� ������, �������� ������, ���������.\n";
		cout << "�� ������ � ������� � �.�.\n\n";

		double a = 0, b = 2, c = 3;

		Line obj1;
		obj1.getA(a);
		obj1.getB(b);
		obj1.Start();
		cout << endl;

		Kvadratn obj2;
		obj2.getA(a);
		obj2.getB(b);
		obj2.getC(c);
		obj2.Start();
	}
};

class Data {
public:
	double x;
	double y;
	double z;
};

namespace twoVar {
	class TwoVariables : public Data {
	public:
		TwoVariables(double a, double b) {
			x = a;
			y = b;
		}
		double Div() {
			return x / y;
		}
		double Sum() {
			return x + y;
		}
		double Mult() {
			return x * y;
		}
		double Diff() {
			return x - y;
		}
	};
	double PrintDiv(TwoVariables a) {
		return a.Div();
	}
	double PrintSum(TwoVariables a) {
		return a.Sum();
	}
	double PrintMult(TwoVariables a) {
		return a.Mult();
	}
	double PrintDiff(TwoVariables a) {
		return a.Diff();
	}
}

namespace threeVar {
	class ThreeVariables : public Data {
	public:
		ThreeVariables(double a, double b, double c) {
			x = a;
			y = b;
			z = c;
		}
		double Div() {
			return x / y / z;
		}
		double Sum() {
			return x + y + z;
		}
		double Mult() {
			return x * y * z;
		}
		double Diff() {
			return x - y - z;
		}
	};
	double PrintDiv(ThreeVariables a) {
		return a.Div();
	}
	double PrintSum(ThreeVariables a) {
		return a.Sum();
	}
	double PrintMult(ThreeVariables a) {
		return a.Mult();
	}
	double PrintDiff(ThreeVariables a) {
		return a.Diff();
	}
}
class Project21_3 {
public:
	void main() {

		cout << "������� 3. � ������ ���������� ��������������� � �������� ������� �� ������� ����� ������� �� ������ � ����������\n";
		cout << "������������ ��������������� ����������(�����,\n";
		cout << "����� � ��������� ������������, ����� � ����������\n";
		cout << "������������ � �.�.).���������� ��� ��������� ������ �\n";
		cout << "������������� ����.���������� ���������� ���������\n";
		cout << "��������� �����������.��������� �������� �����������\n";
		cout << "�������� ��� �� ������������ ����������� �������.\n\n";
		double a = 1, b = 2, c = 3;

		twoVar::TwoVariables obj1(a, b);
		twoVar::TwoVariables obj2(b, c);
		cout << twoVar::PrintDiv(obj1) + twoVar::PrintDiff(obj2) << endl;
		threeVar::ThreeVariables obj3(twoVar::PrintDiv(obj1), twoVar::PrintDiff(obj2), twoVar::PrintSum(obj2));
		cout << threeVar::PrintDiff(obj3) + threeVar::PrintMult(obj3);
		cout << endl;
	}
};