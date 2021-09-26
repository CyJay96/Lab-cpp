/*

Дата сдачи: 18.02.2021

Написать программу для работы с базой данных, содержащей записи со сведениями о студентах:
ФИО, возраст, пол, курс, успеваемость, в которой должны выполняться следующие действия:
1) создание файла;
2) просмотр файла.

Выполнить задания для текстового и бинарного файлов.

По исходному файлу определить ФИО самого старшего студента на каждом курсе. Сформировать файл из этих студентов.

*/


#include "functions.h"

int main() {
	cout << "Enter the number of students:" << endl;
	cout << "N = ";
	int n = 0;
	cin >> n;
	cout << "Enter the students' details:" << endl;


	/* TEXT FILE */
	Info* students = new Info[n];
	Info* oldest_students = new Info[n];

	ofstream write_file("students.txt");
	if (!write_file) {
		cout << "File error" << endl;
		return 1;
	}
	inputData(write_file, students, n);
	write_file.close();

	int k_oldest = searchOldest(students, oldest_students, n);

	write_file.clear();
	write_file.open("oldest_students.txt");
	if (!write_file) {
		cout << "File error" << endl;
		return 2;
	}
	writeData(write_file, oldest_students, k_oldest);
	write_file.close();


	/* BINARY FILE */
	Info* oldest_students_bin = new Info[n];

	write_file.clear();
	write_file.open("students.bin", ios::binary);
	if (!write_file) {
		cout << "File error" << endl;
		return 3;
	}
	writeData(write_file, students, n);
	write_file.close();

	k_oldest = searchOldest(students, oldest_students_bin, n);

	write_file.clear();
	write_file.open("oldest_students.bin", ios::binary);
	if (!write_file) {
		cout << "File error" << endl;
		return 4;
	}
	writeDataBin(write_file, oldest_students_bin, k_oldest);
	write_file.close();

	delete[] students, oldest_students, oldest_students_bin;

	cout << "The text file is ready..." << endl;
	cout << "The binary file is ready..." << endl;


	cout << endl << "Data in text file:" << endl;
	ifstream read_file("oldest_students.txt");
	outputData(read_file);
	read_file.close();

	cout << endl << "Data in binary file:" << endl;
	read_file.clear();
	read_file.open("oldest_students.bin", ios::binary);
	outputDataBin(read_file);
	read_file.close();

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}