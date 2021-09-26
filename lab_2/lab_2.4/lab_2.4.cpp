/*
Дано действительное число х (0 < x <= 1). Вычислить заданную сумму с
точностью e = 10^–6 и указать количество слагаемых. Считать, что требуемая
точность достигнута, если очередное слагаемое по абсолютному значению
меньше e.
*/


#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    double eps = 1e-6;
    double x;

    cout << "Введите x (0 < x <= 1): ";
    cin >> x;

    double chislit = -(x * x * x * x * x * x * x);
    int fact = 6;
    int znamen_bez_fact = 7;

    double slag = chislit / (znamen_bez_fact * fact);
    double s = slag;

    int k = 1;
    while (abs(slag) > eps) {
        k++;

        chislit *= -(x * x * x * x);
        fact *= (2 * k + 1) * (2 * k);
        znamen_bez_fact += 4;

        slag = chislit / (znamen_bez_fact * fact);
        s += slag;
    }

    cout << "Сумма = " << s << endl;
    cout << "Количество членов = " << k << endl;

    return 0;
}