#include <iostream>

short GetBitCount(int in) {
	short count = 0;
	while (in) {
		count += in & 1;
		in >>= 1;
		/*	count ^= (x & 1);
			count >>= 1; 
			�� �����ϴ�. 1�� 1��Ʈ�� Ȧ�����̸� Ȧ���� ����Ǹ鼭 1�� ���� �ɰ��̴�. */
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