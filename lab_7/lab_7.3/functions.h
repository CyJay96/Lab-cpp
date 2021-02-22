#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <conio.h>

using namespace std;

struct Node {
	struct Students {
		string name;
		struct DateOfBirth {
			int day;
			int month;
			int year;
		} date;
		int course;
		double mark;
	} stud;
	Node* link;
};

void writeDate(string date, Node::Students& st);
string outputDate(Node::Students::DateOfBirth date);
void masToList(Node* top, Node::Students*& infoSort);

void fillList(ofstream& file, Node::Students* st, int n);
void add(Node*& top, Node::Students& info);
void del(Node*& top, Node::Students& info);
void output(Node* top);

int searchOldest(Node::Students* students, Node::Students* studentsOldest, int n);
