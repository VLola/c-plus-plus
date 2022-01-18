#include "Header.h"
int main()
{
	setlocale(LC_ALL, "");
	int a;
	for (;;) {
		cout << "\nEnter the number of the project to run";
		cout << "\nAvailable projects: 1, 2, 3, 4, 5\n";
		cin >> a;
		switch (a) {
		case 1: {
			Project11_1 project11_1;
			project11_1.main();
			break;
		}
		case 2: {
			Project11_2 project11_2;
			project11_2.main();
			break;
		}
		case 3: {
			Project11_3 project11_3;
			project11_3.main();
			break;
		}
		case 4: {
			Project11_4 project11_4;
			project11_4.main();
			break;
		}
		case 5:
		{
			Project11_5 project11_5;
			project11_5.main();
			break;
		}
		default:
			cout << "\nThe project does not exist!\n";
			break;
		}
	}
}
