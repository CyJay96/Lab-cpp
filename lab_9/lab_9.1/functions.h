#pragma once
#include <iostream>
#include <vector>
#include <string>>
#include <conio.h>

using namespace std;

const int N = 100;

const string separators = " .,:;!?-()";

bool search_char(string str, char ch);
bool search_str(string s1, string s2);
string select_word(string str, int start_pos);
void create_arr(vector<string>& words, string current_word);
string create_new_str(vector<string>& words);