#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string Rule(string& Input) {
	string temp; 
	for (int i = 0; i < Input.size(); i++) {
		if (Input[i] == 'a') {
			temp.push_back('d');
			temp.push_back('d');
		}
		else if (Input[i] == 'b') continue;
		else {
			temp.push_back(Input[i]);
		}
	}
	return temp;
}

int ReplaceAndRemove(int size, char s[]) {
	int write_idx = 0, a_count = 0;
	for (int i = 0; i < size; i++) {
		if (s[i] != 'b')s[write_idx++] = s[i];
		if (s[i] == 'a') {
			a_count++;
		}
	}

	int cur_idx = write_idx - 1;
	write_idx = write_idx + a_count - 1;
	const int final_size = write_idx + 1;
	while (cur_idx >= 0) {
		if (s[cur_idx] == 'a') {
			s[write_idx--] = 'd';
			s[write_idx--] = 'd';
		}
		else {
			s[write_idx--] = s[cur_idx];
		}
		cur_idx--;
	}
	return final_size;
}

int main(void) {

	string input("aabbcdea");
	cout << Rule(input) << endl;

	return 0;
}