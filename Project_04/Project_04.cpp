#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "");

	cout << "\nЗадание 1:В одномерном массиве, заполненном случайными числами, определить минимальный и максимальный элементы.\n\n";
	int a1 = 0, max, min, b1 = 0;
	int const size = 10;
	int arr[size]{ 8,2,4,37,3,37,34,9,3,8 };
	cout << "Одномерный массив:\n";
	for (int c1 = 0; c1 < size; c1++) {
		cout << arr[c1] << " ";
	}
	cout << endl;
	max = arr[a1];
	for (; a1 < size; a1++) {
		if (max < arr[a1]) {
			max = arr[a1];
		}
	}cout << "Максимальное число " << max << "\n";
	min = arr[b1];
	for (; b1 < size; b1++) {
		if (min > arr[b1]) {
			min = arr[b1];
		}
	}cout << "Минимальное число " << min << "\n";

	cout << "\nЗадание 2: Пользователь вводит прибыль фирмы за год (12 месяцев). Затем пользователь\n";
	cout << "вводит диапазон(например, 3 и 6 – поиск между 3 - м и 6 - м месяцем).Необходимо определить\n";
	cout << "месяц, в котором прибыль была максимальна и месяц, в котором прибыль была минимальна с\n";
	cout << "учетом выбранного диапазона.\n\n";

	int a2 = 0, b2 = 0, c2, d2, min2, max2, e2 = 0, i2 = 0, f = 0, g = 0;
	int const size2 = 12;
	int arr2[size2];
	for (; a2 < size2; a2++) {
		cout << "Введите прибыль за " << a2 + 1 << " месяц ";
		cin >> arr2[a2];
	}
	cout << "Введите начальный месяц ";
	cin >> c2;
	cout << "Введите второй месяц ";
	cin >> d2;
	for (b2 = c2 - 1; b2 < d2; b2++) {
		max2 = arr2[c2 - 1];
		for (e2 = c2 - 1; e2 < d2; e2++) {
			if (max2 < arr2[e2]) {
				max2 = arr2[e2];
			}
		}
		min2 = arr2[c2 - 1];
		for (i2 = c2 - 1; i2 < d2; i2++) {
			if (min2 > arr2[i2]) {
				min2 = arr2[i2];
			}
		}
	}
	for (f = c2 - 1; f < d2; f++) {
		if (max2 == arr2[f]) {
			cout << "Максимальная прибыль в " << f + 1 << " месяце" << "\n";
		}

	}
	for (g = c2 - 1; g < d2; g++) {
		if (min2 == arr2[g]) {
			cout << "Минимальная прибыль в " << g + 1 << " месяце" << "\n";
		}
	}

	cout << "\nЗадание 3: В одномерном массиве, состоящем из N вещественных чисел вычислить :";
	cout << "Сумму отрицательных элементов.";
	cout << "Произведение элементов, находящихся между min и max элементами.";
	cout << "Произведение элементов с четными номерами.";
	cout << "Сумму элементов, находящихся между первым и последним отрицательными элементами.\n\n";


	int a3 = 0, b3 = 0, c3 = 0, d3 = 0, e3 = 0, i3 = 0, f3 = 0, g3 = 0, k3 = 0, l3 = 0, sum3 = 0, proizv3 = 1, min3, max3;
	int const size3 = 10;
	int arr3[size3]{ 1,-2,12,3,6,-9,4,2,5,7 };
	cout << "Одномерный массив:\n";
	for (; c3 < size3; c3++) {
		cout << arr3[c3] << " ";
	}
	cout << endl;
	cout << "Сумма отрицательных элементов:\n";
	for (; a3 < size3; a3++) {
		if (arr3[a3] < 0) {
			i3++;
			for (; e3 < i3; e3++) {
				if (e3 != 0)cout << "+";
			}
			sum3 += arr3[a3];
			if (arr3[a3] > 0) {
				cout << " " << arr3[a3] << " ";
			}
			else {
				cout << " " << "(" << arr3[a3] << ")" << " ";
			}

		}
	}
	cout << "=" << " " << sum3 << "\n";
	cout << "Произведение элементов с четными номерами:\n";
	for (; b3 < size3; b3++) {
		if (b3 % 2 == 0) {
			f3++;
			for (; g3 < f3; g3++) {
				if (g3 != 0)cout << "*";
			}
			proizv3 *= arr3[b3];
			if (arr3[b3] > 0) {
				cout << " " << arr3[b3] << " ";
			}
			else {
				cout << " " << "(" << arr3[b3] << ")" << " ";
			}
		}
	}
	cout << "=" << " " << proizv3 << "\n";


	cout << "Произведение элементов, находящихся между min и max элементами:\n";
	a3 = 0;
	b3 = 0;
	c3 = 0;
	d3 = 0;
	e3 = 0;
	i3 = 0;
	proizv3 = 1;
	max3 = arr3[a3];
	min3 = arr3[a3];
	for (; b3 < size3; b3++) {
		if (max3 < arr3[b3]) {
			max3 = arr3[b3];
		}
		if (min3 > arr3[b3]) {
			min3 = arr3[b3];
		}
	}

	for (; a3 < size3; a3++) {
		if (max3 == arr3[a3]) {
			k3 = a3;
		}
		if (min3 == arr3[a3]) {
			l3 = a3;
		}
	}
	f3 = (l3 > k3) ? l3 : k3;
	g3 = (l3 < k3) ? l3 : k3;


	for (d3 = g3 + 1; d3 < f3; d3++) {
		i3++;
		for (; e3 < i3; e3++) {
			if (e3 != 0)cout << "*";
		}
		proizv3 *= arr3[d3];
		if (arr3[d3] > 0) {
			cout << " " << arr3[d3] << " ";
		}
		else {
			cout << " " << "(" << arr3[d3] << ")" << " ";
		}
		cout << " ";
	}
	cout << "= " << proizv3 << "\n";


	cout << "Сумма элементов, находящихся между первым и последним отрицательными элементами.\n";
	a3 = 0;
	b3 = 0;
	c3 = 0;
	d3 = 0;
	e3 = 0;
	f3 = 0;
	bool m3 = false;
	for (; a3 < size3; a3++) {
		if (arr3[a3] < 0) {
			if (m3 == false) {
				d3 = a3;
				m3 = true;
			}
			for (e3; e3 <= a3; e3++) {
				f3 = e3;
			}
		}
	}
	a3 = 0; e3 = 0; i3 = 0; sum3 = 0;
	for (a3 = d3 + 1; a3 < f3; a3++) {
		i3++;
		for (; e3 < i3; e3++) {
			if (e3 != 0)cout << "+";
		}
		sum3 += arr3[a3];
		if (arr3[a3] > 0) {
			cout << " " << arr3[a3] << " ";
		}
		else {
			cout << " " << "(" << arr3[a3] << ")" << " ";
		}

	}
	cout << "=" << " " << sum3 << "\n";

	cout << "\nЗадание 4:Написать программу, копирующую последовательно элементы одного массива размером 10";
	cout << "  элементов в 2 массива размером 5 элементов каждый.\n\n";
	int a4 = 0;
	int const size4 = 10;
	int const siz4 = 5;
	int arr4[size4]{ 3,4,5,6,7,8,9,10,11,12 };
	int ar1[siz4];
	int ar2[siz4];
	cout << "Массив размером 10 элементов:\n";
	for (int b4 = 0; b4 < size4; b4++) {
		cout << arr4[b4] << " ";
	}
	cout << endl;
	for (; a4 < siz4; a4++) {
		ar1[a4] = arr4[a4];
	}
	a4 = 0;
	for (; a4 < siz4; a4++) {
		ar2[a4] = arr4[a4 + 5];
	}
	cout << "Первый массив размером 5 элементов:\n";
	for (int b4 = 0; b4 < siz4; b4++) {
		cout << ar1[b4] << " ";
	}
	cout << endl;
	cout << "Второй массив размером 5 элементов:\n";
	for (int b4 = 0; b4 < siz4; b4++) {
		cout << ar2[b4] << " ";
	}
	cout << endl;

	cout << "\nЗадание 5:Напишите программу, которая выполняет поэлементную сумму двух массивов и результат";
	cout << "заносит в третий массив\n\n";

	int a5;
	int const size5 = 10;
	int arr5_1[size5]{ 3,4,5,6,7,8,9,10,11,12 };
	int arr5_2[size5]{ 3,4,5,6,7,8,9,10,11,12 };
	int arr5[size5];
	for (a5 = 0; a5 < size5; a5++) {
		arr5[a5] = arr5_1[a5] + arr5_2[a5];
	}

	cout << "Первый массив:\n";
	for (int b5 = 0; b5 < size5; b5++) {
		cout << arr5_1[b5] << " ";
	}
	cout << endl;
	cout << "Второй массив:\n";
	for (int b5 = 0; b5 < size5; b5++) {
		cout << arr5_2[b5] << " ";
	}
	cout << endl;
	cout << "Третий массив:\n";

	for (int b5 = 0; b5 < size5; b5++) {
		cout << arr5[b5] << " ";
	}
}