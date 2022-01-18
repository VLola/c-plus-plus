# include <iostream>
# include <vector>
#include <ctime>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <windows.h>
using namespace std;
class Sudoku {
public:
	vector<vector<int>> myVector;
	vector<int> myVector_2;
	vector<vector<int>> myVector1;
	vector<int> myVector_3;
	int Valik[9];
	void PrintVector();
	void PrintVector1();
	int Next(int);
	void Start();
	int Check2(int);
	void Check1(int, int);
	bool CheckLine(int, int);
	bool CheckColumn(int, int);
	bool Lola = false;
	int sum = 0;
};
void setcolor(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}
bool Sudoku::CheckColumn(int a, int j) {

	for (int g = 0; g < 9; g++) {
		if (myVector[g][j] == a)return false;
	}
	return true;
}
bool Sudoku::CheckLine(int a, int i) {

	for (int g = 0; g < 9; g++) {
		if (myVector[i][g] == a)return false;
	}
	return true;
}

int Sudoku::Check2(int s) {
	for (int r = 0; r < 9; r++) {
		if (s == Valik[r]) return false;
	}
	return true;
}

void Sudoku::Check1(int i, int j) {
	int k = i, l = j, e = 0, h = 0, c = 0, m = 0, n = 0;
	if (k == 0 || k == 1 || k == 2) {
		m = 0;
	}
	else if (k == 3 or k == 4 or k == 5) {
		m = 3;
	}
	else if (k == 6 or k == 7 or k == 8) {
		m = 6;
	}
	if (l == 0 or l == 1 or l == 2) {
		n = 0;
	}
	else if (l == 3 or l == 4 or l == 5) {
		n = 3;
	}
	else if (l == 6 or l == 7 or l == 8) {
		n = 6;
	}
	int x = 0;

	Valik[x] = myVector[m][n];
	x++;
	Valik[x] = myVector[m][n + 1];
	x++;
	Valik[x] = myVector[m][n + 2];
	x++;
	Valik[x] = myVector[m + 1][n];
	x++;
	Valik[x] = myVector[m + 1][n + 1];
	x++;
	Valik[x] = myVector[m + 1][n + 2];
	x++;
	Valik[x] = myVector[m + 2][n];
	x++;
	Valik[x] = myVector[m + 2][n + 1];
	x++;
	Valik[x] = myVector[m + 2][n + 2];
}

int Sudoku::Next(int v) {
	if (v == 9) return 1;
	else return v++;
}

void Sudoku::Start() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (myVector1[i][j] != 0) {
				myVector[i][j] = myVector1[i][j];
			}
			else {
				int f = rand() % 9 + 1;
				Check1(i, j);
				for (int g = 0; g < 9; g++) {
					if (Check2(f) && CheckLine(f, i) && CheckColumn(f, j)) {
						myVector[i][j] = f;
					}
					else f = Next(f);
				}
				if (myVector[i][j] == 0) {
					Start();
				}
			}

		}
	}
}

void Sudoku::PrintVector() {
	for (int o = 0; o < 9; o++) {
		for (int p = 0; p < 9; p++) {
			if (myVector[o][p] == myVector1[o][p]) {
				setcolor(12);
				cout << myVector[o][p] << "\t";
			}
			else {
				setcolor(7);
				cout << myVector[o][p] << "\t";
			}
		}cout << endl;
	}
	cout << '\n';
}
void Sudoku::PrintVector1() {
	for (int o = 0; o < 9; o++) {
		for (int p = 0; p < 9; p++) {
			if (myVector1[o][p] != 0) {
				setcolor(12);
				cout << myVector1[o][p] << "\t";
			}
			else {
				setcolor(7);
				cout << myVector1[o][p] << "\t";
			}
		}cout << endl;
	}
	cout << '\n';
}
int main() {
	srand(unsigned(time(0)));
	setlocale(LC_ALL, "");
	Sudoku a;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			a.myVector_2.push_back(0);
			a.myVector_3.push_back(0);
		}
		a.myVector.push_back(a.myVector_2);
		a.myVector1.push_back(a.myVector_3);
	}
	int b, c, d, e;
	for (;;) {
		cout << "Выберите действие:\n";
		cout << "Добавить цифру в клетку - 1, Запустить решение судоку - 2\n";
		cin >> b;
		if (b == 1) {
			cout << "Введите координаты клетки по горизонтали\n";
			cin >> c;
			cout << "Введите координаты клетки по вертикали\n";
			cin >> d;
			cout << "Введите цифру от 1 до 9\n";
			cin >> e;
			a.myVector1[d - 1][c - 1] = e;
			a.myVector[d - 1][c - 1] = e;
			a.PrintVector1();
		}
		else if (b == 2) {
			a.Start();
			a.PrintVector();
			for (int o = 0; o < 9; o++) {
				for (int p = 0; p < 9; p++) {
					a.myVector[o][p] = 0;
				}
			}
		}
	}
}