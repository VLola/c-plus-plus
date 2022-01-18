#include <iostream>
#include <ctime>
using namespace std;
// глобальные переменные
int days;
bool high, go, out;
//Создание функции
void Task1(int a, int b) {
    int c = 1;
    for (int i = 0; i < b; i++) {
        c *= a;
    }
    if (a == 0 && b == 0) {
        cout << "не определено" << endl;
    }
    else cout << c << endl;
}
//Создание функции
void Task2(int a, int b) {
    int c = 0;
    int min = a < b ? a : b;
    int max = a > b ? a : b;
    cout << "Сумма всех чисел из диапазона между ними " << min << " и " << max << " = ";
    for (int i = min + 1; i < max; i++) {
        c += i;
    }cout << c << endl;
}
//Создание функции
void Task3(int a, int b) {
    int min = a < b ? a : b;
    int max = a > b ? a : b;
    cout << "Интервал чисел " << min << " и " << max << "\n";
    cout << "Совершенные числа в интервале:" << "\n";
    for (int i = min; i <= max; i++) {
        int sum = 0;
        for (int f = 1; f < i; f++) {
            if (i % f == 0) {
                sum += f;
            }
        }
        if (sum == i) {
            cout << i << endl;
        }
    }
}
//Прототип функции
void Task4(char a);
//Создание функции
void Task5(int a) {
    int b = a % 10;
    int c = (a % 100 - b) / 10;
    int d = (a % 1000 - b - c) / 100;
    int e = (a % 10000 - b - c - d) / 1000;
    int f = (a % 100000 - b - c - d - e) / 10000;
    int g = (a - b - c - d - e - f) / 100000;

    if (g + f + e == d + b + c) cout << "Счастливое число" << endl;
    else cout << "Несчастливое число" << endl;

}
//Прототипы функций
void Task6_1(int a);
void Task6_2(int a);
void Task6(int e, int f, int k, int h, int i, int j);
//Создание функции
void Task7(int arr[], int size) {
    int sum = 0;
    for (int f = 0; f < size; f++) {
        sum += arr[f];
    }cout << "Среднее арифметическое массива = " << sum / size << endl;
}
//Создание функции
void Task8(int arr[], int size) {
    int sum = 0, sum_1 = 0, sum_2 = 0;
    for (int f = 0; f < size; f++) {
        if (arr[f] > 0)sum++;
        else if (arr[f] < 0)sum_1++;
        else if (arr[f] == 0)sum_2++;
    }
    cout << "Положительных элементов массива = " << sum << endl;
    cout << "Отрицательных элементов массива = " << sum_1 << endl;
    cout << "Нулевых элементов массива = " << sum_2 << endl;
}
int main()
{
    setlocale(LC_ALL, "");
    srand(unsigned(time(NULL)));

    cout << "\nЗадание 1: Написать функцию, которая принимает два параметра : основание степени и показатель";
    cout << "\nстепени, и вычисляет степень числа на основе полученных данных.\n";
    int a_1, b_1;
    for (;;) {
        // Реализация повтора задания или выхода из него
        cout << endl << "Выход из задания - 0, продолжить задание - 1" << endl;
        char A;
        cin >> A;
        if (A == '0' or A == '1') {
            if (A == '0')break;
        }
        else continue;
        cout << endl;
        cout << "Введите число" << endl;
        cin >> a_1;
        cout << "Введите степень числа" << endl;
        cin >> b_1;
        cout << a_1 << " в степени " << b_1 << " = ";
        // Вызов функции и передача переменных
        Task1(a_1, b_1);
    }

    cout << "\nЗадание 2: Написать функцию, которая получает в качестве параметров 2 целых числа и возвращает сумму";
    cout << "\nчисел из диапазона между ними.\n";
    int a_2, b_2;
    for (;;) {
        // Реализация повтора задания или выхода из него
        cout << endl << "Выход из задания - 0, продолжить задание - 1" << endl;
        char A;
        cin >> A;
        if (A == '0' or A == '1') {
            if (A == '0')break;
        }
        else continue;
        cout << endl;
        cout << "Введите первое число" << endl;
        cin >> a_2;
        cout << "Введите второе число" << endl;
        cin >> b_2;
        // Вызов функции и передача переменных
        Task2(a_2, b_2);
    }
    cout << "\nЗадание 3: Число называется совершенным, если сумма всех его делителей равна ему самому.Напишите";
    cout << "\nфункцию поиска таких чисел во введенном интервале.\n";
    int a_3, b_3;
    for (;;) {
        // Реализация повтора задания или выхода из него
        cout << endl << "Выход из задания - 0, продолжить задание - 1" << endl;
        char A;
        cin >> A;
        if (A == '0' or A == '1') {
            if (A == '0')break;
        }
        else continue;
        cout << endl;
        cout << "Введите первое число" << endl;
        cin >> a_3;
        cout << "Введите второе число" << endl;
        cin >> b_3;
        // Вызов функции и передача переменных
        Task3(a_3, b_3);
    }

    cout << "\nЗадание 4: Написать функцию, выводящую на экран переданную ей игральную карту.\n";
    char a_4;
    bool b_4 = false;
    char card[13] = { '2','3','4','5','6','7','8','9','0','J','D','K','T' };
    for (;;) {
        cout << endl << "Введите символ карты 2,3,4,5,6,7,8,9,0,J,D,K,T для выхода из задания введите 1" << endl;
        cin >> a_4;
        // Реализация выхода из задания
        if (a_4 == '1')break;
        //Проверка переменной после ввода с клавиатуры
        for (int i = 0; i < 13; i++) {
            if (a_4 == card[i]) {
                b_4 = true;
                break;
            }
            else b_4 = false;
        }
        if (b_4 != true) {
            cout << "Неверный символ" << endl;
            continue;
        }
        // Вызов функции и передача переменной
        Task4(a_4);
    }

    cout << "\nЗадание 5: Написать функцию, которая определяет, является ли «счастливым» шестизначное число.\n";
    int a_5;
    for (;;) {
        cout << endl << "Введите шестизначное число, для выхода из задания введите 0" << endl;
        cin >> a_5;
        // Реализация выхода из задания
        if (a_5 == 0)break;
        for (;;) {
            //Проверка переменной после ввода с клавиатуры
            if (a_5 > 99999 && a_5 <= 999999) {
                // Вызов функции и передача переменной
                Task5(a_5);
                break;
            }
            else {
                cout << "Некорректный ввод" << endl;
                break;
            }
        }
    }

    cout << "\nЗадание 6: Написать функцию, которая принимает две даты(т.е.функция принимает шесть параметров) и.";
    cout << "\nвычисляет разность в днях между этими датами.Для решения этой задачи необходимо также";
    cout << "\nнаписать функцию, которая определяет, является ли год високосным.\n";
    int a_6_1, b_6_1, c_6_1, a_6_2, b_6_2, c_6_2;

    for (;;) {
        for (;;) {
            cout << endl << "Введите год первой даты, для выхода из задания введите 0" << endl;
            cin >> a_6_1;
            //Проверка переменной после ввода с клавиатуры
            if (a_6_1 < 0) {
                cout << "Неправильно введен год!" << endl;
                continue;
            }
            // Реализация выхода из задания
            else if (a_6_1 == 0) {
                out = true;
                break;
            }
            cout << "Введите месяц первой даты" << endl;
            cin >> b_6_1;
            //Проверка переменной после ввода с клавиатуры
            if (b_6_1 <= 0 or b_6_1 > 12) {
                cout << "Неправильно введен месяц!" << endl;
                continue;
            }
            cout << "Введите число первой даты" << endl;
            cin >> c_6_1;
            //Проверка переменной после ввода с клавиатуры
            if (c_6_1 <= 0) {
                cout << "Неправильно введен день!" << endl;
                continue;
            }
            //Вызов функции. Проверка года на высокостность
            Task6_2(a_6_1);
            //Вызов функции. Проверка месяца на число дней
            Task6_1(b_6_1);
            //Проверка переменной на соответствие дней в месяце
            if (c_6_1 <= days) {
                go = true;
                break;
            }
            else {
                cout << "В этом месяце " << days << " дней(дня)!" << endl;
                go = false;
                break;
            }
        }
        if (out == true)break;
        if (go == false)continue;
        go = false;
        cout << "Вы ввели дату: " << a_6_1 << "." << b_6_1 << "." << c_6_1 << endl;
        for (;;) {
            cout << "Введите год второй даты" << endl;
            cin >> a_6_2;
            //Проверка переменной после ввода с клавиатуры
            if (a_6_2 < a_6_1) {
                cout << "Год второй даты не может быть меньше года первой даты" << endl;
                continue;
            }
            cout << "Введите месяц второй даты" << endl;
            cin >> b_6_2;
            //Проверка переменной после ввода с клавиатуры
            if (b_6_2 > 12 or b_6_2 < b_6_1) {
                cout << "Неправильно введен месяц!" << endl;
                continue;
            }
            cout << "Введите число второй даты" << endl;
            cin >> c_6_2;
            //Проверка переменной после ввода с клавиатуры
            if (c_6_2 <= 0) {
                cout << "Неправильно введен день!" << endl;
                continue;
            }
            //Проверка переменных на совпадение года даты
            if (b_6_1 == b_6_2) {
                if (c_6_2 < c_6_1) {
                    cout << "Число второй даты не может быть меньше чем число первой даты!" << endl;
                    continue;
                }
            }
            //Проверка года на высокостность
            Task6_2(a_6_2);
            //Проверка месяца на число дней
            Task6_1(b_6_2);
            if (c_6_2 <= days) {
                go = true;
                break;
            }
            else {
                cout << "В этом месяце " << days << " дней(дня)!" << endl;
                go = false;
                break;
            }
        }
        if (go == false)continue;
        // Вызов функции и передача переменных
        Task6(a_6_1, b_6_1, c_6_1, a_6_2, b_6_2, c_6_2);

    }

    cout << "\nЗадание 7: Написать функцию, определяющую среднее арифметическое элементов передаваемого ей массива.\n";

    int const size_7 = 10;
    int arr_7[size_7];
    for (;;) {
        // Реализация повтора задания или выхода из него
        cout << endl << "Выход из задания - 0, продолжить задание - 1" << endl;
        char A;
        cin >> A;
        if (A == '0' or A == '1') {
            if (A == '0')break;
        }
        else continue;
        cout << endl << "Созданный массив из рендомных чисел от 1 до 10" << endl;
        // Создание массива arr_7 с рендом числами от 1 до 10 и вывод его на экран
        for (int i_7 = 0; i_7 < size_7; i_7++) {
            arr_7[i_7] = rand() % 10 + 1;
            cout << arr_7[i_7] << " ";
        }cout << endl;
        Task7(arr_7, size_7);
    }

    cout << "\nЗадание 8: Написать функцию, определяющую количество положительных, отрицательных и нулевых";
    cout << "\nэлементов передаваемого ей массива.\n";

    int const size_8 = 10;
    int arr_8[size_8];
    for (;;) {
        // Реализация повтора задания или выхода из него
        cout << endl << "Выход из задания - 0, продолжить задание - 1" << endl;
        char A;
        cin >> A;
        if (A == '0' or A == '1') {
            if (A == '0')break;
        }
        else continue;
        cout << endl << "Созданный массив из рендомных чисел от -10 до 10" << endl;
        // Создание массива arr_8 с рендом числами от -10 до 10 и вывод его на экран
        for (int i_8 = 0; i_8 < size_8; i_8++) {
            arr_8[i_8] = rand() % 20 - 10;
            cout << arr_8[i_8] << " ";
        }cout << endl;
        Task8(arr_8, size_8);
    }
}

//Описание функции
void Task4(char a) {
    cout << " _____________\n";
    cout << "|             |\n";
    if (a == '0') {
        cout << "|  10         |\n";
    }
    else {
        cout << "|  " << a << "          |\n";
    }
    cout << "|             |\n";
    cout << "|             |\n";
    switch (a) {
    case '2':
        cout << "|    ****     |\n";
        cout << "|   **  **    |\n";
        cout << "|      **     |\n";
        cout << "|     **      |\n";
        cout << "|    *****    |\n";
        break;
    case '3':
        cout << "|    ****     |\n";
        cout << "|   *   **    |\n";
        cout << "|      **     |\n";
        cout << "|   *   **    |\n";
        cout << "|    ****     |\n";
        break;
    case '4':
        cout << "|   **  **    |\n";
        cout << "|   **  **    |\n";
        cout << "|   ******    |\n";
        cout << "|       **    |\n";
        cout << "|       **    |\n";
        break;
    case '5':
        cout << "|    *****    |\n";
        cout << "|    **       |\n";
        cout << "|    ****     |\n";
        cout << "|       **    |\n";
        cout << "|    ****     |\n";
        break;
    case '6':
        cout << "|     ***     |\n";
        cout << "|    *        |\n";
        cout << "|    ****     |\n";
        cout << "|    *   *    |\n";
        cout << "|     ***     |\n";
        break;
    case '7':
        cout << "|   ******    |\n";
        cout << "|       **    |\n";
        cout << "|       **    |\n";
        cout << "|       **    |\n";
        cout << "|       **    |\n";
        break;
    case '8':
        cout << "|     ***     |\n";
        cout << "|    *   *    |\n";
        cout << "|     ***     |\n";
        cout << "|    *   *    |\n";
        cout << "|     ***     |\n";
        break;
    case '9':
        cout << "|     ***     |\n";
        cout << "|    *   *    |\n";
        cout << "|     ****    |\n";
        cout << "|        *    |\n";
        cout << "|     ***     |\n";
        break;
    case '0':
        cout << "|   *   ***   |\n";
        cout << "|  **  *   *  |\n";
        cout << "|   *  *   *  |\n";
        cout << "|   *  *   *  |\n";
        cout << "|   *   ***   |\n";
        break;
    case 'J':
        cout << "|        **   |\n";
        cout << "|        **   |\n";
        cout << "|        **   |\n";
        cout << "|   **   **   |\n";
        cout << "|    *****    |\n";
        break;
    case 'D':
        cout << "|    ***      |\n";
        cout << "|    *   *    |\n";
        cout << "|    *   *    |\n";
        cout << "|    *   *    |\n";
        cout << "|    ***      |\n";
        break;
    case 'K':
        cout << "|   **   **   |\n";
        cout << "|   ** **     |\n";
        cout << "|   ****      |\n";
        cout << "|   **  **    |\n";
        cout << "|   **    **  |\n";
        break;
    case 'T':
        cout << "|   ******    |\n";
        cout << "|     **      |\n";
        cout << "|     **      |\n";
        cout << "|     **      |\n";
        cout << "|     **      |\n";
        break;
    }
    cout << "|             |\n";
    cout << "|             |\n";
    if (a == '0') {
        cout << "|          10 |\n";
    }
    else {
        cout << "|          " << a << "  |\n";
    }

    cout << "|_____________|\n";
}

//Описание функции
// Проверка месяца на дни
void Task6_1(int a) {
    switch (a) {
    case 1:
        days = 31;
        break;
    case 2:
        if (high == true) days = 29;
        else days = 28;
        break;
    case 3:
        days = 31;
        break;
    case 4:
        days = 30;
        break;
    case 5:
        days = 31;
        break;
    case 6:
        days = 30;
        break;
    case 7:
        days = 31;
        break;
    case 8:
        days = 31;
        break;
    case 9:
        days = 30;
        break;
    case 10:
        days = 31;
        break;
    case 11:
        days = 30;
        break;
    case 12:
        days = 31;
        break;
    }
}
// Описание функции
// Проверка года на высокостность
void Task6_2(int a) {
    if (a % 100 == 0) {
        if (a % 400 == 0) {
            high = true;
        }
        else {
            high = false;
        }
    }
    else {
        if (a % 4 == 0) {
            high = true;
        }
        else {
            high = false;
        }
    }

}

//Описание функции
void Task6(int e, int f, int k, int h, int i, int j) {
    int sum = 0, sum_1 = 0, sum_2 = 0;
    if (e < h) {
        for (int n = e; n <= h; n++) {
            if (n == e) {
                //Вызов фуекции проверка года на высокостность
                Task6_2(e);
                if (high == true) cout << n << " - высокостный год" << endl;
                else cout << n << " - невысокостный год" << endl;
                for (int m = f; m <= 12; m++) {
                    //Вызов функции проверка месяца на дни
                    Task6_1(m);
                    if (m == f) {
                        days -= k;
                    }
                    sum += days;
                }
            }
            else if (n == h) {
                //Вызов фуекции проверка года на высокостность
                Task6_2(h);
                if (high == true) cout << n << " - высокостный год" << endl;
                else cout << n << " - невысокостный год" << endl;

                for (int m = 1; m <= i; m++) {
                    //Вызов функции проверка месяца на дни
                    Task6_1(m);
                    if (m == i) {
                        days = j;
                    }
                    sum += days;
                }
            }
            else if (n != e or n != h) {
                //Вызов фуекции проверка года на высокостность
                Task6_2(n);
                if (high == true) {
                    sum_1 = 366;
                    cout << n << " - высокостный год" << endl;
                }
                else {
                    sum_1 = 365;
                    cout << n << " - невысокостный год" << endl;
                }
                sum_2 += sum_1;
            }
        }
    }
    else if (e == h) {
        //Вызов фуекции проверка года на высокостность
        Task6_2(e);
        for (int m = f; m <= i; m++) {
            //Вызов функции проверка месяца на дни
            Task6_1(m);
            if (m == f && m == i) {
                days = j - k;
            }
            else if (m == f) {
                days -= k;
            }
            else if (m == i) {
                days = j;
            }
            sum += days;
        }
        if (high == true) cout << "Это высокостный год" << endl;
        else cout << "Это не высокостный год" << endl;
    }
    cout << "Всего дней между введенными датами " << sum_2 + sum << endl;
}