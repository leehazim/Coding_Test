#include <iostream>

short GetBitCount(int in) {
	short count = 0;
	while (in) {
		count += in & 1;
		in >>= 1;
		/*	count ^= (x & 1);
			count >>= 1; 
			도 가능하다. 1인 1비트가 홀수개이면 홀수번 실행되면서 1이 남게 될것이다. */
	}
	return count % 2;
}

int main(void) {

	long in;
	short parity;

	std::cin >> in;
	
	parity = GetBitCount(in);
	std::cout << parity << std::endl;
	return 0;
}