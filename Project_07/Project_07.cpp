#include "Header.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "");
	int a;
	for (;;) {
		cout << "Enter the number of the project to run";
		cout << "\nAvailable projects: 1, 2\n";
		cin >> a;
		switch (a) {
		case 1:
			Project7_1 project7_1;
			project7_1.main();
			break;
		case 2:
			Project7_2 project7_2;
			project7_2.main();
			break;
		default:
			cout << "\nThe project does not exist!\n";
			break;
		}
	}
}