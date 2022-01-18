#include "Header.h"
int main()
{
	setlocale(LC_ALL, "");
	int a;
	for (;;) {
		cout << "\nEnter the number of the project to run";
		cout << "\nAvailable projects: 1, 2\n";
		cin >> a;
		switch (a) {
		case 1: {
			Project13_1 project13_1;
			project13_1.main();
			break;
		}
		case 2: {
			Project13_2 project13_2;
			project13_2.main();
			break;
		}
		default:
			cout << "\nThe project does not exist!\n";
			break;
		}
	}
}
