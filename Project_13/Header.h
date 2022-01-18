#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
using namespace std;
class Project13_1 {
private:

	class Shot {
	public:
		double a;
		double b;
	};

	Shot Result(Shot x, Shot y) {
		Shot result;
		result.a = x.a / x.b;
		result.b = y.a / y.b;
		return result;
	}
public:
	void main()
	{
		srand(unsigned(time(NULL)));
		cout << "\nЗадача 1: Реализуйте класс Дробь.Необходимо хранить числитель\n";
		cout << "и знаменатель в качестве переменных - членов.Реализуйте\n";
		cout << "функции - члены для ввода данных в переменные - члены,\n";
		cout << "для выполнения арифметических операций(сложение,\n";
		cout << "вычитание, умножение, деление, и т.д.).\n\n";
		char c;
		Shot shot1, shot2;

		for (;;) {

			cout << "Введите действие с дробями '+,-,*,/'\n";
			cin >> c;
			cout << "Введите числитель первой дроби\n";
			cin >> shot1.a;
			cout << "Введите знаменатель первой дроби\n";
			cin >> shot1.b;

			cout << "Введите числитель второй дроби\n";
			cin >> shot2.a;
			cout << "Введите знаменатель второй дроби\n";
			cin >> shot2.b;

			if (c == '+') {
				Shot result = Result(shot1, shot2);
				cout << "Результат сложения: " << "(" << shot1.a << " / " << shot1.b << ")" << " + " << "(" << shot2.a << " / " << shot2.b << ")" << " = " << result.a + result.b << endl;
			}
			else if (c == '-') {
				Shot result = Result(shot1, shot2);
				cout << "Результат разности: " << "(" << shot1.a << " / " << shot1.b << ")" << " - " << "(" << shot2.a << " / " << shot2.b << ")" << " = " << result.a - result.b << endl;
			}
			else if (c == '*') {
				Shot result = Result(shot1, shot2);
				cout << "Результат умножения: " << "(" << shot1.a << " / " << shot1.b << ")" << " * " << "(" << shot2.a << " / " << shot2.b << ")" << " = " << result.a * result.b << endl;
			}
			else if (c == '/') {
				Shot result = Result(shot1, shot2);
				cout << "Результат деления: " << "(" << shot1.a << " / " << shot1.b << ")" << " / " << "(" << shot2.a << " / " << shot2.b << ")" << " = " << result.a / result.b << endl;
			}
		}
	}
};


int m = 7;
int m1 = 5;
int m2 = 30;
char arrayName[15][30] = { "Valik", "Vika", "Ira" , "Katia" , "Vera" };
char arraySurname[15][30] = { "Lola", "Lola", "Lola" , "Lola" , "Lola" };
char arrayPatronymic[15][30] = { "Valerievich", "Valerievna", "Olexandrovna" , "Valentinovna" , "Valentinovna" };
char array_home_phone[15][30] = { "+380509387276", "+380509387277", "+380509387278" , "+380509387279" , "+380509387275" };
char array_work_phone[15][30] = { "+380982667643", "+380982667644", "+380982667645" , "+380982667646" , "+380982667647" };
char array_mobile_phone[15][30] = { "+380662557452", "+380662557453", "+380662557454" , "+380662557455" , "+380662557456" };
char array_additional_information[15][30] = { "Ya", "Sestra", "Plemyashka" , "Doch" , "Mama" };
class Project13_2 {
public:
	
	class PhoneBook {
	public:
		char*** FullInfo = new char** [m];
		char* SearchName = new char[m2];
		char* Name = new char[m2];
		char* Surname = new char[m2];
		char* Patronymic = new char[m2];
		char* home_phone = new char[m2];
		char* work_phone = new char[m2];
		char* mobile_phone = new char[m2];
		char* additional_information = new char[m2];


		void RecordName() {
			FullInfo[0][m1] = Name;
			FullInfo[1][m1] = Surname;
			FullInfo[2][m1] = Patronymic;
			FullInfo[3][m1] = home_phone;
			FullInfo[4][m1] = work_phone;
			FullInfo[5][m1] = mobile_phone;
			FullInfo[6][m1] = additional_information;
			m1 += 1;
		}

		void AddName() {
			Name = new char[m2];
			cout << "Введите имя абонента\n";
			cin >> Name;
			Surname = new char[m2];
			cout << "Введите фамилию абонента\n";
			cin >> Surname;
			Patronymic = new char[m2];
			cout << "Введите отчество абонента\n";
			cin >> Patronymic;
			home_phone = new char[m2];
			cout << "Введите домашний телефон абонента\n";
			cin >> home_phone;
			work_phone = new char[m2];
			cout << "Введите рабочий телефон абонента\n";
			cin >> work_phone;
			mobile_phone = new char[m2];
			cout << "Введите мобильный телефон абонента\n";
			cin >> mobile_phone;
			additional_information = new char[m2];
			cout << "Введите доп.информацию абонента\n";
			cin >> additional_information;
			RecordName();
		}

		void Record() {
			for (int h = 0; h < m; h++) {
				FullInfo[h] = new char* [m1];
				for (int a = 0; a < m1; a++) {
					FullInfo[h][a] = new char[m2];
					for (int i = 0; i < m2; i++) {
						if (h == 0) FullInfo[h][a][i] = arrayName[a][i];
						else if (h == 1) FullInfo[h][a][i] = arraySurname[a][i];
						else if (h == 2) FullInfo[h][a][i] = arrayPatronymic[a][i];
						else if (h == 3) FullInfo[h][a][i] = array_home_phone[a][i];
						else if (h == 4) FullInfo[h][a][i] = array_work_phone[a][i];
						else if (h == 5) FullInfo[h][a][i] = array_mobile_phone[a][i];
						else if (h == 6) FullInfo[h][a][i] = array_additional_information[a][i];
					}
				}
			}
		}

		void Search(int a) {
			for (int i = 0; i < 7; i++) {
				cout << FullInfo[i][a];
				cout << "\t";
			}cout << endl;
		}

		void Delete(int del) {
			int a = m1 - del;

			for (int j = 0; j < a; j++) {
				for (int i = 0; i < m; i++) {
					FullInfo[i][del] = FullInfo[i][del + 1];
				}
				del += 1;
			}

			m1 -= 1;
		}

		void Search_Name(int a) {
			SearchName = new char[m2];
			cout << "Введите имя, фамилию или отчество абонента\n";
			cin >> SearchName;
			int count = strlen(SearchName);
			for (int i = 0; i < m1; i++) {
				int h = 0;
				for (int j = 0; j < count; j++) {
					if (SearchName[j] == FullInfo[0][i][j] or SearchName[j] == FullInfo[1][i][j] or SearchName[j] == FullInfo[2][i][j]) {
						h++;
						if (h == count) {
							if (a == 2)Search(i);
							if (a == 4)Delete(i);
						}
					}
				}
			}
		}

	}x;

	void main()
	{
		srand(unsigned(time(NULL)));
		int a;
		cout << "\nЗадача 2: Создайте приложение «Телефонная книга».Необходимо\n";
		cout << "хранить данные об абоненте(ФИО, домашний телефон,\n";
		cout << "рабочий телефон, мобильный телефон, дополнительная\n";
		cout << "информация о контакте) внутри соответствующего класса.\n";
		cout << "Наполните класс переменными - членами, функциямичленами, конструкторами, inline - функциями - членами,\n";
		cout << "используйте инициализаторы, реализуйте деструктор.\n";
		cout << "Обязательно необходимо выделять динамически память под\n";
		cout << "ФИО.Предоставьте пользователю возможность добавлять\n";
		cout << "новых абонентов, удалять абонентов, искать абонентов\n";
		cout << "по ФИО, показывать всех абонентов.\n\n";
		PhoneBook phonebook;
		phonebook.Record();

		for (;;) {
			cout << "\n Выберите действие:\n";
			cout << " 1 - Показать всех абонентов\n";
			cout << " 2 - Поиск абонента\n";
			cout << " 3 - Добавить абонента\n";
			cout << " 4 - Удалить абонента\n";
			cin >> a;
			if (a == 1) {
				cout << "Имя\t" << "Фамилия\t" << "Отчество\t" << "домашний\t" << "рабочий\t\t" << "мобильный\t" << "дополнительная инфо\n\n";
				for (int i = 0; i < m1; i++) {
					phonebook.Search(i);
				}
			}
			else if (a == 2) {
				phonebook.Search_Name(a);
			}
			else if (a == 3) {
				phonebook.AddName();
			}
			else if (a == 4) {
				cout << "Кого вы хотите удалить?\n";
				phonebook.Search_Name(a);
			}
		}
	}
};