#pragma once
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <conio.h>
#include <fstream>
#include <string>
#include <direct.h>
#include <stdio.h>
using namespace std;
class Project17_1 {
public:
	void main()
	{
		cout << "������� 1: ��� ��������� ����. ������� �� ���� ��������� ������.��������� �������� � ������ ����.\n";
		int b = 0;
		ofstream f;
		ifstream s;
		string path1 = "1.txt";
		string path2 = "2.txt";
		f.open(path1, ios::out);
		f << "Valik" << "\n";
		f << "Vika" << "\n";
		f << "Ira" << "\n";
		f << "Katerina";
		f.close();

		s.open(path1);
		if (!s.is_open()) {
			cout << "\n������ �������� ������� �����!\n";
		}
		else {
			cout << "\n������ ���� ������\n" << "���������� ������� �����:\n";
			string a;
			while (!s.eof()) {
				a = "";
				getline(s, a);
				b++;
				cout << a << "\n";
			}

		}
		s.close();

		s.open(path1);
		if (!s.is_open()) {
			cout << "\n������ �������� ������� �����!\n";
		}
		else {
			cout << "\n������ ���� ������\n" << "������ �� ������ ����:\n";
			string a;
			for (int i = 0; i < b - 1; i++) {
				a = "";
				getline(s, a);
				f.open(path2, ios::app);
				f << a << "\n";
				cout << a << "\n";
				f.close();
			}
		}
	}
};
class Project17_2 {
public:
	void main()
	{
		cout << "������� 2: ��� ��������� ����. ����� ����� ����� ������� ������.\n";
		int b = 0;
		ofstream f;
		ifstream s;
		string path1 = "1.txt";
		f.open(path1, ios::out);
		f << "Valik" << "\n";
		f << "Katerina" << "\n";
		f << "Ira" << "\n";
		f << "Vika";
		f.close();

		s.open(path1);
		if (!s.is_open()) {
			cout << "\n������ �������� �����!\n";
		}
		else {
			cout << "\n���� ������\n" << "���������� ������� �����:\n";
			string a, b;
			int count_a, count_b = 0;
			while (!s.eof()) {
				a = "";
				getline(s, a);
				cout << a << "\n";
				count_a = a.length();
				if (count_b < count_a) {
					b = a;
					count_b = b.length();
				}
			}

			cout << "����� ������� ������ � ����� " << b << " ���������� ��������� � ������: " << count_b;
		}
		s.close();
	}
};
class Project17_3 {
public:
	void main()
	{
		cout << "������� 3: ��� ��������� ����. ��������� ������� ��� � ��� ����������� �������� ������������� �����.\n";
		int b = 0;
		ofstream f;
		ifstream s;
		string path1 = "1.txt";
		f.open(path1, ios::out);
		f << "ValikValikValikValikValikValikValikValikValikValikValikValikValikValik" << "\n";
		f << "ValikValikValikValikValikValikValikValikValikValikValikValikValikValik" << "\n";
		f << "ValikValikValikValikValikValikValikValikValikValikValikValikValikValik" << "\n";
		f << "ValikValikValikValikValikValikValikValikValikValikValikValikValikValik";
		f.close();

		s.open(path1);
		if (!s.is_open()) {
			cout << "\n������ �������� �����!\n";
		}
		else {
			cout << "\n���� ������\n";
			const int size = 6;
			char a[size] = { "Valik" };
			char temp, b;
			int i = 0, j = 0, count = 0;
			while (!s.eof()) {
				i++;
				s.get(b);
				if (b == a[0]) {
					j = i;
					temp = b;
				}
				else if (b == a[i - j] && temp == a[i - j - 1]) {
					temp = b;
					if (i - j == size - 2)count++;
				}

			}

			cout << "���������� ���� � �����: " << count;
		}
		s.close();
	}
};
class File {
private:
	string name;
	string newName;
	string file;
	string fileNew;
	int lengthName;
	int lengthNameNew;
public:
	File();
	void WriteFile(string);
	void ReadFile();
	void Change(string);
	string PrintFile();
	string PrintFileNew();
};
File::File() {
	cout << "������� ����� ������� ������ �����\n";
	cin >> name;
	lengthName = name.length();
	cout << "������� ����� ������� ������ �������� ���������\n";
	cin >> newName;
	lengthNameNew = newName.length();
}
void File::ReadFile() {
	ifstream s;
	string path1 = "1.txt";
	s.open(path1);
	if (!s.is_open()) {
		cout << "\n������ �������� �����!\n";
	}
	else {
		cout << "\n���� ������.\n";
		file = "";
		string b;
		while (!s.eof()) {
			b = "";
			getline(s, b);
			file += b;
		}
	}
	s.close();
}
void File::WriteFile(string g) {
	ofstream f;
	string path1 = "1.txt";
	f.open(path1, ios::out);
	f << g;
	f.close();
}

void File::Change(string a) {
	int d;
	int c = a.length();
	for (int i = 0; i < c; i++) {
		d = 0;
		for (int j = 0; j < lengthName; j++) {
			if (a[i + j] == name[j]) {
				d++;
			}
			else {
				break;
			}
		}
		if (d == lengthName) {
			fileNew += newName;
			i += lengthName - 1;
		}
		else {
			fileNew += a[i];
		}
	}
}
string File::PrintFile() {
	return file;
}
string File::PrintFileNew() {
	return fileNew;
}
class Project17_4 {
public:
	void main()
	{
		cout << "������� 4: ��� ��������� ����. ����� � �������� � ��� �������� �����.\n��� ������ � �� ��� �������� ������������ �������������.\n";

		cout << "\n���������: � ����� ��� ����� Valik � Vika\n";
		File P;
		P.WriteFile("ValikValikValikValikValikValikValikVikaValikValikValikValikVikaValikValik");
		P.ReadFile();
		cout << P.PrintFile() << endl << "�������� ���� �� ������\n" << endl;
		system("PAUSE");
		P.Change(P.PrintFile());
		P.WriteFile(P.PrintFileNew());
		P.ReadFile();
		cout << P.PrintFile() << endl << "�������� ���� �� ������\n" << endl;
	}
};
class FileManager {
private:
	string path;
	string file;
	string content;
public:
	FileManager();
	void CreateFile();
	void DeleteFile();
	void CreateDirectory();
	void RenameFile();
	void TransferFile();
	void Print();
};
FileManager::FileManager() {
	cout << "������� �������� ��������\n";
	cin >> path;
	cout << "������� �������� �����\n";
	cin >> file;
	cout << "������� ���������� ������� ����� �������� � �����\n";
	cin >> content;
}
void FileManager::CreateFile() {
	ofstream f;
	f.open(path + "/" + file, ios::out);
	if (!f.is_open()) cout << "\n������ �������� �����!\n";
	else {
		f << content;
		cout << file << " ���� ������ � ���������� " << path << endl;
	}
	f.close();
}
void FileManager::DeleteFile() {
	string pathFile = path + "/" + file;
	char* char_arr;
	char_arr = &pathFile[0];
	if (remove(char_arr) != 0) {
		cout << "������ � �������� ����� " << file << "\n";
	}
	else
		cout << file << " ���� �����.\n";
}
void FileManager::CreateDirectory() {
	char* char_arr;
	char_arr = &path[0];
	if (_mkdir(char_arr) == -1)
		cout << "������ � �������� ����� " << path << "\n";
	else
		cout << "����� " << path << " �������.\n";
}
void FileManager::RenameFile() {
	string pathFile = path + "/" + file;
	cout << "������� ����� ��� �����\n";
	cin >> file;
	string pathFileNew = path + "/" + file;
	char* char_arr;
	char_arr = &pathFile[0];
	char* char_arr_new;
	char_arr_new = &pathFileNew[0];
	if (rename(char_arr, char_arr_new) != 0) {
		cout << file << " ���� �� ������������." << "\n";
	}
	else cout << file << " ���� ������������.\n";
}
void FileManager::TransferFile() {
	string pathNew;
	cout << "������� �������� ����� ����������\n";
	cin >> pathNew;
	char* char_arr;
	char_arr = &pathNew[0];
	if (_mkdir(char_arr) == -1)
		cout << "������ � �������� ����� " << pathNew << "\n";
	else {
		cout << "����� " << pathNew << " �������.\n";
		string pathFile = path + "/" + file;
		path = pathNew;
		string pathFileNew = path + "/" + file;
		char* char_arr;
		char_arr = &pathFile[0];
		char* char_arr_new;
		char_arr_new = &pathFileNew[0];
		if (rename(char_arr, char_arr_new) != 0) {
			cout << file << " ���� �� ���������." << "\n";
		}
		else cout << file << " ���� ���������.\n";
	}
}
void FileManager::Print() {
	ifstream s;
	s.open(path + "/" + file);
	if (!s.is_open()) {
		cout << "\n������ �������� �����!\n";
	}
	else {
		cout << "\n���� ������. ����� ����������:\n";
		string b;
		while (!s.eof()) {
			b = "";
			getline(s, b);
		}cout << b << endl;
	}
	s.close();
}
class Project17_5 {
public:
	void main() {
		cout << "\n ������� 5: �������� ��������� ����������� �������� �������� :\n";
		cout << "1. �������� ������ ����� � ������� ��������;\n";
		cout << "2. �������� ����� �� �������� ��������;\n";
		cout << "3. �������������� ����� � ������� ��������;\n";
		cout << "4. ����������� ����� �� �������� �������� � ��������� ������������� �������;\n";
		cout << "5. ����� ����������� ���������� ������������� ����� �� �������� �������� �� �����.\n";
		FileManager A;
		// �������� ����������
		A.CreateDirectory();
		// �������� �����
		A.CreateFile();
		// �������� �����
		A.DeleteFile();
		// �������� �����
		A.CreateFile();
		// �������������� �����
		A.RenameFile();
		// ������� �����
		A.TransferFile();
		// ����� ����������� ����� �� �����
		A.Print();
	}
};