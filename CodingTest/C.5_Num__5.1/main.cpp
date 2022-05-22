#include <iostream>
#include <vector>
#include <Time.h>

void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int Partition(int* arr, int left, int right) {

	int Pivot, Temp;
	int Low, High;

	Low = left;
	High = right + 1;
	Pivot = arr[left];

	do {
		do {
			Low++;
		} while (Low <= right && arr[Low] < Pivot);
		do {
			High--;
		} while (High >= left && arr[High] > Pivot);
		if (Low < High) Swap(arr[Low], arr[High]);
	} while (Low < High);

	Swap(arr[left], arr[High]);

	return High;
}

void Quick(int* Arr, int Start, int End) {
	if (Start < End) {
		int pivot = Partition(Arr, Start, End);

		Quick(Arr, Start, pivot - 1);
		Quick(Arr, pivot + 1, End);
	}
}

// ������ ���� ����鿡 ���� ���� Enum���� ǥ���� ���°� 
typedef enum {kRed, kWhite, kBlue} Color;
// ��ȯ�Լ�
void swap(Color& a, Color& b) {
	Color tmp = a;
	a = b; 
	b = tmp;
}

void DutchFlagPartition1(int pivot_index, std::vector<Color>* A_ptr) {
	std::vector<Color>& A = *A_ptr;
	Color pivot = A[pivot_index];

	// ù �ܰ� : �ǹ����� ���� ������ �׷��� ���Ѵ�.
	for (int i = 0; i < size(A); i++) {
		for (int j = i + 1; j < size(A); j++) {
			if (A[j] < pivot) {
				swap(A[i], A[j]);
				break;
			}
		}
	}
	// �� �ܰ� : �ǹ����� ū ������ �׷��� ���Ѵ�.
	for (int i = size(A) - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (A[j] > pivot) {
				swap(A[i], A[j]);
				break;
			}
		}
	}
}

// �� �Լ����� �ð����⵵�� ���̱� ���� ���. 
// ���� ������ ���� �ǹ����� ���� ���ҵ��� ��� ������ �ű��.
void DutchFlagPartition2(int pivot_index, std::vector<Color>* A_ptr) {
	std::vector<Color>& A = *A_ptr;
	Color pivot = A[pivot_index];
	int smaller = 0;
	for (int i = 0; i < size(A); i++) {
		if (A[i] < pivot) {
			swap(A[i], A[smaller++]);
		}
	}
	int larger = size(A) - 1;
	for (int i = size(A) - 1; i >= 0; --i) {
		if (A[i] > pivot) {
			swap(A[i], A[larger--]);
		}
	}
}

// �з��ؾ� �� �κ��� 4������ ������.
// 1. �ǹ����� ���� ����(bottom)
// 2. �ǹ��� ���� ���� ( equal)
// 3. �̺з� ���� ( unclassified)
// 4. �ǹ����� ū ����(top)
void DutchFlagPartition3(int pivot_index, std::vector<Color>* A_ptr) {
	std::vector<Color>& A = *A_ptr;
	Color pivot = A[pivot_index];

	// �з��� ������ ���� �Һ����� ����
	// 1. �ǹ����� ���� ���� �׷� : A[0, smaller-1]
	// 2. �ǹ��� ���� ���� �׷�	: A[smaller, equal-1]
	// 3. �̺з� ���� �׷�		: A[equal, larger-1]
	// 4. �ǹ����� ū ���� �׷�	: A[larger, size(A)- 1]
	int smaller = 0, equal = 0, larger = size(A);
	while (equal < larger) {
		if (A[equal] < pivot) { 
			// A[equal]�� �̺з� ���׷쿡 ���Ѵ�. �� �̺з� ���Ұ� �ǹ����� ������ ���� �׷쿡 ���Ѵ�.
			// ���� �κ��� �ε��� �ȿ� �߰��ϰ� ���� �̺з� ������ �ε����� �̵�
			swap(A[smaller++], A[equal++]);
		}
		else if (A[equal] == pivot) {
			// �̺з��� ���Ұ� �ǹ��� ���ٸ� ���� �̺з� ���� �˻縦 ���ؼ� �迭�� �������� �ʰ� �Ѿ��.
			equal++;
		}
		else {
			// �۰ų� ���� �ʴٸ� ũ�ٴ� ���̴�. �׷��� ���� ���������� �ؼ� �ǹ����� ū �κ����� �����Ѵ�.
			swap(A[equal], A[--larger]);
		}
	}
}
int main(void) {
	std::vector<Color> A;
	A.push_back(kRed);
	A.push_back(kWhite);
	A.push_back(kBlue);
	A.push_back(kRed);
	A.push_back(kBlue);
	A.push_back(kWhite);
	A.push_back(kWhite);
	
	std::vector<Color>::iterator it;
	for (it = A.begin(); it != A.end(); it++) std::cout << *it << " ";
	std::cout << std::endl;
	
	DutchFlagPartition3(2, &A);

	for (it = A.begin(); it != A.end(); it++) std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}