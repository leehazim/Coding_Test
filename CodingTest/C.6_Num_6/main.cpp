#include <iostream>
#include <string>

// 알고림즘들은 참 신기하다.
// 명령을 어떻게 순서를 작성하는 지에 대해서 깊은 생각을 하는 방법을 잘 파악하자.
void ReverseWords(std::string* str) {
	// 단어 전체를 우선 뒤집는다.
	reverse(begin(*str), end(*str));
	// std::cout << *str << std::endl;

	size_t start = 0, finish;
	while ((finish = str->find(" ", start)) != std::string::npos) {
		// start 부터 공백까지의 문자열을 찾는다.
		// 그리고 그 문자열(단어)를 다시 뒤집는다.
		reverse(begin(*str) + start, begin(*str) + finish);
		// 그리고 찾은 공백 다음 부터 다시 다음 공백을 찾는다.
		// 만약 문자열이 끝났으면 쓰래기값들을 찾으며 finish는 string이 가질 수 있는 최대값으로 수렴했을 것
		// 그러면 while문 종료
		start = finish + 1;
	}
	reverse(begin(*str) + start, end(*str));
}

int main(void) {
	std::string str("I study C++");
	ReverseWords(&str);
	std::cout << str << std::endl;
	return 0;
}
