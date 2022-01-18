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
		cout << "\n���������� �� �������� ������:";
		cout << "\n�������� ������\t\t\t��� �������\t\t����� ���������\t\t����\n";
		for (int i = 0; i < int(name.size()); i++)
		{
			SearchName(name[i]);
			cout << endl;
		}
	}
	void PrintSortYear() {
		cout << "\n���������� �� ���� ������� ������:";
		cout << "\n�������� ������\t\t\t��� �������\t\t����� ���������\t\t����\n";
		auto it = year.begin();
		while (it != year.end()) {
			SearchName(it->second);
			++it;
			cout << endl;
		}
	}
	void PrintSortVolume() {
		cout << "\n���������� �� ������ ��������� ������:";
		cout << "\n�������� ������\t\t\t��� �������\t\t����� ���������\t\t����\n";
		auto it = volume.begin();
		while (it != volume.end()) {
			SearchName(it->second);
			++it;
			cout << endl;
		}
	}
	void PrintSortPrice() {
		cout << "\n���������� �� ���� ������:";
		cout << "\n�������� ������\t\t\t��� �������\t\t����� ���������\t\t����\n";
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
				if (NAME == name[i])throw("����� �������� ������ ��� � ������!\n");
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
		cout << "����� �� �������� ������ - 1, ����� �� ��������������� ��� ���� - 2\n";
		cin >> a;
		if (a == 1) {
			cout << "������� �������� ������\n";
			cin >> searchName;
			SearchName(searchName);
		}
		if (a == 2) {
			cout << "������� ��� �������, ����� ��������� ��� ���� ������\n";
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
		cout << "\n������� �������� ������ ������� ������ ������� �� ������\n";
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
		cout << "������� 1. �������� ���������� ��� ������ ����������.����������\n";
		cout << "������� ���������� � ����������� �����������(��������, ��� �������, ����� ���������, ����).����������\n";
		cout << "��������� ��� ���������� ������, �������� ������,\n";
		cout << "����������� ������, ���������� ������ �� ���������\n";
		cout << "����������, ������ ������ �� ��������� ����������.\n";
		cout << "��� ���������� ����������� ����������, �������� � ���������.\n";
		int a = 0;
		Functor functor;
		functor(2014, 3, 29900, "BMW_X5_2014");
		functor(2016, 1.5, 12500, "Dacia_Duster");
		functor(2017, 2, 9500, "Ford_Focus");
		functor(2013, 2.9, 21000, "Audi_Q7_2013");
		functor(2008, 1.6, 5800, "Opel_Astra");
		for (;;) {
			cout << "\n1 - ������� ������ ����� �� �����\n";
			cout << "2 - ���������� ����� �� ���� �������\n";
			cout << "3 - ���������� ����� �� ������ ���������\n";
			cout << "4 - ���������� ����� �� ����\n";
			cout << "5 - ����� ������ �� �������� ��� ������\n";
			cout << "6 - �������� ������ �� ������\n";
			cout << "7 - ���������� ������ � ������\n";
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
				cout << "\n������� �������� ������\n";
				cin >> name;
				cout << "\n������� ��� ������\n";
				cin >> year;
				cout << "\n������� ����� ��������� ������\n";
				cin >> volume;
				cout << "\n������� ���� ������\n";
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
		cout << "������� 2. � ���������� ���� vector �������� ����� ����� �����.\n";
		cout << "�������� �������� ��� ������� ��������� ����� : \n";
		cout << "1. ����� ������������ ��������; \n";
		cout << "2. ����� ������������� ��������; \n";
		cout << "3. ���������� ������ �� ��������; \n";
		cout << "4. ���������� ������ �� �����������; \n";
		cout << "5. ���������� �������� � ���������� �� �������� ���������; \n";
		cout << "6. ���������� �������� � ���������� �� �������� ���������; \n";
		cout << "7. �������� ��������� �� ���������� ������ �������� ��������.\n";

		Functor_Project24_2 functor;
		vector<int> data{ 1,3,5,7,9,2,4,6,8,10 };
		cout << "\n������:\n";
		functor.Print(data);
		cout << "\n����������� ������� � �������:\n";
		functor(data, 1);
		cout << "\n������������ ������� � �������:\n";
		functor(data, 2);
		cout << "\n���������� �� �����������:\n";
		functor(data, 3);
		cout << "\n���������� �� ��������:\n";
		functor(data, 4);
		cout << "\n���������� �������� � ������� �� �������� ���������:\n";
		functor(data, 5);
		cout << "\n���������� �������� � ������� �� �������� ���������:\n";
		functor(data, 6);
		cout << "\n�������� ��������� �� ���������� ������� �������� ��������:\n";
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
		cout << "\n���������� �� �������� ������:";
		cout << "\n�������� ������\t\t\t��� �������\t\t����� ���������\t\t����\n";

		for (int i = 0; i < int(name.size()); i++)
		{
			SearchName(name[i]);
			cout << endl;
		}
	}
	void PrintSortYear() {
		cout << "\n���������� �� ���� ������� ������:";
		cout << "\n�������� ������\t\t\t��� �������\t\t����� ���������\t\t����\n";
		auto it = year.begin();
		while (it != year.end()) {
			SearchName(it->second);
			++it;
			cout << endl;
		}
	}
	void PrintSortVolume() {
		cout << "\n���������� �� ������ ��������� ������:";
		cout << "\n�������� ������\t\t\t��� �������\t\t����� ���������\t\t����\n";
		auto it = volume.begin();
		while (it != volume.end()) {
			SearchName(it->second);
			++it;
			cout << endl;
		}
	}
	void PrintSortPrice() {
		cout << "\n���������� �� ���� ������:";
		cout << "\n�������� ������\t\t\t��� �������\t\t����� ���������\t\t����\n";
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
				if (NAME == name[i])throw("����� �������� ������ ��� � ������!\n");
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
		cout << "����� �� �������� ������ - 1, ����� �� ��������������� ��� ���� - 2\n";
		cin >> a;
		if (a == 1) {
			cout << "������� �������� ������\n";
			cin >> searchName;
			SearchName(searchName);
		}
		if (a == 2) {
			cout << "������� �������������� ��� ���� ������\n";
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
		cout << "\n������� �������� ������ ������� ������ ������� �� ������\n";
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
		cout << "������� 3. �������� �������� �� ������� ������� � ���������\n";
		cout << "������ - ���������.��������� ������ ����������� ������� �� ������ ����������� � ������ ����������.\n";
		cout << "������� 1. �������� ���������� ��� ������ ����������.����������\n";
		cout << "������� ���������� � ����������� �����������(��������, ��� �������, ����� ���������, ����).����������\n";
		cout << "��������� ��� ���������� ������, �������� ������,\n";
		cout << "����������� ������, ���������� ������ �� ���������\n";
		cout << "����������, ������ ������ �� ��������� ����������.\n";
		cout << "��� ���������� ����������� ����������, �������� � ���������.\n";
		int a = 0;
		Functor_Project24_3<double, string> functor;
		functor(2014, 3, 29900, "BMW_X5_2014");
		functor(2016, 1.5, 12500, "Dacia_Duster");
		functor(2017, 2, 9500, "Ford_Focus");
		functor(2013, 3, 21000, "Audi_Q7_2013");
		functor(2008, 1.6, 5800, "Opel_Astra");
		for (;;) {
			cout << "\n1 - ������� ������ ����� �� �����\n";
			cout << "2 - ���������� ����� �� ���� �������\n";
			cout << "3 - ���������� ����� �� ������ ���������\n";
			cout << "4 - ���������� ����� �� ����\n";
			cout << "5 - ����� ������ �� �������� ��� ������\n";
			cout << "6 - �������� ������ �� ������\n";
			cout << "7 - ���������� ������ � ������\n";
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
				cout << "\n������� �������� ������\n";
				cin >> name;
				cout << "\n������� ��� ������\n";
				cin >> year;
				cout << "\n������� ����� ��������� ������\n";
				cin >> volume;
				cout << "\n������� ���� ������\n";
				cin >> price;
				functor(year, volume, price, name);
				break;
			}
		}
	}
};