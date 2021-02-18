#include "functions.h"

void create_numbers(ofstream& file, int n) {
	for (int i = 0; i < n; ++i) {
		file << -50 + rand() % 100 << endl;
	}
}

void create_numbers_bin(ofstream& file, int n) {
	for (int i = 0; i < n; ++i) {
		int number = -50 + rand() % 100;
		file.write(reinterpret_cast<const char*>(&number), sizeof(number));

	}
}

void unsigned_sort(ifstream& file1, ofstream& file2, int n) {
	int* a = new int[n];

	int i = 0;
	while (file1 >> a[i++]);

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

void unsigned_sort_bin(ifstream& file1, ofstream& file2, int n) {
	int* a = new int[n];

	int i = 0;
	while (file1 >> a[i++]);
	while (file1.read(reinterpret_cast<char*>(&a[i]), sizeof(a[i++])));

	for (int i = 0; i < n; ++i) {
		if (a[i] >= 0) {
			file2.write(reinterpret_cast<const char*>(&a[i]), sizeof(a[i]));
		}
	}

	for (int i = 0; i < n; ++i) {
		if (a[i] < 0) {
			file2.write(reinterpret_cast<const char*>(&a[i]), sizeof(a[i]));
		}
	}

	delete[] a;
}
