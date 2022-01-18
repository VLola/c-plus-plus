#pragma once
#include <iostream>
using namespace std;

class Project20_1 {
private:

	class Employer {
	public:

		int age;

		virtual int Print() = 0;
		void getAge(int a) {
			age = a;
		}

	};

	class President : public Employer {
	public:
		int Print() { return age; }
	};

	class Manager : public Employer {
	public:
		int Print() { return age; }
	};

	class Worker : public Employer {
	public:
		int Print() { return age; }
	};
public:
	void main() {

		cout << "Задание 1: Создать абстрактный базовый класс Employer(слу -\n";
		cout << "жащий) с чисто виртуальной функцией Print().Соз - \n";
		cout << "дайте три производных класса : President, Manager, \n";
		cout << "Worker.Переопределите функцию Print() для вывода\n";
		cout << "информации, соответствующей каждому типу служащего.\n";

		int a = 55, b = 40, c = 30;

		President president;
		president.getAge(a);
		cout << "\nВозвраст президента - " << president.Print();

		Manager manager;
		manager.getAge(b);
		cout << "\nВозвраст менеджера - " << manager.Print();

		Worker worker;
		worker.getAge(c);
		cout << "\nВозвраст работника - " << worker.Print();
	}
};
class Project20_2 {
private:
	struct Element {
		char data;
		Element* Next;
	};
	class List {
	public:

		Element* Head;
		Element* Tail;
		int Count;
		virtual void Add(char data) = 0;
		virtual void Del() = 0;
		virtual void DelAll() = 0;
		virtual void Print() = 0;
		virtual int GetCount() = 0;
		virtual void Paste(int, char) = 0;
		virtual void DelElement(int) = 0;


	};


	class Heir : public List {
	public:
		void Paste(int n, char m) {
			Element* temp = Head;

			for (int a = 0; a <= n; a++)
			{
				temp = temp->Next;
				if (a == n - 1)temp->data = m;
			}
		}
		void DelElement(int n) {
			Element* temp = Head;
			char temp1;
			char temp2;
			temp1 = temp->data;
			GetCount();
			for (int a = 0; a < Count; a++) {
				if (a < n) {
					temp = temp->Next;
					temp2 = temp->data;
					temp->data = temp1;
					temp1 = temp2;
				}
				else {
					temp = temp->Next;
				}
			}

			Head = Head->Next;
			delete temp;
		}
		Heir()
		{
			Head = Tail = NULL;
			Count = 0;
		}
		~Heir()
		{
			DelAll();
		}
		int GetCount()
		{
			int a = 0;
			Element* temp = Head;
			while (temp != 0)
			{
				temp = temp->Next;
				a++;
			}
			Count = a;
			return Count;
		}
		void Add(char data)
		{
			Element* temp = new Element;
			temp->data = data;
			temp->Next = NULL;
			if (Head != NULL) {
				Tail->Next = temp;
				Tail = temp;
			}
			else {
				Head = Tail = temp;
			}
		}
		void Del()
		{
			Element* temp = Head;
			Head = Head->Next;
			delete temp;
		}
		void DelAll()
		{
			while (Head != 0) Del();
		}
		void Print()
		{
			Element* temp = Head;
			while (temp != 0)
			{
				cout << temp->data << " ";
				temp = temp->Next;
			}
			cout << "\n\n";
		}
	};
public:
	void main() {
		cout << "Задание 2: Создать базовый класс список.Реализовать на базе\n";
		cout << "списка стек и очередь с виртуальными функциями вставки и вытаскивания.\n\n";


		Heir lst;
		char s[] = "123456789\n";
		int len = strlen(s);
		for (int i = 0; i < len; i++)
			lst.Add(s[i]);
		cout << "Распечатка списока:\n";
		lst.Print();
		cout << "Вставляем элемент '8' в позицию 5\n";
		lst.Paste(5, '8');
		cout << "Распечатка списока:\n";
		lst.Print();
		cout << "Вытаскиваем элемент из позиции 3\n";
		lst.DelElement(3);
		cout << "Распечатка списока:\n";
		lst.Print();
	}
};
class Project20_3 {
private:

	class Square {
	public:
		double a;
		double b;
		double h;
		double radius;
		const double p = 3.14;
		virtual double Calculate() = 0;
		void getA(double A) {
			a = A;
		}
		void getB(double B) {
			b = B;
		}
		void getH(double H) {
			h = H;
		}
		void getR(double R) {
			radius = R;
		}
	};


	class Rectangle : public Square {
	public:
		virtual double Calculate() {
			return a * b;
		}
	};
	class Circle : public Square {
	public:
		virtual double Calculate() {
			return p * radius * radius;
		}
	};
	class RightTriangle : public Square {
	public:
		virtual double Calculate() {
			return a * b / 2;
		}
	};
	class Trapezoid : public Square {
	public:
		virtual double Calculate() {
			return (a + b) * h / 2;
		}
	};
public:
	void main() {
		cout << "Задание 3: Создать абстрактный базовый класс с виртуальной\n";
		cout << "функцией — площадь.Создать производные классы :\n";
		cout << "прямоугольник, круг, прямоугольный треугольник,\n";
		cout << "трапеция со своими функциями площади.Для провер -\n";
		cout << "ки определить массив ссылок на абстрактный класс,\n";
		cout << "которым присваиваются адреса различных объектов.\n\n";
		double a = 1, b = 2, h = 3, r = 4;
		Rectangle rectangle;
		Circle circle;
		RightTriangle rightTriangle;
		Trapezoid trapezoid;

		rectangle.getA(a);
		rectangle.getB(b);
		circle.getR(r);
		rightTriangle.getA(a);
		rightTriangle.getB(b);
		trapezoid.getA(a);
		trapezoid.getB(b);
		trapezoid.getH(h);

		cout << "Площадь прямоугольника - " << rectangle.Calculate() << endl;
		cout << "Площадь круга - " << circle.Calculate() << endl;
		cout << "Площадь прямоугольного треугольника - " << rightTriangle.Calculate() << endl;
		cout << "Площадь трапеции - " << trapezoid.Calculate() << endl;
	}
};
class Project20_4 {
private:

	class Urovneniya {
	public:

		double a;
		double b;
		double c;

		virtual int Start() = 0;
		void getA(double A) {
			a = A;
		}
		void getB(double B) {
			b = B;
		}
		void getC(double C) {
			c = C;
		}

	};

	class Line : public Urovneniya {
	public:
		int Start() {
			if (a != 0) {
				cout << "x = " << -b * a;
				return 0;
			}
		}

	};

	class Kvadratn : public Urovneniya {
	public:
		int Start() {
			if (a != 0) {
				double d = b * b - 4 * a * c;
				if (d > 0) {

					cout << "x = " << ((-b + sqrt(d)) / 2 * a) << endl;
					cout << "x = " << ((-b - sqrt(d)) / 2 * a) << endl;
					return 0;
				}
				else if (d == 0) {
					cout << "x = " << -b / 2 * a;
					return 0;
				}
				else if (d < 0) {
					cout << "no kornei\n";
					return 0;
				}
			}
		}
	};
public:
	void main() {
		cout << "Задание 4: Создать абстрактный базовый класс с виртуальной\n";
		cout << "функцией — корни уравнения.Создать производные\n";
		cout << "классы : класс линейных уравнений и класс квадрат -\n";
		cout << "ных уравнений.Определить функцию вычисления\n";
		cout << "корней уравнений.\n\n";

		double a = 1, b = 2, c = 3;

		Line obj1;
		obj1.getA(a);
		obj1.getB(b);
		cout << "x = ";
		obj1.Start();
		cout << endl;

		Kvadratn obj2;
		obj2.getA(a);
		obj2.getB(b);
		obj2.getC(c);
		obj2.Start();
	}
};