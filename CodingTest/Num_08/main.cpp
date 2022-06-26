#include <iostream>
#include <algorithm>
#include <array>
#include <memory>
using namespace std;

template<typename __type>
struct ListNode {
	__type data;
	ListNode<__type>* next;

	ListNode() {
		data = 0;
		next = nullptr;
	}
};

template<typename __type>
struct ListNode1{
	__type data;
	shared_ptr<ListNode1<__type>> next;
};

template<typename __type>
class List {
public:
	List() {
		_head = new ListNode<int>();
		_tail = nullptr;
		temp = nullptr;
	}
	~List() {
		if (_head != nullptr) {
			while (_head) {
				ListNode<__type>* temp = _head;
				_head = _head->next;
				delete temp;
			}
		}
		if (_tail != nullptr) _tail = nullptr;
	}
	
	void PushBack(__type data) {
		temp = new ListNode<__type>();
		temp->data = data;
		temp->next = nullptr;
		
		if (_head->next == nullptr) {
			_head->next = temp;
			_tail = temp;
			temp = nullptr;		
			return;
		}
		
		_tail->next = temp;
		_tail = temp;
	}

	ListNode<__type>* FindNode(__type data) {
		temp = _head;
		while (temp) {
			if (temp->data == data) {
				return temp;
			}
			temp = temp->next;
		}
	}

	void PrintNode() {
		temp = _head->next;
		while (temp) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
	}

	// 중복된 원소를 삭제 정렬된 리스트라고 가정
	void RemoveSameComponent() {
		ListNode<__type>* temp1, * temp2;
		temp1 = _head->next;
		temp2 = _head->next->next;
		
		while (temp2) {
			if (temp1->data == temp2->data) {
				ListNode<__type>* tmp = temp2;
				temp2 = temp2->next;
				temp1->next = temp2;
				delete tmp;
				tmp = nullptr;
			}
			else {
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
		}
	}

	void MergeOdd() {
		ListNode<int>* temp1, * temp2;
		temp = _head->next;
		while (temp) {
			temp1 = temp->next;
			if (temp1 == nullptr) return;
			temp2 = temp->next->next;
			if (temp->data % 2 == 0 && /*현재 노드가 짝수*/
-				temp1->data % 2 == 0 && /* 다음 노드가 짝수*/
				temp2->data % 2 != 0) { /* 다다음 노드가 홀수*/
				temp->next = temp2;
				temp1->next = temp2->next;
				temp2->next = temp1;
			}
			else if (temp->data % 2 != 0 &&
-					 temp1->data % 2 != 0 &&
					 temp2->data % 2 == 0) {
				temp->next = temp2;
				temp1->next = temp2->next;
				temp2->next = temp1;
				temp = temp->next;
			}
		 temp = temp->next;
		}
	}

private:
	ListNode<__type>* _head;
	ListNode<__type>* _tail;
	ListNode<__type>* temp;
};

int main(void) {
	List<int> li;
	srand(time(nullptr));
	for(int i = 0; i < 10; i++){
		li.PushBack(rand() % 100);
	}
	li.PrintNode();
	std::cout << std::endl;
	li.MergeOdd();
	li.PrintNode();

	return 0;
}

// 단순 연결리스트에서 오른쪽 원형 시프트 하기
//std::shared_ptr<ListNode1<int>> CyclicallyRightShiftList(std::shared_ptr<ListNode1<int>> L, int k) {
//	if (L == nullptr) {
//		return L;
//	}
//
//	auto tail = L;
//	int n = 1;
//	while (tail->next) {
//		n++; 
//		tail = tail->next;
//	}
//	k %= n;
//	if (k == 0) {
//		return L;
//	}
//
//	tail->next = L;
//	int steps_to_new_head = n - k;
//	auto new_tail = tail;
//	while (steps_to_new_head--) {
//		new_tail = new_tail->next;
//	}
//
//	auto new_head = new_tail->next;
//	new_tail->next = nullptr;
//	return new_head;
//}

// 책에서의 짝수 홀수 병합 알고리즘
shared_ptr<ListNode1<int>> EvenOddMerge(const std::shared_ptr<ListNode1<int>>& L) {
	if (L == nullptr) return L;

	auto even_dummy_head = make_shared<ListNode1<int>>(0, nullptr);
	auto odd_dummy_head = make_shared<ListNode1<int>>(0, nullptr);
	std::array<std::shared_ptr<ListNode1<int>>, 2> tails = { even_dummy_head,odd_dummy_head };
	int turn = 0;
	for (auto iter = L; iter; iter = iter->next) {
		tails[turn]->next = iter;
		tails[turn] = tails[turn]->next;
		turn ^= 1;
	}
	tails[1]->next = nullptr;
	tails[0]->next = odd_dummy_head->next;
	return even_dummy_head->next;
}