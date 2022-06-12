#include <iostream>
#include <string>

int RabinKarp(const std::string& t, const std::string& s) {
	// s는 t의 부분 문자열이 아니다.
	// s가 t보다 길다는것은 부분 문자열일 수 없다
	if (size(s) > size(t))
		return -1;

	const int kBase = 26;
	int t_hash = 0, s_hash = 0; // t의 부분 문자열과 s의 해쉬값
	int power_s = 1;			// kBase^[s-1]
	for (int i = 0; i < size(s); i++) {
		power_s = i ? power_s * kBase : 1;
		t_hash = t_hash * kBase + t[i];
		s_hash = s_hash * kBase + s[i];
	}

	// 해시 충돌을 고려해서 두 개의 부분 문자열이 실제로 같은 문자열인 확인
	for (int i = size(s); i < size(t); i++) {
		if (t_hash == s_hash && !t.compare(i - size(s), size(s), s)) {
			return i - size(s);
		}
		// 롤링 해시를 사용해서 다음 해시값을 구한다.
		t_hash -= t[i - size(s)] * power_s;
		s_hash = t_hash * kBase + t[i];
	}

	// s가 t[size(t) - size(s), size(t) - 1] 와 배치되는지 확인한다.
	if (t_hash = s_hash && t.compare(size(t) - size(s), size(s), s) == 0) {
		return size(t) - size(s);
	}
	// s는 t의 부분 문자열이 아니다.
	return -1;
}

int main(void) {
	std::string str1("joshua");
	std::string str2("hu");
	int idx = RabinKarp(str1, str2);
	std::cout << str1.c_str()[idx] << std::endl;
	return 0;
}