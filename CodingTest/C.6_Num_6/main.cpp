#include <iostream>
#include <string>

// �˰������ �� �ű��ϴ�.
// ����� ��� ������ �ۼ��ϴ� ���� ���ؼ� ���� ������ �ϴ� ����� �� �ľ�����.
void ReverseWords(std::string* str) {
	// �ܾ� ��ü�� �켱 �����´�.
	reverse(begin(*str), end(*str));
	// std::cout << *str << std::endl;

	size_t start = 0, finish;
	while ((finish = str->find(" ", start)) != std::string::npos) {
		// start ���� ��������� ���ڿ��� ã�´�.
		// �׸��� �� ���ڿ�(�ܾ�)�� �ٽ� �����´�.
		reverse(begin(*str) + start, begin(*str) + finish);
		// �׸��� ã�� ���� ���� ���� �ٽ� ���� ������ ã�´�.
		// ���� ���ڿ��� �������� �����Ⱚ���� ã���� finish�� string�� ���� �� �ִ� �ִ밪���� �������� ��
		// �׷��� while�� ����
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
