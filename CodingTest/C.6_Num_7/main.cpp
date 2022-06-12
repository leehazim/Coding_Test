#include <iostream>
#include <string>
using namespace std;

string NextNumber(const string& s);

string LookAndSay(int n) {
	string s = "1";
	for (int i = 1; i < n; i++) {
		s = NextNumber(s);
		/*cout << "°è»êÁß" << endl;*/
	}
	return s;
}

string NextNumber(const string& s) {
	string result;
	for (int i = 0; i < size(s); i++){
		int count = 1;
		while (i + 1 < size(s) && s[i] == s[i + 1]) {
			++i, ++count;
		}
		result += to_string(count) + s[i];
	}
	return result;
}

int main(void) {
	int a = 20;
	string str(LookAndSay(a));
	cout << str << endl;

	return 0;
}