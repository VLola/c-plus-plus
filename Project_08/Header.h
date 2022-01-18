#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Project8_1 {
public:

	// �������� �������
	template <class T>
	void bubbleSort(T a[], int size) {
		long i, j;
		T x;
		// ����������� ���������� ������� 
		for (i = 0; i < size; i++) {
			for (j = size - 1; j > i; j--) {
				if (a[j - 1] > a[j]) {
					x = a[j - 1];
					a[j - 1] = a[j];
					a[j] = x;
				}
			}
		}
	}

	void main() {
		cout << "\n������� 1: �������� ���������, ����������� ���������� ����������� ������� ����� ����� ������� ����������� ����������.\n\n";
		srand(unsigned(time(NULL)));
		const int size = 10;
		int ar[size];
		// �������� �������
		for (int i = 0; i < size; i++) {
			ar[i] = rand() % 100;
			cout << ar[i] << " ";
		}
		cout << "\n\n";
		// ����� ������� � �������� �� ����������
		bubbleSort(ar, size);
		// ����� ������� �� �����
		for (int i = 0; i < size; i++) {
			cout << ar[i] << " ";
		}
		cout << "\n\n";
	}
};
class Project8_2 {
public:

	template <class T>
	void Sort(T a[], int size) {
		T x;
		long i, j;
		// ���� ��������, i - ����� �������
		for (i = 0; i < size; i++) {
			x = a[i];
			// ����� ����� �������� � �������
			// ������������������
			for (j = i - 1; j >= 0 && a[j] > x; j--)
				// �������� ������� �������,���� �� �����
				a[j + 1] = a[j];
			// ����� �������, �������� �������
			a[j + 1] = x;
		}
	}
	void main() {
		cout << "\n������� 2: �������� ���������, ����������� ���������� ����������� ������� ����� ����� ������� �������.\n\n";
		srand(unsigned(time(NULL)));
		const int size = 10;
		int ar[size];
		// �������� �������
		for (int i = 0; i < size; i++) {
			ar[i] = rand() % 100;
			cout << ar[i] << " ";
		}
		cout << "\n\n";
		// ����� ������� � �������� �� ����������
		Sort(ar, size);
		// ����� ������� �� �����
		for (int i = 0; i < size; i++) {
			cout << ar[i] << " ";
		}
		cout << "\n\n";
	}
};
class Project8_3 {
public:

	template <class T, class T1>
	void Stipend(T a[], T1 size) {
		T sum = 0;
		for (int i = 0; i < size; i++) {
			a[i];
			sum += a[i];
		}
		if (sum / size > 10.7) cout << "������� ������� �� ���������\n ������� ��� �������� - " << sum / size << endl;
		else cout << "������� �� ������� �� ���������\n ������� ��� �������� - " << sum / size << endl;
	}

	template <class T>
	void Array(T a[], int size) {
		cout << endl << "������ ��������:\n";
		for (int i = 0; i < size; i++) {
			cout << a[i] << " ";
		}cout << endl;
	}

	void main() {
		cout << "\n������� 3: �������� ��������� ��������������. ������������ ������ 10 ������ ��������. ����������� ���� ��� ������������";
		cout << "\n����� ������(����� ����������� �������)";
		cout << "\n��������� ��������(������������ ������ ����� �������� ������� � ����� ������)";
		cout << "\n������� �� ���������(��������� �������, ���� ������� ��� �� ���� 10.7) \n\n";
		srand(unsigned(time(NULL)));
		const int size = 10;

		int value, retake;
		double grade, new_grade;
		double ar[size];
		// �������� �������
		for (int i = 0; i < size; i++) {
			cout << "������� " << i + 1 << " ������\n";
			cin >> grade;
			ar[i] = grade;
		}
		cout << "\n\n";
		for (int i = 0; i < size; i++) {
			cout << "\n�������� ��������:\n 0 - ����� �� ���������\n 1 - ����� ������\n 2 - ��������� ��������\n 3 - ������� �� ���������\n";
			cin >> value;
			if (value == 1) {
				// ����� ������� "����� ������� �� �����"
				Array(ar, size);
			}
			else if (value == 2) {
				// ���� ������ �������� �������
				cout << "������� ����� ������ ������� ������ ���������\n";
				cin >> retake;
				// ���� ����� ������
				cout << "������� ����� ������\n";
				cin >> new_grade;
				// ������������ ������ �������� �������
				ar[retake] = new_grade;
				// ����� ������� "����� ������� �� �����"
				Array(ar, size);
				continue;
			}
			else if (value == 3) {
				Stipend(ar, size);
				continue;
			}
			else if (value == 0) {
				break;
			}
			else {
				continue;
			}
		}
	}
};
class Project8_4 {
public:

	// �������� �������
	template <class T>
	void SortFirst(T a[], int size_condition, int size) {
		int i, j;
		T x;
		// ����������� ���������� ������� 
		for (i = 0; i < size_condition; i++) {
			for (j = size_condition - 1; j > i; j--) {
				if (a[j - 1] > a[j]) {
					x = a[j - 1];
					a[j - 1] = a[j];
					a[j] = x;
				}
			}
		}
	}
	// �������� �������
	template <class T1, class T2>
	void SortSecond(T1 a[], T2 arr[], int size_condition, int size) {
		int i, j;
		// ������������ ������� � �������� �������
		for (i = size_condition; i < size; i++) {
			for (j = size - 1; j > size + size_condition - i - 2; j--) {
				a[i] = arr[j];
			}
		}
		// ����� ������� �� �����
		for (int i = 0; i < size; i++) {
			cout << a[i] << " ";
		}cout << endl;
	}

	void main() {
		cout << "\n������� 4: ���������� ������������� ������ ��� ����� ������� � ������� �����������, ���� �������";
		cout << "\n�������������� ���� ��������� ������ ����; ����� - ���� ������ �����.��������� �����";
		cout << "\n������� �� �����������, � ����������� � �������� �������. \n\n";

		srand(unsigned(time(NULL)));
		const int size = 9;

		int sum = 0, srednee, size_condition;
		int ar[size], arr[size];
		// �������� �������
		for (int i = 0; i < size; i++) {
			ar[i] = rand() % 100 - 50;
			cout << ar[i] << " ";
		}cout << endl;
		// ������� �������������� �������
		for (int i = 0; i < size; i++) {
			sum += ar[i];
		}
		srednee = sum / size;
		// �������� ������������ ������� (��� ���������� �������)
		for (int i = 0; i < size; i++) {
			arr[i] = ar[i];
		}
		if (srednee > 0) {
			cout << "������� �������������� ���� ��������� ������� ������ ����\n";
			// ������ ������� ������
			size_condition = size / 3 * 2;
			// ����� ������� "����������� ���������� �������"
			SortFirst(ar, size_condition, size);
			// ����� ������� "������������ ������� � �������� �������"
			SortSecond(ar, arr, size_condition, size);
		}
		else {
			cout << "������� �������������� ���� ��������� ������� ������ ����\n";
			// ������ ������� ������
			size_condition = size / 3;
			// ����� ������� "����������� ���������� �������"
			SortFirst(ar, size_condition, size);
			// ����� ������� "������������ ������� � �������� �������"
			SortSecond(ar, arr, size_condition, size);
		}
	}
};