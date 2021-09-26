#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

const int MIN_COURSE = 1;
const int MAX_COURSE = 4;

struct Info {
	string name;
	int age;
	string gender;
	int course;
	double mark;
};

void inputData(ofstream& file, Info* students, int n);
void readData(ifstream& file, Info* students);
void writeData(ofstream& file, Info* students, int n);
void writeDataBin(ofstream& file, Info* students, int n);
void outputData(ifstream& file);
void outputDataBin(ifstream& file);
int searchOldest(Info* students, Info* oldest_stud, int n);