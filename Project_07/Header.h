#pragma once
#pragma once
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Project7_1 {
private:
	// ������ ������� �� ������� N3
	template <class T1, class T2>
	T2 Max(T1 a, T2 b) {
		return a > b ? a : b;
	}
	// ������ ������� �� ������� N3
	template <class T1, class T2>
	T2 Min(T1 a, T2 b) {
		return a < b ? a : b;
	}
	// ����� ������� �� �����
	template <class T1, class T2, class T3>
	void ShowMatrix(T1 matr[][5], T2 rows, T3 cols) {
		for (T2 i = 0; i < rows; i++) {
			for (T3 j = 0; j < cols; j++) {
				cout << matr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	// ������������� ���������� �������
	template <class T1, class T2, class T3>
	void InitMatrix(T1 matr[][5], T2 rows, T3 cols, int a) {
		for (T2 i = 0; i < rows; i++) {
			for (T3 j = 0; j < cols; j++) {
				if (a == 1) {
					matr[i][j] = rand() % 10;
				}
				else if (a == 2) {
					int rnd = rand() % 10;
					double rnd_double = (double)rnd + 0.5;
					T1 rnd_matr = (T1)rnd_double;
					matr[i][j] = rnd_matr;
				}
				else if (a == 3) {
					matr[i][j] = rand() % 10 + 70;
				}
			}
		}

	}
	// ����������� ������������� � ������������ �������� �� ������� ��������� �������
	template <class T1, class T2, class T3>
	void MinMax(T1 matr[][5], T2 rows, T3 cols) {
		T1 x, y;
		x = matr[0][0];
		y = matr[0][0];
		for (T2 i = 0; i < rows; i++) {
			for (T3 j = 0; j < cols; j++) {
				if (i == j) {
					x = Max(x, matr[i][j]);
					y = Min(y, matr[i][j]);
				}
			}

		}
		cout << "������������ ������� �� ������� ��������� ������� - " << x << endl;
		cout << "����������� ������� �� ������� ��������� ������� - " << y << endl;
	}
	// ���������� ��������� �� ����������� �������� ��� ������ ������ �������
	template <class T1, class T2, class T3>
	void SortBuble(T1 matr[][5], T2 rows, T3 cols) {
		cout << "\n���������� ������� �� �����������\n";
		T1 x;
		for (T2 i = 0; i < rows; i++) {
			for (T3 a = 0; a < cols; a++) {
				for (T3 j = cols - 1; j > a; j--) {
					if (matr[i][j - 1] > matr[i][j]) {
						x = matr[i][j - 1];
						matr[i][j - 1] = matr[i][j];
						matr[i][j] = x;
					}
				}
			}
		}
		cout << endl;

	}
public:
	void main() {
		cout << "\n������� 3: �������� ��������� �� ������� � ������� ������� � ������� ��������\n";
		cout << "\n������� 1: �������� ������������� �������(int, double, char) ��� ���������� ��������� ����� :";
		cout << "\n������������� ���������� �������;";
		cout << "\n����� ������� �� �����;";
		cout << "\n����������� ������������� � ������������ �������� �� ������� ��������� �������;";
		cout << "\n���������� ��������� �� ����������� �������� ��� ������ ������ �������.\n\n";

		srand(unsigned(time(NULL)));
		const int mRows = 5;
		const int mCols = 5;
		int intMatr[mRows][mCols];
		double doubleMatr[mRows][mCols];
		char charMatr[mRows][mCols];
		// ������������� ���������� �������
		InitMatrix(intMatr, mRows, mCols, 1);
		// ����� ������� �� �����
		cout << "\n����� int ������� �� �����\n\n";
		ShowMatrix(intMatr, mRows, mCols);
		// ����������� ������������� � ������������ �������� �� ������� ��������� �������
		MinMax(intMatr, mRows, mCols);
		// ���������� ��������� �� ����������� �������� ��� ������ ������ �������
		SortBuble(intMatr, mRows, mCols);
		// ����� ������� �� �����
		ShowMatrix(intMatr, mRows, mCols);
		// ������������� ���������� �������
		InitMatrix(doubleMatr, mRows, mCols, 2);
		// ����� ������� �� �����
		cout << "\n����� double ������� �� �����\n\n";
		ShowMatrix(doubleMatr, mRows, mCols);
		// ����������� ������������� � ������������ �������� �� ������� ��������� �������
		MinMax(doubleMatr, mRows, mCols);
		// ���������� ��������� �� ����������� �������� ��� ������ ������ �������
		SortBuble(doubleMatr, mRows, mCols);
		// ����� ������� �� �����
		ShowMatrix(doubleMatr, mRows, mCols);
		// ������������� ���������� �������
		InitMatrix(charMatr, mRows, mCols, 3);
		// ����� ������� �� �����
		cout << "\n����� char ������� �� �����\n\n";
		ShowMatrix(charMatr, mRows, mCols);
		// ����������� ������������� � ������������ �������� �� ������� ��������� �������
		MinMax(charMatr, mRows, mCols);
		// ���������� ��������� �� ����������� �������� ��� ������ ������ �������
		SortBuble(charMatr, mRows, mCols);
		// ����� ������� �� �����
		ShowMatrix(charMatr, mRows, mCols);
	}
};
class Project7_2 {
private:
	// ������ ������� �� ������� N3
	template <class T>
	int MinMax(T a, T b) {
		return a > b ? a : b;
	}
	// ������ ������� �� ������� N3
	template <class T>
	int Sum(T a, T b) {
		return a += b;
	}
	// ����� ������� �� �����
	template <class T>
	void ShowMatrix(T Array[3], T matr2[][3], T matr3[][3][3], T page, T row, T column) {
		cout << endl << "���������� ������" << endl;
		for (T j = 0; j < column; j++) {
			cout << Array[j] << " ";
		}
		cout << endl;
		cout << endl << "��������� ������" << endl;
		for (T i = 0; i < row; i++) {
			for (T j = 0; j < column; j++) {
				cout << matr2[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << endl << "���������� ������" << endl;
		for (T a = 0; a < page; a++) {
			for (T i = 0; i < row; i++) {
				for (T j = 0; j < column; j++) {
					cout << matr3[a][i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		cout << endl;
	}
	// ������������� �������
	template <class T>
	void InitMatrix(T Array[3], T matr2[][3], T matr3[][3][3], T page, T row, T column) {

		for (T j = 0; j < column; j++) {
			Array[j] = rand() % 100;
		}
		for (T i = 0; i < row; i++) {
			for (T j = 0; j < column; j++) {
				matr2[i][j] = rand() % 100;
			}
		}
		for (T a = 0; a < page; a++) {
			for (T i = 0; i < row; i++) {
				for (T j = 0; j < column; j++) {
					matr3[a][i][j] = rand() % 100;
				}
			}
		}

	}
	// ���������� ������������� �������� 
	template <class T>
	void Max(T Array[3], T matr2[][3], T matr3[][3][3], T page, T row, T column) {
		T x;

		x = Array[0];
		for (T j = 0; j < column; j++) {
			// ������������� ������� �������
			x = MinMax(x, Array[j]);
		}
		cout << "������������ ������� ����������� ������� - " << x << endl;

		x = matr2[0][0];
		for (T i = 0; i < row; i++) {
			for (T j = 0; j < column; j++) {
				// ������������� ������� �������
				x = MinMax(x, matr2[i][j]);
			}
		}
		cout << "������������ ������� ���������� ������� - " << x << endl;

		x = matr3[0][0][0];
		for (T a = 0; a < page; a++) {
			for (T i = 0; i < row; i++) {
				for (T j = 0; j < column; j++) {
					// ������������� ������� �������
					x = MinMax(x, matr3[a][i][j]);
				}
			}
		}
		cout << "������������ ������� ����������� ������� - " << x << endl;
	}
	// ���������� ������������� �������� ���� �����
	template <class T>
	void MaxMatrix2(T matr2[][3], T row, T column) {
		T x, sum;
		x = matr2[0][0];
		for (T i = 0; i < row; i++) {
			sum = 0;
			for (T j = 0; j < column; j++) {
				// ������������� ������� �������
				sum = Sum(sum, matr2[j][i]);
				x = MinMax(x, sum);

			}
		}
		cout << "������������ �������� ���� ����� - " << x << endl;

	}
	// ���������� ������������� �������� ��� �����
	template <class T>
	void MaxMatrix3(T matr3[][3][3], T page, T row, T column) {
		T x, sum;
		x = matr3[0][0][0];
		for (T a = 0; a < page; a++) {
			sum = 0;
			for (T i = 0; i < row; i++) {
				for (T j = 0; j < column; j++) {
					// ������������� ������� �������
					sum = Sum(sum, matr3[j][i][a]);
					x = MinMax(x, sum);
				}
			}
		}
		cout << "������������ �������� ��� ����� - " << x << endl;

	}
public:
	void main() {
		cout << "\n������� 3: �������� ��������� �� ������� � ������� ������� � ������� ��������\n";
		cout << "\n������� 2: �������� ������������� ������� � �������������� �� � �������� ��������� :";
		cout << "\n���������� ������������� �������� � ���������� �������;";
		cout << "\n���������� ������������� �������� � ��������� �������;";
		cout << "\n���������� ������������� �������� � ��������� �������;";
		cout << "\n���������� ������������� �������� ���� �����;";
		cout << "\n���������� ������������� �������� ��� �����;\n\n";

		srand(unsigned(time(NULL)));
		const int mPage = 3;
		const int mRow = 3;
		const int mColumn = 3;
		int Array[mColumn];
		int Matr2[mRow][mColumn];
		int Matr3[mPage][mRow][mColumn];
		// ������������� �������
		InitMatrix(Array, Matr2, Matr3, mPage, mRow, mColumn);
		// ����� ������� �� �����
		ShowMatrix(Array, Matr2, Matr3, mPage, mRow, mColumn);
		// ���������� ������������� �������� 
		Max(Array, Matr2, Matr3, mPage, mRow, mColumn);
		// ���������� ������������� �������� ���� �����
		MaxMatrix2(Matr2, mRow, mColumn);
		// ���������� ������������� �������� ��� �����
		MaxMatrix3(Matr3, mPage, mRow, mColumn);
	}
};
