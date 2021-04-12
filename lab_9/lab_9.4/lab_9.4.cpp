/*

Дата сдачи: 12.02.2021

Дана программа на С++. Проанализировать программу за один просмотр и записать в выходной файл построчно
все идентификаторы, встречающиеся в этой программе, указав количество появлений для каждого идентификатора
и номера строк программы, в которых они встречаются.

*/


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <conio.h>

using namespace std;

struct Properties {
	int quantity;
	vector<int> lines;
};

bool isKeyWord(string& word);
bool isKeySymbol(char ch);
vector<string> getWords(string& line, bool& multiComment);
void scanCPP(string& cppName, map<string, Properties>& identifiers);
void getResultFile(string& fileName, map<string, Properties>& identifiers);



int main() {
	map<string, Properties> identifiers;

	string cppName = "lab_9.4.cpp";
	scanCPP(cppName, identifiers);

	string fileName = "output.txt";
	getResultFile(fileName, identifiers);

	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}



bool isKeyWord(string& word) {
	const vector<string> keyWords = { "using", "namespace",
		"void", "int", "long", "short", "double", "float", "char", "bool", "const",
		"cin", "cout", "return", "true", "false", "new", "delete", "nullptr",
		"if", "else", "switch", "case", "for", "while", "do", "xor", "not",
		"continue", "break", "default", "auto", "try", "catch", "throw",
		"class", "struct", "union", "enum",
		"signed", "unsigned", "sizeof",
		"static", "virtual", "friend", "inline", "operator",
		"public", "private", "protected",
		"template", "typename", "this",
		"override", "final" };

	vector<string>::const_iterator iter = keyWords.begin();
	while (iter != keyWords.end()) {
		if (*iter == word) {
			return true;
		}
		++iter;
	}

	return false;
}

bool isKeySymbol(char ch) {
	const vector<char> keySymbols = { ' ', '+', '-', '*', '/', '<',
		'>', '=', ';', ',', '.', ':', '(', ')',
		'{', '}', '[', ']', '!', '&', '|', '\t' };

	vector<char>::const_iterator iter = keySymbols.begin();
	while (iter != keySymbols.end()) {
		if (*iter == ch) {
			return true;
		}
		++iter;
	}

	return false;
}

vector<string> getWords(string& line, bool& multiComment) {
	vector<string> result;

	int i = 0;
	while (i != line.size()) {
		string currentWord;
		currentWord.clear();

		if (line.empty() || line[0] == '#') {
			break;
		}
		if (line[i] == '/' && line[i + 1] == '/') {
			break;
		}
		if (line[i] == '/' && line[i + 1] == '*') {
			multiComment = true;
			break;
		}
		if (line[i] == '*' && line[i + 1] == '/') {
			multiComment = false;
			break;
		}
		if (isKeySymbol(line[i])) {
			i++;
			continue;
		}
		if (line[i] == '"') {
			i++;
			while (line[i] != '"') {
				i++;
			}
			i++;
			continue;
		}
		string mark = "'";
		if (line[i] == mark[0]) {
			i++;
			while (i < line.size() && line[i] != mark[0]) {
				i++;
			}
			i++;
			continue;
		}

		while (i != line.size() && !isKeySymbol(line[i])) {
			currentWord.push_back(line[i++]);
		}
		result.push_back(currentWord);
		currentWord.clear();
	}

	for (auto i = result.begin(); i != result.end();) {
		if (isKeyWord(*i) || ((*i)[0] >= 48 && (*i)[0] <= 57)) {
			i = result.erase(i);
			continue;
		}
		++i;
	}

	return result;
}

void scanCPP(string& cppName, map<string, Properties>& identifiers) {
	ifstream cppFile(cppName);

	if (!cppFile) {
		cerr << "FILE ERROR" << endl;
		return;
	}
	if (!cppFile.is_open()) {
		cerr << "FILE ISN'T OPEN" << endl;
		return;
	}

	int lineCounter = 0;
	bool multiComment = false;

	while (!cppFile.eof()) {
		lineCounter++;

		string line = "";
		getline(cppFile, line);

		Properties currentProperties;
		vector<string> words = getWords(line, multiComment);

		if (multiComment) {
			continue;
		}

		for (int i = 0; i < words.size(); ++i) {
			multimap<string, Properties>::iterator mm = identifiers.find(words[i]);

			if (mm == identifiers.end()) {
				currentProperties.quantity = 1;
				currentProperties.lines.push_back(lineCounter);
				identifiers.insert(make_pair(words[i], currentProperties));
			}
			else {
				mm->second.quantity++;
				if (find(mm->second.lines.begin(), mm->second.lines.end(), lineCounter) == mm->second.lines.end()) {
					mm->second.lines.push_back(lineCounter);
				}
			}

			currentProperties.lines.clear();
		}
	}

	cppFile.close();
}

void getResultFile(string& fileName, map<string, Properties>& identifiers) {
	const int widthLeft = 20;

	ofstream outFile(fileName);

	if (!outFile) {
		cerr << "FILE ERROR" << endl;
		return;
	}
	if (!outFile.is_open()) {
		cerr << "FILE ISN'T OPEN" << endl;
		return;
	}

	map<string, Properties>::iterator iter = identifiers.begin();
	while (iter != identifiers.end()) {
		outFile.width(widthLeft);
		outFile << left << iter->first << " met for " << iter->second.quantity << " times at lines: ";
		for (int i = 0; i < iter->second.lines.size(); ++i) {
			outFile << iter->second.lines[i] << " ";
		}
		outFile << endl;

		++iter;
	}

	outFile.close();

	cout << "The file is ready" << endl;
}