#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include <windows.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
class Game {
	vector<string>slova;
	string conceived;
	string slovo;
public:
	char Input() {
		char a;
		cout << "Введите букву\n";
		cin >> a;
		return a;
	}
	void Start() {
		string word;
		for (int i = 0; i < 3; i++) {
			cout << "Загадайте " << i + 1 << " слово\n";
			cin >> word;
			slova.push_back(word);
		}
		int a = rand() % 3;
		slovo = slova[a];
		cout << "Игра началась\n";
		for (int i = 0; i < slovo.length(); i++)conceived += '-';
		for (int i = 0; i < 9; i++) {
			cout << "У вас " << 9 - i << " Попыток!\n";
			if (!isCheck())Output();
			else break;
		}
		if (isCheck())cout << "Вы отгадали слово";
		else cout << "Вас повесили";
	}
	void Output() {

		Check(slovo, Input());
		for (int i = 0; i < slovo.length(); i++) {
			if (slovo[i] == conceived[i]) cout << slovo[i];
			else cout << "-";
		}cout << endl;
	}
	void Check(string initial, char a) {
		int b = 0;
		for (int i = 0; i < initial.length(); i++) {
			if (initial[i] == a) {
				conceived[i] = a;
				cout << "Вы отгадали букву! " << a << "\n";
			}
			else {
				if (conceived[i] == '-')	conceived[i] = '-';
				else { conceived[i] = conceived[i]; }
			}
		}cout << endl;
	}
	bool isCheck() {
		if (slovo == conceived) return true;
		else return false;
	}
};
int main() {
	setlocale(LC_ALL, "");
	Game a;
	a.Start();
}