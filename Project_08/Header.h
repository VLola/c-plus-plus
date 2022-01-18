#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Project8_1 {
public:

	// Создание функции
	template <class T>
	void bubbleSort(T a[], int size) {
		long i, j;
		T x;
		// Пузырьковая сортировка массива 
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
		cout << "\nЗадание 1: Написать программу, выполняющую сортировку одномерного массива целых чисел методом пузырьковой сортировки.\n\n";
		srand(unsigned(time(NULL)));
		const int size = 10;
		int ar[size];
		// Создание массива
		for (int i = 0; i < size; i++) {
			ar[i] = rand() % 100;
			cout << ar[i] << " ";
		}
		cout << "\n\n";
		// Вызов функции и передача ей переменных
		bubbleSort(ar, size);
		// Вывод массива на экран
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
		// цикл проходов, i - номер прохода
		for (i = 0; i < size; i++) {
			x = a[i];
			// поиск места элемента в готовой
			// последовательности
			for (j = i - 1; j >= 0 && a[j] > x; j--)
				// сдвигаем элемент направо,пока не дошли
				a[j + 1] = a[j];
			// место найдено, вставить элемент
			a[j + 1] = x;
		}
	}
	void main() {
		cout << "\nЗадание 2: Написать программу, выполняющую сортировку одномерного массива целых чисел методом вставок.\n\n";
		srand(unsigned(time(NULL)));
		const int size = 10;
		int ar[size];
		// Создание массива
		for (int i = 0; i < size; i++) {
			ar[i] = rand() % 100;
			cout << ar[i] << " ";
		}
		cout << "\n\n";
		// Вызов функции и передача ей переменных
		Sort(ar, size);
		// Вывод массива на экран
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
		if (sum / size > 10.7) cout << "Студент выходит на степендию\n Средний бал студента - " << sum / size << endl;
		else cout << "Студент не выходит на степендию\n Средний бал студента - " << sum / size << endl;
	}

	template <class T>
	void Array(T a[], int size) {
		cout << endl << "Оценки студента:\n";
		for (int i = 0; i < size; i++) {
			cout << a[i] << " ";
		}cout << endl;
	}

	void main() {
		cout << "\nЗадание 3: Написать программу «успеваемость». Пользователь вводит 10 оценок студента. Реализовать меню для пользователя";
		cout << "\nВывод оценок(вывод содержимого массива)";
		cout << "\nПересдача экзамена(пользователь вводит номер элемента массива и новую оценку)";
		cout << "\nВыходит ли стипендия(стипендия выходит, если средний бал не ниже 10.7) \n\n";
		srand(unsigned(time(NULL)));
		const int size = 10;

		int value, retake;
		double grade, new_grade;
		double ar[size];
		// Создание массива
		for (int i = 0; i < size; i++) {
			cout << "Введите " << i + 1 << " оценку\n";
			cin >> grade;
			ar[i] = grade;
		}
		cout << "\n\n";
		for (int i = 0; i < size; i++) {
			cout << "\nВыберите действие:\n 0 - Выход из программы\n 1 - Вывод оценок\n 2 - Пересдача экзамена\n 3 - Выходит ли стипендия\n";
			cin >> value;
			if (value == 1) {
				// Вызов функции "вывод массива на экран"
				Array(ar, size);
			}
			else if (value == 2) {
				// Ввод номера элемента массива
				cout << "Введите номер оценки которую хотите перездать\n";
				cin >> retake;
				// Ввод новой оценки
				cout << "Введите новую оценку\n";
				cin >> new_grade;
				// Присваивание оценки элементу массива
				ar[retake] = new_grade;
				// Вызов функции "вывод массива на экран"
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

	// Создание функции
	template <class T>
	void SortFirst(T a[], int size_condition, int size) {
		int i, j;
		T x;
		// Пузырьковая сортировка массива 
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
	// Создание функции
	template <class T1, class T2>
	void SortSecond(T1 a[], T2 arr[], int size_condition, int size) {
		int i, j;
		// Расположение массива в обратном порядке
		for (i = size_condition; i < size; i++) {
			for (j = size - 1; j > size + size_condition - i - 2; j--) {
				a[i] = arr[j];
			}
		}
		// Вывод массива на экран
		for (int i = 0; i < size; i++) {
			cout << a[i] << " ";
		}cout << endl;
	}

	void main() {
		cout << "\nЗадание 4: Необходимо отсортировать первые две трети массива в порядке возрастания, если среднее";
		cout << "\nарифметическое всех элементов больше нуля; иначе - лишь первую треть.Остальную часть";
		cout << "\nмассива не сортировать, а расположить в обратном порядке. \n\n";

		srand(unsigned(time(NULL)));
		const int size = 9;

		int sum = 0, srednee, size_condition;
		int ar[size], arr[size];
		// Создание массива
		for (int i = 0; i < size; i++) {
			ar[i] = rand() % 100 - 50;
			cout << ar[i] << " ";
		}cout << endl;
		// Среднее арифметическое массива
		for (int i = 0; i < size; i++) {
			sum += ar[i];
		}
		srednee = sum / size;
		// Создание дублирующего массива (Для перезаписи массива)
		for (int i = 0; i < size; i++) {
			arr[i] = ar[i];
		}
		if (srednee > 0) {
			cout << "Среднее арифметическое всех элементов массива больше нуля\n";
			// Первое условие задачи
			size_condition = size / 3 * 2;
			// Вызов функции "Пузырьковая сортировка массива"
			SortFirst(ar, size_condition, size);
			// Вызов функции "Расположение массива в обратном порядке"
			SortSecond(ar, arr, size_condition, size);
		}
		else {
			cout << "Среднее арифметическое всех элементов массива меньше нуля\n";
			// Второе условие задачи
			size_condition = size / 3;
			// Вызов функции "Пузырьковая сортировка массива"
			SortFirst(ar, size_condition, size);
			// Вызов функции "Расположение массива в обратном порядке"
			SortSecond(ar, arr, size_condition, size);
		}
	}
};