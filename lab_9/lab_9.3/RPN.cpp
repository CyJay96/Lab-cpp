#include "RPN.h"

void correction(string& expression) {
	for (int i = 0; i < expression.size(); ++i) {
		if (expression[i] == ' ') {
			expression.erase(i, 1);
			i--;
		}
	}

	char last = expression[expression.size() - 1];

	if (last != '=') {
		if (last == '*' || last == '/' || last == '*' || last == '+' || last == '-' || last == '(') {
			expression.pop_back();
		}
		expression.push_back('=');
	}
}

string convertToRPN(string expression) {
	correction(expression);

	string result;
	result.clear();

	multimap<char, int> symbols;
	symbols.insert(make_pair('*', 3));
	symbols.insert(make_pair('/', 3));
	symbols.insert(make_pair('+', 2));
	symbols.insert(make_pair('-', 2));
	symbols.insert(make_pair('(', 1));
	symbols.insert(make_pair('=', 0));

	list<string> operands; // числа
	list<char> signs; // знаки

	for (int i = 0; i < expression.size(); ++i) {
		string currentOperand; // текущее число
		currentOperand.clear();

		multimap<char, int>::iterator iMapSym = symbols.find(expression[i]);
		if (iMapSym == symbols.end()) { // если число
			while (i < expression.size() && iMapSym == symbols.end()) { // заполянем текущее число
				if (expression[i] == ')') { // отыскиваем левую скобку, перенося знаки в список операндов
					break;
				}
				currentOperand.push_back(expression[i]);
				iMapSym = symbols.find(expression[++i]);
			}

			operands.push_back(currentOperand);
		}

		if (expression[i] == ')') { // отыскиваем левую скобку, перенося знаки в список операндов
			list<char>::reverse_iterator iMoveSigns = signs.rbegin();
			while (iMoveSigns != signs.rend() && (*iMoveSigns) != '(') {
				string charToString;
				charToString = *iMoveSigns;
				operands.push_back(charToString);
				signs.erase(next(iMoveSigns).base());
			}
			if ((*iMoveSigns) == '(') {
				signs.erase(next(iMoveSigns).base());
			}
		}

		if (iMapSym != symbols.end()) {
			signs.push_back(iMapSym->first);
		}

		// iMapSym - следующий знак за числом
		if (signs.size() > 1 && iMapSym != symbols.end() && iMapSym->first != '(') {
			list<char>::reverse_iterator headSigns = signs.rbegin(); // вершина списка знаков
			++headSigns;
			map<char, int>::iterator headSignsMap = symbols.find(*headSigns); // вершина списка знаков в map
			while (headSigns != signs.rend() && iMapSym->second <= headSignsMap->second) {
				string charToString;
				charToString = *headSigns;

				operands.push_back(charToString);
				signs.erase(next(headSigns).base());

				headSigns = signs.rbegin();
				if (signs.size() > 1) {
					++headSigns;
					headSignsMap = symbols.find(*headSigns);
				}
				else if (expression[i] == '=') {
					continue;
				}
				else {
					break;
				}
			}
		}
	}

	list<string>::iterator iOperands = operands.begin();
	while (iOperands != operands.end()) {
		result += *iOperands + " ";
		++iOperands;
	}

	return result;
}

double calculateRPN(string polExpression) {
	double result = 0;

	multimap<char, int> symbols;
	symbols.insert(make_pair('*', 3));
	symbols.insert(make_pair('/', 3));
	symbols.insert(make_pair('+', 2));
	symbols.insert(make_pair('-', 2));
	symbols.insert(make_pair('(', 1));
	symbols.insert(make_pair('=', 0));

	list<string> operands;

	for (int i = 0; i < polExpression.size(); ++i) {
		string currentOperand;
		currentOperand.clear();

		while (polExpression[i] != ' ') {
			currentOperand.push_back(polExpression[i++]);
		}

		operands.push_back(currentOperand);
	}

	list<string>::iterator iOperands = operands.begin();
	while (iOperands != operands.end()) {
		if ((*iOperands)[0] == '=') {
			--iOperands;
			result = stod(*iOperands);
			break;
		}

		multimap<char, int>::iterator iMapSym = symbols.find((*iOperands)[0]);
		if (iMapSym != symbols.end()) {
			--iOperands; --iOperands;
			double firstOperand = stod(*iOperands);
			++iOperands;
			double secondOperand = stod(*iOperands);
			--iOperands;
			
			double resultOperand = 0;

			switch (iMapSym->first) {
			case '*':
				resultOperand = firstOperand * secondOperand;
				break;
			case '/':
				resultOperand = firstOperand / secondOperand;
				break;
			case '+':
				resultOperand = firstOperand + secondOperand;
				break;
			case '-':
				resultOperand = firstOperand - secondOperand;
				break;
			default:
				cerr << "OPERATION NOT DEFINED" << endl;
				exit(0);
				break;
			}

			iOperands = operands.erase(iOperands);
			iOperands = operands.erase(iOperands);
			iOperands = operands.erase(iOperands);

			operands.insert(iOperands, to_string(resultOperand));

			iOperands = operands.begin();
		}
		else {
			++iOperands;
		}
	}

	return result;
}