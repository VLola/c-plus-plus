#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Project11_1 {
private:

	int m1 = 3;
	int m2 = 5;
	int** pArr = new int* [m1];
	// ������� ������ ���������� �������
	void Array() {
		for (int i = 0; i < m1; i++) {
			for (int j = 0; j < m2; j++) {
				cout << pArr[i][j] << " ";
			}cout << endl;
		}cout << endl;
	}
	// ������� ���������� ������� ���������� �������
	void AddColumn(int a) {
		// ���������� �������� ������� �� +1
		m2 += 1;
		// ���������� ������� ����� ������������ �������
		for (int i = 0; i < m1; i++) {
			for (int j = m2; j > a; j--) {
				pArr[i][j] = pArr[i][j - 1];
			}
		}
		// ���������� ������� � ��������� ������
		for (int j = 0; j < m1; j++) {
			pArr[j][a] = rand() % 89 + 10;
		}
		// ����� ������� ������ �������
		Array();
	}
public:
	void main()
	{
		srand(unsigned(time(NULL)));
		cout << "\n������ 1: �������� �������, ����������� ������� ����������� ������� � ��������� �������.\n\n";
		int a;
		// �������� ���������� �������
		for (int i = 0; i < m1; i++) {
			pArr[i] = new int[m2];
			for (int j = 0; j < m2; j++) {
				pArr[i][j] = rand() % 89 + 10;
			}
		}
		// ����� ������� ������ �������
		Array();

		for (;;) {
			cout << "������� ����� ������� ����������� �������, ����� �� 0 �� " << m2 << endl << "��� ������ �� ������� ������� '-1'" << endl;
			cin >> a;
			if (a == -1) {
				break;
			}
			// ����� ������� ���������� ������� ���������� �������
			AddColumn(a);
		}

	}
};
class Project11_2 {
private:
	int m1 = 3;
	int m2 = 10;
	int** pArr = new int* [m1];
	// ������� ������ ���������� �������
	void Array() {
		for (int i = 0; i < m1; i++) {
			for (int j = 0; j < m2; j++) {
				cout << pArr[i][j] << " ";
			}cout << endl;
		}cout << endl;
	}
	// ������� ���������� ������� ���������� �������
	void AddColumn(int a) {
		// ���������� �������� ������� �� -1
		m2 -= 1;
		// �������� ������� ���������� �������
		for (int i = 0; i < m1; i++) {
			for (int j = a; j < m2; j++) {
				pArr[i][j] = pArr[i][j + 1];
			}
		}


		// ����� ������� ������ �������
		Array();
	}

public:
	void main()
	{
		srand(unsigned(time(NULL)));
		cout << "\n������ 2: �������� �������, ��������� ������� ����������� ������� �� ���������� ������.\n\n";
		int a;
		// �������� ���������� �������
		for (int i = 0; i < m1; i++) {
			pArr[i] = new int[m2];
			for (int j = 0; j < m2; j++) {
				pArr[i][j] = rand() % 89 + 10;
			}
		}
		// ����� ������� ������ �������
		Array();

		for (;;) {
			cout << "������� ����� ������� ����������� �������, ����� �� 0 �� " << m2 - 1 << endl << "��� ������ �� ������� ������� '-1'" << endl;
			cin >> a;
			if (a == -1) {
				break;
			}
			if (a <= m2 - 1) {
				// ����� ������� �������� ������� ���������� �������
				AddColumn(a);
			}
			else cout << "������!\n";
		}
	}
};
class Project11_3 {
private:
	int m1 = 5;
	int m2 = 5;
	int** pArr = new int* [m1];
	// ������� ������ ���������� �������
	void Array() {
		for (int i = 0; i < m1; i++) {
			for (int j = 0; j < m2; j++) {
				cout << pArr[i][j] << " ";
			}cout << endl;
		}cout << endl;
	}
	// ������� ������ ����� �/��� �������� ���������� �������
	void Shift(int b, int c) {
		int temp;

		// ����� ������ ���������� ������� �����
		if (b == 1) {
			for (int i = 0; i < m1; i++) {
				for (int j = 0; j < m2 - 1; j++) {
					temp = pArr[i][j];
					pArr[i][j] = pArr[i][j + 1];
					pArr[i][j + 1] = temp;
				}
			}
		}
		// ����� ������ ���������� ������� ������
		else if (b == 2) {
			for (int i = 0; i < m1; i++) {
				for (int j = m2 - 1; j > 0; j--) {
					temp = pArr[i][j];
					pArr[i][j] = pArr[i][j - 1];
					pArr[i][j - 1] = temp;
				}
			}
		}
		// ����� ������� ���������� ������� �����
		if (c == 1) {
			for (int i = 0; i < m1 - 1; i++) {
				for (int j = 0; j < m2; j++) {
					temp = pArr[i][j];
					pArr[i][j] = pArr[i + 1][j];
					pArr[i + 1][j] = temp;
				}
			}
		}
		// ����� ������� ���������� ������� ������
		else if (c == 2) {
			for (int i = m2 - 1; i > 0; i--) {
				for (int j = 0; j < m2; j++) {
					temp = pArr[i][j];
					pArr[i][j] = pArr[i - 1][j];
					pArr[i - 1][j] = temp;
				}
			}
		}

	}

public:
	void main()
	{
		srand(unsigned(time(NULL)));
		cout << "\n������ 3: ���� ������� ������� MxN(M �����, N ��������).���������� ��������� �� ���������� �\n";
		cout << "�������� �������, �������������� ����������� ����� ����� � / ��� �������� �������\n";
		cout << "��������� ���������� ��� � � ��������� �������.\n\n";

		int a, b, c;
		// �������� ���������� �������
		for (int i = 0; i < m1; i++) {
			pArr[i] = new int[m2];
			for (int j = 0; j < m2; j++) {

				pArr[i][j] = rand() % 89 + 10;
			}
		}
		// ����� ������� ������ ���������� �������
		Array();

		for (;;) {
			cout << "������� �� ������� ��������" << endl << "��� ������ �� ������� ������� '-1'" << endl;
			cin >> a;
			if (a == -1) {
				break;
			}

			cout << "������� ���� �������� ������" << endl;
			cout << "����� - 1, ������ - 2, �� �������� - 0" << endl;
			cin >> b;

			cout << "������� ���� �������� �������" << endl;
			cout << "����� - 1, ���� - 2, �� �������� - 0" << endl;
			cin >> c;


			for (int i = 0; i < a; i++) {
				// ����� ������� ������ ����� �/��� �������� ���������� �������
				Shift(b, c);
			}
			// ����� ������� ������ ���������� �������
			Array();
		}

	}
};
class Project11_4 {
private:
	int m = 5;
	int** pArr = new int* [m];
	// ������� ������ ���������� �������
	void Array() {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				cout << pArr[i][j] << " ";
			}cout << endl;
		}cout << endl;
	}
	// ������� ���������������� �������
	void Transpose() {
		int temp, j, k = 1;
		for (int i = 0; i < m; i++) {
			j = k;
			for (j; j < m; j++) {
				temp = pArr[i][j];
				pArr[i][j] = pArr[j][i];
				pArr[j][i] = temp;
			}k++;
		}

	}

public:
	void main()
	{
		srand(unsigned(time(NULL)));
		cout << "\n������ 4: ���������������� ������� � ��� ��������, ����� ������� ������� ������� �������\n";
		cout << "���������� ��������, � ������ ���������.�������� ������� ���������������� �������.\n\n";

		// �������� ���������� �������
		for (int i = 0; i < m; i++) {
			pArr[i] = new int[m];
			for (int j = 0; j < m; j++) {
				pArr[i][j] = rand() % 89 + 10;
			}
		}
		// ����� ������� ������ ���������� �������
		Array();

		// ����� ������� ���������������� �������
		Transpose();
		// ����� ������� ������ ���������� �������
		Array();

	}
};
class Project11_5 {
private:
	int m3 = 5;
	int m1 = 15;
	int m2 = 15;
	char** pArrName = new char* [m1];
	char** pArrTelefon = new char* [m2];
	char* nameSearch = new char[m1];
	char* Telefon = new char[m2];
	char* nameAdd = new char[m1];
	char* TelefonAdd = new char[m2];
	char name[15][15] = { "Valik","Vika","Roma","Nastia","Ira" };
	char telefon[15][15] = { "+380501111111","+380502222222","+380503333333","+380504444444","+380505555555" };

	// ������� ������ ���������� �������
	void Array() {
		for (int i = 0; i < m3; i++) {
			cout << pArrName[i];
			cout << "\t";
			cout << pArrTelefon[i];
			cout << endl;
		}cout << endl;
	}
	// ������� ���������������� �������
	void Add() {
		cout << "������� ��� ��������\n";
		nameAdd = new char[m1];
		cin >> nameAdd;
		cout << "������� ����� ��������\n";
		TelefonAdd = new char[m2];
		cin >> TelefonAdd;
		m3++;
		pArrName[m3 - 1] = nameAdd;
		pArrTelefon[m3 - 1] = TelefonAdd;

	}
	void Change() {
		cout << "������� ��� ��������\n";
		nameAdd = new char[m1];
		cin >> nameAdd;
		int count = strlen(nameAdd);
		cout << "������� ����� ��������\n";
		TelefonAdd = new char[m2];
		cin >> TelefonAdd;
		for (int i = 0; i < m3; i++) {
			for (int j = 0; j < m2; ) {
				if (nameAdd[j] == pArrName[i][j] or nameAdd[j] == pArrTelefon[i][j]) {
					j++;
					if (j == count) {
						pArrTelefon[i] = TelefonAdd;
						cout << pArrName[i] << "\t" << pArrTelefon[i] << endl;
					}
				}
				else break;
			}
		}
	}
	void Search() {
		cout << "������� ��� ��� ����� �������� ���������\n";
		cin >> nameSearch;
		int count = strlen(nameSearch);
		for (int i = 0; i < m3; i++) {
			for (int j = 0; j < m2; ) {
				if (nameSearch[j] == pArrName[i][j] or nameSearch[j] == pArrTelefon[i][j]) {
					j++;
					if (j == count) {
						cout << pArrName[i] << "\t" << pArrTelefon[i] << endl;
					}
				}
				else break;
			}
		}
	}
public:
	void main()
	{
		srand(unsigned(time(NULL)));
		cout << "\n������ 5: �������� ������������ ������, �������� � ������ ������ ���, � �� ������ - �������.\n";
		cout << "����������� ����� �� ����� � �� ������ �������� � ����������� ����� � ��������� ������.\n\n";


		int a;
		// �������� ���������� �������
		for (int i = 0; i < m1; i++) {
			pArrName[i] = new char[m1];
			for (int j = 0; j < m2; j++) {
				pArrName[i][j] = name[i][j];
			}
		}
		for (int i = 0; i < m1; i++) {
			pArrTelefon[i] = new char[m1];
			for (int j = 0; j < m2; j++) {
				pArrTelefon[i][j] = telefon[i][j];
			}
		}
		// ����� ������� ������ ���������� �������
		Array();
		for (;;) {
			cout << "����� - 0, ����� �� ����� ��� ������ - 1, �������� ����� �������� - 2\n";
			cout << "�������� ���������� - 3, �������� ���� ������ ����� - 4\n";
			cin >> a;
			if (a == 1) {
				Search();
			}
			else if (a == 2) {
				Change();
			}
			else if (a == 3) {
				Add();
			}
			else if (a == 4)Array();
			else if (a == 0) break;
		}
	}
};