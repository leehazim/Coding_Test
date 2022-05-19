#include <iostream>

long long int SwapBit(long long x, int i, int j) {
	if (((x >> i) & 1) != ((x >> j) & 1)) {
		// 두 개의 비트를 바꾼다는 이야기는 두 비트가 같으면 교환이 이루어질 이유가 없음이 1번
		// 두 개의 비트가 서로 다르다는 전제하에 
		// 둘을 1로 xor연산을 하면 1이면 0으로 바뀌고 0 이면 1로 바뀌는 결과가 생겨 두 값이 뭐였든 스왑이 된다.
		unsigned long long bit_mask = (1L << i) | (1L << j);
		x ^= bit_mask;
	}
	return x;
}

// 비트마스크가 알고리즘에 관련해서는 필요한 문제일 수는 있는데 게임 프로그래밍을 공부하는 과정에서 공부해야 하는 이유가 있을까?

int main(void) {
	
	return 0;
}