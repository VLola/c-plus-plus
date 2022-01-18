#include <iostream>
using namespace std;
int main()
{
    //Task 1
    cout << "\n\t\t\tTask 1\n\n";

    cout << "\t\tSo close, no matter how far\n";
    cout << "\t\tCouldn't be much more from the heart\n";
    cout << "\t\tForever trusting who we are\n";
    cout << "\t\tAnd nothing else matters\n\n";
    cout << "\t\t\t\t\t\tMetallica\n";

    //Task 2
    cout << "\n\t\t\tTask 2\n\n";

    cout << "\tEvery hunter wants red\n";
    cout << "\t\tEvery hunter wants blue\n";
    cout << "\t\t\tEvery hunter wants green\n";
    cout << "\t\t\t\tEvery hunter wants black\n";

    //Task 3
    cout << "\n\t\t\tTask 3\n\n";

    cout << "\tFor sale laptop\n";
    cout << "\tCondition: Used.\n";
    cout << "\tModel: Acer\n";
    cout << "\tTel.: +380982667643\n";
    cout << "\tPrice: 2000 UAH\n";

    //Task 4
    cout << "\n\t\t\tTask 4\n\n";

    double R0, R1, R2, R3;
    cout << "Enter R1\n";
    cin >> R1;
    cout << "Enter R2\n";
    cin >> R2;
    cout << "Enter R3\n";
    cin >> R3;
    R0 = 1 / (1 / R1 + 1 / R2 + 1 / R3);
    cout << "Resistance value R0 = " << R0 << "\n";

    //Task 5
    cout << "\n\t\t\tTask 5\n\n";

    double S, pi, R, L;
    pi = 3.14;
    cout << "Enter the circumference of the circle\n";
    cin >> L;
    R = L / 2 * pi;
    S = pi * R * R;
    cout << "Area of circle S = " << R << "\n";

    //Task 6
    cout << "\n\t\t\tTask 6\n\n";

    double S1, v, t, a;
    cout << "Enter speed v\n";
    cin >> v;
    cout << "Enter time t\n";
    cin >> t;
    cout << "Enter acceleration a\n";
    cin >> a;
    S1 = v * t + (a * t * t) / 2;
    cout << "Distance traveled S = " << S1 << "\n";

    //Task 7
    cout << "\n\t\t\tTask 7\n\n";

    double v1, t1, S2;
    cout << "Enter distance S(m)\n";
    cin >> S2;
    cout << "Enter time t(min)\n";
    cin >> t1;
    v1 = (S2 / 1000) / (t1 / 60);
    cout << "Speed v = " << v1 << "km/h\n";

    //Task 8
    cout << "\n\t\t\tTask 8\n\n";

    double t3, t4, t5, t6, t7, t8, coin, coin1;
    cout << "Enter the start time of the call (hour)\n";
    cin >> t3;
    cout << "Enter the start time of the call (min)\n";
    cin >> t4;
    cout << "Enter the start time of the conversation (sec)\n";
    cin >> t5;
    cout << "Enter the end time of the call (hour)\n";
    cin >> t6;
    cout << "Enter the end time of the call (min)\n";
    cin >> t7;
    cout << "Enter the end time of the call (sec)\n";
    cin >> t8;
    coin1 = 30;
    coin = ((t6 - t3) * 60 + (t7 - t4) + (t8 - t5) / 60) * coin1;
    cout << "Call cost " << coin << " kopecks\n";

    //Task 9
    cout << "\n\t\t\tTask 9\n\n";

    double z1, z2, z3, x1, x2, x3, y1, y2, c1, c2, c3;
    cout << "Enter the name of the first type of gasoline\n";
    cin >> z1;
    cout << "Enter the name of the second type of gasoline\n";
    cin >> z2;
    cout << "Enter the name of the third type of gasoline\n";
    cin >> z3;
    cout << "Enter the cost of " << z1 << " gasoline\n";
    cin >> x1;
    cout << "Enter the cost of " << z2 << " gasoline\n";
    cin >> x2;
    cout << "Enter the cost of " << z3 << " gasoline\n";
    cin >> x3;
    cout << "Enter gas consumption per 100 km\n";
    cin >> y1;
    cout << "Enter travel distance (km)\n";
    cin >> y2;
    c1 = y2 / 100 * y1 * x1;
    c2 = y2 / 100 * y1 * x2;
    c3 = y2 / 100 * y1 * x3;

    cout << "=================================\n";
    cout << "|\t" << "Trip " << y2 << "km" << "\t\t|\n";
    cout << "===============================\n";
    cout << "| " << "Gasoline" << "\t|\t" << "Price" << "\t|\n";
    cout << "=================================\n";
    cout << "|\t" << z1 << "\t|\t" << c1 << "\t|\n";
    cout << "=================================\n";
    cout << "|\t" << z2 << "\t|\t" << c2 << "\t|\n";
    cout << "=================================\n";
    cout << "|\t" << z3 << "\t|\t" << c3 << "\t|\n";
    cout << "=================================\n";
}
