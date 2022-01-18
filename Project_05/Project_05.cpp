﻿#include <iostream>
#include <ctime>
using namespace std;
int main() {
    setlocale(LC_ALL, "");
    srand(unsigned(time(NULL)));

    cout << "\nЗадание 1:Напишите программу, которая создает двухмерный массив и заполняет его по следующему";
    cout << "\nпринципу: пользователь вводит число(например, 3) первый элемент массива принимает";
    cout << "\nзначение этого числа, последующий элемент массива принимает значение этого числа";
    cout << "\nумноженного на 2 (т.е. 6 для нашего примера), третий элемент массива предыдущий элемент,";
    cout << "\nумноженный на 2 (т.е. 6 * 2 = 12 для нашего примера).Созданный массив вывести на экран.\n";
    int a_1;
    int const size_1 = 2;
    int const size_1_1 = 10;
    int arr_1[size_1][size_1_1];
    for (;;) {
        // Реализация повтора задания или выхода из него
        cout << endl << "Выход из задания - 0, продолжить задание - 1" << endl;
        char A;
        cin >> A;
        if (A == '0' or A == '1') {
            if (A == '0')break;
        }
        else continue;
        //Создание двумерного массива
        for (int i_1 = 0; i_1 < size_1; i_1++) {
            cout << "Введите первый элемент массива N " << i_1 + 1 << "\n";
            cin >> a_1;
            for (int f_1 = 0; f_1 < size_1_1; f_1++) {
                arr_1[i_1][f_1] = a_1;
                //Формула записи чисел в двумерный массив
                a_1 *= 2;
            }
        }
        cout << "Двумерный массив задания N1" << endl;
        //Вывод двумерного массива arr_1 на экран
        for (int f_1 = 0; f_1 < size_1; f_1++) {
            for (int i_1 = 0; i_1 < size_1_1; i_1++) {
                cout << arr_1[f_1][i_1] << " ";
            }cout << endl;
        }
    }
    cout << "\nЗадание 2:Напишите программу, которая создает двухмерный массив и заполняет его по следующему";
    cout << "\nпринципу : пользователь вводит число(например, 3) первый элемент массива принимает";
    cout << "\nзначение этого числа, последующий элемент массива принимает значение этого числа + 1 (т.е. 4";
    cout << "\nдля нашего примера), третий элемент массива предыдущий элемент + 1 (т.е. 5 для нашего";
    cout << "\nпримера).Созданный массив вывести на экран.\n";
    int a_2;
    int const size_2 = 2;
    int const size_2_1 = 10;
    int arr_2[size_2][size_2_1];
    for (;;) {
        // Реализация повтора задания или выхода из него
        cout << endl << "Выход из задания - 0, продолжить задание - 1" << endl;
        char A;
        cin >> A;
        if (A == '0' or A == '1') {
            if (A == '0')break;
        }
        else continue;
        //Создание двумерного массива
        for (int i_2 = 0; i_2 < size_2; i_2++) {
            cout << "Введите первый элемент массива N " << i_2 + 1 << "\n";
            cin >> a_2;
            for (int f_2 = 0; f_2 < size_2_1; f_2++) {
                arr_2[i_2][f_2] = a_2;
                //Формула записи чисел в двумерный массив
                a_2 += 1;
            }
        }
        cout << "Двумерный массив задания N2" << endl;
        //Вывод двумерного массива arr_2 на экран
        for (int f_2 = 0; f_2 < size_2; f_2++) {
            for (int i_2 = 0; i_2 < size_2_1; i_2++) {
                cout << arr_2[f_2][i_2] << " ";
            }cout << endl;
        }
    }
    cout << "\nЗадание 3:Создайте двухмерный массив.Заполните его случайными числами и покажите на экран.";
    cout << "\nПользователь выбирает количество сдвигов и положение(влево, вправо, вверх, вниз).";
    cout << "\nВыполнить сдвиг массива и показать на экран полученный результат.Сдвиг циклический.\n\n";
    int a_3, b_3, c_3, d_3, e_3;
    bool h_3;
    int const size_3 = 2;
    int const size_3_1 = 10;
    int arr_3[size_3][size_3_1];
    int arr_3_1[size_3][size_3_1];
    // Создание двумерного массива arr_3 с рендом числами от 1 до 10
    for (int i_3 = 0; i_3 < size_3; i_3++) {
        for (int f_3 = 0; f_3 < size_3_1; f_3++) {
            arr_3[i_3][f_3] = rand() % 10 + 1;
        }
    }
    // Запуск бесконечного цикла с условием для пользователя: при вводе 0 с клавиатуры цикл прерывается
    for (;;) {
        cout << "Двумерный массив задания N3" << endl;
        //Вывод двумерного массива arr_3 на экран
        for (int f_3 = 0; f_3 < size_3; f_3++) {
            for (int i_3 = 0; i_3 < size_3_1; i_3++) {
                cout << arr_3[f_3][i_3] << " ";
            }cout << endl;
        }

        cout << "Введите направление сдвига массива\n";
        cout << "влево - 1, вправо - 2, вверх - 3, вниз - 4\n";
        cin >> b_3;
        cout << "Введите количество сдвигов масивов\n";
        // Запуск бесконечного цикла
        // Проверка числа которое введет пользователь,число небыло меньше 0 и больше чем строк или столбцов в двумерном массиве
        for (;;) {
            if (b_3 == 1 || b_3 == 2) {
                cin >> a_3;
                if (a_3 > size_3_1) {
                    cout << "Число превышает количество элементов массива.\n" << "Введите число от 0 до " << size_3_1 << endl;
                    continue;
                }
                else if (a_3 < 0) {
                    cout << "Неверное число.\n" << "Введите число от 0 до " << size_3_1 << endl;
                    continue;
                }
                else break;
            }
            else if (b_3 == 3 || b_3 == 4) {
                cin >> a_3;
                if (a_3 > size_3) {
                    cout << "Число превышает количество массивов.\n" << "Введите число от 0 до " << size_3 << endl;
                    continue;
                }
                else if (a_3 < 0) {
                    cout << "Неверное число.\n" << "Введите число от 0 до " << size_3 << endl;
                    continue;
                }
                else break;

            }
        }
        // Перезапись двумерного массива arr_3 в двумерный массив arr_3_1
        // Учитывая условия которые ввел пользователь
        for (int i_3 = 0; i_3 < size_3; i_3++) {
            for (int f_3 = 0; f_3 < size_3_1; f_3++) {
                if (b_3 == 1) {
                    c_3 = f_3;
                    d_3 = c_3 + a_3;
                    if (d_3 >= size_3_1) {
                        d_3 = c_3 + a_3 - size_3_1;
                    }
                    arr_3_1[i_3][f_3] = arr_3[i_3][d_3];
                }
                else if (b_3 == 2) {
                    c_3 = f_3;
                    d_3 = c_3 - a_3;
                    if (d_3 < 0) {
                        d_3 = c_3 - a_3 + size_3_1;
                    }
                    arr_3_1[i_3][f_3] = arr_3[i_3][d_3];
                }
                else if (b_3 == 3) {
                    c_3 = i_3;
                    d_3 = c_3 + a_3;
                    if (d_3 >= size_3) {
                        d_3 = c_3 + a_3 - size_3;
                    }
                    arr_3_1[i_3][f_3] = arr_3[d_3][f_3];
                }
                else if (b_3 == 4) {
                    c_3 = i_3;
                    d_3 = c_3 - a_3;
                    if (d_3 < 0) {
                        d_3 = c_3 - a_3 + size_3;
                    }
                    arr_3_1[i_3][f_3] = arr_3[d_3][f_3];
                }

            }
        }
        cout << "Двумерный массив задания N3" << endl;
        //Вывод двумерного массива arr_3_1 на экран
        for (int f_3 = 0; f_3 < size_3; f_3++) {
            for (int i_3 = 0; i_3 < size_3_1; i_3++) {
                cout << arr_3_1[f_3][i_3] << " ";
            }cout << endl;
        }
        // Перезапись двумерного массива arr_3_1 в двумерный массив arr_3
        for (int i_3 = 0; i_3 < size_3; i_3++) {
            for (int f_3 = 0; f_3 < size_3_1; f_3++) {
                arr_3[i_3][f_3] = arr_3_1[i_3][f_3];
            }
        }
        // Реализация выхода из третьего задания с проверкой на введение пользователем числа и без использования return
        for (;;) {
            cout << endl << "Выход из задания - 0, продолжить задание - 1" << endl;
            cin >> e_3;
            if (e_3 == 0) {
                h_3 = true;
                break;
            }
            else if (e_3 == 1) {
                h_3 = false;
                break;
            }
            else cout << "Ошибка\n";
        }
        if (h_3 == true) break;
        else continue;

    }

    cout << "\nЗадание 4: В двумерном массиве целых чисел посчитать:";
    cout << "\nСумму всех элементов массива";
    cout << "\nСреднее арифметическое всех элементов массива";
    cout << "\nМинимальный элемент";
    cout << "\nМаксимальный элемент\n";
    int sum_4, sr_4, min_4, max_4, sum_4_1, sr_4_1, min_4_1, max_4_1;
    int const size_4 = 2;
    int const size_4_1 = 10;
    int arr_4[size_4][size_4_1];
    for (;;) {
        // Реализация повтора задания или выхода из него
        cout << endl << "Выход из задания - 0, продолжить задание - 1" << endl;
        char A;
        cin >> A;
        if (A == '0' or A == '1') {
            if (A == '0')break;
        }
        else continue;
        // Создание двумерного массива arr_4 с рендом числами от 1 до 100
        for (int i_4 = 0; i_4 < size_4; i_4++) {
            for (int f_4 = 0; f_4 < size_4_1; f_4++) {
                arr_4[i_4][f_4] = rand() % 100 + 1;
            }
        }
        min_4 = arr_4[0][0];
        max_4 = 0;
        sum_4 = 0;
        cout << "Двумерный массив задания N4" << endl;
        //Вывод двумерного массива arr_4 на экран
        for (int f_4 = 0; f_4 < size_4; f_4++) {
            for (int i_4 = 0; i_4 < size_4_1; i_4++) {
                cout << arr_4[f_4][i_4] << " ";
            }cout << endl;
        }
        //Вывод первого и второго массивов двумерного массива arr_4 на экран поочередно
        //Выводит ответы на действия произведенные с элементами массивов поочередно
        //Сначало первый массив двумерного массива потом второй массив двумерного массива затем всего двумерного массива
        for (int f_4 = 0; f_4 < size_4; f_4++) {
            cout << endl << "Массив N " << f_4 + 1 << " двумерного массива" << endl;
            min_4_1 = arr_4[f_4][0];
            max_4_1 = 0;
            sum_4_1 = 0;
            for (int i_4 = 0; i_4 < size_4_1; i_4++) {
                sum_4 += arr_4[f_4][i_4];
                sum_4_1 += arr_4[f_4][i_4];
                cout << arr_4[f_4][i_4] << " ";
                if (min_4 > arr_4[f_4][i_4]) {
                    min_4 = arr_4[f_4][i_4];
                }
                if (max_4 < arr_4[f_4][i_4]) {
                    max_4 = arr_4[f_4][i_4];
                }
                if (min_4_1 > arr_4[f_4][i_4]) {
                    min_4_1 = arr_4[f_4][i_4];
                }
                if (max_4_1 < arr_4[f_4][i_4]) {
                    max_4_1 = arr_4[f_4][i_4];
                }
            }cout << endl << endl;
            cout << "Сумма всех чисел массива = " << sum_4_1 << endl;
            sr_4_1 = sum_4_1 / size_4_1;
            cout << "Среднее арифметическое всех элементов массива = " << sr_4_1 << endl;
            cout << "Минимальный элемент массива = " << min_4_1 << endl;
            cout << "Максимальный элемент массива = " << max_4_1 << endl;
        }
        cout << endl << "Сумма всех чисел двухмерного массива = " << sum_4 << endl;
        sr_4 = sum_4 / (size_4 * size_4_1);
        cout << "Среднее арифметическое всех элементов двухмерного массива = " << sr_4 << endl;
        cout << "Минимальный элемент двухмерного массива = " << min_4 << endl;
        cout << "Максимальный элемент двухмерного массива = " << max_4 << endl;
    }
    cout << "\nЗадание 5: В двумерном массиве целых чисел посчитать сумму элементов :";
    cout << "\n в каждой строке; в каждом столбце; одновременно по всем строкам и всем столбцам.\n";
    int sum_5, sum_5_1, sum_5_2 = 0;
    int const size_5 = 3;
    int const size_5_1 = 4;
    int arr_5[size_5][size_5_1];
    for (;;) {
        // Реализация повтора задания или выхода из него
        cout << endl << "Выход из задания - 0, продолжить задание - 1" << endl;
        char A;
        cin >> A;
        if (A == '0' or A == '1') {
            if (A == '0')break;
        }
        else continue;
        // Создание двумерного массива arr_5 с рендом числами от 1 до 10
        for (int i_5 = 0; i_5 < size_5; i_5++) {
            for (int f_5 = 0; f_5 < size_5_1; f_5++) {
                arr_5[i_5][f_5] = rand() % 10 + 1;
            }
        }
        //Подсчет суммы элементов в строках массива
        for (int f_5 = 0; f_5 < size_5; f_5++) {
            sum_5 = 0;
            for (int i_5 = 0; i_5 < size_5_1; i_5++) {
                sum_5 += arr_5[f_5][i_5];
                cout << arr_5[f_5][i_5] << "\t";
            }
            cout << "|\t" << sum_5 << endl;

        }
        cout << "------------------------------------------" << endl;
        //Подсчет суммы элементов в столбцах трехмерного массива
        for (int f_5 = 0; f_5 < size_5_1; f_5++) {
            sum_5_1 = 0;
            for (int i_5 = 0; i_5 < size_5; i_5++) {
                sum_5_1 += arr_5[i_5][f_5];
            }
            cout << sum_5_1 << "\t";
            sum_5_2 += sum_5_1;
        }
        cout << "|\t" << sum_5_2 << endl;
    }
    cout << "\nЗадание 6: Напишите программу, в которой объявляется массив размером 5х10 и массив размером 5х5.";
    cout << "\nПервый массив заполняется случайными числами, в диапазоне от 0 до 50. Второй массив";
    cout << "\nзаполняется по следующему принципу : первый элемент второго массива равен сумме первого и";
    cout << "\nвторого элемента первого массива, второй элемент второго массива равен сумму третьего и";
    cout << "\nчетвертого элемента первого массива.\n";

    int a_6 = 0;
    int const size_6 = 5;
    int const size_6_1 = 10;
    int const size_6_2 = 5;
    int arr_6[size_6][size_6_1];
    int arr_6_1[size_6][size_6_2];
    for (;;) {
        // Реализация повтора задания или выхода из него
        cout << endl << "Выход из задания - 0, продолжить задание - 1" << endl;
        char A;
        cin >> A;
        if (A == '0' or A == '1') {
            if (A == '0')break;
        }
        else continue;
        // Создание пятимерного массива arr_6 с рендом числами от 1 до 10
        for (int i_6 = 0; i_6 < size_6; i_6++) {
            for (int f_6 = 0; f_6 < size_6_1; f_6++) {
                arr_6[i_6][f_6] = rand() % 10 + 1;
            }
        }
        cout << endl << "Пятимерный массив с 10 строками задания N6" << endl;
        //Вывод пятимерного массива arr_6 на экран
        for (int f_6 = 0; f_6 < size_6; f_6++) {
            for (int i_6 = 0; i_6 < size_6_1; i_6++) {
                cout << arr_6[f_6][i_6] << " ";
            }cout << endl;
        }
        //Перезапись пятимерного массива arr_6 с 10 строками в пятимерный массив arr_6_1 с 5 строками через формулу
        for (int f_6 = 0; f_6 < size_6; f_6++) {
            for (int i_6 = 0; i_6 < size_6_2; i_6++) {
                a_6 = i_6 * 2;
                arr_6_1[f_6][i_6] = arr_6[f_6][a_6] + arr_6[f_6][a_6 + 1];
            }
        }
        cout << endl << "Пятимерный массив с 5 строками задания N6" << endl;
        //Вывод пятимерного массива arr_6_1 на экран
        for (int f_6 = 0; f_6 < size_6; f_6++) {
            for (int i_6 = 0; i_6 < size_6_2; i_6++) {
                cout << arr_6_1[f_6][i_6] << " ";
            }cout << endl;
        }
    }
}