#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

struct Elem {
	char Telephone[20];
	char NameFirst[20];
	Elem* left, * right, * parent;
};
class Notebook {
	Elem* root;

public:
	Notebook();
	~Notebook();
	//печать от указанного узла
	void Print(Elem* Node);
	//поиск от указанного узла
	Elem* Search(Elem* Node, char* key);
	Elem* SearchName(Elem* Node, char* key);
	//min от указанного узла
	Elem* Min(Elem* Node);
	//max от указанного узла
	Elem* Max(Elem* Node);
	//следующий для указанного узла
	Elem* Next(Elem* Node);
	//предыдущий для указанного узла
	Elem* Previous(Elem* Node);
	//вставка узла
	void Insert(Elem* z);
	//удаление ветки для указанного узла,
	//0 - удаление всего дерева
	void Del(Elem* z = 0);
	//получить корень
	Elem* GetRoot();

};

Notebook notebook;
Notebook::Notebook() {
	root = NULL;
}
Notebook::~Notebook() {
	Del();
}


//Рекурсивный обход дерева
void Notebook::Print(Elem* Node)
{
	if (Node != 0)
	{
		Print(Node->left);
		cout << Node->Telephone << "\t" << Node->NameFirst << endl;
		Print(Node->right);
	}
}
Elem* Notebook::Search(Elem* Node, char* k)
{
	//Пока есть узлы и ключи не совпадают
	while (Node != 0 && strcmp(k, Node->Telephone) != 0)
	{
		if (strcmp(k, Node->Telephone) < 0)
			Node = Node->left;
		else
			Node = Node->right;
	}
	return Node;
}
Elem* Notebook::SearchName(Elem* Node, char* k)
{

	//Пока есть узлы и ключи не совпадают
	while (Node != 0 && strcmp(k, Node->NameFirst) != 0)
	{
		if (strcmp(k, Node->NameFirst) < 0)
			Node = Node->left;
		else if (strcmp(k, Node->NameFirst) > 0)
			Node = Node->right;
	}
	if (Node == 0) {

		Node = notebook.GetRoot();
		//Пока есть узлы и ключи не совпадают
		while (Node != 0 && strcmp(k, Node->NameFirst) != 0)
		{
			if (strcmp(k, Node->NameFirst) < 0)
				Node = Node->right;
			else if (strcmp(k, Node->NameFirst) > 0)
				Node = Node->left;
		}
	}
	if (Node == 0) {

		Node = notebook.GetRoot();
		//Пока есть узлы и ключи не совпадают
		while (Node != 0 && strcmp(k, Node->NameFirst) != 0)
		{
			if (strcmp(k, Node->NameFirst) < 0)
				Node = Node->right;
			else if (strcmp(k, Node->NameFirst) > 0)
				Node = Node->right;
		}
	}
	if (Node == 0) {

		Node = notebook.GetRoot();
		//Пока есть узлы и ключи не совпадают
		while (Node != 0 && strcmp(k, Node->NameFirst) != 0)
		{
			if (strcmp(k, Node->NameFirst) < 0)
				Node = Node->left;
			else if (strcmp(k, Node->NameFirst) > 0)
				Node = Node->left;
		}
	}
	return Node;
}
Elem* Notebook::Min(Elem* Node)
{
	//Поиск самого "левого" узла
	if (Node != 0)
		while (Node->left != 0)
			Node = Node->left;
	return Node;
}
Elem* Notebook::Max(Elem* Node)
{
	//Поиск самого "правого" узла
	if (Node != 0)
		while (Node->right != 0)
			Node = Node->right;
	return Node;
}
Elem* Notebook::Next(Elem* Node)
{
	Elem* y = 0;
	if (Node != 0)
	{
		//если есть правый потомок
		if (Node->right != 0)
			return Min(Node->right);
		//родитель узла
		y = Node->parent;
		//если Node не корень и Node справа
		while (y != 0 && Node == y->right)
		{
			//Движемся вверх
			Node = y;
			y = y->parent;
		}
	}
	return y;
}
Elem* Notebook::Previous(Elem* Node)
{
	Elem* y = 0;
	if (Node != 0)
	{
		//если есть левый потомок
		if (Node->left != 0)
			return Max(Node->left);
		//родитель узла
		y = Node->parent;
		//если Node не корень и Node слева
		while (y != 0 && Node == y->left)
		{
			//Движемся вверх
			Node = y;
			y = y->parent;
		}
	}
	return y;
}
Elem* Notebook::GetRoot()
{
	return root;
}
void Notebook::Insert(Elem* z)
{
	//потомков нет
	z->left = NULL;
	z->right = NULL;
	Elem* y = NULL;
	Elem* Node = root;
	//поиск места
	while (Node != 0)
	{
		//будущий родитель
		y = Node;
		if (strcmp(z->Telephone, Node->Telephone) < 0)
			Node = Node->left;
		else
			Node = Node->right;
	}
	//заполняем родителя
	z->parent = y;
	if (y == 0) //элемент первый (единственный)
		root = z;
	//чей ключ больше?
	else if (strcmp(z->Telephone, y->Telephone) < 0)
		y->left = z;
	else
		y->right = z;
}
void Notebook::Del(Elem* z)
{
	//удаление куста
	if (z != 0)
	{
		Elem* Node, * y;
		//не 2 ребенка
		if (z->left == 0 || z->right == 0)
			y = z;
		else
			y = Next(z);
		if (y->left != 0)
			Node = y->left;
		else
			Node = y->right;
		if (Node != 0)
			Node->parent = y->parent;
		//Удаляется корневой узел?
		if (y->parent == 0)
			root = Node;
		else if (y == y->parent->left)
			//слева от родителя?
			y->parent->left = Node;
		else
			//справа от родителя?
			y->parent->right = Node;
		if (y != z)
		{
			//Копирование данных узла
			strcpy_s(z->Telephone, y->Telephone);
			strcpy_s(z->NameFirst, y->NameFirst);
		}
		delete y;
	}
	else //удаление всего дерева
		while (root != 0)
			Del(root);
}


void Start(char Numbers[][20], char Numes[][20], int N)
{
	int j;
	Elem* temp;

	for (j = 0; j < N; j++)
	{
		temp = new Elem;

		strcpy_s(temp->Telephone, Numbers[j]);
		strcpy_s(temp->NameFirst, Numes[j]);

		notebook.Insert(temp);
	}
}
void Add()
{
	char NumbersNew[20], NamesNew[20];

	Elem* temp;

	temp = new Elem;
	cout << "Введите номер телефона который хотите добавить в телефонную книгу\n";
	cin >> NumbersNew;
	cout << "Введите фамилию\n";
	cin >> NamesNew;

	strcpy_s(temp->Telephone, NumbersNew);
	strcpy_s(temp->NameFirst, NamesNew);

	notebook.Insert(temp);
}
void SearchNew() {
	char search[20];

	cout << "Введите номер телефона который хотите найти\n";
	cin >> search;
	while (notebook.Search(notebook.GetRoot(), search) == 0) {
		cout << "Нет такого абонента!\n";
		cout << "Введите номер абонента\n";
		cin >> search;
		notebook.Search(notebook.GetRoot(), search);
	}
	cout << notebook.Search(notebook.GetRoot(), search)->Telephone;
	cout << "\t";
	cout << notebook.Search(notebook.GetRoot(), search)->NameFirst;
}
void SearchNewName() {
	char search[20];
	cout << "Введите имя абонента которого хотите найти\n";
	cin >> search;
	while (notebook.SearchName(notebook.GetRoot(), search) == 0) {
		cout << "Нет такого абонента!\n";
		cout << "Введите имя абонента\n";
		cin >> search;
		notebook.SearchName(notebook.GetRoot(), search);
	}
	cout << notebook.SearchName(notebook.GetRoot(), search)->Telephone;
	cout << "\t";
	cout << notebook.SearchName(notebook.GetRoot(), search)->NameFirst;
}
void DeleteTelephone() {
	char search[20];
	cout << "Введите номер телефона который хотите удалить\n";
	cin >> search;

	while (notebook.Search(notebook.GetRoot(), search) == 0) {
		cout << "Нет такого абонента!\n";
		cout << "Введите номер абонента\n";
		cin >> search;
		notebook.Search(notebook.GetRoot(), search);
	}
	notebook.Del(notebook.Search(notebook.GetRoot(), search));
}
void DeleteTelephoneName() {
	char search[20];
	cout << "Введите фамилию абонента которого хотите удалить\n";
	cin >> search;
	while (notebook.SearchName(notebook.GetRoot(), search) == 0) {
		cout << "Нет такого абонента!\n";
		cout << "Введите имя абонента\n";
		cin >> search;
		notebook.SearchName(notebook.GetRoot(), search);
	}
	notebook.Del(notebook.SearchName(notebook.GetRoot(), search));
}
void Change() {
	char search[20], change[20];
	char* Name = new char[20];
	char* Name1 = new char[20];
	cout << "Введите номер телефона который хотите изменить\n";
	cin >> search;
	while (notebook.Search(notebook.GetRoot(), search) == 0) {
		cout << "Нет такого абонента!\n";
		cout << "Введите номер абонента\n";
		cin >> search;
		notebook.Search(notebook.GetRoot(), search);
	}

	Name = notebook.Search(notebook.GetRoot(), search)->NameFirst;

	cout << "Введите новый номер телефона\n";
	cin >> change;
	Elem* temp;
	temp = new Elem;
	strcpy_s(temp->Telephone, change);
	strcpy_s(temp->NameFirst, Name);
	notebook.Insert(temp);
	notebook.Del(notebook.Search(notebook.GetRoot(), search));
}
void ChangeName() {
	char search[20], change[20];
	char* Name = new char[20];
	cout << "Введите фамилию абонента у которого хотите изменить номер\n";
	cin >> search;
	while (notebook.SearchName(notebook.GetRoot(), search) == 0) {
		cout << "Нет такого абонента!\n";
		cout << "Введите фамилию абонента\n";
		cin >> search;
		notebook.SearchName(notebook.GetRoot(), search);
	}

	Name = notebook.SearchName(notebook.GetRoot(), search)->NameFirst;

	cout << "Введите новый номер телефона\n";
	cin >> change;
	Elem* temp;
	temp = new Elem;
	strcpy_s(temp->Telephone, change);
	strcpy_s(temp->NameFirst, Name);

	notebook.Insert(temp);

	notebook.Del(notebook.SearchName(notebook.GetRoot(), search));
}
int main() {
	setlocale(LC_ALL, "");
	cout << "\nЗадача: Создать телефонный справочник для осуществления следующих ситуаций:\n";
	cout << "Добавление абонентов в базу.\n";
	cout << "Удаление абонентов из базы.\n";
	cout << "Модификация данных абонента.\n";
	cout << "Поиск абонентов по телефонному номеру или фамилии.\n\n";
	int const N = 5;
	char Numbers[5][20]{
		"380503331111",
		"380503332222",
		"380503333333",
		"380503334444",
		"380503335555"
	};
	char Names[5][20]{
		"Lola",
		"Kurochka",
		"Sudakova",
		"Mosin",
		"Cerepkov"
	};

	Start(Numbers, Names, N);
	notebook.Print(notebook.GetRoot());
	cout << "\n\t\tДобавление телефона\n";
	Add();
	notebook.Print(notebook.GetRoot());
	cout << "\n\t\tПоиск телефона по номеру\n";
	SearchNew();
	cout << "\n\t\tПоиск телефона по имени\n";
	SearchNewName();
	cout << "\n\t\tУдалить номер телефона из книги по номеру\n";
	DeleteTelephone();
	notebook.Print(notebook.GetRoot());
	cout << "\n\t\tУдалить номер телефона из книги по фамилии абонента\n";
	DeleteTelephoneName();
	notebook.Print(notebook.GetRoot());
	cout << "\n\t\tИзменить номер телефона по номеру\n";
	Change();
	notebook.Print(notebook.GetRoot());
	cout << "\n\t\tИзменить номер телефона по фамилии\n";
	ChangeName();
	notebook.Print(notebook.GetRoot());
}