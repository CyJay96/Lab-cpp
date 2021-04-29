#include "functions.h"

void inputData(ofstream& file, Info* students, int n) {
	for (int i = 0; i < n; ++i) {
		string fio;
		cin >> students[i].name;
		cin >> fio; students[i].name += " " + fio;
		cin >> fio; students[i].name += " " + fio;
		cin >> students[i].age;
		cin >> students[i].gender;
		cin >> students[i].course;
		cin >> students[i].mark;

		file << students[i].name << " " << students[i].age << " " << students[i].gender << " "
			<< students[i].course << " " << students[i].mark << endl;
	}
}

void readData(ifstream& file, Info* students) {
	int i = 0;
	while (!file.eof()) {
		string fio = "";

		file >> students[i].name;
		file >> fio; students[i].name += " " + fio;
		file >> fio; students[i].name += " " + fio;
		file >> students[i].age;
		file >> students[i].gender;
		file >> students[i].course;
		file >> students[i].mark;

		i++;
	}
}

void writeData(ofstream& file, Info* students, int n) {
	for (int i = 0; i < n; ++i) {
		file << students[i].name << " " << students[i].age << " " << students[i].gender << " "
			<< students[i].course << " " << students[i].mark << endl;
	}
}

void writeDataBin(ofstream& file, Info* students, int n) {
	for (int i = 0; i < n; ++i) {
		file.write(reinterpret_cast<const char*>(&students[i]), sizeof(Info));
	}
}

void outputData(ifstream& file) {
	Info student;

	while (!file.eof()) {
		string fio = "";

		file >> student.name;
		file >> fio; student.name += " " + fio;
		file >> fio; student.name += " " + fio;
		file >> student.age;
		file >> student.gender;
		file >> student.course;
		file >> student.mark;

		cout << student.name << " " << student.age << " " << student.gender << " "
			<< student.course << " " << student.mark << endl;
	}
}

void outputDataBin(ifstream& file) {
	Info student;

	while (!file.eof()) {
		file.read(reinterpret_cast<char*>(&student), sizeof(Info));
		cout << student.name << " " << student.age << " " << student.gender << " "
			<< student.course << " " << student.mark << endl;
	}
}

int searchOldest(Info* students, Info* oldest_stud, int n) {
	int k_oldest = 0;
	for (int course = MIN_COURSE; course <= MAX_COURSE; ++course) {
		int pos_oldest = 0;
		while (pos_oldest < n && students[pos_oldest].course != course) {
			pos_oldest++;
		}

		for (int i = pos_oldest + 1; i < n; ++i) {
			if (students[pos_oldest].age < students[i].age && students[i].course == course) {
				pos_oldest = i;
			}
		}

		for (int i = 0; i < n; ++i) {
			if (students[i].age == students[pos_oldest].age && students[i].course == course) {
				oldest_stud[k_oldest++] = students[i];
			}
		}
	}

	return k_oldest;
}
