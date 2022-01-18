#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Project9_1 {
public:
	// ����������� �������
	template <class T>
	int Recursion(T a, T b, T N) {
		if (N < 1) {
			cout << "������ �������� �� �������";
			return 0;
		}
		// ����� ������ ����� �������� ������� ������
		// � �������� N-1
		else {
			if (a % N == 0) {
				if (b % N == 0) {
					cout << "���������� ����� �������� " << a << " � " << b << " = " << N;
					return 0;
				}
				return Recursion(a, b, N - 1);
			}
			return Recursion(a, b, N - 1);
		}

	}

	void main() {
		cout << "\n������� 1: �������� ����������� ������� ���������� ����������� ������ �������� ���� ����� �����.\n\n";
		// ���� ���������� 
		cout << "\n������� ������ �����\n";
		int a, b, N;
		cin >> a;
		cout << "\n������� ������ �����\n";
		cin >> b;
		// ����������� ������� ���������� �� ��������� �������������
		N = a < b ? a : b;
		// ����� ����������� �������
		Recursion(a, b, N);

	}
};
class Project9_2 {
public:
	// ����������� �������
	template <class T>
	int Recursion(T a, T b, T N, T n, T c, T array[2][4], T d, T j, T h) {


		if (c > 3) {
			if (b == n) {
				cout << "�� �������� �����!!!" << endl;
				cout << "������� ���� �������: " << h << endl;
				return 0;
			}
			int a_1, b_1, c_1, d_1;
			if (b < 10) {
				a_1 = b;
				b_1 = -1;
				c_1 = -1;
				d_1 = -1;
			}
			else if (b < 100) {
				a_1 = b % 10;
				b_1 = b / 10 % 10;
				c_1 = -1;
				d_1 = -1;
			}
			else if (b < 1000) {
				a_1 = b % 10;
				b_1 = b / 10 % 10;
				c_1 = b / 100 % 10;
				d_1 = -1;
			}
			else if (b < 10000) {
				a_1 = b % 10;
				b_1 = b / 10 % 10;
				c_1 = b / 100 % 10;
				d_1 = b / 1000 % 10;
			}

			array[0][0] = a_1;
			array[0][1] = b_1;
			array[0][2] = c_1;
			array[0][3] = d_1;

			if (a < 4) {
				if (array[0][0] == array[1][a] or array[0][1] == array[1][a] or array[0][2] == array[1][a] or array[0][3] == array[1][a]) {
					d++;
				}
				if (array[0][a] == array[1][a]) {
					j++;
				}
				if (a == 3) {
					cout << "���� �������� " << d << endl;
					cout << "���� ����� �� ������ ����� " << j << endl;
				}
				return Recursion(a + 1, b, N, n, c, array, d, j, h);
			}
			else {
				cout << "\n������� �����\n";
				cin >> b;

				d = 0;
				j = 0;
				a = 0;

				return Recursion(a, b, N, n, c, array, d, j, h + 1);

			}

		}
		else {
			int e = N % 10;
			N = N / 10;
			array[1][c] = e;
			return Recursion(a, b, N, n, c + 1, array, d, j, h);
		}


	}

	void main() {
		srand(unsigned(time(NULL)));
		cout << "\n������� 2: �������� ���� ����� � �������.��������� ���������� ������������� ����� � ��������\n";
		cout << "������ ������� ���.����� ����� ������������� ����� ��������� ��������, ������� ���� �����\n";
		cout << "�������(����) � ������� ���� ������� � ����� �� ������ �����(������).����� �����������\n";
		cout << "����� �� ����� ���������� ������� ���������� ��������� ������������� �������.�\n";
		cout << "��������� ���������� ������������ ��������.\n\n";


		int a = 0, b, N, n, c = 0, d = 0, j = 0, h = 1;
		int array[2][4];
		// ��������� ���������� 4� ������� �����
		N = rand() % 9000 + 1000;
		n = N;
		// ����� ��������������� ��������� ������  <<���������>>
		cout << n << "\t - ��������� �������� ����� \t // ����� ��������������� � ����������" << endl;
		cout << "\n������� �����\n";
		cin >> b;

		Recursion(a, b, N, n, c, array, d, j, h);

	}
};
class Project9_3 {
public:

	template <class T>
	int NewMove(T a, T b) {
		int d = rand() % 8 + 1;
		if (d == 1) {
			a += 1;
			b += 2;
			return a * 10 + b;
		}
		else if (d == 2) {
			a += 1;
			b -= 2;
			return a * 10 + b;
		}
		else if (d == 3) {
			a -= 1;
			b += 2;
			return a * 10 + b;
		}
		else if (d == 4) {
			a -= 1;
			b -= 2;
			return a * 10 + b;
		}
		else if (d == 5) {
			a += 2;
			b += 1;
			return a * 10 + b;
		}
		else if (d == 6) {
			a += 2;
			b -= 1;
			return a * 10 + b;
		}
		else if (d == 7) {
			a -= 2;
			b += 1;
			return a * 10 + b;
		}
		else if (d == 8) {
			a -= 2;
			b -= 1;
			return a * 10 + b;
		}
		return 0;

	}

	template <class T>
	int Recurssion(T arr[36], T array[6][6], T a, T b, T c, T A, T B, T i, T d, T g, T g1, T g2, T g3) {


		if (i > 35) {
			return 0;
		}
		else {
			for (; i < 36; d++) {
				c = arr[i - 1];
				a = c / 10;
				b = c % 10;
				for (int m = 0; m < 1;) {
					c = NewMove(a, b);
					for (int j = 0; j < 6; j++) {
						for (int h = 0; h < 6; h++) {
							if (c == array[j][h]) {
								m++;
							}
						}
					}
				}

				int x = 0;
				for (int j = 0; j < i; j++) {
					if (c == arr[j]) {
						x++;
					}
				}
				if (x == 0) {
					arr[i] = c;
					i++;
				}
				else {
					g++;
					g1++;
					g2++;
					g3++;
					if (g3 > 200 && i > 21) {
						for (int j = 20; j > 0; j--) {
							arr[i - j] = 0;
						}
						i -= 20;
						g3 = 0;
					}
					else if (g2 > 150 && i > 11) {
						for (int j = 10; j > 0; j--) {
							arr[i - j] = 0;
						}
						i -= 10;
						g2 = 0;
					}
					else if (g1 > 70 && i > 6) {
						for (int j = 5; j > 0; j--) {
							arr[i - j] = 0;
						}

						i -= 5;
						g1 = 0;
					}
					else if (g > 40 && i > 2) {
						arr[i - 1] = 0;
						i -= 1;
						g = 0;
					}


				}

				if (d > 20000) {
					cout << ".";
					for (int j = 0; j < 36; j++) {
						if (j == 0) {
							arr[j] = A * 10 + B;
						}
						else arr[j] = 0;
					}
					return Recurssion(arr, array, a, b, c, A, B, i = 1, d = 0, g, g1, g2, g3);
				}

			}

			return Recurssion(arr, array, a, b, c, A, B, i, d, g, g1, g2, g3);
		}
	}

	void main()
	{
		srand(unsigned(time(NULL)));
		cout << "\n������� 3: ���� ��������� ����� �������� 8�8 � ��������� ����.��������� ������ ��������� �\n";
		cout << "������������ ���������� ������ ���� � ��������� ���� ����.������ ��������� ����� �\n";
		cout << "������� ���� ����, ��� ������� �� ������� ��� ������ �����, ��������� � ������ ������\n";
		cout << "������ ���� ���. (��� ��� ������� ��������� ���� ��� ������ ��������� ������ �����\n";
		cout << "����������, �� ������������� ������� ���������� ������ �� ���� �������� 6�6).� ���������\n";
		cout << "���������� ������������ ��������.\n\n";

		int a, b, c;
		int array[6][6];
		int arr[36];

		// �������� �������

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				array[i][j] = (i + 1) * 10 + j + 1;
			}
		}

		// ����� �������
		cout << "\n��������� ����� � ������������:\n";
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (i > 1) {
					if (j == 1) cout << "|" << " ";
					else if (j == 0) cout << i - 1 << " ";
					else if (j > 1)cout << array[i - 2][j - 2] << " ";
				}
				else if (i == 0) {
					if (j == 0 or j == 1)cout << " " << " ";
					else cout << " " << j - 1 << " ";
				}
				else if (i == 1) {
					if (j == 0 or j == 1)cout << " " << " ";
					else cout << "-" << "-" << "-";
				}


			}cout << endl;
		}

		cout << "\n������� ���������� �� ���������\n";
		cin >> a;
		cout << "\n������� ���������� �� �����������\n";
		cin >> b;


		int A = a;
		int B = b;

		c = a * 10 + b;
		arr[0] = c;

		int i = 1, d = 0, g = 0, g1 = 0, g2 = 0, g3 = 0;
		Recurssion(arr, array, a, b, c, A, B, i, d, g, g1, g2, g3);

		cout << "\n���� ���� �� ����������� �� ��������� �����:\n";
		for (int i = 0; i < 36; i++) {
			cout << arr[i] << " ";
		}

		for (int h = 0; h < 36; h++) {
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					if (arr[h] == array[i][j]) {
						array[i][j] = h;
					}

				}
			}

		}
		// ����� �������
		cout << "\n��������� ����� � ���������������� ������ ����:\n";
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (i > 1) {
					if (j == 1) cout << "|" << "\t";
					else if (j == 0) cout << i - 1 << "\t";
					else if (j > 1)cout << array[i - 2][j - 2] << "\t";
				}
				else if (i == 0) {
					if (j == 0 or j == 1)cout << "\t";
					else cout << j - 1 << "\t";
				}
				else if (i == 1) {
					if (j == 0 or j == 1)cout << "\t";
					else cout << "--" << "\t";
				}


			}cout << endl << endl;
		}

	}
};
class Project9_4 {
public:
	template<class T>
	int Degree(T a, T b, T c) {
		if (b == 0 && a != 0) return 1;
		if (b == 1) return a;
		else return Degree(a *= c, b - 1, c);
	}
	void main()
	{
		int a, b, c;
		cout << "\n������� 4: �������� ����������� ������� ���������� ������� �����.\n\n";

		cout << "������� �����\n";
		cin >> a;
		cout << "������� ������� �����\n";
		cin >> b;
		c = a;
		cout << a << " � ������� " << b << " = " << Degree(a, b, c);

	}
};
class Project9_5 {
public:

	template<class T>
	int Recurssion(T N) {
		if (N == 0) return 0;
		else {
			cout << "*";
			return Recurssion(N - 1);
		}
	}
	template<class T>
	int RecurssionExample(T N) {
		if (N == 0) {
			cout << "\n����� �� ��������\n";
			return 0;
		}
		else {
			cout << "\n����� ������\n";
			cout << "*";
			cout << "\n������� ����� (������� �������� �������) - " << N - 1;
			return RecurssionExample(N - 1);
		}
	}
	void main()
	{
		int N;
		cout << "\n������� 5: �������� ����������� �������, ������� ������� N ����� � ���, ����� N ������ ������������.\n";
		cout << "���������������� ������ ������� ��������.\n\n";

		cout << "������� ����� ����\n";
		cin >> N;
		Recurssion(N);
		cout << "\n������ ����������� ������� '������'\n";
		RecurssionExample(N);
		cout << "����� ���������";
	}
};
class Project9_6 {
public:
	template<class T>
	int Recurssion(T a, T b, T c) {

		if (a == b) return c;
		else {
			cout << c << " + " << a - 1 << " = " << c + a - 1 << endl;
			c += a - 1;
			return Recurssion(a - 1, b, c);
		}
	}

	void main()
	{
		int a, b, c, d, e;
		cout << "\n������� 6: �������� ����������� �������, ������� ��������� ����� ���� ����� � ��������� �� a �� b.\n";
		cout << "������������ ������ a � b. ���������������� ������ ������� ��������.\n\n";

		cout << "������� a\n";
		cin >> a;
		cout << "������� b\n";
		cin >> b;
		c = a > b ? a : b;
		d = a < b ? a : b;
		e = c;
		cout << "C���� ���� ����� � ��������� �� " << a << " �� " << b << " = " << Recurssion(c, d, e);

	}
};
class Project9_7 {
public:

	template<class T>
	int Recurssion(T array[100], T arr[100], T a, T b, T min) {

		if (a > 90) {
			if (min == arr[b]) {
				cout << endl << "� ������� N " << b << " � ���������� ������� ���������� ������������������ �� 10 �����, ����� ������� ���������� � ����� " << min;
			}
			else if (b > 90) return 0;
			return Recurssion(array, arr, a, b + 1, min);
		}
		else {
			arr[a] = array[a] + array[a + 1] + array[a + 2] + array[a + 3] + array[a + 4] + array[a + 5] + array[a + 6] + array[a + 7] + array[a + 8] + array[a + 9];
			if (min < arr[a]) {
				min = arr[a];
			}
			return Recurssion(array, arr, a + 1, b, min);
		}
	}

	void main()
	{
		srand(unsigned(time(NULL)));
		int a = 0, b = 0, min, sum = 0;
		int array[100];
		int arr[100];
		cout << "\n������� 7: �������� ����������� �������, ������� ��������� ���������� ������ �� 100 ����� �����,\n";
		cout << "����������� ��������� �������, � ������� �������, � ������� ����������\n";
		cout << "������������������ �� 10 �����, ����� ������� ����������.\n\n";

		cout << "���������� ������\n";
		for (int i = 0; i < 100; i++) {
			array[i] = rand() % 100;
			cout << array[i] << " ";
		}cout << endl;
		for (int i = 0; i < 10; i++) {
			sum += array[i];
		}
		min = sum;
		Recurssion(array, arr, a, b, min);

	}
};