#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <conio.h>

using namespace std;

class Vector {
private:
	int size;
	int* arr;

public:
	Vector();
	Vector(int size);
	Vector(const Vector& obj);

	~Vector();

	int& operator [] (int index);

	friend ifstream& operator >> (ifstream& file, Vector& obj) {
		while (!file.eof()) {
			int number = 0;
			file >> number;
			obj.arr[number]++;
		}

		return file;
	}

	friend ofstream& operator << (ofstream& file, const Vector& obj) {
		for (int i = obj.size - 1; i >= 0; --i) {
			if (obj.arr[i] != 0) {
				file << i << endl;
			}
		}

		return file;
	}

	void setSize(int size);
	int getSize();

	void fillRandom(int range);
};