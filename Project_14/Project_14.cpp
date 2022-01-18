#include "Header.h"
int main()
{
	setlocale(LC_ALL, "");
	int a;
	for (;;) {
		cout << "\nEnter the number of the project to run";
		cout << "\nAvailable projects: 1, 2, 3\n";
		cin >> a;
		switch (a) {
		case 1: {
			Project14_1 project_1;
			project_1.main();
			break;
		}
		case 2: {
			Project14_2 project_2;
			project_2.main();
			break;
		}
		case 3: {
			Project14_3 project_3;
			project_3.main();
			break;
		}
		default:
			cout << "\nThe project does not exist!\n";
			break;
		}
	}
}
