#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> Multiply(vector<int> num1, vector<int> num2) { 
	// ^ xor연산자 둘다 참이면 거짓임으로 양수가 되어야 하고  둘다 거짓이어도 두수가 양수임으로 거짓으로 회귀하도록 xor연산을 실행 
	const int sign = (num1.front() < 0) ^ (num2.front() < 0) ? -1 : 1; // 곱셈결과가 양수인지 음수인지 확인하기 위한 삼항 연산
	num1.front() = abs(num1.front()), num2.front() = abs(num2.front()); // 곱센 결과가 양수인지 음수인지 확인 이후 연산시 음수가 나오지 않도록 부호를 양수화

	vector<int> result(size(num1) + size(num2), 0); // m의 자리 숫자와 n의 자리 숫자의 곱의 최대길이는 m+n이다. 그래서 그만큼의 배열을 할당해둠

	for (int i = size(num1) - 1; i >= 0; --i) { // index 0이 숫자의 가장 앞자리로 가장했기때문에 가장 뒤에서 부터 시작
		for (int j = size(num2) - 1; j >= 0; --j) {
			result[i + j + 1] += num1[i] * num2[j]; // 마지막 자리수를 곱셈해서 가장 마지막 인덱스에 채운다.
			result[i + j] += result[i + j + 1] / 10; // 그 다음 자리수에 10의 자리 이사으올 나온 결과값을 추가
			result[i + j + 1] %= 10;				 // 10의자리 수가 넘어가는 수는 다음 자리로 넘겼으니까 다시 내린다.
		}
	}

	result = {
		find_if_not(begin(result), end(result), [](int a) { return a == 0; }),
		end(result) };
	if (empty(result)) return { 0 };
	result.front() *= sign;
	return result;
}
// 알고리즘 짜는 것에 능숙해지려면 어떻게 하는게 좋을까
// 내가 생각을 안하고 뭔제를 봐서 그런건가.

int main(void) {
	vector<int> num1 = { 1,2 };
	vector<int> num2 = { 1,1 };
	vector<int> result = Multiply(num1, num2);
	vector<int>::iterator it;
	for (it = result.begin(); it != result.end(); it++)
		cout << *it;
	cout << endl;

	return 0;
}