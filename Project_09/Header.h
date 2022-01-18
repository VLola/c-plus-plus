#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Project9_1 {
public:
	// Рекурсивная функция
	template <class T>
	int Recursion(T a, T b, T N) {
		if (N < 1) {
			cout << "Общего делителя не найдено";
			return 0;
		}
		// любое другое число вызывает функцию заново
		// с формулой N-1
		else {
			if (a % N == 0) {
				if (b % N == 0) {
					cout << "Найбольший общий делитель " << a << " и " << b << " = " << N;
					return 0;
				}
				return Recursion(a, b, N - 1);
			}
			return Recursion(a, b, N - 1);
		}

	}

	void main() {
		cout << "\nЗадание 1: Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел.\n\n";
		// Ввод переменных 
		cout << "\nВведите первое число\n";
		int a, b, N;
		cin >> a;
		cout << "\nВведите второе число\n";
		cin >> b;
		// определение меньшей переменной из введенных пользователем
		N = a < b ? a : b;
		// Вызов рекурсивной функции
		Recursion(a, b, N);

	}
};
class Project9_2 {
public:
	// Рекурсивная функция
	template <class T>
	int Recursion(T a, T b, T N, T n, T c, T array[2][4], T d, T j, T h) {


		if (c > 3) {
			if (b == n) {
				cout << "Вы отгадали число!!!" << endl;
				cout << "Попыток было сделано: " << h << endl;
				return 0;
			}
			int a_1, b_1, c_1, d_1;
			if (b < 10) {
				a_1 = b;
				b_1 = -1;
				c_1 = -1;
				d_1 = -1;
			}
			else if (b < 100) {
				a_1 = b % 10;
				b_1 = b / 10 % 10;
				c_1 = -1;
				d_1 = -1;
			}
			else if (b < 1000) {
				a_1 = b % 10;
				b_1 = b / 10 % 10;
				c_1 = b / 100 % 10;
				d_1 = -1;
			}
			else if (b < 10000) {
				a_1 = b % 10;
				b_1 = b / 10 % 10;
				c_1 = b / 100 % 10;
				d_1 = b / 1000 % 10;
			}

			array[0][0] = a_1;
			array[0][1] = b_1;
			array[0][2] = c_1;
			array[0][3] = d_1;

			if (a < 4) {
				if (array[0][0] == array[1][a] or array[0][1] == array[1][a] or array[0][2] == array[1][a] or array[0][3] == array[1][a]) {
					d++;
				}
				if (array[0][a] == array[1][a]) {
					j++;
				}
				if (a == 3) {
					cout << "Цифр отгадано " << d << endl;
					cout << "Цифр стоит на нужном месте " << j << endl;
				}
				return Recursion(a + 1, b, N, n, c, array, d, j, h);
			}
			else {
				cout << "\nВведите число\n";
				cin >> b;

				d = 0;
				j = 0;
				a = 0;

				return Recursion(a, b, N, n, c, array, d, j, h + 1);

			}

		}
		else {
			int e = N % 10;
			N = N / 10;
			array[1][c] = e;
			return Recursion(a, b, N, n, c + 1, array, d, j, h);
		}


	}

	void main() {
		srand(unsigned(time(NULL)));
		cout << "\nЗадание 2: Написать игру «Быки и коровы».Программа загадывает четырёхзначное число и играющий\n";
		cout << "должен угадать его.После ввода пользователем числа программа сообщает, сколько цифр числа\n";
		cout << "угадано(быки) и сколько цифр угадано и стоит на нужном месте(коровы).После отгадывания\n";
		cout << "числа на экран необходимо вывести количество сделанных пользователем попыток.В\n";
		cout << "программе необходимо использовать рекурсию.\n\n";


		int a = 0, b, N, n, c = 0, d = 0, j = 0, h = 1;
		int array[2][4];
		// Программа загадывает 4х значное число
		N = rand() % 9000 + 1000;
		n = N;
		// Можно закоментировать следующую строку  <<подсказку>>
		cout << n << "\t - Программа загадала число \t // можно закоментировать в прогорамме" << endl;
		cout << "\nВведите число\n";
		cin >> b;

		Recursion(a, b, N, n, c, array, d, j, h);

	}
};
class Project9_3 {
public:

	template <class T>
	int NewMove(T a, T b) {
		int d = rand() % 8 + 1;
		if (d == 1) {
			a += 1;
			b += 2;
			return a * 10 + b;
		}
		else if (d == 2) {
			a += 1;
			b -= 2;
			return a * 10 + b;
		}
		else if (d == 3) {
			a -= 1;
			b += 2;
			return a * 10 + b;
		}
		else if (d == 4) {
			a -= 1;
			b -= 2;
			return a * 10 + b;
		}
		else if (d == 5) {
			a += 2;
			b += 1;
			return a * 10 + b;
		}
		else if (d == 6) {
			a += 2;
			b -= 1;
			return a * 10 + b;
		}
		else if (d == 7) {
			a -= 2;
			b += 1;
			return a * 10 + b;
		}
		else if (d == 8) {
			a -= 2;
			b -= 1;
			return a * 10 + b;
		}
		return 0;

	}

	template <class T>
	int Recurssion(T arr[36], T array[6][6], T a, T b, T c, T A, T B, T i, T d, T g, T g1, T g2, T g3) {


		if (i > 35) {
			return 0;
		}
		else {
			for (; i < 36; d++) {
				c = arr[i - 1];
				a = c / 10;
				b = c % 10;
				for (int m = 0; m < 1;) {
					c = NewMove(a, b);
					for (int j = 0; j < 6; j++) {
						for (int h = 0; h < 6; h++) {
							if (c == array[j][h]) {
								m++;
							}
						}
					}
				}

				int x = 0;
				for (int j = 0; j < i; j++) {
					if (c == arr[j]) {
						x++;
					}
				}
				if (x == 0) {
					arr[i] = c;
					i++;
				}
				else {
					g++;
					g1++;
					g2++;
					g3++;
					if (g3 > 200 && i > 21) {
						for (int j = 20; j > 0; j--) {
							arr[i - j] = 0;
						}
						i -= 20;
						g3 = 0;
					}
					else if (g2 > 150 && i > 11) {
						for (int j = 10; j > 0; j--) {
							arr[i - j] = 0;
						}
						i -= 10;
						g2 = 0;
					}
					else if (g1 > 70 && i > 6) {
						for (int j = 5; j > 0; j--) {
							arr[i - j] = 0;
						}

						i -= 5;
						g1 = 0;
					}
					else if (g > 40 && i > 2) {
						arr[i - 1] = 0;
						i -= 1;
						g = 0;
					}


				}

				if (d > 20000) {
					cout << ".";
					for (int j = 0; j < 36; j++) {
						if (j == 0) {
							arr[j] = A * 10 + B;
						}
						else arr[j] = 0;
					}
					return Recurssion(arr, array, a, b, c, A, B, i = 1, d = 0, g, g1, g2, g3);
				}

			}

			return Recurssion(arr, array, a, b, c, A, B, i, d, g, g1, g2, g3);
		}
	}

	void main()
	{
		srand(unsigned(time(NULL)));
		cout << "\nЗадание 3: Дана шахматная доска размером 8х8 и шахматный конь.Программа должна запросить у\n";
		cout << "пользователя координаты клетки поля и поставить туда коня.Задача программы найти и\n";
		cout << "вывести путь коня, при котором он обойдет все клетки доски, становясь в каждую клетку\n";
		cout << "только один раз. (Так как процесс отыскания пути для разных начальных клеток может\n";
		cout << "затянуться, то рекомендуется сначала опробовать задачу на поле размером 6х6).В программе\n";
		cout << "необходимо использовать рекурсию.\n\n";

		int a, b, c;
		int array[6][6];
		int arr[36];

		// Создание массива

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				array[i][j] = (i + 1) * 10 + j + 1;
			}
		}

		// Показ массива
		cout << "\nШахматная доска с координатами:\n";
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (i > 1) {
					if (j == 1) cout << "|" << " ";
					else if (j == 0) cout << i - 1 << " ";
					else if (j > 1)cout << array[i - 2][j - 2] << " ";
				}
				else if (i == 0) {
					if (j == 0 or j == 1)cout << " " << " ";
					else cout << " " << j - 1 << " ";
				}
				else if (i == 1) {
					if (j == 0 or j == 1)cout << " " << " ";
					else cout << "-" << "-" << "-";
				}


			}cout << endl;
		}

		cout << "\nВведите координату по вертикали\n";
		cin >> a;
		cout << "\nВведите координату по горизантали\n";
		cin >> b;


		int A = a;
		int B = b;

		c = a * 10 + b;
		arr[0] = c;

		int i = 1, d = 0, g = 0, g1 = 0, g2 = 0, g3 = 0;
		Recurssion(arr, array, a, b, c, A, B, i, d, g, g1, g2, g3);

		cout << "\nПуть коня по координатам на шахматной доске:\n";
		for (int i = 0; i < 36; i++) {
			cout << arr[i] << " ";
		}

		for (int h = 0; h < 36; h++) {
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					if (arr[h] == array[i][j]) {
						array[i][j] = h;
					}

				}
			}

		}
		// Показ массива
		cout << "\nШахматная доска с пронумерованными ходами коня:\n";
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (i > 1) {
					if (j == 1) cout << "|" << "\t";
					else if (j == 0) cout << i - 1 << "\t";
					else if (j > 1)cout << array[i - 2][j - 2] << "\t";
				}
				else if (i == 0) {
					if (j == 0 or j == 1)cout << "\t";
					else cout << j - 1 << "\t";
				}
				else if (i == 1) {
					if (j == 0 or j == 1)cout << "\t";
					else cout << "--" << "\t";
				}


			}cout << endl << endl;
		}

	}
};
class Project9_4 {
public:
	template<class T>
	int Degree(T a, T b, T c) {
		if (b == 0 && a != 0) return 1;
		if (b == 1) return a;
		else return Degree(a *= c, b - 1, c);
	}
	void main()
	{
		int a, b, c;
		cout << "\nЗадание 4: Написать рекурсивную функцию нахождения степени числа.\n\n";

		cout << "Введите число\n";
		cin >> a;
		cout << "Введите степень числа\n";
		cin >> b;
		c = a;
		cout << a << " в степени " << b << " = " << Degree(a, b, c);

	}
};
class Project9_5 {
public:

	template<class T>
	int Recurssion(T N) {
		if (N == 0) return 0;
		else {
			cout << "*";
			return Recurssion(N - 1);
		}
	}
	template<class T>
	int RecurssionExample(T N) {
		if (N == 0) {
			cout << "\nВыход из рекурсии\n";
			return 0;
		}
		else {
			cout << "\nВывод звезды\n";
			cout << "*";
			cout << "\nПодсчет звезд (сколько осталось вывести) - " << N - 1;
			return RecurssionExample(N - 1);
		}
	}
	void main()
	{
		int N;
		cout << "\nЗадание 5: Написать рекурсивную функцию, которая выводит N звезд в ряд, число N задает пользователь.\n";
		cout << "Проиллюстрируйте работу функции примером.\n\n";

		cout << "Введите число звёзд\n";
		cin >> N;
		Recurssion(N);
		cout << "\nЗапуск рекурсивной функции 'пример'\n";
		RecurssionExample(N);
		cout << "Конец программы";
	}
};
class Project9_6 {
public:
	template<class T>
	int Recurssion(T a, T b, T c) {

		if (a == b) return c;
		else {
			cout << c << " + " << a - 1 << " = " << c + a - 1 << endl;
			c += a - 1;
			return Recurssion(a - 1, b, c);
		}
	}

	void main()
	{
		int a, b, c, d, e;
		cout << "\nЗадание 6: Написать рекурсивную функцию, которая вычисляет сумму всех чисел в диапазоне от a до b.\n";
		cout << "Пользователь вводит a и b. Проиллюстрируйте работу функции примером.\n\n";

		cout << "Введите a\n";
		cin >> a;
		cout << "Введите b\n";
		cin >> b;
		c = a > b ? a : b;
		d = a < b ? a : b;
		e = c;
		cout << "Cумма всех чисел в диапазоне от " << a << " до " << b << " = " << Recurssion(c, d, e);

	}
};
class Project9_7 {
public:

	template<class T>
	int Recurssion(T array[100], T arr[100], T a, T b, T min) {

		if (a > 90) {
			if (min == arr[b]) {
				cout << endl << "С позиции N " << b << " в одномерном массиве начинается последовательность из 10 чисел, сумма которых минимальна и равна " << min;
			}
			else if (b > 90) return 0;
			return Recurssion(array, arr, a, b + 1, min);
		}
		else {
			arr[a] = array[a] + array[a + 1] + array[a + 2] + array[a + 3] + array[a + 4] + array[a + 5] + array[a + 6] + array[a + 7] + array[a + 8] + array[a + 9];
			if (min < arr[a]) {
				min = arr[a];
			}
			return Recurssion(array, arr, a + 1, b, min);
		}
	}

	void main()
	{
		srand(unsigned(time(NULL)));
		int a = 0, b = 0, min, sum = 0;
		int array[100];
		int arr[100];
		cout << "\nЗадание 7: Напишите рекурсивную функцию, которая принимает одномерный массив из 100 целых чисел,\n";
		cout << "заполненных случайным образом, и находит позицию, с которой начинается\n";
		cout << "последовательность из 10 чисел, сумма которых минимальна.\n\n";

		cout << "Одномерный массив\n";
		for (int i = 0; i < 100; i++) {
			array[i] = rand() % 100;
			cout << array[i] << " ";
		}cout << endl;
		for (int i = 0; i < 10; i++) {
			sum += array[i];
		}
		min = sum;
		Recurssion(array, arr, a, b, min);

	}
};