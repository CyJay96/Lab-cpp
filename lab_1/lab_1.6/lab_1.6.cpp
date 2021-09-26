/*
Задано число n в формате unsigned char. Вывести на экран значения 0-го
и 7-го битов представления в ЭВМ этого числа. Объяснить результат.
Инвертировать биты 2, 4. Вывести и объяснить результат.
*/


#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    unsigned char n;

    cout << "Введите символ: ";
    cin >> n;

    short bit0 = (n >> 0) & 1;
    short bit7 = (n >> 7) & 1;

    n ^= 4;
    n ^= 16;

    cout << "0-й бит: " << bit0 << endl;
    cout << "7-й бит: " << bit7 << endl;
    cout << "2 и 4 бит инвертированы: " << n;

    return 0;
}