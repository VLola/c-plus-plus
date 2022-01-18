#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
using namespace std;
class Project12_1 {
private:
	struct Complex
	{
		double a;
		double b;
	};

	Complex Summa(Complex x, Complex y) {
		Complex suma;
		suma.a = x.a + y.a;
		suma.b = x.b + y.b;
		return suma;
	}
	Complex Subtraction(Complex x, Complex y) {
		Complex sub;
		sub.a = x.a - y.a;
		sub.b = x.b - y.b;
		return sub;
	}
	Complex Multiplication(Complex x, Complex y) {
		Complex mult;
		mult.a = (x.a * y.a) - (x.b * y.b);
		mult.b = (x.b * y.a) + (x.b * y.a);
		return mult;
	}
	Complex Division(Complex x, Complex y) {
		Complex div;
		div.a = (x.a * y.a + x.b * y.b) / (y.a * y.a + y.b * y.b);
		div.b = (x.b * y.a - y.b * x.a) / (y.a * y.a + y.b * y.b);
		return div;
	}
public:
	void main()
	{
		srand(unsigned(time(NULL)));
		cout << "\n������ 1: �������� ���������, ����������� ����������� �����.���������� �������������� ��������\n";
		cout << "� ������������ ������� : �����, ��������, ���������, �������.\n\n";
		char c;
		Complex complex1, complex2;

		for (;;) {

			cout << "������� �������� � ������������ ������� '+,-,*,/'\n";
			cin >> c;
			cout << "������� ������ �������� ������� ����������� �����\n";
			cin >> complex1.a;
			cout << "������� ������ �������� ������� ����������� �����\n";
			cin >> complex1.b;

			cout << "������� ������ �������� ������� ����������� �����\n";
			cin >> complex2.a;
			cout << "������� ������ �������� ������� ����������� �����\n";
			cin >> complex2.b;
			switch (c) {
			case '+':
				Complex suma = Summa(complex1, complex2);
				cout << "��������� ��������: " << suma.a << " + " << suma.b << "i" << endl;
				break;
			case '-':
				Complex sub = Subtraction(complex1, complex2);
				cout << "��������� ��������: " << sub.a << " + " << sub.b << "i" << endl;
				break;
			case '*':
				Complex mult = Multiplication(complex1, complex2);
				cout << "��������� ���������: " << mult.a << " + " << mult.b << "i" << endl;
				break;
			case '/':
				Complex div = Division(complex1, complex2);
				cout << "��������� �������: " << div.a << " + " << div.b << "i" << endl;
				break;
			default:
				break;
			}
		}
	}
};
class Project12_2 {
private:
	struct Avto
	{
		double length;
		double height;
		double volume;
		double power;
		double diameter;
		char color[10];
		char type[10];
	}x;
	void Add() {
		cout << "������� ����� ����������\n";
		cin >> x.length;
		cout << "������� ������ ������� ����������\n";
		cin >> x.height;
		cout << "������� ����� ��������� ����������\n";
		cin >> x.volume;
		cout << "������� �������� ��������� ����������\n";
		cin >> x.power;
		cout << "������� ������� ����� ����������\n";
		cin >> x.diameter;
		cout << "������� ���� ����������\n";
		cin >> x.color;
		cout << "������� ��� ������� ������� ����������\n";
		cin >> x.type;
	}

	void Search() {
		int a;
		cout << "\n�������� ����� �������� ������ �����:\n";
		cout << "1 - ����� ����������,2 - ������ ������� ����������,3 - ����� ��������� ����������, \n";
		cout << "4 - �������� ��������� ����������,5 -  ������� ����� ����������,6 -  ���� ����������, \n";
		cout << "7 - ��� ������� ������� ����������. \n";
		cin >> a;
		switch (a) {
		case 1:
			cout << x.length << " - ����� ����������\n";
			break;
		case 2:
			cout << x.height << " - ������ ������� ����������\n";
			break;
		case 3:
			cout << x.volume << " - ����� ��������� ����������\n";
			break;
		case 4:
			cout << x.power << " - �������� ��������� ����������\n";
			break;
		case 5:
			cout << x.diameter << " - ������� ����� ����������\n";
			break;
		case 6:
			cout << x.color << " - ���� ����������\n";
			break;
		case 7:
			cout << x.type << " - ��� ������� ������� ����������\n";
			break;
		default:
			break;
		}
	}

	void Display() {
		cout << endl;
		cout << x.length << " - ����� ����������\n";
		cout << x.height << " - ������ ������� ����������\n";
		cout << x.volume << " - ����� ��������� ����������\n";
		cout << x.power << " - �������� ��������� ����������\n";
		cout << x.diameter << " - ������� ����� ����������\n";
		cout << x.color << " - ���� ����������\n";
		cout << x.type << " - ��� ������� ������� ����������\n";
	}
public:
	void main()
	{
		srand(unsigned(time(NULL)));
		cout << "\n������ 2: ����������� ��������� ������������(�����, �������(������ �������), ����� ���������,\n";
		cout << "�������� ���������, ������� �����, ����, ��� ������� �������).�������� ������� ��� �������\n";
		cout << "��������, ����������� ��������, ������ ��������.\n\n";

		Add();
		Display();
		for (;;) {
			Search();
		}
	}
};
class Project12_3 {
private:

	int m1 = 4;
	int const static m2 = 10;
	int const static m3 = 40;

	struct Book
	{
		int sorting = 0;
		char*** biblioteck = new char** [m2];
		char* nameSearch = new char[m3];
		char arrayName[10][40] = { "��������_�_����", "���_�_����������", "�������_��������_����������", "����������", "��������_���������", "�����_�_��������", "����������_�����", "����_��������_�������", "��������_����_�����", "��������_����������" };
		char arrayAuthor[10][40] = { "����_�������", "����_�����",  "�������_�������",  "������_���",  "����_��������",  "����_�����",  "��_������",  "�������_�������",  "����_������",  "���_��������" };
		char arrayPublishing[10][40] = { "�����", "�����",  "�������_�������",  "���",  "�����",  "�����",  "�����",  "���",  "���",  "��������" };
		char arrayGenre[10][40] = { "�����", "��������",  "�������",  "�������_����������",  "�������_����������",  "�������_����������",  "�������_����������",  "�������_����������",  "�������",  "�������" };

	}x;

	void Add(int a) {

		for (int h = 0; h < m1; h++) {
			if (h == 0)cout << "������� ����� �������� �����\n";
			else if (h == 1)cout << "������� ������ ������ �����\n";
			else if (h == 2)cout << "������� ����� ������������ �����\n";
			else if (h == 3)cout << "������� ����� ���� �����\n";
			x.biblioteck[h][a] = new char[m3];
			x.nameSearch = new char[m2];
			cin >> x.nameSearch;
			for (int j = 0; j < m3; j++) {
				x.biblioteck[h][a][j] = x.nameSearch[j];

			}
		}
	}

	void Search(int a) {
		x.nameSearch = new char[m2];
		cin >> x.nameSearch;
		int count = strlen(x.nameSearch);
		for (int h = 0; h < m1; h++) {
			for (int i = 0; i < m2; i++) {
				for (int j = 0; j < m3; ) {
					if (x.nameSearch[j] == x.biblioteck[h][i][j]) {
						j++;
						if (j == count && h == 0) {
							cout << x.biblioteck[0][i] << "\t" << x.biblioteck[1][i] << "\t" << x.biblioteck[2][i] << "\t" << x.biblioteck[3][i] << endl;
							if (a == 2)Add(i);
						}
						else if (j == count && h == 1) {
							cout << x.biblioteck[1][i] << "\t" << x.biblioteck[0][i] << "\t" << x.biblioteck[2][i] << "\t" << x.biblioteck[3][i] << endl;
						}
						else if (j == count && h == 2) {
							cout << x.biblioteck[2][i] << "\t" << x.biblioteck[0][i] << "\t" << x.biblioteck[1][i] << "\t" << x.biblioteck[3][i] << endl;
						}
						else if (j == count && h == 3) {
							cout << x.biblioteck[3][i] << "\t" << x.biblioteck[0][i] << "\t" << x.biblioteck[1][i] << "\t" << x.biblioteck[2][i] << endl;
						}

					}
					else break;
				}
			}
		}
	}
	// ������� ������ 
	void Array(int b) {
		int count, l;
		if (b == 0) cout << "�����\t\t\t\t�����\t\t\t\t������������\t\t\t����\n\n";
		else if (b == 1) cout << "�����\t\t\t\t������������\t\t\t����\t\t\t\t�����\n\n";
		else if (b == 2) cout << "������������\t\t\t����\t\t\t\t�����\t\t\t\t�����\n\n";
		else if (b == 3) cout << "����\t\t\t\t�����\t\t\t\t�����\t\t\t\t������������\n\n";

		for (int i = 0; i < m2; i++) {
			l = b;
			for (int j = 0; j < m1; l++, j++) {
				cout << x.biblioteck[l][i];
				count = strlen(x.biblioteck[l][i]);
				if (count > 15 && count <= 25)cout << "\t\t";
				else if (count > 25)cout << "\t";
				else if (count > 7 && count <= 15) cout << "\t\t\t";
				else if (count <= 7) cout << "\t\t\t\t";
				if (l == 3)l = 0;
			}
		}cout << endl;
	}

public:
	void main()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		srand(unsigned(time(NULL)));
		int a, b;
		cout << "\n������ 3: ������������ ��������� �����������.�������� ��������� ������(��������, �����,\n";
		cout << "������������, ����).�������� ������ �� 10 ����.���������� ��� ���� ��������� ����������� :\n";
		cout << "������������� �����\n";
		cout << "������ ���� ����\n";
		cout << "����� ���� �� ������\n";
		cout << "����� ����� �� ��������\n";
		cout << "���������� ������� �� �������� ����\n";
		cout << "���������� ������� �� ������\n";
		cout << "���������� ������� �� ������������\n\n";
		// �������� ���������� �������
		for (int h = 0; h < m1; h++) {
			x.biblioteck[h] = new char* [m2];
			for (int i = 0; i < m2; i++) {
				x.biblioteck[h][i] = new char[m3];
				for (int j = 0; j < m3; j++) {
					if (h == 0) {
						char temp = x.arrayName[i][j];
						x.biblioteck[0][i][j] = temp;
					}
					else if (h == 1) {
						char temp = x.arrayAuthor[i][j];
						x.biblioteck[1][i][j] = temp;
					}
					else if (h == 2) {
						char temp = x.arrayPublishing[i][j];
						x.biblioteck[2][i][j] = temp;
					}
					else if (h == 3) {
						char temp = x.arrayGenre[i][j];
						x.biblioteck[3][i][j] = temp;
					}
				}
			}
		}


		for (;;) {
			cout << " 1 - ����� �� ��������,������,������������,��� ����� �����.\n 2 - ������������� �����\n 3 - ������ ���� ����\n";
			cout << " 4 - ���������� ����������. 5 - ����� �� ���������\n \n";
			cin >> a;
			if (a == 1) {
				cout << "������� �����:\n";
				Search(a);
			}
			else if (a == 2) {
				cout << "������� �������� �����:\n";
				Search(a);
			}
			else if (a == 3) Array(x.sorting);
			else if (a == 4) {
				cout << "������� ��� ������ ����������� ������:\n";
				cout << " 0 - ���������� �� �������� ����\n";
				cout << " 1 - ���������� �� ������\n";
				cout << " 2 - ���������� �� ������������\n";
				cout << " 3 - ���������� �� �����\n\n";
				cin >> b;
				x.sorting = b;
				Array(x.sorting);
			}
			else if (a == 5) break;
		}
	}
};
class Project12_4 {
private:
	int m1 = 4;
	int const static m2 = 10;
	int m3 = 40;
	char chekNumber[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	struct Av��
	{
		char arrayColor[10][10] = { "�����","�������","�����","�������","������", "������","�������","�������", "�����","�������", };
		char arrayModel[10][10] = { "Audi","BMW","Acura","Bentley","Bugatti", "Buick","Fiat","Chery", "Dacia","Daewoo", };
		char arrayNumber[10][10] = { "12345","65432","55555","66666","78945", "35795","12345","45678", "98765","95125", };
		char** arrayAvtoColor = new char* [m2];
		char** arrayAvtoModel = new char* [m2];
		char** arrayAvtoNumber = new char* [m2];
		char* color = new char[m2];
		char* model = new char[m2];
		char* number = new char[m2];
		char* searchNumber = new char[m2];
	}x;

	void Add() {
		int check;
		cout << "������� ���� ����� ������\n";
		x.color = new char[m2];
		cin >> x.color;
		cout << "������� ������ ����� ������\n";
		x.model = new char[m2];
		cin >> x.model;
		for (;;) {
			int h = 0;
			cout << "�������� ����� ����� ����� ����� ������\n";
			cout << " 1 - ����������� �����\n";
			cout << " 2 - ����� �� 8 ��������\n";
			cin >> check;
			cout << "������� ����� ����� ������\n";
			x.number = new char[m2];
			cin >> x.number;
			int count = strlen(x.number);
			if (check == 1) {
				if (count == 5) {
					for (int i = 0; i < count; i++) {
						for (int j = 0; j < m2; j++) {
							if (x.number[i] == chekNumber[j]) {
								h++;
							}
						}

					}
				}
			}
			else if (check == 2) {
				if (count <= 8) break;
				else  cout << "������!\n";
			}
			if (h == 5) break;
			else cout << "������! ������������ ���������� ����!\n";
		}
	}

	void Record(int b) {
		x.arrayAvtoColor[b] = new char[m2];
		x.arrayAvtoModel[b] = new char[m2];
		x.arrayAvtoNumber[b] = new char[m2];
		for (int j = 0; j < m2; j++) {
			x.arrayAvtoColor[b][j] = x.color[j];
			x.arrayAvtoModel[b][j] = x.model[j];
			x.arrayAvtoNumber[b][j] = x.number[j];
		}
	}

	int Search() {
		cout << "������� ����� ������ ������� ������ �����\n";
		cin >> x.searchNumber;
		int count = strlen(x.searchNumber);
		for (int i = 0; i < m3; i++) {
			for (int j = 0; j < m2; ) {
				if (x.searchNumber[j] == x.arrayAvtoNumber[i][j]) {
					j++;
					if (j == count) {
						cout << x.arrayAvtoNumber[i] << "\t" << x.arrayAvtoModel[i] << "\t" << x.arrayAvtoColor[i] << endl;
						return i;
					}
				}
				else break;
			}
		}
	}
	// ������� ������ 
	void Array(int a) {
		if (a == 2) {
			for (int i = 0; i < 1; i++) {
				cout << x.color << "\t" << x.model << "\t" << x.number << "\n";
			}
		}
		else if (a == 4) {
			for (int i = 0; i < m2; i++) {
				cout << x.arrayAvtoModel[i] << "\t\t";
				cout << x.arrayAvtoColor[i] << "\t\t";
				cout << x.arrayAvtoNumber[i] << "\n";
			}
		}

	}
	
public:
	void main()
	{
		setlocale(LC_ALL, "rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		srand(unsigned(time(NULL)));
		int a, b;
		cout << "\n������ 4: ����������� ��������� �������(����, ������, �����).����� ������ ����� ������������ ��\n";
		cout << "���� ��� ����������� ����� ��� ����� �� 8 ��������.\n";
		cout << "������������: ����� ����������� ��� �����������.\n";
		cout << "������� ��������� ��������� ������� � ����������� ��� ���� ��������� ������� :\n";
		cout << "���������� ������\n";
		cout << "������ ������\n";
		cout << "������� ������ �� 10 ����������� ��������� ������� � ����������� ��� ���� ��������� ������� :\n";
		cout << "������������� ������\n";
		cout << "������ ���� �����\n";
		cout << "����� ������ �� ������\n\n";
		for (int i = 0; i < m2; i++) {
			x.arrayAvtoColor[i] = new char[m2];
			x.arrayAvtoModel[i] = new char[m2];
			x.arrayAvtoNumber[i] = new char[m2];
			for (int j = 0; j < m2; j++) {
				x.arrayAvtoColor[i][j] = x.arrayColor[i][j];
				x.arrayAvtoModel[i][j] = x.arrayModel[i][j];
				x.arrayAvtoNumber[i][j] = x.arrayNumber[i][j];
			}
		}
		for (;;) {
			cout << " 1 - ���������� ������.\n 2 - ������ ������.\n 3 - ������������� ������\n";
			cout << " 4 - ������ ���� �����.\n 5 - ����� ������ �� ������.\n 6 - ����� �� ���������\n \n";
			cin >> a;
			if (a == 1) {
				Add();
			}
			else if (a == 2) {
				Array(a);
			}
			else if (a == 3) {
				b = Search();
				Add();
				Record(b);
			}
			else if (a == 4) {
				Array(a);
			}
			else if (a == 5) {
				Search();
			}
			else if (a == 6) break;
		}

	}
};