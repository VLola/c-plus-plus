#pragma once
#pragma once
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Project7_1 {
private:
	// Шаблон функции по заданию N3
	template <class T1, class T2>
	T2 Max(T1 a, T2 b) {
		return a > b ? a : b;
	}
	// Шаблон функции по заданию N3
	template <class T1, class T2>
	T2 Min(T1 a, T2 b) {
		return a < b ? a : b;
	}
	// Вывод матрицы на экран
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
	// Инициализация квадратной матрицы
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
	// Определение максимального и минимального элемента на главной диагонали матрицы
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
		cout << "Максимальный элемент на главной диагонали матрицы - " << x << endl;
		cout << "Минимальный элемент на главной диагонали матрицы - " << y << endl;
	}
	// Сортировка элементов по возрастанию отдельно для каждой строки матрицы
	template <class T1, class T2, class T3>
	void SortBuble(T1 matr[][5], T2 rows, T3 cols) {
		cout << "\nСортировка матрицы по возрастанию\n";
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
		cout << "\nЗадание 3: Измените программы из первого и второго задания с помощью шаблонов\n";
		cout << "\nЗадание 1: Написать перегруженные функции(int, double, char) для выполнения следующих задач :";
		cout << "\nИнициализация квадратной матрицы;";
		cout << "\nВывод матрицы на экран;";
		cout << "\nОпределение максимального и минимального элемента на главной диагонали матрицы;";
		cout << "\nСортировка элементов по возрастанию отдельно для каждой строки матрицы.\n\n";

		srand(unsigned(time(NULL)));
		const int mRows = 5;
		const int mCols = 5;
		int intMatr[mRows][mCols];
		double doubleMatr[mRows][mCols];
		char charMatr[mRows][mCols];
		// Инициализация квадратной матрицы
		InitMatrix(intMatr, mRows, mCols, 1);
		// Вывод матрицы на экран
		cout << "\nВывод int матрицы на экран\n\n";
		ShowMatrix(intMatr, mRows, mCols);
		// Определение максимального и минимального элемента на главной диагонали матрицы
		MinMax(intMatr, mRows, mCols);
		// Сортировка элементов по возрастанию отдельно для каждой строки матрицы
		SortBuble(intMatr, mRows, mCols);
		// Вывод матрицы на экран
		ShowMatrix(intMatr, mRows, mCols);
		// Инициализация квадратной матрицы
		InitMatrix(doubleMatr, mRows, mCols, 2);
		// Вывод матрицы на экран
		cout << "\nВывод double матрицы на экран\n\n";
		ShowMatrix(doubleMatr, mRows, mCols);
		// Определение максимального и минимального элемента на главной диагонали матрицы
		MinMax(doubleMatr, mRows, mCols);
		// Сортировка элементов по возрастанию отдельно для каждой строки матрицы
		SortBuble(doubleMatr, mRows, mCols);
		// Вывод матрицы на экран
		ShowMatrix(doubleMatr, mRows, mCols);
		// Инициализация квадратной матрицы
		InitMatrix(charMatr, mRows, mCols, 3);
		// Вывод матрицы на экран
		cout << "\nВывод char матрицы на экран\n\n";
		ShowMatrix(charMatr, mRows, mCols);
		// Определение максимального и минимального элемента на главной диагонали матрицы
		MinMax(charMatr, mRows, mCols);
		// Сортировка элементов по возрастанию отдельно для каждой строки матрицы
		SortBuble(charMatr, mRows, mCols);
		// Вывод матрицы на экран
		ShowMatrix(charMatr, mRows, mCols);
	}
};
class Project7_2 {
private:
	// Шаблон функции по заданию N3
	template <class T>
	int MinMax(T a, T b) {
		return a > b ? a : b;
	}
	// Шаблон функции по заданию N3
	template <class T>
	int Sum(T a, T b) {
		return a += b;
	}
	// Вывод матрицы на экран
	template <class T>
	void ShowMatrix(T Array[3], T matr2[][3], T matr3[][3][3], T page, T row, T column) {
		cout << endl << "Одномерный массив" << endl;
		for (T j = 0; j < column; j++) {
			cout << Array[j] << " ";
		}
		cout << endl;
		cout << endl << "Двумерный массив" << endl;
		for (T i = 0; i < row; i++) {
			for (T j = 0; j < column; j++) {
				cout << matr2[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << endl << "Трехмерный массив" << endl;
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
	// Инициализация матрицы
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
	// Нахождения максимального значения 
	template <class T>
	void Max(T Array[3], T matr2[][3], T matr3[][3][3], T page, T row, T column) {
		T x;

		x = Array[0];
		for (T j = 0; j < column; j++) {
			// Использование шаблона функции
			x = MinMax(x, Array[j]);
		}
		cout << "Максимальный элемент одномерного массива - " << x << endl;

		x = matr2[0][0];
		for (T i = 0; i < row; i++) {
			for (T j = 0; j < column; j++) {
				// Использование шаблона функции
				x = MinMax(x, matr2[i][j]);
			}
		}
		cout << "Максимальный элемент двумерного массива - " << x << endl;

		x = matr3[0][0][0];
		for (T a = 0; a < page; a++) {
			for (T i = 0; i < row; i++) {
				for (T j = 0; j < column; j++) {
					// Использование шаблона функции
					x = MinMax(x, matr3[a][i][j]);
				}
			}
		}
		cout << "Максимальный элемент трехмерного массива - " << x << endl;
	}
	// Нахождения максимального значения двух целых
	template <class T>
	void MaxMatrix2(T matr2[][3], T row, T column) {
		T x, sum;
		x = matr2[0][0];
		for (T i = 0; i < row; i++) {
			sum = 0;
			for (T j = 0; j < column; j++) {
				// Использование шаблона функции
				sum = Sum(sum, matr2[j][i]);
				x = MinMax(x, sum);

			}
		}
		cout << "Максимальное значение двух целых - " << x << endl;

	}
	// Нахождения максимального значения трёх целых
	template <class T>
	void MaxMatrix3(T matr3[][3][3], T page, T row, T column) {
		T x, sum;
		x = matr3[0][0][0];
		for (T a = 0; a < page; a++) {
			sum = 0;
			for (T i = 0; i < row; i++) {
				for (T j = 0; j < column; j++) {
					// Использование шаблона функции
					sum = Sum(sum, matr3[j][i][a]);
					x = MinMax(x, sum);
				}
			}
		}
		cout << "Максимальное значение трёх целых - " << x << endl;

	}
public:
	void main() {
		cout << "\nЗадание 3: Измените программы из первого и второго задания с помощью шаблонов\n";
		cout << "\nЗадание 2: Написать перегруженные функции и протестировать их в основной программе :";
		cout << "\nНахождения максимального значения в одномерном массиве;";
		cout << "\nНахождения максимального значения в двумерном массиве;";
		cout << "\nНахождения максимального значения в трёхмерном массиве;";
		cout << "\nНахождения максимального значения двух целых;";
		cout << "\nНахождения максимального значения трёх целых;\n\n";

		srand(unsigned(time(NULL)));
		const int mPage = 3;
		const int mRow = 3;
		const int mColumn = 3;
		int Array[mColumn];
		int Matr2[mRow][mColumn];
		int Matr3[mPage][mRow][mColumn];
		// Инициализация матрицы
		InitMatrix(Array, Matr2, Matr3, mPage, mRow, mColumn);
		// Вывод матрицы на экран
		ShowMatrix(Array, Matr2, Matr3, mPage, mRow, mColumn);
		// Нахождения максимального значения 
		Max(Array, Matr2, Matr3, mPage, mRow, mColumn);
		// Нахождения максимального значения двух целых
		MaxMatrix2(Matr2, mRow, mColumn);
		// Нахождения максимального значения трёх целых
		MaxMatrix3(Matr3, mPage, mRow, mColumn);
	}
};
