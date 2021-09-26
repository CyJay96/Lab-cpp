#include "functions.h"

bool search_char(string str, char ch) {
	bool flag = false;

	for (int i = 0; i < str.length(); ++i) {
		if (ch == str[i]) {
			flag = true;
			break;
		}
	}

	return flag;
}

bool search_str(string s1, string s2) {
	bool flag = true;

	for (int i = 0; i < s2.length(); ++i) {
		if (!search_char(s1, s2[i])) {
			flag = false;
			break;
		}
	}

	return flag;
}

string roman(int n) {
	const int K_RIM_ARAB = 13;

	const string rim[K_RIM_ARAB] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
	const int arab[K_RIM_ARAB] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

	string res = { 0 };
	int k = K_RIM_ARAB - 1;

	if (n <= 0) {
		res += "0";
	}

	while (n > 0) {
		while (n < arab[k]) {
			k--;
		}
		res += rim[k];
		n -= arab[k];
	}

	return res;
}

string hex_to_bin(string num16) {
	const int SIZE = 18;

	const string HEX = "0123456789ABCDEF.";
	const string hex = "0123456789abcdef.";

	const string bin[SIZE] = { {"0000"}, {"0001"}, {"0010"}, {"0011"}, {"0100"}, {"0101"}, {"0110"}, {"0111"},
							   {"1000"}, {"1001"}, {"1010"}, {"1011"}, {"1100"}, {"1101"}, {"1110"}, {"1111"}, {"."} };

	string num2 = { 0 };

	for (int i = 0; i < num16.length(); ++i) {
		for (int j = 0; j < hex.length(); ++j) {
			if (num16[i] == HEX[j] || num16[i] == hex[j]) {
				num2 += bin[j] + " ";
				break;
			}
		}
	}

	return num2;
}

string word_selection(string str) {
	const string separators = " .,:;!?-()";

	string last_word = "";
	string new_str = "";

	//длина строки, есть на конце есть разделители
	int len = str.length() - 1;
	while (search_char(separators, str[len])) {
		len--;
	}

	//длина последнего слова
	int len_last = 0;
	while (!search_char(separators, str[len]) && len >= 0) {
		last_word += str[len];
		len--;
	}

	//поиск слов
	for (int i = 0; i <= len; ++i) {
		string tec_word = "";

		while (!search_char(separators, str[i])) {
			tec_word += str[i];
			i++;
		}

		while (search_char(separators, str[i])) {
			i++;
		}

		i--;

		if (search_str(last_word, tec_word)) {
			new_str += tec_word + " ";
		}
	}

	return new_str;
}