#include "Header.h"
int main()
{
	setlocale(LC_ALL, "");
	int a;
	for (;;) {
		cout << "Enter the number of the project to run";
		cout << "\nAvailable projects: 1, 2, 3, 4\n";
		cin >> a;
		switch (a) {
		case 1:
			Project8_1 project8_1;
			project8_1.main();
			break;
		case 2:
			Project8_2 project8_2;
			project8_2.main();
			break;
		case 3:
			Project8_3 project8_3;
			project8_3.main();
			break;
		case 4:
			Project8_4 project8_4;
			project8_4.main();
			break;
		default:
			cout << "\nThe project does not exist!\n";
			break;
		}
	}
}
