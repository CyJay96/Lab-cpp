#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

const int N = 40;

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
void fillList(ifstream& file, Node::Students* st);

int compare_str(Node*& top, Node::Students& info);
void add(Node*& top, Node::Students& info);
void output(Node* top);