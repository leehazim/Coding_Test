#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 공간복잡도를 희생해서 무식하게 풀이한 방법
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

// 공간복잡도를 늘리지 않고 풀이하는 방법
// 그런데 공간 복잡도는 줄였지만 시간복잡도는 그대로이다.
// 빡빡하게 프로그래밍 해야하는 경우가 아니라면 공간 복잡도를 희생하는게
// 코드를 파악하기 쉬워보인다.
// 하지만 공간복잡도가 상수에서 n이 되기때문에 이왕이면 공간복잡도도
// 사용하지않는 방법이 더 타당하기도 하다.
int ReplaceAndRemove(int size, char s[]) {
	int write_idx = 0, a_count = 0;
	for (int i = 0; i < size; i++) {
		if (s[i] != 'b') {
			s[write_idx++] = s[i]; // b가 아니면 배열에 그 원소를 다시 추가한다.
		}
		if (s[i] == 'a') { // a이면 d를 두번쓰기 때문에 a의 개수도 추가한다.
			a_count++;
		}
	}
	int cur_idx = write_idx - 1; // 뒤에서 부터 작성을 시작한다.
	write_idx = write_idx + a_count - 1; // 쓰기 개수는 a의 개수만큼 한번씩 더 추가해야한다.
	const int final_size = write_idx + 1; // 마지막 크기는 쓰기할 idx보다 하나 큰 사이즈로 반환한다.
	while (cur_idx >= 0) { // 뒤에서부터 문자열을 다시 쓸 수 있는 허용 idx동안
		if (s[cur_idx] == 'a') { //쓰려고 하는 위치의 문자열이 a 인경우
			s[write_idx--] = 'd'; // 뒤에서 부터 d를 더 쓴다.
			s[write_idx--] = 'd';
		}
		else {
			s[write_idx--] = s[cur_idx]; // a가 아닌 경우 문자열을 그냥 써 내려 간다.
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