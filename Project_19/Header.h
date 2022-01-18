#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Project19_1 {
private:
	void Write(string a, string c) {
		fstream b;
		b.open(c, ios::app);
		if (!b.is_open()) {
			cout << "������!\n";
		}
		else {
			b << a << "\n";
		}
		b.close();
	}

	void Compare(string e, string f) {
		string c, d;
		fstream a, b;
		a.open(e, ios::in);
		b.open(f, ios::in);
		if (!a.is_open()) {
			cout << "������!1\n";
		}
		else {
			if (!b.is_open()) {
				cout << "������!2\n";
			}
			else {
				while (!a.eof()) {
					c = "";
					d = "";
					getline(a, c);
					getline(b, d);
					if (c == d) {
						cout << "������ ����������:\n" << c << endl << d << endl;
					}
					else {
						cout << "������ ������:\n" << c << endl << d << endl;
					}
				}
			}
		}
		a.close();
		b.close();
	}
public:
	void main() {
		cout << "������� 1.���� ��� ��������� �����.��������, ��������� �� ��\n";
		cout << "������.���� ���, �� ������� ������������� ������ ��\n";
		cout << "������� �����.\n\n";

		char a[5][15]{ "Vika","Vika","Vika","Vika","Vika" };
		char b[5][15]{ "Valik","Vika","Roma","Nastia","Ira" };

		string path_1 = "1_1.txt";
		string path_2 = "1_2.txt";

		for (int i = 0; i < 5; i++) {
			Write(a[i], path_1);
			Write(b[i], path_2);
		}

		Compare(path_1, path_2);
	}
};
class Project19_2 {
private:
	char consonants[32]{ '�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','a', 'e', 'i', 'o', 'u', 'y','A', 'E', 'I', 'O', 'U', 'Y' };
	char vowels[84]{ '�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z','B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z' };
	char numbers[10]{ '0','1','2','3','4','5','6','7','8','9' };
	void Write(string a, string path) {
		fstream b;
		b.open(path, ios::app);
		if (!b.is_open()) {
			cout << "������!\n";
		}
		else {
			b << a << "\n";
		}
		b.close();
	}

	void Print(string path) {
		char b;
		fstream a;
		int line = 0, symbol = 0, consonants_symbol = 0, vowels_symbol = 0, numbers_symbol = 0;
		a.open(path, ios::in);
		if (!a.is_open()) {
			cout << "������!\n";
		}
		else {
			while (!a.eof()) {
				a.get(b);
				symbol++;
				if (b == '\n') {
					line++;
				}
				for (int i = 0; i < 32; i++) {
					if (b == consonants[i]) {
						consonants_symbol++;
					}
				}
				for (int i = 0; i < 84; i++) {
					if (b == vowels[i]) {
						vowels_symbol++;
					}
				}
				for (int i = 0; i < 10; i++) {
					if (b == numbers[i]) {
						numbers_symbol++;
					}
				}
			}
		}
		cout << "����������:\n";
		cout << "���������� �������� - " << symbol << endl;
		cout << "���������� ����� - " << line << endl;
		cout << "���������� ������� ���� - " << vowels_symbol << endl;
		cout << "���������� ��������� ���� - " << consonants_symbol << endl;
		cout << "���������� ���� - " << numbers_symbol << endl;
		a.close();
	}
public:
	void main() {
		cout << "������� 2.��� ��������� ����.���������� ������� ����� ����\n";
		cout << "� �������� � ���� ��������� ���������� �� ��������� ����� :\n";
		cout << "���������� ��������;\n";
		cout << "���������� �����;\n";
		cout << "���������� ������� ����;\n";
		cout << "���������� ��������� ����;\n";
		cout << "���������� ����.\n\n\n";
		char c[5][10]{ "Valik1", "����2", "����3", "Ira", "Roma" };

		string path = "2_1.txt";

		for (int i = 0; i < 5; i++) {
			Write(c[i], path);
		}

		Print(path);
	}
};
class Project19_3 {
private:
	char alphabet[33]{ '�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�' };
	char ALPHABET[33]{ '�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�' };

	//���� ����������:
	int key = 3;

	void Add(char a, string path) {
		fstream b;
		char c;
		b.open(path, ios::out | ios::binary | ios::app);
		if (!b.is_open()) {
			cout << "!\n";
		}
		else {
			b << a;
		}
		b.close();
	}

	void Cipher(string path, string path_new) {
		char b;
		char c;
		fstream a;
		a.open(path, ios::in);
		if (!a.is_open()) {
			cout << "Error!\n";
		}
		else {
			while (!a.eof()) {
				a.get(b);
				c = b;
				for (int i = 0; i < 33; i++) {
					if (b == alphabet[i]) {
						if (i > 33 - key) {
							c = alphabet[i + key - 33];
						}
						else c = alphabet[i + key];
					}
				}
				for (int i = 0; i < 33; i++) {
					if (b == ALPHABET[i]) {
						if (i > 33 - key) {
							c = ALPHABET[i + key - 33];
						}
						else c = ALPHABET[i + key];
					}
				}
				Add(c, path_new);
			}
		}
		a.close();
	}

	void Print(string path) {
		fstream a;
		char b;
		a.open(path, ios::in);
		if (!a.is_open()) {
			cout << "Error!\n";
		}
		else {
			while (!a.eof()) {
				a.get(b);
				cout << b;
			}
		}
		a.close();
	}
public:
	void main() {
		cout << "������� 3.���� ������ � ���� �� ���������� ������.��� ���������� ������ ������ ���������� ������, ���������\n";
		cout << "�� ���� � �������� �� ������������� ����� �������.\n\n";

		char c[58] = "����� �� ��� ���� ������ ����������� �����, �� ����� ���.";

		string path_1 = "3_1.txt";
		string path_2 = "3_2.txt";
		for (int i = 0; i < 58; i++) {
			Add(c[i], path_1);
		}
		Cipher(path_1, path_2);
		cout << "������ ����:\n";
		Print(path_1);
		cout << "\n������ ����:\n";
		Print(path_2);
	}
};