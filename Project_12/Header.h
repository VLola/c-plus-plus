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
		cout << "\nЗадача 1: Создайте структуру, описывающую комплексное число.Реализуйте арифметические операции\n";
		cout << "с комплексными числами : сумму, разность, умножение, деление.\n\n";
		char c;
		Complex complex1, complex2;

		for (;;) {

			cout << "Введите действие с комплексными числами '+,-,*,/'\n";
			cin >> c;
			cout << "Введите первое значение первого коплексного числа\n";
			cin >> complex1.a;
			cout << "Введите второе значение первого коплексного числа\n";
			cin >> complex1.b;

			cout << "Введите первое значение второго коплексного числа\n";
			cin >> complex2.a;
			cout << "Введите второе значение второго коплексного числа\n";
			cin >> complex2.b;
			switch (c) {
			case '+':
				Complex suma = Summa(complex1, complex2);
				cout << "Результат сложения: " << suma.a << " + " << suma.b << "i" << endl;
				break;
			case '-':
				Complex sub = Subtraction(complex1, complex2);
				cout << "Результат разности: " << sub.a << " + " << sub.b << "i" << endl;
				break;
			case '*':
				Complex mult = Multiplication(complex1, complex2);
				cout << "Результат умножения: " << mult.a << " + " << mult.b << "i" << endl;
				break;
			case '/':
				Complex div = Division(complex1, complex2);
				cout << "Результат деления: " << div.a << " + " << div.b << "i" << endl;
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
		cout << "Введите длину автомобиля\n";
		cin >> x.length;
		cout << "Введите высоту посадки автомобиля\n";
		cin >> x.height;
		cout << "Введите обьем двигателя автомобиля\n";
		cin >> x.volume;
		cout << "Введите мощность двигателя автомобиля\n";
		cin >> x.power;
		cout << "Введите диаметр колес автомобиля\n";
		cin >> x.diameter;
		cout << "Введите цвет автомобиля\n";
		cin >> x.color;
		cout << "Введите тип коробки передач автомобиля\n";
		cin >> x.type;
	}

	void Search() {
		int a;
		cout << "\nВыберите какое значение хотите найти:\n";
		cout << "1 - длина автомобиля,2 - высота посадки автомобиля,3 - обьем двигателя автомобиля, \n";
		cout << "4 - мощность двигателя автомобиля,5 -  диаметр колес автомобиля,6 -  цвет автомобиля, \n";
		cout << "7 - тип коробки передач автомобиля. \n";
		cin >> a;
		switch (a) {
		case 1:
			cout << x.length << " - длина автомобиля\n";
			break;
		case 2:
			cout << x.height << " - высота посадки автомобиля\n";
			break;
		case 3:
			cout << x.volume << " - обьем двигателя автомобиля\n";
			break;
		case 4:
			cout << x.power << " - мощность двигателя автомобиля\n";
			break;
		case 5:
			cout << x.diameter << " - диаметр колес автомобиля\n";
			break;
		case 6:
			cout << x.color << " - цвет автомобиля\n";
			break;
		case 7:
			cout << x.type << " - тип коробки передач автомобиля\n";
			break;
		default:
			break;
		}
	}

	void Display() {
		cout << endl;
		cout << x.length << " - длина автомобиля\n";
		cout << x.height << " - высота посадки автомобиля\n";
		cout << x.volume << " - обьем двигателя автомобиля\n";
		cout << x.power << " - мощность двигателя автомобиля\n";
		cout << x.diameter << " - диаметр колес автомобиля\n";
		cout << x.color << " - цвет автомобиля\n";
		cout << x.type << " - тип коробки передач автомобиля\n";
	}
public:
	void main()
	{
		srand(unsigned(time(NULL)));
		cout << "\nЗадача 2: Реализовать структуру «Автомобиль»(длина, клиренс(высота посадки), объем двигателя,\n";
		cout << "мощность двигателя, диаметр колес, цвет, тип коробки передач).Создайте функции для задания\n";
		cout << "значений, отображения значений, поиска значений.\n\n";

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
		char arrayName[10][40] = { "Вечность_в_тебе", "Чат_с_мертвецами", "Хроники_простого_волшебства", "Чудотворцы", "Обмануть_вселенную", "Ветер_и_вечность", "Блуждающая_Земля", "Клан_потомков_Дракона", "Академия_пяти_дорог", "Академия_наездников" };
		char arrayAuthor[10][40] = { "Аннэ_Фрейтаг", "Анна_Велес",  "Надежда_Мамаева",  "Саймон_Рич",  "Макс_Максимов",  "Вера_Камша",  "Лю_Цысинь",  "Алексей_Федотов",  "Лара_Ингвар",  "Зоя_Анишкина" };
		char arrayPublishing[10][40] = { "Эксмо", "Эксмо",  "Надежда_Мамаева",  "АСТ",  "Эксмо",  "Эксмо",  "Эксмо",  "АСТ",  "АСТ",  "Самиздат" };
		char arrayGenre[10][40] = { "Роман", "Детектив",  "Фэнтези",  "Научная_фантастика",  "Научная_фантастика",  "Научная_фантастика",  "Научная_фантастика",  "Научная_фантастика",  "Фэнтези",  "Фэнтези" };

	}x;

	void Add(int a) {

		for (int h = 0; h < m1; h++) {
			if (h == 0)cout << "Введите новое название книги\n";
			else if (h == 1)cout << "Введите нового автора книги\n";
			else if (h == 2)cout << "Введите новое издательство книги\n";
			else if (h == 3)cout << "Введите новый жанр книги\n";
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
	// Функция показа 
	void Array(int b) {
		int count, l;
		if (b == 0) cout << "Книга\t\t\t\tАвтор\t\t\t\tИздательство\t\t\tЖанр\n\n";
		else if (b == 1) cout << "Автор\t\t\t\tИздательство\t\t\tЖанр\t\t\t\tКнига\n\n";
		else if (b == 2) cout << "Издательство\t\t\tЖанр\t\t\t\tКнига\t\t\t\tАвтор\n\n";
		else if (b == 3) cout << "Жанр\t\t\t\tКнига\t\t\t\tАвтор\t\t\t\tИздательство\n\n";

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
		cout << "\nЗадача 3: Разработайте программу «Библиотека».Создайте структуру «Книга»(название, автор,\n";
		cout << "издательство, жанр).Создайте массив из 10 книг.Реализуйте для него следующие возможности :\n";
		cout << "Редактировать книгу\n";
		cout << "Печать всех книг\n";
		cout << "Поиск книг по автору\n";
		cout << "Поиск книги по названию\n";
		cout << "Сортировка массива по названию книг\n";
		cout << "Сортировка массива по автору\n";
		cout << "Сортировка массива по издательству\n\n";
		// Создание двумерного массива
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
			cout << " 1 - Поиск по названию,автору,издательству,или жанру книги.\n 2 - Редактировать книгу\n 3 - Печать всех книг\n";
			cout << " 4 - Сортировка библиотеки. 5 - Выход из программы\n \n";
			cin >> a;
			if (a == 1) {
				cout << "Введите слово:\n";
				Search(a);
			}
			else if (a == 2) {
				cout << "Введите название книги:\n";
				Search(a);
			}
			else if (a == 3) Array(x.sorting);
			else if (a == 4) {
				cout << "Введите как хотите сортировать список:\n";
				cout << " 0 - Сортировка по названию книг\n";
				cout << " 1 - Сортировка по автору\n";
				cout << " 2 - Сортировка по издательству\n";
				cout << " 3 - Сортировка по жанру\n\n";
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

	struct Avто
	{
		char arrayColor[10][10] = { "Синий","Красный","Белый","Зеленый","Черный", "Желтый","Голубой","Розовый", "Серый","Золотой", };
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
		cout << "Введите цвет новой машины\n";
		x.color = new char[m2];
		cin >> x.color;
		cout << "Введите модель новой машины\n";
		x.model = new char[m2];
		cin >> x.model;
		for (;;) {
			int h = 0;
			cout << "Выберите какой будет номер новой машины\n";
			cout << " 1 - пятизначный номер\n";
			cout << " 2 - слово до 8 символов\n";
			cin >> check;
			cout << "Введите номер новой машины\n";
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
				else  cout << "Ошибка!\n";
			}
			if (h == 5) break;
			else cout << "Ошибка! Неправильное количество цыфр!\n";
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
		cout << "Введите номер машины которую хотите найти\n";
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
	// Функция показа 
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
		cout << "\nЗадача 4: Реализовать структуру «Машина»(цвет, модель, номер).Номер машины может представлять из\n";
		cout << "себя или пятизначный номер или слово до 8 символов.\n";
		cout << "Рекомендации: номер реализовать как объединение.\n";
		cout << "Создать экземпляр структуры «Машина» и реализовать для него следующие функции :\n";
		cout << "Заполнение машины\n";
		cout << "Печать машины\n";
		cout << "Создать массив из 10 экземпляров структуры «Машина» и реализовать для него следующие функции :\n";
		cout << "Редактировать машину\n";
		cout << "Печать всех машин\n";
		cout << "Поиск машины по номеру\n\n";
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
			cout << " 1 - Заполнение машины.\n 2 - Печать машины.\n 3 - Редактировать машину\n";
			cout << " 4 - Печать всех машин.\n 5 - Поиск машины по номеру.\n 6 - Выход из программы\n \n";
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