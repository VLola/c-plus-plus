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
	// Функция показа двумерного массива
	void Array() {
		for (int i = 0; i < m1; i++) {
			for (int j = 0; j < m2; j++) {
				cout << pArr[i][j] << " ";
			}cout << endl;
		}cout << endl;
	}
	// Функция добавления столбца двумерному массиву
	void AddColumn(int a) {
		// Увеличение столбцов массива на +1
		m2 += 1;
		// Перезапись массива после добавленного столбца
		for (int i = 0; i < m1; i++) {
			for (int j = m2; j > a; j--) {
				pArr[i][j] = pArr[i][j - 1];
			}
		}
		// Добавление столбца в двумерный массив
		for (int j = 0; j < m1; j++) {
			pArr[j][a] = rand() % 89 + 10;
		}
		// Вызов функции показа массива
		Array();
	}
public:
	void main()
	{
		srand(unsigned(time(NULL)));
		cout << "\nЗадача 1: Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию.\n\n";
		int a;
		// Создание двумерного массива
		for (int i = 0; i < m1; i++) {
			pArr[i] = new int[m2];
			for (int j = 0; j < m2; j++) {
				pArr[i][j] = rand() % 89 + 10;
			}
		}
		// Вызов функции показа массива
		Array();

		for (;;) {
			cout << "Введите номер столбца двухмерного массива, число от 0 до " << m2 << endl << "для выхода из задания введите '-1'" << endl;
			cin >> a;
			if (a == -1) {
				break;
			}
			// Вызов функции добавления столбца двумерному массиву
			AddColumn(a);
		}

	}
};
class Project11_2 {
private:
	int m1 = 3;
	int m2 = 10;
	int** pArr = new int* [m1];
	// Функция показа двумерного массива
	void Array() {
		for (int i = 0; i < m1; i++) {
			for (int j = 0; j < m2; j++) {
				cout << pArr[i][j] << " ";
			}cout << endl;
		}cout << endl;
	}
	// Функция добавления столбца двумерному массиву
	void AddColumn(int a) {
		// Уменьшение столбцов массива на -1
		m2 -= 1;
		// Удаление столбца двумерного массива
		for (int i = 0; i < m1; i++) {
			for (int j = a; j < m2; j++) {
				pArr[i][j] = pArr[i][j + 1];
			}
		}


		// Вызов функции показа массива
		Array();
	}

public:
	void main()
	{
		srand(unsigned(time(NULL)));
		cout << "\nЗадача 2: Написать функцию, удаляющую столбец двухмерного массива по указанному номеру.\n\n";
		int a;
		// Создание двумерного массива
		for (int i = 0; i < m1; i++) {
			pArr[i] = new int[m2];
			for (int j = 0; j < m2; j++) {
				pArr[i][j] = rand() % 89 + 10;
			}
		}
		// Вызов функции показа массива
		Array();

		for (;;) {
			cout << "Введите номер столбца двухмерного массива, число от 0 до " << m2 - 1 << endl << "для выхода из задания введите '-1'" << endl;
			cin >> a;
			if (a == -1) {
				break;
			}
			if (a <= m2 - 1) {
				// Вызов функции удаления столбца двумерному массиву
				AddColumn(a);
			}
			else cout << "Ошибка!\n";
		}
	}
};
class Project11_3 {
private:
	int m1 = 5;
	int m2 = 5;
	int** pArr = new int* [m1];
	// Функция показа двумерного массива
	void Array() {
		for (int i = 0; i < m1; i++) {
			for (int j = 0; j < m2; j++) {
				cout << pArr[i][j] << " ";
			}cout << endl;
		}cout << endl;
	}
	// Функция сдвига строк и/или столбцов двумерного массива
	void Shift(int b, int c) {
		int temp;

		// Сдвиг строки двумерного массива влево
		if (b == 1) {
			for (int i = 0; i < m1; i++) {
				for (int j = 0; j < m2 - 1; j++) {
					temp = pArr[i][j];
					pArr[i][j] = pArr[i][j + 1];
					pArr[i][j + 1] = temp;
				}
			}
		}
		// Сдвиг строки двумерного массива вправо
		else if (b == 2) {
			for (int i = 0; i < m1; i++) {
				for (int j = m2 - 1; j > 0; j--) {
					temp = pArr[i][j];
					pArr[i][j] = pArr[i][j - 1];
					pArr[i][j - 1] = temp;
				}
			}
		}
		// Сдвиг столбца двумерного массива влево
		if (c == 1) {
			for (int i = 0; i < m1 - 1; i++) {
				for (int j = 0; j < m2; j++) {
					temp = pArr[i][j];
					pArr[i][j] = pArr[i + 1][j];
					pArr[i + 1][j] = temp;
				}
			}
		}
		// Сдвиг столбца двумерного массива вправо
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
		cout << "\nЗадача 3: Дана матрица порядка MxN(M строк, N столбцов).Необходимо заполнить ее значениями и\n";
		cout << "написать функцию, осуществляющую циклический сдвиг строк и / или столбцов массива\n";
		cout << "указанное количество раз и в указанную сторону.\n\n";

		int a, b, c;
		// Создание двумерного массива
		for (int i = 0; i < m1; i++) {
			pArr[i] = new int[m2];
			for (int j = 0; j < m2; j++) {

				pArr[i][j] = rand() % 89 + 10;
			}
		}
		// Вызов функции показа двумерного массива
		Array();

		for (;;) {
			cout << "Введите на сколько сдвигать" << endl << "для выхода из задания введите '-1'" << endl;
			cin >> a;
			if (a == -1) {
				break;
			}

			cout << "Введите куда сдвигать строку" << endl;
			cout << "Влево - 1, вправо - 2, не сдвигаем - 0" << endl;
			cin >> b;

			cout << "Введите куда сдвигать столбец" << endl;
			cout << "Вверх - 1, вниз - 2, не сдвигаем - 0" << endl;
			cin >> c;


			for (int i = 0; i < a; i++) {
				// Вызов функции сдвига строк и/или столбцов двумерного массива
				Shift(b, c);
			}
			// Вызов функции показа двумерного массива
			Array();
		}

	}
};
class Project11_4 {
private:
	int m = 5;
	int** pArr = new int* [m];
	// Функция показа двумерного массива
	void Array() {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				cout << pArr[i][j] << " ";
			}cout << endl;
		}cout << endl;
	}
	// Функция транспонирование матрицы
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
		cout << "\nЗадача 4: Транспонирование матрицы – это операция, после которой столбцы прежней матрицы\n";
		cout << "становятся строками, а строки столбцами.Напишите функцию транспонирования матрицы.\n\n";

		// Создание двумерного массива
		for (int i = 0; i < m; i++) {
			pArr[i] = new int[m];
			for (int j = 0; j < m; j++) {
				pArr[i][j] = rand() % 89 + 10;
			}
		}
		// Вызов функции показа двумерного массива
		Array();

		// Вызов функции транспонирование матрицы
		Transpose();
		// Вызов функции показа двумерного массива
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

	// Функция показа двумерного массива
	void Array() {
		for (int i = 0; i < m3; i++) {
			cout << pArrName[i];
			cout << "\t";
			cout << pArrTelefon[i];
			cout << endl;
		}cout << endl;
	}
	// Функция транспонирование матрицы
	void Add() {
		cout << "Введите имя человека\n";
		nameAdd = new char[m1];
		cin >> nameAdd;
		cout << "Введите номер телефона\n";
		TelefonAdd = new char[m2];
		cin >> TelefonAdd;
		m3++;
		pArrName[m3 - 1] = nameAdd;
		pArrTelefon[m3 - 1] = TelefonAdd;

	}
	void Change() {
		cout << "Введите имя человека\n";
		nameAdd = new char[m1];
		cin >> nameAdd;
		int count = strlen(nameAdd);
		cout << "Введите номер телефона\n";
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
		cout << "Введите имя или номер телефона чекловека\n";
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
		cout << "\nЗадача 5: Создайте динамический массив, хранящий в первой строке имя, а во второй - телефон.\n";
		cout << "Организуйте поиск по имени и по номеру телефона и возможность ввода и изменения данных.\n\n";


		int a;
		// Создание двумерного массива
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
		// Вызов функции показа двумерного массива
		Array();
		for (;;) {
			cout << "Выход - 0, Поиск по имени или номеру - 1, Изменить номер телефона - 2\n";
			cout << "Добавить информацию - 3, Показать весь список людей - 4\n";
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