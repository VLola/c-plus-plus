#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;
class Firma {
	public:
	string name;
	string director;
	string telephone;
	string adress;
	string occupation;
	Firma();
	~Firma();
	void Write(string, string, string, string, string);
	void Write();
	void Print();
	void Search();
}x;
Firma::Firma() {

}
Firma::~Firma() {

}
void Firma::Write(string a, string b, string c, string d, string e) {
	fstream s;
	s.open("directory.txt", fstream::app);
	if (!s.is_open())cout << "Ошибка открытия файла\n";
	else {
		s << a << "\n" << b << "\n" << c << "\n" << d << "\n" << e << "\n\n";
		s.close();
	}
}
void Firma::Write() {
	fstream s;
	s.open("directory.txt", fstream::app);
	if (!s.is_open())cout << "Ошибка открытия файла\n";
	else {
		cout << "Введите название фирмы\n";
		SetConsoleCP(1251);
		cin >> x.name;
		SetConsoleCP(866);
		cout << "Введите имя владельца фирмы\n";
		SetConsoleCP(1251);
		cin >> x.director;
		SetConsoleCP(866);
		cout << "Введите Телефон фирмы\n";
		SetConsoleCP(1251);
		cin >> x.telephone;
		SetConsoleCP(866);
		cout << "Введите Адрес фирмы\n";
		SetConsoleCP(1251);
		cin >> x.adress;
		SetConsoleCP(866);
		cout << "Введите род деятельности фирмы\n";
		SetConsoleCP(1251);
		cin >> x.occupation;
		s << x.name << "\n" << x.director << "\n" << x.telephone << "\n" << x.adress << "\n" << x.occupation << "\n\n";
		SetConsoleCP(866);
		s.close();
	}
}
void Firma::Print() {
	fstream s;
	s.open("directory.txt", fstream::in);
	if (!s.is_open())cout << "Ошибка открытия файла\n";
	else {
		string b;
		while (!s.eof()) {
			b = "";
			getline(s, b);
			cout << b << "\n";
		}
	}
	s.close();
}
void Firma::Search() {
	cout << "Введите слово\n";
	string search;
	cin >> search;
	fstream s;
	s.open("directory.txt", fstream::in);
	if (!s.is_open())cout << "Ошибка открытия файла\n";
	else {
		string b;
		int c = 0, d = 0;
		while (!s.eof()) {
			if (c == 6) c = 0;
			b = "";
			getline(s, b);
			if (b == search) {
				d++;
			}
			if (c == 0) x.name = b;
			else if (c == 1) x.director = b;
			else if (c == 2) x.telephone = b;
			else if (c == 3) x.adress = b;
			else if (c == 4) x.occupation = b;
			else if (c == 5 && d > 0) {
				cout << "По вашему запросу нашлась фирма:\n";
				cout << "Название фирмы:\t\t" << x.name << endl;
				cout << "Имя владельца фирмы:\t" << x.director << endl;
				cout << "Телефон фирмы:\t\t" << x.telephone << endl;
				cout << "Адрес фирмы:\t\t" << x.adress << endl;
				cout << "Род деятельности фирмы: " << x.occupation << endl << endl;
				d = 0;
			}
			c++;
		}
	}
	s.close();

}
int main() {
	setlocale(LC_ALL, "");
	cout << "Задание: Используя потоки создайте класс СПРАВОЧНИК со следующими полями :\n";
	cout << "1. Название фирмы;\n";
	cout << "2. Владелец;\n";
	cout << "3. Телефон;\n";
	cout << "4. Адрес;\n";
	cout << "5. Род деятельности.\n";
	cout << "Реализовать следующие возможности :\n";
	cout << "1. Поиск по названию;\n";
	cout << "2. Поиск по владельцу;\n";
	cout << "3. Поиск по номеру телефона;\n";
	cout << "4. Поиск по роду деятельности;\n";
	cout << "5. Показ всех записей и добавление.\n";
	cout << "Вся информация, должна сохранятся в файле, должна\n";
	cout << "быть реализована возможность добавления новых данных.\n";
	Firma firma;
	//Добавление записей в справочник
	char a[5][15] = { "ooo1","ooo2","ooo3","ooo4","ooo5" };
	char b[5][15] = { "Valik","Vika","Roma","Nastia","Ira" };
	char c[5][15] = { "38050","38060","38070","38080","38090" };
	char d[5][15] = { "Stroitelei","Stusa","Karavaeva","Harkovskaya","Drujnaya" };
	char e[5][15] = { "Cofeinya","Restoran","Zakusochnaya","Picca","Sushi" };
	for (int j = 0; j < 5; j++) {
		firma.Write(a[j], b[j], c[j], d[j], e[j]);
	}


	int i;
	for (;;) {
		cout << endl << "Сделайте выбор:\n";
		cout << "0 - Выход с программы\n1 - Добавить фирму в справочник\n2 - Показ всех записей справочника\n3 - Поиск фирмы по названию, владельцу ,телефону, роду деятельности\n";
		cin >> i;
		if (i == 0)break;
		if (i == 1)firma.Write();
		if (i == 2)firma.Print();
		if (i == 3)firma.Search();
	}
}