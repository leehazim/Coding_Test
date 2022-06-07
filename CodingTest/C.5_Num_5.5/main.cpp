#include <iostream>
#include <vector>
#include <algorithm>

// 중복된 원소가 떨어져 있으면 적용이 안되기 때문에 정렬을 한 뒤에 사용 하자.
int DeleteDuplicates(std::vector<int>* A_ptr) {
	std::vector<int>& A = *A_ptr;
	if (empty(A)) {
		return 0;
	}

	int write_index = 1;
	for (int i = 1; i < size(A); i++) {
		if (A[write_index - 1] != A[i]) {
			A[write_index++] = A[i];
		}
	}
	return write_index;
}

int main(void) {
	std::vector<int> q;
	std::vector<int>::iterator it;
	
	srand(time(nullptr));
	for (int i = 0; i < 25; i++)
		q.push_back(rand() % 25);
	
	for (it = q.begin(); it != q.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::sort(q.begin(), q.end());
	int index = DeleteDuplicates(&q);
	for (int i = 0; i < index; i++)
		std::cout << q[i] << " ";
	std::cout << std::endl;
	return 0;
}