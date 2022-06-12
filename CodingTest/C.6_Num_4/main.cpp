#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// �������⵵�� ����ؼ� �����ϰ� Ǯ���� ���
string Rule(string& Input) {
	string temp; 
	for (int i = 0; i < Input.size(); i++) {
		if (Input[i] == 'a') {
			temp.push_back('d');
			temp.push_back('d');
		}
		else if (Input[i] == 'b') {
			continue;
		}
		else {
			temp.push_back(Input[i]);
		}
	}
	return temp;
}

// �������⵵�� �ø��� �ʰ� Ǯ���ϴ� ���
// �׷��� ���� ���⵵�� �ٿ����� �ð����⵵�� �״���̴�.
// �����ϰ� ���α׷��� �ؾ��ϴ� ��찡 �ƴ϶�� ���� ���⵵�� ����ϴ°�
// �ڵ带 �ľ��ϱ� �������δ�.
// ������ �������⵵�� ������� n�� �Ǳ⶧���� �̿��̸� �������⵵��
// ��������ʴ� ����� �� Ÿ���ϱ⵵ �ϴ�.
int ReplaceAndRemove(int size, char s[]) {
	int write_idx = 0, a_count = 0;
	for (int i = 0; i < size; i++) {
		if (s[i] != 'b') {
			s[write_idx++] = s[i]; // b�� �ƴϸ� �迭�� �� ���Ҹ� �ٽ� �߰��Ѵ�.
		}
		if (s[i] == 'a') { // a�̸� d�� �ι����� ������ a�� ������ �߰��Ѵ�.
			a_count++;
		}
	}
	int cur_idx = write_idx - 1; // �ڿ��� ���� �ۼ��� �����Ѵ�.
	write_idx = write_idx + a_count - 1; // ���� ������ a�� ������ŭ �ѹ��� �� �߰��ؾ��Ѵ�.
	const int final_size = write_idx + 1; // ������ ũ��� ������ idx���� �ϳ� ū ������� ��ȯ�Ѵ�.
	while (cur_idx >= 0) { // �ڿ������� ���ڿ��� �ٽ� �� �� �ִ� ��� idx����
		if (s[cur_idx] == 'a') { //������ �ϴ� ��ġ�� ���ڿ��� a �ΰ��
			s[write_idx--] = 'd'; // �ڿ��� ���� d�� �� ����.
			s[write_idx--] = 'd';
		}
		else {
			s[write_idx--] = s[cur_idx]; // a�� �ƴ� ��� ���ڿ��� �׳� �� ���� ����.
		}
		cur_idx--; 
	}
	return final_size;
}

int main(void) {

	char str[128] = "absab";
	int size = ReplaceAndRemove(strlen(str), str);
	for (int i = 0; i < size; i++) {
		cout << str[i];
	}
	cout << endl;

	string str2("absab");
	str2 = Rule(str2);
	cout << str2 << endl;

	return 0;
}