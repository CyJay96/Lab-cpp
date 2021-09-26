#include "functions.h"

bool search_char(string str, char ch) {
	for (int i = 0; i < str.length(); ++i) {
		if (ch == str[i]) {
			return true;
		}
	}

	return false;
}

bool search_str(string s1, string s2) {
	for (int i = 0; i < s2.length(); ++i) {
		if (!search_char(s1, s2[i])) {
			return false;
		}
	}

	return true;
}

string select_word(string str, int start_pos) {
	string current_word = "";

	int i = 0;
	while (!search_char(separators, str[start_pos]) && start_pos < str.length()) {
		current_word += str[start_pos++];
	}

	return current_word;
}

void create_arr(vector<string>& words, string current_word) {
	words.push_back(current_word);
}

string create_new_str(vector<string>& words) {
	string new_str = "";

	vector<string>::iterator i = words.begin();
	while (i != words.end()) {
		string s1 = *i;

		string new_str_before = new_str;
		new_str += s1 + " ";
		string new_str_after = new_str;

		vector<string>::iterator j = i + 1;
		while (j != words.end()) {
			string s2 = *j;

			if (search_str(s1, s2)) {
				new_str += s2 + " ";
			}

			++j;
		}

		if (new_str_after == new_str) {
			new_str = new_str_before;
		}

		if (new_str != "") {
			break;
		}

		++i;
	}

	return new_str;
}