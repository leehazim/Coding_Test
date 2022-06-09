#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

void RandomSampling(int k, std::vector<int>* A_ptr) {
	std::vector<int>& A = *A_ptr;
	std::default_random_engine seed((std::random_device())());
	for (int i = 0; i < k; i++) {
		std::swap(A[i], A[std::uniform_int_distribution<int>{ i, static_cast<int>(A.size()) - 1 }(seed)]);
	}
}

int main(void) {

	std::vector<int> v = { 2, 4, 5, 3, 6 };
	RandomSampling(3, &v);
	for (std::vector<int>::iterator it = v.begin(); it != v.begin() + 3; it++) std::cout << *it << " ";
	std::cout << std::endl;
	return 0;
}