#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

std::string IntToString(int aInput) {
	char* tmp; 
	int length = 0;
	int temp = aInput;
	std::string buffer;
	while (temp) {
		length++;
		temp /= 10;
	}

	tmp = (char*)calloc(length, sizeof(char));
	for (int i = 0; i < length; i++) {
		tmp[i] = aInput % 10 + '0';
		aInput /= 10;
	}
	tmp[length] = '\0';

	for (int i = length - 1; i >= 0; i--) {
		buffer.push_back(tmp[i]);
	}

	/*free(tmp);*/
	return buffer;
}

long long int StringToInt(std::string& aInput) {
	long long int buffer = 0;
	
	for (int i = 0; i < aInput.size(); i++) {
		buffer *= 10;
		buffer += aInput.c_str()[i] - '0';
	}

	return buffer;
}

std::string IntToString1(int input) {
	bool is_negative = false;
	if (input < 0)
		is_negative = true;
	std::string buffer;
	do {
		buffer += '0' + abs(input % 10);
		input /= 10;
	} while (input);

	buffer += is_negative ? "-" : "";
	return { rbegin(buffer), rend(buffer) };
	// 공간복잡도를 늘리지 않고 완료하기 위해서 string에 있는 문자열 뒤집기를 사용하는 것이 더 효율적이다.
	// 문자열을 뒤집기위해서 필요한 메소드가 정의되어 있음을 기억하자
}

int stringToInt1(const std::string& input) {
	return (input[0] == '-' ? -1 : 1) *
		std::accumulate(begin(input) + (input[0] == '-' || input[0] == '+'), end(input), 0, [](int running_sum, char c) {
		return running_sum * 10 + c - '0';
						});
}

int main(void) {
	std::string buffer;
	long long int input;
	//std::cin >> input;
	
	buffer = IntToString(10023);
	std::cout << buffer << std::endl;

	buffer = "12003458123";
	input = StringToInt(buffer);
	std::cout << input << std::endl;

	return 0;
}