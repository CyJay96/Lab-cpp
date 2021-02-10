/*

Дата сдачи: ...

Дата последнего редактирования: 28.01.2021

Написать программу для работы с базой данных, содержащей записи со сведениями о студентах:
ФИО, возраст, пол, курс, успеваемость, в которой должны выполняться следующие действия:
1) создание файла;
2) просмотр файла.

Выполнить задания для текстового и бинарного файлов.

По исходному файлу определить ФИО самого старшего студента на каждом курсе. Сформировать файл из этих студентов.

*/


#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct info {
	string name;
	int age;
	string gender;
	int course;
	double mark;
};

int main() {
	setlocale(LC_ALL, "rus");

	const int N = 80;
	const int MIN_COURSE = 1;
	const int MAX_COURSE = 4;

	info students[N];
	info oldest_stud[N];

	ifstream read_f("students.txt");
	if (!read_f) {
		cout << "File error" << endl;
		return 1;
	}

	int i = 0;
	while (!read_f.eof()) {
		string fio = "";

		read_f >> students[i].name;
		read_f >> fio; students[i].name += " " + fio;
		read_f >> fio; students[i].name += " " + fio;
		read_f >> students[i].age;
		read_f >> students[i].gender;
		read_f >> students[i].course;
		read_f >> students[i].mark;

		i++;
	}

	read_f.close();

	int new_pos_oldest = 0;
	for (int course = MIN_COURSE; course <= MAX_COURSE; ++course) {
		int pos_oldest = 0;
		while (students[pos_oldest].course != course) {
			pos_oldest++;
		}

		for (int i = pos_oldest + 1; i < N; ++i) {
			if (students[pos_oldest].age < students[i].age && students[i].course == course) {
				pos_oldest = i;
			}
		}

		for (int i = 0; i < N; ++i) {
			if (students[i].age == students[pos_oldest].age && students[i].course == course) {
				oldest_stud[new_pos_oldest++] = students[i];
			}
		}
	}

	ofstream write_f("oldest_students.txt");
	if (!write_f) {
		cout << "File error" << endl;
		return 2;
	}

	for (int i = 0; i < new_pos_oldest; ++i) {
		write_f << oldest_stud[i].name << " " << oldest_stud[i].age << " " << oldest_stud[i].gender << " "
			<< oldest_stud[i].course << " " << oldest_stud[i].mark << endl;
	}

	write_f.close();

	cout << "The text file is ready..." << endl;
	//cout << "The binary file is ready..." << endl;

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}