#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>	// std::min_element
#include <iterator>		// std::begin, std::end
using namespace std;
class Functor {
public:
	vector<string>name;
	map<double, string>year;
	map<double, string>volume;
	map<double, string>price;
	void Sort() {
		sort(name.begin(), name.end());
	}
	void PrintSortName() {
		cout << "\nСортировка по названию машины:";
		cout << "\nНазвание машины\t\t\tГод выпуска\t\tОбьем двигателя\t\tЦена\n";
		for (int i = 0; i < int(name.size()); i++)
		{
			SearchName(name[i]);
			cout << endl;
		}
	}
	void PrintSortYear() {
		cout << "\nСортировка по году выпуска машины:";
		cout << "\nНазвание машины\t\t\tГод выпуска\t\tОбьем двигателя\t\tЦена\n";
		auto it = year.begin();
		while (it != year.end()) {
			SearchName(it->second);
			++it;
			cout << endl;
		}
	}
	void PrintSortVolume() {
		cout << "\nСортировка по обьему двигателя машины:";
		cout << "\nНазвание машины\t\t\tГод выпуска\t\tОбьем двигателя\t\tЦена\n";
		auto it = volume.begin();
		while (it != volume.end()) {
			SearchName(it->second);
			++it;
			cout << endl;
		}
	}
	void PrintSortPrice() {
		cout << "\nСортировка по цене машины:";
		cout << "\nНазвание машины\t\t\tГод выпуска\t\tОбьем двигателя\t\tЦена\n";
		auto it = price.begin();
		while (it != price.end()) {
			SearchName(it->second);
			++it;
			cout << endl;
		}
	}
	void operator()(double YEAR, double VOLUME, double PRICE, string NAME) {
		try {
			for (int i = 0; i < int(name.size()); i++) {
				if (NAME == name[i])throw("Такое название машины уже в списке!\n");
			}

			name.push_back(NAME);
			year.insert(pair<double, string>(YEAR, NAME));
			volume.insert(pair<double, string>(VOLUME, NAME));
			price.insert(pair<double, string>(PRICE, NAME));
			Sort();
		}
		catch (const char* exeption) {
			cout << exeption;
		}
	}
	void SearchName(string Name) {
		int i = 0;
		for (; i < int(name.size()); i++)
		{
			if (Name == name[i]) {
				auto it = year.begin(); auto it1 = volume.begin(); auto it2 = price.begin();
				while (it != year.end()) {
					if (it->second == name[i]) {
						cout << name[i] << "\t\t\t" << it->first << "\t\t\t";
					}
					++it;
				}
				while (it1 != volume.end()) {
					if (it1->second == name[i]) {
						cout << it1->first << "\t\t\t";
					}
					++it1;
				}
				while (it2 != price.end()) {
					if (it2->second == name[i]) {
						cout << it2->first << "\t\t\t";
					}
					++it2;
				}
			}

		}
	}
	void Search() {
		string searchName;
		double searchData;
		int a;
		cout << "Поиск по названию машины - 1, Поиск по характеристикам или цене - 2\n";
		cin >> a;
		if (a == 1) {
			cout << "Введите название машины\n";
			cin >> searchName;
			SearchName(searchName);
		}
		if (a == 2) {
			cout << "Введите год выпуска, обьем двигателя или цену машины\n";
			cin >> searchData;
			auto it = year.begin(); auto it1 = volume.begin(); auto it2 = price.begin();
			while (it != year.end()) {
				if (it->first == searchData) {
					SearchName(it->second);
				}
				++it;
			}
			while (it1 != volume.end()) {
				if (it1->first == searchData) {
					SearchName(it1->second);
				}
				++it1;
			}
			while (it2 != price.end()) {
				if (it2->first == searchData) {
					SearchName(it2->second);
				}
				++it2;
			}
		}
	}
	void Delete() {
		string searchName;
		cout << "\nВведите название машины которую хотите удалить со списка\n";
		cin >> searchName;
		for (int i = 0; i < int(name.size()); i++) {
			if (searchName == name[i])name.erase(name.begin() + i);;
		}
		auto it = year.begin(); auto it1 = volume.begin(); auto it2 = price.begin();
		while (it != year.end()) {
			if (it->second == searchName)
			{
				it = year.erase(it);
			}
			else
			{
				++it;
			}
		}
		while (it1 != volume.end()) {
			if (it1->second == searchName)
			{
				it1 = volume.erase(it1);
			}
			else
			{
				++it1;
			}
		}
		while (it2 != price.end()) {
			if (it2->second == searchName)
			{
				it2 = price.erase(it2);
			}
			else
			{
				++it2;
			}
		}
	}

};
class Project24_1{
public:
	void main() {
		cout << "Задание 1. Создайте приложение для работы автосалона.Необходимо\n";
		cout << "хранить информацию о продаваемых автомобилях(название, год выпуска, объем двигателя, цену).Реализуйте\n";
		cout << "интерфейс для добавления данных, удаления данных,\n";
		cout << "отображения данных, сортировке данных по различным\n";
		cout << "параметрам, поиску данных по различным параметрам.\n";
		cout << "При реализации используйте контейнеры, функторы и алгоритмы.\n";
		int a = 0;
		Functor functor;
		functor(2014, 3, 29900, "BMW_X5_2014");
		functor(2016, 1.5, 12500, "Dacia_Duster");
		functor(2017, 2, 9500, "Ford_Focus");
		functor(2013, 2.9, 21000, "Audi_Q7_2013");
		functor(2008, 1.6, 5800, "Opel_Astra");
		for (;;) {
			cout << "\n1 - Вывести список машин на экран\n";
			cout << "2 - Сортировка машин по году выпуска\n";
			cout << "3 - Сортировка машин по обьему двигателя\n";
			cout << "4 - Сортировка машин по цене\n";
			cout << "5 - Поиск машины по названию или данным\n";
			cout << "6 - Удаление машины со списка\n";
			cout << "7 - Добавление машины в список\n";
			cin >> a;
			switch (a) {
			case 1:
				functor.PrintSortName();
				break;
			case 2:
				functor.PrintSortYear();
				break;
			case 3:
				functor.PrintSortVolume();
				break;
			case 4:
				functor.PrintSortPrice();
				break;
			case 5:
				functor.Search();
				break;
			case 6:
				functor.Delete();
				break;
			case 7:
				string name;
				double year;
				double volume;
				double price;
				cout << "\nВведите название машины\n";
				cin >> name;
				cout << "\nВведите год машины\n";
				cin >> year;
				cout << "\nВведите обьем двигателя машины\n";
				cin >> volume;
				cout << "\nВведите цену машины\n";
				cin >> price;
				functor(year, volume, price, name);
				break;
			}

		}
	}
};
class Functor_Project24_2 {
public:
	void Print(vector<int> data) {
		for (int i = 0; i < data.size(); i++)
		{
			cout << data[i] << '\t';
		}cout << endl;
	}
	void operator()(vector<int> data, int number) {
		const int boost = 5;
		switch (number) {
		case 1:
			cout << *min_element(data.begin(), data.end()) << endl;
			break;
		case 2:
			cout << *max_element(data.begin(), data.end()) << endl;
			break;
		case 3:
			sort(data.begin(), data.end());
			Print(data);
			break;
		case 4:
			sort(data.begin(), data.end(), [](int a, int b) { return a > b; });
			Print(data);
			break;
		case 5:
			for (int i = 0; i < data.size(); i++)
			{
				data[i] += boost;
			}
			Print(data);
			break;
		case 6:
			for (int i = 0; i < data.size(); i++)
			{
				data[i] -= boost;
			}
			Print(data);
			break;
		case 7:
			int c = 5;
			auto it = find(data.begin(), data.end(), c);
			if (it != data.end())
				data.erase(it);
			Print(data);
			break;
		}
	}
};
class Project24_2 {
public:
	void main() {
		cout << "Задание 2. В контейнере типа vector хранится набор целых чисел.\n";
		cout << "Создайте функторы для решения следующих задач : \n";
		cout << "1. Поиск минимального значения; \n";
		cout << "2. Поиск максимального значения; \n";
		cout << "3. Сортировка данных по убыванию; \n";
		cout << "4. Сортировка данных по возрастанию; \n";
		cout << "5. Увеличение значений в контейнере на заданную константу; \n";
		cout << "6. Уменьшение значений в контейнере на заданную константу; \n";
		cout << "7. Удаление элементов из контейнера равных искомому значению.\n";

		Functor_Project24_2 functor;
		vector<int> data{ 1,3,5,7,9,2,4,6,8,10 };
		cout << "\nВектор:\n";
		functor.Print(data);
		cout << "\nМинимальный элемент в векторе:\n";
		functor(data, 1);
		cout << "\nМаксимальный элемент в векторе:\n";
		functor(data, 2);
		cout << "\nСортировка по возрастанию:\n";
		functor(data, 3);
		cout << "\nСортировка по убыванию:\n";
		functor(data, 4);
		cout << "\nУвеличение значений в векторе на заданную константу:\n";
		functor(data, 5);
		cout << "\nУменьшение значений в векторе на заданную константу:\n";
		functor(data, 6);
		cout << "\nУдаление элементов из контейнера равному искомому значению:\n";
		functor(data, 7);
	}
};
template <typename T1, typename T2 >
class Functor_Project24_3 {
public:
	vector<T2>name;
	multimap<T1, T2>year;
	multimap<T1, T2>volume;
	multimap<T1, T2>price;
	void Sort() {
		sort(name.begin(), name.end());
	}
	void PrintSortName() {
		cout << "\nСортировка по названию машины:";
		cout << "\nНазвание машины\t\t\tГод выпуска\t\tОбьем двигателя\t\tЦена\n";

		for (int i = 0; i < int(name.size()); i++)
		{
			SearchName(name[i]);
			cout << endl;
		}
	}
	void PrintSortYear() {
		cout << "\nСортировка по году выпуска машины:";
		cout << "\nНазвание машины\t\t\tГод выпуска\t\tОбьем двигателя\t\tЦена\n";
		auto it = year.begin();
		while (it != year.end()) {
			SearchName(it->second);
			++it;
			cout << endl;
		}
	}
	void PrintSortVolume() {
		cout << "\nСортировка по обьему двигателя машины:";
		cout << "\nНазвание машины\t\t\tГод выпуска\t\tОбьем двигателя\t\tЦена\n";
		auto it = volume.begin();
		while (it != volume.end()) {
			SearchName(it->second);
			++it;
			cout << endl;
		}
	}
	void PrintSortPrice() {
		cout << "\nСортировка по цене машины:";
		cout << "\nНазвание машины\t\t\tГод выпуска\t\tОбьем двигателя\t\tЦена\n";
		auto it = price.begin();
		while (it != price.end()) {
			SearchName(it->second);
			++it;
			cout << endl;
		}
	}
	void operator()(T1 YEAR, T1 VOLUME, T1 PRICE, T2 NAME) {
		try {
			for (int i = 0; i < int(name.size()); i++) {
				if (NAME == name[i])throw("Такое название машины уже в списке!\n");
			}

			name.push_back(NAME);
			year.insert(pair<T1, T2>(YEAR, NAME));
			volume.insert(pair<T1, T2>(VOLUME, NAME));
			price.insert(pair<T1, T2>(PRICE, NAME));
			Sort();
		}
		catch (const char* exeption) {
			cout << exeption;
		}
	}
	void SearchName(T2 Name) {
		for (int i = 0; i < int(name.size()); i++)
		{
			if (Name == name[i]) {
				auto it = year.begin(); auto it1 = volume.begin(); auto it2 = price.begin();
				while (it != year.end()) {
					if (it->second == name[i]) {
						cout << name[i] << "\t\t\t" << it->first << "\t\t\t";
					}
					++it;
				}
				while (it1 != volume.end()) {
					if (it1->second == name[i]) {
						cout << it1->first << "\t\t\t";
					}
					++it1;
				}
				while (it2 != price.end()) {
					if (it2->second == name[i]) {
						cout << it2->first << "\t\t\t";
					}
					++it2;
				}
			}

		}
	}
	void Search() {
		T2 searchName;
		T1 searchData;
		int a;
		cout << "Поиск по названию машины - 1, Поиск по характеристикам или цене - 2\n";
		cin >> a;
		if (a == 1) {
			cout << "Введите название машины\n";
			cin >> searchName;
			SearchName(searchName);
		}
		if (a == 2) {
			cout << "Введите характеристику или цену машины\n";
			cin >> searchData;
			auto it = year.begin(); auto it1 = volume.begin(); auto it2 = price.begin();
			while (it != year.end()) {
				if (it->first == searchData) {
					SearchName(it->second);
				}
				++it;
			}
			while (it1 != volume.end()) {
				if (it1->first == searchData) {
					SearchName(it1->second);
				}
				++it1;
			}
			while (it2 != price.end()) {
				if (it2->first == searchData) {
					SearchName(it2->second);
				}
				++it2;
			}
		}
	}
	void Delete() {
		T2 searchName;
		cout << "\nВведите название машины которую хотите удалить со списка\n";
		cin >> searchName;
		for (int i = 0; i < int(name.size()); i++) {
			if (searchName == name[i])name.erase(name.begin() + i);;
		}
		auto it = year.begin(); auto it1 = volume.begin(); auto it2 = price.begin();
		while (it != year.end()) {
			if (it->second == searchName)
			{
				it = year.erase(it);
			}
			else
			{
				++it;
			}
		}
		while (it1 != volume.end()) {
			if (it1->second == searchName)
			{
				it1 = volume.erase(it1);
			}
			else
			{
				++it1;
			}
		}
		while (it2 != price.end()) {
			if (it2->second == searchName)
			{
				it2 = price.erase(it2);
			}
			else
			{
				++it2;
			}
		}
	}

};
class Project24_3 {
public:
	void main() {
		cout << "Задание 3. Измените функторы из первого задания в шаблонные\n";
		cout << "классы - функторов.Проверьте работу полученного решения на разных контейнерах с разным содержимым.\n";
		cout << "Задание 1. Создайте приложение для работы автосалона.Необходимо\n";
		cout << "хранить информацию о продаваемых автомобилях(название, год выпуска, объем двигателя, цену).Реализуйте\n";
		cout << "интерфейс для добавления данных, удаления данных,\n";
		cout << "отображения данных, сортировке данных по различным\n";
		cout << "параметрам, поиску данных по различным параметрам.\n";
		cout << "При реализации используйте контейнеры, функторы и алгоритмы.\n";
		int a = 0;
		Functor_Project24_3<double, string> functor;
		functor(2014, 3, 29900, "BMW_X5_2014");
		functor(2016, 1.5, 12500, "Dacia_Duster");
		functor(2017, 2, 9500, "Ford_Focus");
		functor(2013, 3, 21000, "Audi_Q7_2013");
		functor(2008, 1.6, 5800, "Opel_Astra");
		for (;;) {
			cout << "\n1 - Вывести список машин на экран\n";
			cout << "2 - Сортировка машин по году выпуска\n";
			cout << "3 - Сортировка машин по обьему двигателя\n";
			cout << "4 - Сортировка машин по цене\n";
			cout << "5 - Поиск машины по названию или данным\n";
			cout << "6 - Удаление машины со списка\n";
			cout << "7 - Добавление машины в список\n";
			cin >> a;
			switch (a) {
			case 1:
				functor.PrintSortName();
				break;
			case 2:
				functor.PrintSortYear();
				break;
			case 3:
				functor.PrintSortVolume();
				break;
			case 4:
				functor.PrintSortPrice();
				break;
			case 5:
				functor.Search();
				break;
			case 6:
				functor.Delete();
				break;
			case 7:
				string name;
				double year;
				double volume;
				double price;
				cout << "\nВведите название машины\n";
				cin >> name;
				cout << "\nВведите год машины\n";
				cin >> year;
				cout << "\nВведите обьем двигателя машины\n";
				cin >> volume;
				cout << "\nВведите цену машины\n";
				cin >> price;
				functor(year, volume, price, name);
				break;
			}
		}
	}
};