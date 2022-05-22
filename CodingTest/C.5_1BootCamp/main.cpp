#include <iostream>
#include <vector>


void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void EvenOdd(std::vector<int>* A_ptr) {
	std::vector<int>& A = *A_ptr;
	int next_even = 0, next_odd = size(A) - 1;
	while (next_even < next_odd) {
		if (A[next_even] % 2 == 0)
			++next_even;
		else
			swap(A[next_even], A[next_odd--]);
	}
}

int main(void) {

	std::vector<int> testVector;
	testVector.push_back(5);
	testVector.push_back(3);
	testVector.push_back(7);
	testVector.push_back(6);
	testVector.push_back(8);
	testVector.push_back(10);
	testVector.push_back(2);

	std::vector<int>::iterator it = testVector.begin();
	for (; it != testVector.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	EvenOdd(&testVector);
	for (it = testVector.begin(); it != testVector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}