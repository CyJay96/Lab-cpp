/*

Дата сдачи: 11.02.2021

Дата последнего редактирования: 05.02.2021

Написать функции для выполнения следующего задания:
Задача о восьми слонах: на шахматной доске расставить восемь слонов так,
чтобы каждое поле находилось под ударом одного из них.

1) 9.45 min
2) 5.95 min
3) 1.75 min
4) 1.17 min

*/

#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

const int N = 8;

void print(int* a) {
	for (int i = 0; i < N; ++i) {
		cout << N - i << "| ";
		for (int j = 0; j < N; ++j) {
			a[i * N + j] != 1 ? a[i * N + j] = 0 : true;
			cout << a[i * N + j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < N * 2 + 2; ++i) {
		cout << "-";
	}
	cout << endl << " | ";
	for (int i = 0; i < N; ++i) {
		cout << static_cast<char>('a' + i) << " ";
	}

	cout << endl;
}

bool check(int* a) {
	int k_null = N * (N - 1);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (a[i * N + j] == 1) {
				for (int k = i - 1, m = j - 1; k >= 0 && m >= 0; --k, --m) {
					if (a[k * N + m] == 0) {
						a[k * N + m] = 2;
						k_null--;
					}
				}
				for (int k = i + 1, m = j + 1; k < N && m < N; ++k, ++m) {
					if (a[k * N + m] == 0) {
						a[k * N + m] = 2;
						k_null--;
					}
				}
				for (int k = i + 1, m = j - 1; k < N && m >= 0; ++k, --m) {
					if (a[k * N + m] == 0) {
						a[k * N + m] = 2;
						k_null--;
					}
				}
				for (int k = i - 1, m = j + 1; k >= 0 && m < N; --k, ++m) {
					if (a[k * N + m] == 0) {
						a[k * N + m] = 2;
						k_null--;
					}
				}
			}
		}
	}

	return k_null == 0 ? true : false;
}

void chess(int* board) {
	for (int a = 1; a < N * 7; ++a) {
		for (int b = a + 1; b < N * 7 + 1; ++b) {
			for (int c = b + 1; c < N * 7 + 2; ++c) {
				for (int d = c + 1; d < N * 7 + 3; ++d) {
					for (int e = d + 1; e < N * 7 + 4; ++e) {
						for (int f = e + 1; f < N * 7 + 5; ++f) {
							for (int g = f + 1; g < N * 7 + 6; ++g) {
								for (int h = g + 1; h < N * 7 + 7; ++h) {
									for (int k = 0; k < N * N; ++k) {
										board[k] = 0;
									}
									board[a] = 1;
									board[b] = 1;
									board[c] = 1;
									board[d] = 1;
									board[e] = 1;
									board[f] = 1;
									board[g] = 1;
									board[h] = 1;

									if (check(board)) {
										goto LoopEnd;
									}
								}
							}
						}
					}
				}
			}
		}
	}

LoopEnd:

	print(board);
}

int main() {
	int* board = new int[N * N];

	chess(board);

	delete[] board;

	cout << endl << "Runtime = " << clock() / 60000.0 << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}