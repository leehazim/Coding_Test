#include <iostream>
#include <vector>
#include <algorithm>

void ApplyPermutation(std::vector<int> perm, std::vector<int>* A_ptr) {
	std::vector<int>& A = *A_ptr;
	for (size_t i = 0; i < size(A); i++) {
		while (perm[i] != i) {
			std::swap(A[i], A[perm[i]]);
			std::swap(perm[i], perm[perm[i]]);
		}
	}
}

int main(void) {

	std::vector<int> vi = { 1, 5, 3, 4, 2 };
	std::vector<int> perm = { 2, 0, 1, 3, 4 };
	
	ApplyPermutation(perm, &vi);
	for (std::vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
		std::cout << (char)('a' + *it - 1) << " ";
	std::cout << std::endl;
	
	return 0;
}