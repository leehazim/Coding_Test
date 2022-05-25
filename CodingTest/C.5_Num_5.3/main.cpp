#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> Multiply(vector<int> num1, vector<int> num2) {
	const int sign = (num1.front() < 0) ^ (num2.front() < 0) ? -1 : 1; // ��������� ������� �������� Ȯ���ϱ� ���� ���� ����
	num1.front() = abs(num1.front()), num2.front() = abs(num2.front()); // ���� ����� ������� �������� Ȯ�� ���� ����� ������ ������ �ʵ��� ��ȣ�� ���ȭ

	vector<int> result(size(num1) + size(num2), 0);
	for (int i = size(num1) - 1; i >= 0; --i) { // index 0�� ������ ���� ���ڸ��� �����߱⶧���� ���� �ڿ��� ���� ����
		for (int j = size(num2) - 1; j >= 0; --j) {
			result[i + j + 1] += num1[i] * num2[j]; 
			result[i + j] += result[i + j + 1] / 10; // �迭�� ���� ������ ���� ä���. 
			result[i + j + 1] %= 10;
		}
	}

	result = {
		find_if_not(begin(result), end(result), [](int a) { return a == 0; }),end(result)
	};
	if (empty(result)) return { 0 };
	result.front() *= sign;
	return result;
}
// �˰��� ¥�� �Ϳ� �ɼ��������� ��� �ϴ°� ������
// ���� ������ ���ϰ� ������ ���� �׷��ǰ�.

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