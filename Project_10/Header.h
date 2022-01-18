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
        cout << "\n������� 1: ��������� ��� ��������� �� ������ ����� �����, ����������� ���� ������ � ������.\n";
        cout << "������������ � ��������� ���������� ���������� ��� ����������� �� �������, � �����\n";
        cout << "�������� �������������.\n\n";
        for (int i = 0; i < 10; i++) {
            array_A[i] = rand() % 100;
        }
        cout << "������ �" << endl;
        for (int i = 0; i < 10; i++) {
            cout << array_A[i] << " ";
        }
        for (int i = 0; i < 10; i++) {
            *parray_B = *parray_A;
            parray_A++;
            parray_B++;
        }
        cout << endl << "������ B" << endl;
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
        cout << "\n������� 2: ��������� ��������� �� ������ ����� �����, �������� ������� ���������� ��������� ������� \n";
        cout << "�� ���������������.������������ � ��������� ���������� ���������� ��� ����������� �� �������, � �����\n";
        cout << "�������� �������������.\n\n";

        for (int i = 0; i < 10; i++) {
            array_A[i] = rand() % 100;
        }
        cout << "������ �" << endl;
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
        cout << endl << "������ B" << endl;
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
        cout << "\n������� 3: ��������� ��� ��������� �� ������� ����� �����, ����������� ���� ������ � ������ ���, �����\n";
        cout << " �� ������ ������� �������� ���������� � �������� �������.\n";
        cout << "������������ � ��������� ���������� ���������� ��� ����������� �� �������, � ����� �������� �������������.\n\n";


        for (int i = 0; i < 10; i++) {
            array_A[i] = rand() % 100;
        }
        cout << "������ �" << endl;
        for (int i = 0; i < 10; i++) {
            cout << array_A[i] << " ";
        }
        for (int i = 9; i >= 0; i--) {
            *(parray_B + i) = *parray_A++;
        }
        cout << endl << "������ B" << endl;
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
        cout << "\n������� 4: ��������� ��������� � �������� �������������, ���������� ���������� �� ���� �����.\n\n";
        a = rand() % 100;
        b = rand() % 100;
        pa = &a;
        pb = &b;

        cout << "���������� �� ���� �����: " << a << " � " << b << " - " << (*pa > *pb ? *pa : *pb);
    }
};
class Project10_5 {
public:
    void main()
    {
        int a;
        int* pa;
        cout << "\n������� 5: ��������� ��������� � �������� �������������, ���������� ���� �����, ��������� � ����������. \n\n";
        for (;;) {
            cout << "��� ������ �� ��������� ������� 0\n";
            cout << "������� ����� ";
            cin >> a;
            pa = &a;
            if (*pa > 0) {
                cout << "���� ����� +\n";
            }
            else if (*pa == 0) {
                break;
            }
            else if (*pa < 0) {
                cout << "���� ����� -\n";
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
        cout << "\n������� 6: ��������� ��������� � �������� �������������, �������� ������� �������� ���� ����������. \n\n";
        cout << "����������: x = " << x << ", y = " << y << endl;
        temp = *px;
        *px = *py;
        *py = temp;
        cout << "����������: x = " << x << ", y = " << y << endl;
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
        cout << "\n������� 7: �������� ����������� �����������, ��������� ������ �����������. \n\n";
        cout << "������� ��������� � ������� �����\n";
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
        cout << "\n������� 8: ��������� ��������� �� ������ ����� �����, ��������� ����� ��������� �������.������������\n";
        cout << " � ��������� ���������� ���������� ��� ����������� �� �������, � ����� �������� �������������.\n\n";
        for (int i = 0; i < size; i++) {
            array[i] = rand() % 100;
        }
        cout << "���������� ������" << endl;
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        for (int i = 0; i < size; i++) {
            *psum += *parray++;
        }
        cout << endl << "����� ��������� ������� = " << *psum << endl;
    }
};