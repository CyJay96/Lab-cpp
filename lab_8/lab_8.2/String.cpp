#include "String.h"

String::String() {
	int n = 100;
	this->setSize(n);
	this->str = new char[this->getSize() + 1];
	this->str[0] = '\0';
}

String::String(int size) {
	this->size < 0 ? this->size = 0 : true;
	this->setSize(size);
	this->str = new char[this->getSize() + 1];
	this->str[0] = '\0';
}

String::String(const String& obj) {
	this->size = obj.size;
	this->str = new char[this->getSize()];
	for (int i = 0; i < this->getSize(); ++i) {
		this->str[i] = obj.str[i];
	}
}

String::~String() {
	if (this->str != nullptr) {
		delete[] this->str;
		this->str = nullptr;
	}
}

void String::setSize(int size) {
	if (this->str != nullptr) {
		this->str[strlen(this->str)] = '\0';
		this->size = size;
	}
	else {
		this->size = size;
	}
}

int String::getSize() {
	return this->size;
}

istream& operator >> (istream& in, String& obj) {
	int n = 100;
	char* newStr = new char[n];
	in >> newStr;

	int enter = strlen(newStr);
	int dop = obj.getSize();

	int i = 0;
	while (i < dop && i < enter) {
		obj.str[i] = newStr[i];
		i++;
	}
	obj.str[i] = '\0';

	return in;
}

ostream& operator << (ostream& out, const String& obj) {
	out << obj.str;

	return out;
}

char& String::operator [] (int index) {
	if (index >= 0 && index < this->getSize()) {
		return this->str[index];
	}
	else {
		cout << "Going out of the array" << endl;
		exit(0);
	}
}

bool String::operator == (const String& obj) {
	return (strcmp(this->str, obj.str) == 0);
}
bool String::operator > (const String& obj) {
	return (strcmp(this->str, obj.str) > 0);
}
bool String::operator < (const String& obj) {
	return (strcmp(this->str, obj.str) < 0);
}

String& String::operator = (const String& obj) {
	if (&obj != this) {
		delete[] this->str;
		this->size = obj.size;
		this->str = new char[this->getSize() + 1];

		int i = 0;
		while (i < strlen(obj.str)) {
			this->str[i] = obj.str[i];
			i++;
		}
		this->str[i] = '\0';
	}

	return *this;
}

String String::operator + (const String& obj) {
	int newSize = strlen(this->str) + strlen(obj.str) + 1;
	String res(newSize);

	strcat(res.str, this->str);
	strcat(res.str, obj.str);

	return res;
}

void String::operator += (const String& obj) {
	char* oldStr = new char[strlen(this->str)];
	int i = 0;
	while (i < strlen(this->str)) {
		oldStr[i] = this->str[i];
		i++;
	}
	oldStr[i] = '\0';

	int newSize = strlen(this->str) + strlen(obj.str);
	this->setSize(newSize);

	delete[] this->str;
	this->str = new char[this->getSize() + 1];
	this->str[0] = '\0';

	strcat(this->str, oldStr);
	strcat(this->str, obj.str);
}

void String::delChar(const char ch) {
	for (int i = 0; i < this->getSize(); ++i) {
		if (this->str[i] == ch) {
			for (int j = i; j < strlen(this->str); ++j) {
				this->str[j] = this->str[j + 1];
			}
		}
	}
}

void String::deletingSymbols(const String& s) {
	for (int i = 0; i < this->getSize(); ++i) {
		for (int j = 0; j < s.size; ++j) {
			if (this->str[i] == s.str[j]) {
				this->delChar(s.str[j]);
			}
		}
	}
}