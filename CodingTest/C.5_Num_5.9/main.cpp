#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

std::vector<int> GeneratePrimes(int n) {
	std::vector<int> primes;
	// is_prime[p]는 p가 소수인지 아닌지 나타낸다. 초기에는 0과 1을 제외한
	// 나머지 모두를 참으로 세팅한다. 그 다음에 소수가 아닌 숫자들을 걸러낸다.
	std::deque<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int p = 2; p <= n; p++) {
		// 모두 참으로 세팅되어있던 숫자크기만큼의 배열을 통해서 그 배열에 참이 들어있으면
		// 새로운 배열의 뒤에 소수라고 배열에 적힌 인덱스를 벡터에 추가한다.
		if (is_prime[p]) primes.emplace_back(p);

		// 소수 라고 판명되었던 수의 배수들은 소수일 수 가 업기 때문에 소수의 배수들은 배열에서 false로 갱신한다.
		for (int i = p * 2; i <= n; i += p) 
			is_prime[i] = false;
	}
	return primes;
}

int main(void) {
	
	std::vector<int> vi = GeneratePrimes(1000);
	for (std::vector<int>::iterator it = vi.begin(); it != vi.end(); it++) std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}