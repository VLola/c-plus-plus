#pragma once
#include <iostream>
using namespace std;
struct Element
{
	//Данные
	char data;
	//Адрес следующего элемента списка
	Element* Next;
};
//Односвязный список
class List
{
	//Адрес головного элемента списка
	Element* Head;
	//Адрес концевого элемента списка
	Element* Tail;
	//Количество элементов списка
	int Count;
public:
	//Конструктор
	List();
	//Деструктор
	~List();
	//Добавление элемента в список
	//(Новый элемент становится последним)
	void Add(char data);
	//Удаление элемента списка
	//(Удаляется головной элемент)
	void Del();
	//Удаление всего списка
	void DelAll();
	//Распечатка содержимого списка
	//(Распечатка начинается с головного элемента)
	void Print();
	//Получение количества элементов,
	//находящихся в списке
	int GetCount();
	//вставка элемента в заданную позицию
	void Paste(int, char);
	//Удаление элемента по заданной позиции
	void DelElement(int);
	//Поиск заданного элемента
	int SearchElement(char);
};
int List::SearchElement(char n) {
	Element* temp = Head;
	int b;
	int* c = &b;
	GetCount();
	for (int a = 0; a < Count; a++) {
		if (temp->data == n) {
			b = a;
			return b;
		}
		temp = temp->Next;
	}
	if (*c == NULL)return NULL;
}
void List::Paste(int n, char m) {
	Element* temp = Head;

	for (int a = 0; a <= n; a++)
	{
		//Переходим на следующий элемент
		temp = temp->Next;
		//По заданой позиции присваиваем новый елемент
		if (a == n - 1)temp->data = m;
	}
}
void List::DelElement(int n) {
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

	//перебрасываем голову на следующий элемент
	Head = Head->Next;
	//удаляем бывший головной элемент
	delete temp;
}
List::List()
{
	//Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}
List::~List()
{
	//Вызов функции удаления
	DelAll();
}
int List::GetCount()
{
	int a = 0;
	//запоминаем адрес головного элемента
	Element* temp = Head;
	//Пока еще есть элементы
	while (temp != 0)
	{
		//Переходим на следующий элемент
		temp = temp->Next;
		a++;
	}
	//Возвращаем количество элементов
	Count = a;
	return Count;
}
void List::Add(char data)
{
	//создание нового элемента
	Element* temp = new Element;
	//заполнение данными
	temp->data = data;
	//следующий элемент отсутствует
	temp->Next = NULL;
	//новый элемент становится последним элементом списка
	//если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	//новый элемент становится единственным
	//если он первый добавленный
	else {
		Head = Tail = temp;
	}
}
void List::Del()
{
	//запоминаем адрес головного элемента
	Element* temp = Head;
	//перебрасываем голову на следующий элемент
	Head = Head->Next;
	//удаляем бывший головной элемент
	delete temp;
}
void List::DelAll()
{
	//Пока еще есть элементы
	while (Head != 0)
		//Удаляем элементы по одному
		Del();
}
void List::Print()
{
	//запоминаем адрес головного элемента
	Element* temp = Head;
	//Пока еще есть элементы
	while (temp != 0)
	{
		//Выводим данные
		cout << temp->data << " ";
		//Переходим на следующий элемент
		temp = temp->Next;
	}
	cout << "\n\n";
}
class Project15_1 {
public:
	void main()
	{
		cout << "Задание 1: Добавить в класс << Односвязный список >> следующие функции : вставка элемента в заданную позицию,\n";
		cout << "удаление элемента по заданной позиции, поиск заданного элемента(функция возвращает\n";
		cout << "позицию найденного элемента в случае успеха или NULL в случае неудачи).\n";

		//Создаем объект класса List
		List lst;
		//Тестовая строка
		char s[] = "123456789\n";
		//Выводим строку
		cout << s << "\n\n";
		//Определяем длину строки
		int len = strlen(s);
		//Загоняем строку в список
		for (int i = 0; i < len; i++)
			lst.Add(s[i]);
		//Распечатываем содержимое списка
		lst.Print();
		//Вставляем элемент в заданную позицию
		lst.Paste(5, '8');
		//Распечатываем содержимое списка
		lst.Print();
		//Удаляем элемент по заданной позиции
		lst.DelElement(3);
		//Распечатываем содержимое списка
		lst.Print();
		//Поиск заданного элемента
		cout << lst.SearchElement('6');
	}
};
template <typename T>
struct Elem
{
	T data;
	Elem* next, * prev;
};
template <typename T>
class Array
{
	Elem<T>* Head, * Tail;
	int Size;
	int Grow;
public:
	Array();
	Array(const Array&);
	~Array();
	void InsertAt(int, T);
	void RemoveAt(int);
	void GetData();
	void Append(const Array&, const Array&);
	void Add(T);
	void SetAt(int, T);
	int GetAt(int pos);
	void RemoveAll();
	void FreeExtra();
	void IsEmpty();
	int GetUpperBound();
	int GetSize();
	int SetSize(int, int);
	void AddTail(T);
	void AddHead(T);
	void Print();
	Array& operator = (const Array&);
};

template <typename T>
void Array<T>::InsertAt(int index, T element)
{
	SetSize(Size + 1, 1);
	Elem<T>* temp = Head;
	int a, b;
	for (int i = 0; i <= Size; i++) {
		if (i == index) {
			a = temp->data;
			b = a;
			SetAt(i, element);
			temp = temp->next;
		}
		else if (i < index) {
			SetAt(i, temp->data);
			temp = temp->next;
		}
		else if (i > index && i % 2 == 0) {
			if (i == Size - 1) {
				SetAt(i, a);
			}
			else {
				b = temp->data;
				SetAt(i, a);
				temp = temp->next;
			}

		}
		else if (i > index && i % 2 != 0) {
			if (i == Size - 1) {
				SetAt(i, b);
			}
			else {
				a = temp->data;
				SetAt(i, b);
				temp = temp->next;
			}

		}


	}

}
template <typename T>
void Array<T>::RemoveAt(int n)
{
	if (n < 1 || n > Size)
	{
		cout << "Incorrect position !!!\n";
		return;
	}
	int i = 1;
	Elem<T>* Del = Head;
	while (i < n)
	{
		Del = Del->next;
		i++;
	}
	Elem<T>* PrevDel = Del->prev;
	Elem<T>* AfterDel = Del->next;
	if (PrevDel != 0 && Size != 1)
		PrevDel->next = AfterDel;
	if (AfterDel != 0 && Size != 1)
		AfterDel->prev = PrevDel;
	if (n == 1)
		Head = AfterDel;
	if (n == Size)
		Tail = PrevDel;
	delete Del;
	Size--;
}
template <typename T>
void Array<T>::GetData()
{
	Elem<T>* temp = Head;
	while (temp != 0)
	{
		cout << temp << " " << temp->data << endl;
		temp = temp->next;
	}
}
template <typename T>
void Array<T>::Append(const Array& arr1, const Array& arr2)
{

	Elem<T>* temp1 = arr1.Head;
	Elem<T>* temp2 = arr2.Head;
	while (temp1 != 0) {
		T a, b;
		a = temp1->data;
		b = temp2->data;
		temp1 = temp1->next;
		temp2 = temp2->next;
		AddTail(a + b);

	}
}
template <typename T>
void Array<T>::Add(T n)
{
	AddTail(n);
	if (Grow > 1) {
		for (int a = 1; a < Grow; a++)AddTail(NULL);
	}
}
template <typename T>
void Array<T>::SetAt(int index, T element)
{
	Elem<T>* temp = Head;
	int a = 0;
	if (index >= 0 || index < Size) {
		while (temp != 0)
		{
			if (a == index)temp->data = element;
			a++;
			temp = temp->next;
		}
	}
}
template <typename T>
int Array<T>::GetAt(int index)
{
	Elem<T>* temp = Head;
	int a = 0;
	if (index >= 0 || index < Size) {
		while (temp != 0)
		{
			if (a == index)return temp->data;
			a++;
			temp = temp->next;
		}
	}
}
template <typename T>
void Array<T>::RemoveAll()
{
	while (Size != 0)
		RemoveAt(1);
}
template <typename T>
void Array<T>::FreeExtra()
{
	int a = GetUpperBound();
	for (int i = Size; i > a + 1; i--) {
		RemoveAt(i);
	}
}
template <typename T>
void Array<T>::IsEmpty()
{
	Elem<T>* temp = Head;
	int a = 0;

	for (int i = 0; i < Size; i++) {
		if (temp->data != NULL) {
			a = i;
		}
		temp = temp->next;
	}

	if (a != NULL)cout << "Массив не пуст\n";
	else cout << "Массив пуст\n";
}
template <typename T>
int Array<T>::GetUpperBound()
{
	Elem<T>* temp = Head;
	int a = 0;

	for (int i = 0; i < Size; i++) {
		if (temp->data != NULL) {
			a = i;
		}
		temp = temp->next;
	}

	return a;
}
template <typename T>
int Array<T>::SetSize(int size, int grow)
{
	int set_size;
	Grow = grow;
	if (size < Size) {
		set_size = Size - (Size - size) * Grow;
		if (set_size >= Size) {
			cout << "Error";
			return 0;
		}
		for (int i = Size; i > set_size; i--)RemoveAt(i);
	}
	else if (size > Size) {
		set_size = Size + (size - Size) * Grow;
		for (int i = Size; i < set_size; i++)AddTail(NULL);
	}
}
template <typename T>
Array<T>::Array()
{
	Head = Tail = 0;
	Size = 0;
	Grow = 1;
}
template <typename T>
Array<T>::Array(const Array& L)
{
	Head = Tail = 0;
	Size = 0;
	Grow = 1;
	Elem<T>* temp = L.Head;
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}
template <typename T>
Array<T>::~Array()
{
	RemoveAll();
}
template <typename T>
void Array<T>::AddHead(T n)
{
	Elem<T>* temp = new Elem<T>;
	temp->prev = 0;
	temp->data = n;
	temp->next = Head;
	if (Head != 0)
		Head->prev = temp;
	if (Size == 0)
		Head = Tail = temp;
	else
		Head = temp;
	Size++;
}
template <typename T>
void Array<T>::AddTail(T n)
{
	Elem<T>* temp = new Elem<T>;
	temp->next = 0;
	temp->data = n;
	temp->prev = Tail;
	if (Tail != 0)
		Tail->next = temp;
	if (Size == 0)
		Head = Tail = temp;
	else
		Tail = temp;
	Size++;
}
template <typename T>
void Array<T>::Print()
{
	if (Size != 0)
	{
		Elem<T>* temp = Head;
		while (temp != 0)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}
template <typename T>
int Array<T>::GetSize()
{
	return Size;
}
template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& L)
{
	if (this == &L)
		return *this;
	this->~Array();
	Elem<T>* temp = L.Head;
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
	return *this;
}
class Project15_2 {
public:
	void main() {
		Array <int> L;
		const int n = 10;
		int a[n] = { 1,2,3,4,5,6,7,8,9,10 };

		Array  <int> array1, array2, array3;
		for (int i = 0; i < 10; i++)
		{
			array1.AddTail(a[i]);
		}
		cout << "Распечатка массива:\n";
		array1.Print();
		//Копируем массив
		array2 = array1;
		cout << "Распечатка копии array2:\n";
		array2.Print();
		cout << "Распечатка размера массива array2:\n" << array2.GetSize() << endl;
		//Устанавливаем размер массива
		cout << "Устанавливаем размер массива array2(8,2)\n";
		array2.SetSize(8, 2);
		cout << "Распечатка размера массива array2\n" << array2.GetSize() << endl;
		cout << "Распечатка массива array2:\n";
		array2.Print();
		//Устанавливаем размер массива
		cout << "Устанавливаем размер массива array2(12,2)\n";
		array2.SetSize(12, 2);
		cout << "Распечатка размера массива array2\n" << array2.GetSize() << endl;
		cout << "Распечатка массива array2:\n";
		array2.Print();
		//Вывод последнего допустимого индекса в массиве
		cout << "Последний допустимый индекс в массиве array2:\n" << array2.GetUpperBound() << "\n";
		//Проверка массива
		array2.IsEmpty();
		//Удаляем лишнию память
		array2.FreeExtra();
		array2.Print();
		cout << endl << "Распечатка 2-го и 4-го элементов массива";
		cout << endl << array2.GetAt(2);
		cout << endl << array2.GetAt(4) << endl;
		cout << "Установка нового значения на индекс 2 array2:\n";
		array2.SetAt(2, 9);
		cout << "Распечатка массива array2:\n";
		array2.Print();
		cout << "Добавление элемента в массив array2:\n";
		array2.Add(7);
		cout << "Распечатка массива array2:\n";
		array2.Print();
		cout << "Копируем массив array1 в array2";
		array2 = array1;
		cout << "Распечатка массива array1:\n";
		array1.Print();
		cout << "Распечатка массива array2:\n";
		array2.Print();
		cout << "Сложение массивов array1 и array2";
		array3.Append(array1, array2);
		cout << "Распечатка массива array3:\n";
		array3.Print();
		cout << "Получение адреса массива с данными array3:\n";
		array3.GetData();
		cout << "Вставка элемента в позицию 5 array3:\n";
		array3.InsertAt(5, 11);
		cout << "Распечатка массива array3:\n";
		array3.Print();
		cout << "Удаление элемента с заданной позиции массива array3:\n";
		array3.RemoveAt(8);
		cout << "Распечатка массива array3:\n";
		array3.Print();
	}
};