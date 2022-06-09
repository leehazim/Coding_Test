#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

void RandomSampling(int k, std::vector<int>* A_ptr) {
	std::vector<int>& A = *A_ptr;
	std::default_random_engine seed((std::random_device())());
	for (int i = 0; i < k; i++) {
		std::swap(A[i], A[std::uniform_int_distribution<int>{i, static_cast<int>(A.size() - 1)}(seed)]);
	}
}

std::vector<int> ComputeRandomPermutation(int n) {
	std::vector<int> permutation(n);
	std::iota(begin(permutation), end(permutation), 0);
	RandomSampling(n, &permutation);
	return permutation;
}

