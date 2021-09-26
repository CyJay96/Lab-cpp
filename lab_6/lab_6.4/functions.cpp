#include "functions.h"

void draw_line(int n) {
	for (int i = 0; i < n; ++i) {
		cout << "-";
	}
	cout << endl;
}

void generateData(DoubleUnion& st) {
	st.numData.mantissa = rand() % INT_MAX; // 2^52
	st.numData.order = rand() % 2048; // 2^11
	st.numData.sign = rand() % 2; // 2^1
}

void output(DoubleUnion& st) {
	cout.width(widthNum); cout << left << st.num;
	cout.width(widthSign); cout << left << st.numData.sign;
	cout.width(widthOrder); cout << left << st.numData.order;
	cout.width(widthMant); cout << left << st.numData.mantissa << endl;
}

bool compNum(DoubleUnion& number1, DoubleUnion& number2) {
	return number1.num < number2.num;
}