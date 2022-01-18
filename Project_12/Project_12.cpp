#include "Header.h"
int main()
{
	setlocale(LC_ALL, "");
	int a;
	for (;;) {
		cout << "\nEnter the number of the project to run";
		cout << "\nAvailable projects: 1, 2, 3, 4\n";
		cin >> a;
		switch (a) {
		case 1: {
			Project12_1 project12_1;
			project12_1.main();
			break;
		}
		case 2: {
			Project12_2 project12_2;
			project12_2.main();
			break;
		}
		case 3: {
			Project12_3 project12_3;
			project12_3.main();
			break;
		}
		case 4: {
			Project12_4 project12_4;
			project12_4.main();
			break;
		}
		default:
			cout << "\nThe project does not exist!\n";
			break;
		}
	}
}
