/*
Составить программу вычисления значений функции в точках хi = [х0; хn],
хi = х0 + idх, i = 0,1, ..., воспользовавшись формулами разложения элементарных
функций в ряд Тейлора с точностью e = 10^–6. Вывести на экран необходимое
количество слагаемых в каждом случае. Сравнить результаты со значениями
функции в этих точках, вычисленных с помощью встроенных функций системы
программирования.
*/


#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    double eps = 1e-6;

    double x0 = -0.8;
    double xn = 1;
    double dx = 0.1;
    double x = 0;

    cout << "xi = [" << x0 << "; " << xn << "]" << endl;
    cout << "dx = " << dx << endl << endl;

    cout << "---------------------------------------" << endl;

    cout.width(7);
    cout << left << "x";

    cout.width(15);
    cout << left << "y_t";

    cout.width(15);
    cout << left << "y";

    cout.width(10);
    cout << left << "k" << endl;

    cout << "---------------------------------------" << endl;

    int i = 0;
    while (x <= (xn - dx)) {
        x = x0 + dx * i;
        i++;

        double s = 0;
        double p = x * x;
        double slag = p / 2;

        int k = 2;
        while (abs(slag) > eps) {
            k++;

            s -= slag;
            p *= x;
            slag = p / k;
        }

        k -= 2;

        cout.width(7);
        cout << left << x;
        
        cout.width(15);
        cout << left << s;
        
        cout.width(15);
        cout << left << log(1 - x) + x;
        
        cout.width(10);
        cout << left << k << endl;
    }

    return 0;
}