#include "functions.h"

void draw_line(int n) {
	for (int i = 0; i < n; ++i) {
		cout << "-";
	}
	cout << endl;
}

void rand_mas(char* a, int n) {
	for (int i = 0; i < n; ++i) {
		a[i] = 65 + rand() % 26;
	}
}

// перегрузка для записи по возрастанию
void inc_mas(int* a, int n) {
	int a1 = 0;
	int a2 = 10;

	a[0] = a1 + rand() % (a2 - a1);

	a1 += 10;
	a2 += 10;

	for (int i = 1; i < n; ++i) {
		int nextInt = a1 + rand() % (a2 - a1 + 1);
		while (nextInt < a[i - 1]) {
			nextInt = a1 + rand() % (a2 - a1 + 1);
		}

		a1 += 10;
		a2 += 10;

		a[i] = nextInt;
	}
}

void inc_mas(char* a, int n) {
	int a1 = 48;
	int a2 = 58;

	int number = a1 + rand() % (a2 - a1 + 1);
	a[0] = static_cast<char>(number);

	a1 += 10;
	a2 += 10;

	for (int i = 1; i < n; ++i) {
		int nextInt = a1 + rand() % (a2 - a1 + 1);
		int beforeInt = static_cast<int>(a[i - 1]);
		while (nextInt < beforeInt) {
			nextInt = a1 + rand() % (a2 - a1 + 1);
		}

		a1 += 10;
		a2 += 10;

		a[i] = static_cast<char>(nextInt);
	}
}

void inc_mas(double* a, int n) {
	int a1 = 0;
	int a2 = 10;

	a[0] = a1 + (rand() % (a2 - a1 + 1)) * 1.1;

	a1 += 10;
	a2 += 10;

	for (int i = 1; i < n; ++i) {
		double nextDouble = a1 + (rand() % (a2 - a1 + 1)) * 1.1;
		while (nextDouble < a[i - 1]) {
			nextDouble = a1 + (rand() % (a2 - a1 + 1)) * 1.1;
		}

		a1 += 10;
		a2 += 10;

		a[i] = nextDouble;
	}
}

// перегрузка для записи по убыванию
void dec_mas(int* a, int n) {
	int a1 = n * 9;
	int a2 = n * 10;

	a[0] = a1 + rand() % (a2 - a1);

	a1 -= 10;
	a2 -= 10;

	for (int i = 1; i < n; ++i) {
		int nextInt = a1 + rand() % (a2 - a1 + 1);
		while (nextInt > a[i - 1]) {
			nextInt = a1 + rand() % (a2 - a1 + 1);
		}

		a1 -= 10;
		a2 -= 10;

		a[i] = nextInt;
	}
}

void dec_mas(char* a, int n) {
	int a1 = 115;
	int a2 = 125;

	int number = a1 + rand() % (a2 - a1 + 1);
	a[0] = static_cast<char>(number);

	a1 -= 10;
	a2 -= 10;

	for (int i = 1; i < n; ++i) {
		int nextInt = a1 + rand() % (a2 - a1 + 1);
		int beforeInt = static_cast<int>(a[i - 1]);
		while (nextInt > beforeInt) {
			nextInt = a1 + rand() % (a2 - a1 + 1);
		}

		a1 -= 10;
		a2 -= 10;

		a[i] = static_cast<char>(nextInt);
	}
}

void dec_mas(double* a, int n) {
	int a1 = n * 9;
	int a2 = n * 10;

	a[0] = a1 + (rand() % (a2 - a1 + 1)) * 1.1;

	a1 -= 10;
	a2 -= 10;

	for (int i = 1; i < n; ++i) {
		double nextDouble = a1 + (rand() % (a2 - a1 + 1)) * 1.1;
		while (nextDouble > a[i - 1]) {
			nextDouble = a1 + (rand() % (a2 - a1 + 1)) * 1.1;
		}

		a1 -= 10;
		a2 -= 10;

		a[i] = nextDouble;
	}
}

void selectSort(int* a, int n, int& compare, int& move) {
	for (int i = 0; i < n - 1; ++i) {
		int min = a[i];
		int min_pos = i;

		for (int j = i + 1; j < n; ++j) {
			compare++;
			if (a[j] < min) {
				min = a[j]; move++;
				min_pos = j;
			}
		}

		a[min_pos] = a[i];
		a[i] = min;
	}
}

void insertSort(int* a, int n, int& compare, int& move) {
	for (int i = 1; i < n; ++i) {
		int x = a[i];
		int j = i - 1;

		while (compare++, x < a[j] && j >= 0) {
			a[j + 1] = a[j--];
			move++;
		}

		a[j + 1] = x;
	}
}