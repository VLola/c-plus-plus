#include "Header.h"
int main()
{
	setlocale(LC_ALL, "");
	int a;
	for (;;) {
		cout << "\nEnter the number of the project to run";
		cout << "\nAvailable projects: 1, 2, 3, 4, 5, 6, 7, 8\n";
		cin >> a;
		switch (a) {
		case 1:
			Project10_1 project10_1;
			project10_1.main();
			break;
		case 2:
			Project10_2 project10_2;
			project10_2.main();
			break;
		case 3:
			Project10_3 project10_3;
			project10_3.main();
			break;
		case 4:
			Project10_4 project10_4;
			project10_4.main();
			break;
		case 5:
			Project10_5 project10_5;
			project10_5.main();
			break;
		case 6:
			Project10_6 project10_6;
			project10_6.main();
			break;
		case 7:
			Project10_7 project10_7;
			project10_7.main();
			break;
		case 8:
			Project10_8 project10_8;
			project10_8.main();
			break;
		default:
			cout << "\nThe project does not exist!\n";
			break;
		}
	}
}
