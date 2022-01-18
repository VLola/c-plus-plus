#include "Header.h"
int main()
{
	setlocale(LC_ALL, "");
	int number;
	for (;;) {
		cout << "\nEnter the number of the project to run";
		cout << "\nAvailable projects: 1, 2, 3, 4, 5\n";
		cin >> number;
		switch (number) {
		case 1: {
			Project17_1 project_1;
			project_1.main();
			break;
		}
		case 2: {
			Project17_2 project_2;
			project_2.main();
			break;
		}
		case 3: {
			Project17_3 project_3;
			project_3.main();
			break;
		}
		case 4: {
			Project17_4 project_4;
			project_4.main();
			break;
		}
		case 5: {
			Project17_5 project_5;
			project_5.main();
			break;
		}
		default:
			cout << "\nThe project does not exist!\n";
			break;
		}
	}
}
