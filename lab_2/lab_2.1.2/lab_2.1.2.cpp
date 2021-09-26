/*
Определить сумму первых k цифр дробной части заданного
положительного вещественного числа.
*/


#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    long double n;
    int k, s = 0;

    cout << "Введите положительное вещественное число: ";
    cin >> n;
    cout << "Введите количество цифр: ";
    cin >> k;

    for (int i = 1; i <= k; i++) {
        n = (n - int(n)) * 10;
        s += int(n);
    }
    cout << "Сумма первых " << k << " цифр дробной части: " << s << endl;

    return 0;
}