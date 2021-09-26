/*
Дано натуральное n. Верно ли, что это число содержит ровно три одинаковых цифры?
*/


#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    long long n;
    int broke[30];

    cout << "Введите натуральное число: ";
    cin >> n;

    int k = 0;
    while (n) {
        broke[k] = n % 10;
        n /= 10;
        k++;
    }

    int digits[10] = {0};
    for (int pos = 0; pos < k; ++pos) {
        ++digits[broke[pos]];
    }

    bool check = false;
    for (int i = 0; i < k; ++i) {
        if (digits[i] == 3) {
            check = true;
            break;
        }
    }

    if (check) {
        cout << "Да, это число содержит ровно три одинаковые цифры" << endl;
    }
    else {
        cout << "Нет, это число не содержит ровно три одинаковые цифры" << endl;
    }

    return 0;
}