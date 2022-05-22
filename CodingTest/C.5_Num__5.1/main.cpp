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

// 국기의 구성 색상들에 대한 값을 Enum으로 표현해 보는거 
typedef enum {kRed, kWhite, kBlue} Color;
// 교환함수
void swap(Color& a, Color& b) {
	Color tmp = a;
	a = b; 
	b = tmp;
}

void DutchFlagPartition1(int pivot_index, std::vector<Color>* A_ptr) {
	std::vector<Color>& A = *A_ptr;
	Color pivot = A[pivot_index];

	// 첫 단계 : 피벗보다 작은 원소의 그룹을 구한다.
	for (int i = 0; i < size(A); i++) {
		for (int j = i + 1; j < size(A); j++) {
			if (A[j] < pivot) {
				swap(A[i], A[j]);
				break;
			}
		}
	}
	// 둘 단계 : 피벗보다 큰 원소의 그룹을 구한다.
	for (int i = size(A) - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (A[j] > pivot) {
				swap(A[i], A[j]);
				break;
			}
		}
	}
}

// 위 함수보다 시간복잡도를 줄이기 위한 방법. 
// 단일 루프를 통해 피벗보다 작은 원소들을 모두 앞으로 옮기기.
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

// 분류해야 할 부분을 4가지로 나눈다.
// 1. 피벗보다 작은 원소(bottom)
// 2. 피벗과 같은 원소 ( equal)
// 3. 미분류 원소 ( unclassified)
// 4. 피벗보다 큰 원소(top)
void DutchFlagPartition3(int pivot_index, std::vector<Color>* A_ptr) {
	std::vector<Color>& A = *A_ptr;
	Color pivot = A[pivot_index];

	// 분류할 때마다 다음 불변식을 만족
	// 1. 피벗보다 작은 원소 그룹 : A[0, smaller-1]
	// 2. 피벗과 같은 원소 그룹	: A[smaller, equal-1]
	// 3. 미분류 원소 그룹		: A[equal, larger-1]
	// 4. 피벗보다 큰 원소 그룹	: A[larger, size(A)- 1]
	int smaller = 0, equal = 0, larger = size(A);
	while (equal < larger) {
		if (A[equal] < pivot) { 
			// A[equal]은 미분류 원그룹에 속한다. 이 미분류 원소가 피벗보다 작으면 작은 그룹에 속한다.
			// 작은 부분의 인덱스 안에 추가하고 다음 미분류 원소의 인덱스로 이동
			swap(A[smaller++], A[equal++]);
		}
		else if (A[equal] == pivot) {
			// 미분류된 원소가 피벗과 같다면 다음 미분류 원소 검사를 위해서 배열을 변경하지 않고 넘어간다.
			equal++;
		}
		else {
			// 작거나 같지 않다면 크다는 것이다. 그러면 제일 마지막부터 해서 피벗보다 큰 부분으로 구분한다.
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