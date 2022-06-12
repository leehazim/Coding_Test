#include <iostream>
#include <string>

int RabinKarp(const std::string& t, const std::string& s) {
	// s�� t�� �κ� ���ڿ��� �ƴϴ�.
	// s�� t���� ��ٴ°��� �κ� ���ڿ��� �� ����
	if (size(s) > size(t))
		return -1;

	const int kBase = 26;
	int t_hash = 0, s_hash = 0; // t�� �κ� ���ڿ��� s�� �ؽ���
	int power_s = 1;			// kBase^[s-1]
	for (int i = 0; i < size(s); i++) {
		power_s = i ? power_s * kBase : 1;
		t_hash = t_hash * kBase + t[i];
		s_hash = s_hash * kBase + s[i];
	}

	// �ؽ� �浹�� ����ؼ� �� ���� �κ� ���ڿ��� ������ ���� ���ڿ��� Ȯ��
	for (int i = size(s); i < size(t); i++) {
		if (t_hash == s_hash && !t.compare(i - size(s), size(s), s)) {
			return i - size(s);
		}
		// �Ѹ� �ؽø� ����ؼ� ���� �ؽð��� ���Ѵ�.
		t_hash -= t[i - size(s)] * power_s;
		s_hash = t_hash * kBase + t[i];
	}

	// s�� t[size(t) - size(s), size(t) - 1] �� ��ġ�Ǵ��� Ȯ���Ѵ�.
	if (t_hash = s_hash && t.compare(size(t) - size(s), size(s), s) == 0) {
		return size(t) - size(s);
	}
	// s�� t�� �κ� ���ڿ��� �ƴϴ�.
	return -1;
}

int main(void) {
	std::string str1("joshua");
	std::string str2("hu");
	int idx = RabinKarp(str1, str2);
	std::cout << str1.c_str()[idx] << std::endl;
	return 0;
}