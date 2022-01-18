#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Project10_1 {
public:
    void main()
    {
        srand(unsigned(time(NULL)));
        int array_A[10];
        int array_B[10];
        int* parray_A = array_A;
        int* parray_B = array_B;
        cout << "\nЗадание 1: Используя два указателя на массив целых чисел, скопировать один массив в другой.\n";
        cout << "Использовать в программе арифметику указателей для продвижения по массиву, а также\n";
        cout << "оператор разыменования.\n\n";
        for (int i = 0; i < 10; i++) {
            array_A[i] = rand() % 100;
        }
        cout << "Массив А" << endl;
        for (int i = 0; i < 10; i++) {
            cout << array_A[i] << " ";
        }
        for (int i = 0; i < 10; i++) {
            *parray_B = *parray_A;
            parray_A++;
            parray_B++;
        }
        cout << endl << "Массив B" << endl;
        for (int i = 0; i < 10; i++) {
            cout << array_B[i] << " ";
        }
    }
};
class Project10_2 {
public:
    void main()
    {
        srand(unsigned(time(NULL)));
        int array_A[10];
        int* parray_A = array_A;
        cout << "\nЗадание 2: Используя указатель на массив целых чисел, изменить порядок следования элементов массива \n";
        cout << "на противоположный.Использовать в программе арифметику указателей для продвижения по массиву, а также\n";
        cout << "оператор разыменования.\n\n";

        for (int i = 0; i < 10; i++) {
            array_A[i] = rand() % 100;
        }
        cout << "Массив А" << endl;
        for (int i = 0; i < 10; i++) {
            cout << array_A[i] << " ";
        }
        int j = 9;
        int temp;
        for (int i = 0; i < 5; i++) {
            temp = *parray_A++;
            array_A[i] = array_A[j];
            array_A[j] = temp;
            j--;
        }
        cout << endl << "Массив B" << endl;
        for (int i = 0; i < 10; i++) {
            cout << array_A[i] << " ";
        }
    }
};
class Project10_3 {
public:
    void main()
    {
        srand(unsigned(time(NULL)));
        int array_A[10];
        int array_B[10];
        int* parray_A = array_A;
        int* parray_B = array_B;
        cout << "\nЗадание 3: Используя два указателя на массивы целых чисел, скопировать один массив в другой так, чтобы\n";
        cout << " во втором массиве элементы находились в обратном порядке.\n";
        cout << "Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.\n\n";


        for (int i = 0; i < 10; i++) {
            array_A[i] = rand() % 100;
        }
        cout << "Массив А" << endl;
        for (int i = 0; i < 10; i++) {
            cout << array_A[i] << " ";
        }
        for (int i = 9; i >= 0; i--) {
            *(parray_B + i) = *parray_A++;
        }
        cout << endl << "Массив B" << endl;
        for (int i = 0; i < 10; i++) {
            cout << array_B[i] << " ";
        }
    }
};
class Project10_4 {
public:
    void main()
    {
        srand(unsigned(time(NULL)));
        int a, b;
        int* pa;
        int* pb;
        cout << "\nЗадание 4: Используя указатели и оператор разыменования, определить наибольшее из двух чисел.\n\n";
        a = rand() % 100;
        b = rand() % 100;
        pa = &a;
        pb = &b;

        cout << "Наибольшее из двух чисел: " << a << " и " << b << " - " << (*pa > *pb ? *pa : *pb);
    }
};
class Project10_5 {
public:
    void main()
    {
        int a;
        int* pa;
        cout << "\nЗадание 5: Используя указатели и оператор разыменования, определить знак числа, введённого с клавиатуры. \n\n";
        for (;;) {
            cout << "Для выхода из программы введите 0\n";
            cout << "Введите число ";
            cin >> a;
            pa = &a;
            if (*pa > 0) {
                cout << "Знак числа +\n";
            }
            else if (*pa == 0) {
                break;
            }
            else if (*pa < 0) {
                cout << "Знак числа -\n";
            }
        }
    }
};
class Project10_6 {
public:
    void main()
    {
        int x = 7, y = 9, temp;
        int* px = &x;
        int* py = &y;
        cout << "\nЗадание 6: Используя указатели и оператор разыменования, обменять местами значения двух переменных. \n\n";
        cout << "Переменные: x = " << x << ", y = " << y << endl;
        temp = *px;
        *px = *py;
        *py = temp;
        cout << "Переменные: x = " << x << ", y = " << y << endl;
    }
};
class Project10_7 {
public:
    void main()
    {
        double a, b, c;
        char d;
        double* pa = &a;
        double* pb = &b;
        double* pc = &c;
        char* pd = &d;
        cout << "\nЗадание 7: Написать примитивный калькулятор, пользуясь только указателями. \n\n";
        cout << "Введите уровнение и нажмите энтер\n";
        cin >> *pa;
        cin >> *pd;
        cin >> *pb;
        if (*pd == '+') *pc = *pa + *pb;
        else if (*pd == '-') *pc = *pa - *pb;
        else if (*pd == '/') *pc = *pa / *pb;
        else if (*pd == '*') *pc = *pa * *pb;
        cout << *pa << *pd << *pb << " = " << *pc << endl;
    }
};
class Project10_8 {
public:
    void main()
    {
        srand(unsigned(time(NULL)));
        int sum = 0;
        int const size = 10;
        int array[size];
        int* parray = array;
        int* psum = &sum;
        cout << "\nЗадание 8: Используя указатель на массив целых чисел, посчитать сумму элементов массива.Использовать\n";
        cout << " в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.\n\n";
        for (int i = 0; i < size; i++) {
            array[i] = rand() % 100;
        }
        cout << "Одномерный массив" << endl;
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        for (int i = 0; i < size; i++) {
            *psum += *parray++;
        }
        cout << endl << "Сумма элементов массива = " << *psum << endl;
    }
};