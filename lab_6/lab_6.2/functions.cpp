#include "functions.h"

void create_numbers(ofstream& file, int n) {
	for (int i = 0; i < n - 1; ++i) {
		file << -50 + rand() % 100 << endl;
	}
	file << -50 + rand() % 100 << endl;
}

void unsigned_sort(ifstream& file1, ofstream& file2, int n) {
	int* a = new int[n];

	int i = 0;
	while (!file1.eof()) {
		file1 >> a[i++];
	}

	for (int i = 0; i < n; ++i) {
		if (a[i] >= 0) {
			file2 << a[i] << endl;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		if (a[i] < 0) {
			file2 << a[i] << endl;
		}
	}

	delete[] a;
}