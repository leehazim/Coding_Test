#include <iostream>
#include <vector>

using namespace std;

void AddPrime(vector<int>& Arr) {
	
	reverse(Arr.begin(), Arr.end());
	int sizeArr = size(Arr);
	int i = 0;
	while (true) {
		Arr[i]++;
		if (Arr[i] == 10) {
			Arr[i] %= 10;
		}
		else {
			break;
		}

		if (++i == sizeArr) {
			Arr.push_back(0);
		}
	}
	reverse(Arr.begin(), Arr.end());
}

int main(void) {
	
	vector<int> A = { 9, 9, 9, 9 }; // 이게 129를 나타내는 것이다.
	vector<int>::iterator it;
	for (it = A.begin(); it != A.end(); it++) cout << *it << " ";
	cout << endl;

	AddPrime(A);
	for (it = A.begin(); it != A.end(); it++) cout << *it << " ";
	cout << endl;

	return 0;
}