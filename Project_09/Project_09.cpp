#include "Header.h"
int main()
{
	setlocale(LC_ALL, "");
	int a;
	for (;;) {
		cout << "\nEnter the number of the project to run";
		cout << "\nAvailable projects: 1, 2, 3, 4, 5, 6, 7\n";
		cin >> a;
		switch (a) {
		case 1:
			Project9_1 project9_1;
			project9_1.main();
			break;
		case 2:
			Project9_2 project9_2;
			project9_2.main();
			break;
		case 3:
			Project9_3 project9_3;
			project9_3.main();
			break;
		case 4:
			Project9_4 project9_4;
			project9_4.main();
			break;
		case 5:
			Project9_5 project9_5;
			project9_5.main();
			break;
		case 6:
			Project9_6 project9_6;
			project9_6.main();
			break;
		case 7:
			Project9_7 project9_7;
			project9_7.main();
			break;
		default:
			cout << "\nThe project does not exist!\n";
			break;
		}
	}
}
