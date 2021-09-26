#include "String.h"

String::String() {
	int n = 100;
	this->setSize(n);
	this->str = new char[this->getSize() + 1];
	this->str[0] = '\0';
}

String::String(int size) {
	size < 0 ? this->size = 0 : this->size = size;
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

int String::getSize() const {
	return this->size;
}

int String::getLen() const {
	return strlen(this->str);
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
	if (index >= 0 && index < this->getLen()) {
		return this->str[index];
	}
	else {
		cout << "Going out of the array" << endl;
		exit(0);
	}
}

char& String::operator [] (int index) const {
	if (index >= 0 && index < this->getLen()) {
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

		for (int i = 0; i < strlen(obj.str); ++i) {
			this->str[i] = obj.str[i];
		}
		this->str[strlen(obj.str)] = '\0';
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
	for (int i = 0; i < strlen(this->str); ++i) {
		oldStr[i] = this->str[i];
		i++;
	}
	oldStr[strlen(this->str)] = '\0';

	int newSize = strlen(this->str) + strlen(obj.str);
	this->setSize(newSize);

	delete[] this->str;
	this->str = new char[this->getSize() + 1];
	this->str[0] = '\0';

	strcat(this->str, oldStr);
	strcat(this->str, obj.str);
}

void String::delChar(char ch) {
	for (int i = 0; i < this->getSize(); ++i) {
		if (this->str[i] == ch) {
			for (int j = i; j < strlen(this->str); ++j) {
				this->str[j] = this->str[j + 1];
			}
		}
	}
}

void deletingSymbols(String& s1, const String& s2) {
	for (int i = 0; i < s1.getLen(); ++i) {
		for (int j = 0; j < s2.getLen(); ++j) {
			if (s1[i] == s2[j]) {
				s1.delChar(s2[j]);
			}
		}
	}
}