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

	int k_min = 3;
	int k_max = 5;

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
		enter(cin, number);
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

int searchWay(Graf* top, Vertexes* head, int ver2) {
	Vertexes* real = head;
	while (real) {
		if (real->numVer == ver2) {
			return real->numVer;
		}
		real = real->next;
	}

	real = head;
	while (real) {
		Graf* findGraf = top;
		while (findGraf) {
			if (findGraf->numVer == real->numVer) {
				break;
			}
			findGraf = findGraf->next;
		}

		Vertexes* head = findGraf->listAdVer;
		while (head) {
			if (head->numVer == ver2) {
				return head->numVer * 10 + findGraf->numVer;
			}
			head = head->next;
		}

		real = real->next;
	}

	cout << "There is no connection" << endl;
	exit(0);
}

void oneToOther(Graf* top, int ver1, int ver2) {
	Graf* graf1 = top;
	while (graf1) {
		if (graf1->numVer == ver1) {
			break;
		}
		graf1 = graf1->next;
	}

	int way = searchWay(top, graf1->listAdVer, ver2);

	way = way * 10 + ver1;

	while (way / 10) {
		cout << way % 10;
		cout << " -> ";
		way /= 10;
	}
	cout << way % 10;
	cout << endl;
}
