#include <iostream>
#include <string>

bool IsPalindrome(const std::string& str) {
	int i = 0, j = size(str) - 1;
	while (i < j) {
		while (!isalnum(str[i]) && i < j) {
			++i;
		}
		while (!isalnum(str[j]) && i < j) {
			--j;
		}
		if (tolower(str[i++]) != tolower(str[j--])) {
			return false;
		}
	}
	return true;
}

int main(void) {
	std::string str("A man, a plan, a nanal, Panama.");
	std::string str2("amna");
	bool isPalindrome = IsPalindrome(str2);
	std::cout << (isPalindrome ? "true" : "false") << std::endl;
	return 0;
}