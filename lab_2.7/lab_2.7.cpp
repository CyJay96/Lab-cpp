/*
Вычислить значение многочлена для заданного n в точках хi = [х0; хn]
(хi = х0 + idх, i = 0, 1, ...) двумя способами: суммируя элементы по
возрастанию степени x и по схеме Горнера. Посчитать количество операций
сложения и умножения в том и другом случае.
*/


#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    double x0 = 1;
    double xn = 5;
    double dx = 0.5;

    double i, x;

    int k_sum1, k_sum2, k_multi1, k_multi2;

    int n;

    cout << "xi = [" << x0 << "; " << xn << "]" << endl;
    cout << "dx = " << dx << endl << endl;
    cout << "Введите количество членов: ";
    cin >> n;

    cout << "---------------------------------------" << endl;

    cout.width(10);
    cout << left << "x";

    cout.width(18);
    cout << left << "y";

    cout.width(18);
    cout << left << "y_gorner" << endl;

    cout << "---------------------------------------" << endl;

    x = 0;
    i = 0;

    while (x <= (xn - dx)) {
        x = x0 + dx * i;
        i++;

        double x_mul = x;
        double y_stepen = 5 + x;
        double y_gorner = n * x;

        //способ 1
        k_sum1 = 1;
        k_multi1 = 0;

        for (int j = 2; j <= n; ++j) {
            x_mul *= x * x;

            y_stepen += j * x_mul;

            k_sum1++;
            k_multi1 += 3;
        }

        //способ 2
        k_sum2 = 0;
        k_multi2 = 1;

        for (int j = n - 1; j >= 1; --j) {
            y_gorner *= x * x;
            y_gorner += j * x;

            k_sum2++;
            k_multi2 += 3;
        }

        y_gorner += 5;

        cout.width(10);
        cout << left << x;

        cout.width(18);
        cout << left << y_stepen;

        cout.width(18);
        cout << left << y_gorner << endl;
    }

    cout << endl << "Вычесление значения многочлена суммируя элементы:" << endl;
    cout << "Кол-во сложений = " << k_sum1 << "\t" << "Кол-во умножений = " << k_multi1 << endl;

    cout << endl << "Вычесление значения многочлена по схеме Горнера:" << endl;
    cout << "Кол-во сложений = " << k_sum2 << "\t" << "Кол-во умножений = " << k_multi2 << endl;

    return 0;
}