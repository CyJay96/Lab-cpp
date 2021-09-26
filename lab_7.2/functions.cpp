#include "functions.h"

void input(int* mas1, int** mas2, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mas1[i * n + j];
			mas2[i][j] = mas1[i * n + j];
		}
	}
}

void output(int* mas, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << mas[i * n + j] << " ";
		}
		cout << endl;
	}
}

void output(int** mas, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
}