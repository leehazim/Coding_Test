#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;

int SSDecodeColID(const string& col) {
	return accumulate(begin(col), end(col), 0, [](int result, char c) {
		return result * 26 + c - 'A' + 1;
					  });
}