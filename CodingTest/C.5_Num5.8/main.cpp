#include <iostream>
#include <vector>
#include <algorithm>

void Rearrange(std::vector<int>* A_ptr) {
	std::vector<int>& A = *A_ptr;
	for (size_t i = 1; i < size(A); i++) {
		if ((!(i % 2) && A[i - 1] < A[i]) || // i�� ¦���� �ƴҶ��� ���� �� ũ�� �ȵǰ�
			((i % 2) && A[i - 1] > A[i])) { // i�� ¦���϶��� ������ Ŀ���Ѵ�.
			std::swap(A[i - 1], A[i]);
		}
	}
}

int main(void) {

	srand(time(nullptr));
	std::vector<int> vi;
	for (int i = 0; i < 10; i++) vi.push_back(rand() % 25);
	
	std::vector<int>::iterator it;
	for (it = vi.begin(); it != vi.end(); it++) std::cout << *it << " ";
	std::cout << std::endl;
	Rearrange(&vi);
	for (it = vi.begin(); it != vi.end(); it++) std::cout << *it << " ";
	std::cout << std::endl;
	
	return 0;
}