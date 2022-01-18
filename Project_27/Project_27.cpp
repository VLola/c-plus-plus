#include <iostream>		//Поток ввода-вывода 
#include <string>		//Реализует стандартные строковые классы и шаблоны
#include <iomanip>		//Реализует инструменты для работы с форматированием вывода
#include <memory>		//Реализует инструменты управления памятью
#include <fstream>		//Реализует инструменты для файлового ввода и вывода
#include <ctime>		//Реализует инструменты для работы со временем и датой
#include <windows.h>	//Реализует инструменты предоставленные Windows
#include <vector>		//STL Реализует шаблон класса контейнеров динамического массива
#include <array>		//STL Реализует шаблон класса контейнеров статического массива
#include <list>			//STL Реализует шаблон класса контейнера двусвязный список.
#include <map>			//STL Реализует шаблоны классов контейнеров Ассоциативный массив и мультиотображение
#include <algorithm>	//STL алгоритмические операции над контейнерами
//==============================================================================================================//
using namespace std;	//Пространство имен ::std
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
class Day {
public:
	int toYear;
	multimap<int, int> day;
	void StartDay(int a, int b) {
		day.insert(pair<int, int>(a, b));
	}
};

class Mounth :public Day {
public:
	multimap<int, multimap<int, int>> mounth;
	void StartMounth(int a) {
		mounth.insert(pair<int, multimap<int, int>>(a, day));
	}
};

class Year :public Mounth {
public:
	multimap<int, multimap<int, multimap<int, int>>> year;
	void StartYear(int a) {
		year.insert(pair<int, multimap<int, multimap<int, int>>>(a, mounth));
	}
};

class Week :public Year {
public:
	Week() {
		int a = 6;
		cout << "Введите год:\n";
		cin >> toYear;
		cout << "Загрузка таблиц.";
		for (int i = 0; i <= toYear; i++) {
			for (int j = 1; j < 13; j++) {
				for (int h = 1; h <= CheckDay(j, i); h++) {
					StartDay(h, a);
					a = NextWeek(a);
				}
				StartMounth(j);
				day.clear();
			}
			StartYear(i);
			mounth.clear();
			if (i % 100 == 0) {
				cout << ".";
			}
		}cout << endl;
	}
	// Проверка на день недели
	int CheckWeek(int a, int b) {
		auto it = year.find(toYear);
		auto it1 = it->second.find(a);
		auto it2 = it1->second.find(b);
		return it2->second;
	}
	// Следующий день недели
	int NextWeek(int a) {
		if (a == 7)return 1;
		else return a + 1;
	}
	// Проверка месяца на дни
	int CheckDay(int a, int b) {
		int leap_year[12]{ 31,29,31,30,31,30,31,31,30,31,30,31 };
		int not_leap_year[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (CheckYear(b)) return leap_year[a - 1];
		else return not_leap_year[a - 1];
	}
	// Проверка года на высокосность
	bool CheckYear(int a) {
		if (a % 100 == 0) {
			if (a % 400 == 0) return true;
			else return false;
		}
		else {
			if (a % 4 == 0) return true;
			else return false;
		}
	}
};

class Cost :public Week {
public:
	multimap<int, multimap<int, multimap<int, char>>>money_mounth;
	multimap<int, multimap<int, char>>money_day;
	multimap<int, char>money_comment;
	multimap<int, int>mounthTop;
	multimap<int, multimap<int, int>>dayTop;
	multimap<int, multimap<int, int>>weekTop;

	void AddCost() {
		string errorChar = "Не верный коментарий!(введите знак '+' или '-')";
		string errorData = "Такой даты не существует!";
		int a, b, c;
		char d;
		cout << "Введите день\n";
		cin >> b;
		cout << "Введите месяц\n";
		cin >> a;
		cout << "Введите количество денег\n";
		cin >> c;
		cout << "Введите коментарий - символ '+' (прибыль) символ '-' (расходы)\n";
		cin >> d;
		try {
			if (d != '-' && d != '+')throw errorChar;
			if (!isData(toYear, a, b)) throw errorData;
			money_comment.insert(pair<int, char>(c, d));
			money_day.insert(pair<int, multimap<int, char>>(b, money_comment));
			money_mounth.insert(pair<int, multimap<int, multimap<int, char>>>(a, money_day));
			money_comment.clear();
			money_day.clear();
		}
		catch (string exception) {
			SetConsoleTextAttribute(h, 4);
			cout << exception << endl;
			SetConsoleTextAttribute(h, 7);
		}
	}

	void PrintTopMounth(char sign) {
		if (Sumbol(sign)) cout << "Топ 3 сумм месяцев (прибыль):\n";
		else cout << "Топ 3 сумм месяцев (расходы):\n";
		cout << "Сумма\t\t" << "Дата\n";
		// Запись в файл
		string check, text;
		if (Sumbol(sign)) {
			check = "profit.txt";
			text = "Топ 3 сумм месяцев (прибыль):\n";
		}
		else {
			check = "cost.txt";
			text = "Топ 3 сумм месяцев (расходы):\n";
		}
		ofstream file;
		file.open(check, ofstream::app);
		if (!file.is_open()) {
			cout << "Ошибка!\n";
		}
		else {
			file << text;
		}
		file.close();
		for (int i = 1; i < 13; i++) {
			int sumMoney = 0;
			for (auto it : money_mounth) {
				for (auto it1 : it.second) {
					for (auto it2 : it1.second) {
						if (i == it.first && it2.second == sign) {
							sumMoney += it2.first;
						}
					}
				}
			}
			if (sumMoney != 0)
				mounthTop.insert(pair<int, int>(sumMoney, i));
		}
		int a = mounthTop.size();
		for (int i = 0; i < 3; i++, a--) {
			int b = 0;
			for (auto it : mounthTop) {
				b++;
				if (b == a) {
					cout << it.first << "\t\t" << it.second << "." << toYear << endl;
					// Запись в файл
					file.open(check, ofstream::app);
					if (!file.is_open()) {
						cout << "Ошибка!\n";
					}
					else {
						file << it.first << "\t\t" << it.second << "." << toYear << endl;
					}
					file.close();
				}
			}
		}
		mounthTop.clear();
	}
	void PrintTopDay(char sign) {
		if (Sumbol(sign)) cout << "Топ 3 сумм дней (прибыль):\n";
		else cout << "Топ 3 сумм дней (расходы):\n";
		cout << "Сумма\t\t" << "Дата\n";
		// Запись в файл
		string check, text;
		if (Sumbol(sign)) {
			check = "profit.txt";
			text = "Топ 3 сумм месяцев (прибыль):\n";
		}
		else {
			check = "cost.txt";
			text = "Топ 3 сумм месяцев (расходы):\n";
		}
		ofstream file;
		file.open(check, ofstream::app);
		if (!file.is_open()) {
			cout << "Ошибка!\n";
		}
		else {
			file << text;
		}
		file.close();
		for (int i = 1; i < 13; i++) {
			int mounthSize = CheckDay(i, toYear);
			for (int j = 1; j <= mounthSize; j++) {
				int sumMoney = 0;
				for (auto it : money_mounth) {
					for (auto it1 : it.second) {
						for (auto it2 : it1.second) {
							if (i == it.first && j == it1.first && it2.second == sign) {
								sumMoney += it2.first;
							}
						}
					}
				}
				if (sumMoney != 0) {
					mounthTop.insert(pair<int, int>(j, i));
					dayTop.insert(pair<int, multimap<int, int>>(sumMoney, mounthTop));
					mounthTop.clear();
				}
			}
		}
		int a = dayTop.size();
		for (int i = 0; i < 3; i++, a--) {
			int b = 0;
			for (auto it : dayTop) {
				for (auto it1 : it.second) {
					b++;
					if (b == a) {
						cout << it.first << "\t\t" << it1.first << "." << it1.second << "." << toYear << endl;
						// Запись в файл
						file.open(check, ofstream::app);
						if (!file.is_open()) {
							cout << "Ошибка!\n";
						}
						else {
							file << it.first << "\t\t" << it1.first << "." << it1.second << "." << toYear << endl;
						}
						file.close();
					}
				}
			}
		}
		dayTop.clear();
	}

	void PrintTopWeek(char sign) {
		if (Sumbol(sign)) cout << "Топ 3 сумм недель (прибыль):\n";
		else cout << "Топ 3 сумм недель (расходы):\n";
		cout << "Сумма\t\t" << "Дата(Последнего дня недели)\n";
		// Запись в файл
		string check, text;
		if (Sumbol(sign)) {
			check = "profit.txt";
			text = "Топ 3 сумм месяцев (прибыль):\n";
		}
		else {
			check = "cost.txt";
			text = "Топ 3 сумм месяцев (расходы):\n";
		}
		ofstream file;
		file.open(check, ofstream::app);
		if (!file.is_open()) {
			cout << "Ошибка!\n";
		}
		else {
			file << text;
		}
		file.close();
		for (int i = 1; i < 13; i++) {
			int sumMoney = 0;
			int mounthSize = CheckDay(i, toYear);
			for (int j = 1; j <= mounthSize; j++) {
				for (auto it : money_mounth) {
					for (auto it1 : it.second) {
						for (auto it2 : it1.second) {
							if (i == it.first && j == it1.first && it2.second == sign) {
								sumMoney += it2.first;
							}
						}
					}

				}
				if (sumMoney != 0 && CheckWeek(i, j) == 7 or sumMoney != 0 && CheckDay(i, toYear) == j) {
					mounthTop.insert(pair<int, int>(j, i));
					weekTop.insert(pair<int, multimap<int, int>>(sumMoney, mounthTop));
					mounthTop.clear();
					sumMoney = 0;
				}
			}
		}
		int a = weekTop.size();
		for (int i = 0; i < 3; i++, a--) {
			int b = 0;
			for (auto it : weekTop) {
				for (auto it1 : it.second) {
					b++;
					if (b == a) {
						cout << it.first << "\t\t" << it1.first << "." << it1.second << "." << toYear << endl;
						// Запись в файл
						file.open(check, ofstream::app);
						if (!file.is_open()) {
							cout << "Ошибка!\n";
						}
						else {
							file << it.first << "\t\t" << it1.first << "." << it1.second << "." << toYear << endl;
						}
						file.close();
					}
				}
			}
		}
		weekTop.clear();
	}

	bool isData(int YEAR, int MOUNTH, int DAY) {
		for (auto it : year) {
			if (YEAR == it.first) {
				for (auto it1 : it.second) {
					if (MOUNTH == it1.first) {
						for (auto it2 : it1.second) {
							if (DAY == it2.first) return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool Sumbol(char a) {
		if (a == '+')return true;
		else return false;
	}
	void ClearFile(int a) {
		string path;
		if (a == 2) path = "cost.txt";
		else if (a == 3)path = "profit.txt";
		ofstream file;
		file.open(path, ofstream::trunc);
		if (!file.is_open()) {
			cout << "Ошибка!\n";
		}
		file.close();
	}
};

int main() {
	setlocale(LC_ALL, "");
	int a;
	char cost = '-';
	char profit = '+';
	Cost c;
	for (;;) {
		cout << "1 - Записать сумму\n" << "2 - Вывести топ сумм по расходам\n" << "3 - Вывести топ сумм по прибыли\n";
		cin >> a;
		if (a == 1) {
			c.AddCost();
		}
		else if (a == 2) {
			c.ClearFile(a);
			SetConsoleTextAttribute(h, 2);
			c.PrintTopDay(cost);
			SetConsoleTextAttribute(h, 7);
			SetConsoleTextAttribute(h, 3);
			c.PrintTopWeek(cost);
			SetConsoleTextAttribute(h, 7);
			SetConsoleTextAttribute(h, 4);
			c.PrintTopMounth(cost);
			SetConsoleTextAttribute(h, 7);
		}
		else if (a == 3) {
			c.ClearFile(a);
			SetConsoleTextAttribute(h, 2);
			c.PrintTopDay(profit);
			SetConsoleTextAttribute(h, 7);
			SetConsoleTextAttribute(h, 3);
			c.PrintTopWeek(profit);
			SetConsoleTextAttribute(h, 7);
			SetConsoleTextAttribute(h, 4);
			c.PrintTopMounth(profit);
			SetConsoleTextAttribute(h, 7);
		}
	}
}