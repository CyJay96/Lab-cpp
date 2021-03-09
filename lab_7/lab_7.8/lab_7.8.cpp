/*

Дата сдачи: ...

Создать подходящий тип данных для представления графа. Написать и протестировать процедуры,
обеспечивающие добавление вершины в граф, вывода элементов графа на экран, выполнить следующие задания.
Количество вершин графа <= 65000, среднее число связей на вершину 6, ограничение по памяти 64 МiB.
Оценить асимптотическую сложность алгоритма.

Определить, что для любой пары вершин заданного орграфа одна из этих вершин достижима от другой.

*/


#include "Graf.h"

void add(Vertexes*& top, int number) {
	Vertexes* newGraf = new Vertexes;

	newGraf->numVer = number;
	newGraf->next = nullptr;

	if (!top) {
		top = newGraf;
	}
	else {
		Vertexes* real = top;
		Vertexes* pred = top;

		while (real) {
			if (real->numVer == number) {
				return;
			}

			pred = real;
			real = real->next;
		}

		newGraf->next = pred->next;
		pred->next = newGraf;
	}
}

void add(Graf*& top, int number) {
	Graf* newGraf = new Graf;

	newGraf->numVer = number;
	newGraf->next = nullptr;
	newGraf->listAdVer = nullptr;

	if (!top) {
		top = newGraf;
	}
	else {
		Graf* real = top;
		Graf* pred = top;

		while (real) {
			if (real->numVer == number) {
				return;
			}

			pred = real;
			real = real->next;
		}

		newGraf->next = pred->next;
		pred->next = newGraf;
	}
}

void del(Vertexes*& top, int number) {
	if (!top) {
		return;
	}

	Vertexes* real = top;
	Vertexes* pred = top;

	while (real && real->numVer != number) {
		pred = real;
		real = real->next;
	}

	if (pred == top && top->numVer == number) {
		top = top->next;
		delete pred;
		return;
	}
	real = pred->next;
	if (!real) {
		return;
	}

	pred->next = real->next;
	delete real;
}

void del(Graf*& top, int number) {
	if (!top) {
		return;
	}

	Graf* inReal = top;
	while (inReal) {
		//Vertexes* head = inReal->listAdVer;
		del(inReal->listAdVer, number);
		inReal = inReal->next;
	}

	Graf* real = top;
	Graf* pred = top;

	while (real && real->numVer != number) {
		pred = real;
		real = real->next;
	}

	if (pred == top && top->numVer == number) {
		top = top->next;
		delete pred;
		return;
	}
	real = pred->next;
	if (!real) {
		return;
	}

	pred->next = real->next;
	delete real;
}

void addConnect(Graf*& top, int n) {
	srand(static_cast<unsigned int>(time(nullptr)));

	int k_min = 5;
	int k_max = 8;

	Graf* real = top;
	while (real) {
		int k_connect = k_min + rand() % k_max;

		for (int j = 0; j < k_connect; ++j) {
			int randNumGraf = rand() % n;
			Graf* randGraf = top;
			for (int k = 0; k < randNumGraf; ++k) {
				randGraf = randGraf->next;
			}

			add(real->listAdVer, randGraf->numVer);
		}

		real = real->next;
	}
}

void input(Graf*& top, int n) {
	for (int i = 0; i < n; ++i) {
		int number = 0;
		enter(number);
		add(top, number);
	}

	addConnect(top, n);
}

void output(Graf* top) {
	while (top) {
		cout << top->numVer << ": ";

		Vertexes* head = top->listAdVer;
		while (head) {
			cout << head->numVer << " ";
			head = head->next;
		}
		cout << endl;

		top = top->next;
	}
}

bool checkGraf(Graf* top, int ver1, int ver2) {
	bool flag1 = true;
	Graf* graf1 = top;
	if (graf1) {
		while (graf1) {
			if (graf1->numVer == ver1) {
				break;
			}
			else if (graf1->numVer != ver1 && !graf1->next) {
				flag1 = false;
				cout << "The first entered graph wasn't found" << endl;
			}
			graf1 = graf1->next;
		}
	}
	else {
		flag1 = false;
		cout << "The first entered graph wasn't found" << endl;
	}

	bool flag2 = true;
	Graf* graf2 = top;
	if (graf2) {
		while (graf2) {
			if (graf2->numVer == ver2) {
				break;
			}
			else if (graf2->numVer != ver2 && !graf2->next) {
				flag2 = false;
				cout << "The second entered graph wasn't found" << endl;
			}
			graf2 = graf2->next;
		}
	}
	else {
		flag2 = false;
		cout << "The second entered graph wasn't found" << endl;
	}

	return flag1 && flag2;
}

//void oneToOther(Graf* top, int ver1, int ver2) {
//	Graf* graf1 = top;
//	while (graf1) {
//		if (graf1->numVer == ver1) {
//			break;
//		}
//		else {
//			graf1 = graf1->next;
//		}
//	}
//
//	Vertexes* searchVer = top->listAdVer;
//	while (searchVer) {
//		if (searchVer->numVer == ver2) {
//			cout << "zbs" << endl;
//		}
//	}
//}

int main() {
	cout << "Enter the number of tree elements:" << endl;
	cout << "N = ";
	int n = 0;
	enter(n);
	if (n > MAX_SIZE) {
		cout << "Too many graphs!" << endl;
		return 0;
	}
	cout << endl;

	Graf* top = nullptr;

	cout << "Enter elements of the graf:" << endl;
	input(top, n);
	cout << endl;

	cout << "Elements of the graf:" << endl;
	output(top);
	cout << endl;

	//cout << "Enter the number of the first vertex: ";
	//int ver1 = 0;
	//enter(ver1);

	//cout << "Enter the number of the second vertex: ";
	//int ver2 = 0;
	//enter(ver2);
	//cout << endl;

	//if (checkGraf(top, ver1, ver2)) {
	//	//oneToOther(top, ver1, ver2);
	//}

	output(top); cout << endl;
	del(top, 3);
	output(top);

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}