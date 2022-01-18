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
			Project15_1 project_1;
			project_1.main();
			break;
		}
		case 2: {
			Project15_2 project_2;
			project_2.main();
			break;
		}
		default:
			cout << "\nThe project does not exist!\n";
			break;
		}
	}
}
