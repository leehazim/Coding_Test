#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

std::vector<int> GeneratePrimes(int n) {
	std::vector<int> primes;
	// is_prime[p]�� p�� �Ҽ����� �ƴ��� ��Ÿ����. �ʱ⿡�� 0�� 1�� ������
	// ������ ��θ� ������ �����Ѵ�. �� ������ �Ҽ��� �ƴ� ���ڵ��� �ɷ�����.
	std::deque<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int p = 2; p <= n; p++) {
		// ��� ������ ���õǾ��ִ� ����ũ�⸸ŭ�� �迭�� ���ؼ� �� �迭�� ���� ���������
		// ���ο� �迭�� �ڿ� �Ҽ���� �迭�� ���� �ε����� ���Ϳ� �߰��Ѵ�.
		if (is_prime[p]) primes.emplace_back(p);

		// �Ҽ� ��� �Ǹ�Ǿ��� ���� ������� �Ҽ��� �� �� ���� ������ �Ҽ��� ������� �迭���� false�� �����Ѵ�.
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