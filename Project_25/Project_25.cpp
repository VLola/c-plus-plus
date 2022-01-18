#include<iostream>
#include<string>
#include<ctime>
#include <windows.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
class Creature {
private:
	string name;
	int MaxHealth;
	int Health;
	int Damage;
	int Gold;
	int level;
public:
	int getLevel() { return level; }
	int getDamage() { return Damage; }
	int getGold() { return Gold; }
	void regenHealth() {
		for (int i = 0; i < level; i++)
			if (Health < MaxHealth)
				Health++;
	}
	void reduceHealth(int a) { Health -= a; }
	bool isDead() {
		if (Health <= 0) return true;
		else return false;
	}
	void addGold(int a) { Gold += a; }
	void FullInfo() {
		cout << "Характеристики - ";
		SetConsoleTextAttribute(h, 2);
		cout << name;
		SetConsoleTextAttribute(h, 7);
		cout << "; Уровень - ";
		SetConsoleTextAttribute(h, 3);
		cout << level;
		SetConsoleTextAttribute(h, 7);
		cout << "; Здоровье - ";
		SetConsoleTextAttribute(h, 4);
		cout << Health;
		SetConsoleTextAttribute(h, 7);
		cout << "; Урон - ";
		SetConsoleTextAttribute(h, 5);
		cout << Damage;
		SetConsoleTextAttribute(h, 7);
		cout << "; Золото - ";
		SetConsoleTextAttribute(h, 6);
		cout << Gold << endl;
		SetConsoleTextAttribute(h, 7);
	}
	void setName(string a) { name = a; }
	void setLevel(int a) { level = a; }
	void setHealth(int a) { Health = a; }
	void setMaxHealth(int a) { MaxHealth = a; }
	void setDamage(int a) { Damage = a; }
	void setGold(int a) { Gold = a; }
	void addLevel() { level++; }
	void addDamage() { Damage *= level; }
	void addHealth() { Health *= level; }
	void addMaxHealth() { MaxHealth *= level; }
};
class Player :public Creature {
public:
	Player() {
		string a;
		cout << "Введите имя игрока:\n";
		cin >> a;
		setName(a);
		setLevel(1);
		setHealth(10);
		setMaxHealth(10);
		setDamage(1);
		setGold(0);
	}
	void levelUp() {
		addLevel();
		addDamage();
		addHealth();
		addMaxHealth();
	}
	bool hasWon() {
		if (getLevel() >= 20)return true;
		else return false;
	}

};
class Monster :public Creature {
public:
	Monster(int lvl) {
		int a = rand() % 3 + 1;
		if (a == 1) Dragon(lvl);
		else if (a == 2) Ork(lvl);
		else if (a == 3) Slime(lvl);
	}
	void Dragon(int lvl) {
		setName("dragon");
		setLevel(lvl);
		setHealth(20 * getLevel());
		setDamage(4 * getLevel());
		setGold(100 * getLevel());
	}
	void Ork(int lvl) {
		setName("orc");
		setLevel(lvl);
		setHealth(4 * getLevel());
		setDamage(2 * getLevel());
		setGold(25 * getLevel());
	}
	void Slime(int lvl) {
		setName("slime");
		setLevel(lvl);
		setHealth(1 * getLevel());
		setDamage(1 * getLevel());
		setGold(10 * getLevel());
	}

};
int getRandom() {
	int a = rand() % 2 + 1;
	return a;
}
int main() {
	setlocale(LC_ALL, "");
	srand(static_cast<unsigned int>(time(0)));
	Player one;
	int a;
	for (;;) {
		one.FullInfo();
		cout << "На Вас напал:\n";
		Monster m(one.getLevel());
		m.FullInfo();
		cout << "Выберите действие:\n1 - бежать, 2 - сражаться\n";
		cin >> a;
		if (a == 1) {
			one.regenHealth();
			continue;
		}
		if (a == 2) {
			for (;;) {
				int a = getRandom();
				if (a == 1) {
					cout << "Монстр ударил\n";
					one.reduceHealth(m.getDamage());
				}
				else if (a == 2) {
					cout << "Вы ударили\n";
					m.reduceHealth(one.getDamage());
				}
				if (one.isDead()) {
					cout << "Вы мертвы!\n";
					break;
				}
				if (m.isDead()) {
					SetConsoleTextAttribute(h, 4);
					cout << "Монстр Убит!\n";
					SetConsoleTextAttribute(h, 7);
					one.addGold(m.getGold());
					one.levelUp();
					break;
				}
				one.FullInfo();
				m.FullInfo();
				system("pause");
			}
		}
		if (one.hasWon()) {
			cout << "Вы прошли игру!\n";
			break;
		}
		if (one.isDead()) {
			break;
		}
	}
}