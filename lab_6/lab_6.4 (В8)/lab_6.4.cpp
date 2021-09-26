#include <iostream>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;

union MyUnion {
	unsigned int ticket;
	struct MyStruct {
		unsigned letterplace : 3;
		unsigned numofplace : 8;
		unsigned numofflight : 10;
		unsigned destinationB : 5;
		unsigned destinationA : 5;
	} kiket;
};

// вывод на экран
void Output(MyUnion& kek) {

	cout << static_cast<char>(kek.kiket.destinationA + 65) <<
		static_cast<char>(kek.kiket.destinationB + 65) << setw(4) <<
		kek.kiket.numofflight + 1 << setw(4) <<
		kek.kiket.numofplace + 1 << setw(2) <<
		static_cast<char>(kek.kiket.letterplace + 65) << endl;
}
// генерация билета 
void CreatingTicket(MyUnion& kek) {
	kek.kiket.letterplace = rand() % 8;
	kek.kiket.numofplace = rand() % 200;
	kek.kiket.numofflight = rand() % 1000;
	kek.kiket.destinationB = rand() % 26;
	kek.kiket.destinationA = rand() % 25 + 1;
}
// компаратор для сорта
bool comp(MyUnion a, MyUnion b) {
	return a.ticket < b.ticket;
}

int main() {
	srand((unsigned)time(NULL));
	MyUnion plane[100];
	short x;
	cin >> x;

	for (short i = 0; i < x; ++i) {
		CreatingTicket(plane[i]);
	}
	for (short i = 0; i < x; ++i) {
		Output(plane[i]);
	}
	cout << endl << endl;

	sort(plane, plane + x, comp);
	for (short i = 0; i < x; ++i) {
		Output(plane[i]);
	}
	cout << endl;
	for (short i = 0; i < x; ++i) {
		for (short j = i + 1; j < x; ++j) {
			if (plane[i].ticket == plane[j].ticket) {
				Output(plane[i]);
			}
		}
	}
}