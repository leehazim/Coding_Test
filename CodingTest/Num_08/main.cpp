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
struct ListNode_shared {
	__type data;
	shared_ptr<ListNode_shared<__type>> next;
};

template<typename __type>
class List {
public:
	List() {
		_head = new ListNode<__type>();
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

	void PushFront(__type data) {
		temp = new ListNode<__type>();
		temp->data = data;

		if (_head->next == nullptr) {
			PushBack(data);
			return;
		}
		temp->next = _head->next;		
		_head->next = temp;
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
		ListNode<__type>* temp1, * temp2;
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

// 피벗 어떤 정수 k를 기준으로 k보다 큰 키를 오른쪽으로
// k보다 작은 키를 왼쪽으로 배치하는 과정을 피버팅이라 한다.
// 단순연결 리스트와 정수 k가 주어졌을 때 k를 기준으로 리스트를 피버팅 하는 함수
	// 공간복잡도를 희생해서 만든 알고리즘
	void Pivoting(__type k) {
		ListNode<__type>* small, *smallTmp;
		ListNode<__type>* big, *bigTmp;
		ListNode<__type>* same, *sameTmp;
		small = new ListNode<__type>();
		big = new ListNode<__type>();
		same = new ListNode<__type>();

		temp = _head->next;
		while (temp) {
			if (temp->data == k) {
				sameTmp = same;
				while (sameTmp->next) same = same->next;
				sameTmp->next = new ListNode<__type>();
				sameTmp->next->data = temp->data;
				sameTmp->next->next = nullptr;
			}
			else if (temp->data > k) {
				bigTmp = big;
				while (bigTmp->next) { bigTmp = bigTmp->next; }
				bigTmp->next = new ListNode<__type>();
				bigTmp->next->data = temp->data;
				bigTmp->next->next = nullptr;
			}
			else {
				smallTmp = small;
				while (smallTmp->next) { smallTmp = smallTmp->next; }
				smallTmp->next = new ListNode<__type>();
				smallTmp->next->data = temp->data;
				smallTmp->next->next = nullptr;
			}
			temp = temp->next;
		}
		temp = _head;

		temp->next = small->next;
		while (temp->next) temp = temp->next;
		temp->next = same->next;
		while (temp->next) temp = temp->next;
		temp->next = big->next;
	}

private:
	ListNode<__type>* _head;
	ListNode<__type>* _tail;
	ListNode<__type>* temp;
};

int main(void) {
	List<int> li, li2;
	li.PushFront(4);
	li.PushFront(1);
	li.PushFront(3);
	li2.PushFront(9);
	li2.PushFront(0);
	li2.PushFront(7);
	li.PrintNode();
	cout << endl;
	li2.PrintNode();
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
//shared_ptr<ListNode1<int>> EvenOddMerge(const std::shared_ptr<ListNode1<int>>& L) {
//	if (L == nullptr) return L;
//
//	auto even_dummy_head = make_shared<ListNode1<int>>(0, nullptr);
//	auto odd_dummy_head = make_shared<ListNode1<int>>(0, nullptr);
//	std::array<std::shared_ptr<ListNode1<int>>, 2> tails = { even_dummy_head,odd_dummy_head };
//	int turn = 0;
//	for (auto iter = L; iter; iter = iter->next) {
//		tails[turn]->next = iter;
//		tails[turn] = tails[turn]->next;
//		turn ^= 1;
//	}
//	tails[1]->next = nullptr;
//	tails[0]->next = odd_dummy_head->next;
//	return even_dummy_head->next;
//}
//
//shared_ptr<ListNode1<int>> ReverseSubList(shared_ptr<ListNode1<int>> L, int start, int finish) {
//	auto dummy_head = make_shared<ListNode1<int>>(0, L);
//	auto sublist_head = dummy_head;
//	int k = 1;
//	while (k++ < start) {
//		sublist_head = sublist_head->next;
//	}
//	auto sublist_iter = sublist_head->next;
//	while (start++ < finish) {
//		auto temp = sublist_iter->next;
//		sublist_iter->next = temp->next;
//		temp->next = sublist_head->next;
//		sublist_head->next = temp;
//	}
//	return dummy_head->next;
//}
//
////  Num 11 회문인지 확인하는 알고리즘
//bool IsLinkedListAPalindrome(shared_ptr<ListNode1<int>>L) {
//	shared_ptr<ListNode1<int>>slow = L, fast = L;
//	while (fast && fast->next) {
//		fast = fast->next->next;
//		slow = slow->next;
//	}
//	// list의 노드 개수가 몇개인지 파악하는 코드 추가 후 그 개수를 매개변수로 넘기자.
//
//	auto first_half_iter = L, second_half_iter = ReverseSubList(slow, 0, 10);
//	while (second_half_iter && first_half_iter) {
//		if (second_half_iter->data != first_half_iter->data) return false;
//		second_half_iter = second_half_iter->next;
//		first_half_iter = first_half_iter->next;
//	}
//	return true;
//}

/// <summary>
/// Num 12  피벗 구현하기
/// </summary>
//shared_ptr<ListNode_shared<int>> ListPivoting(const shared_ptr<ListNode_shared<int>>& l, int x) {
//	shared_ptr<ListNode_shared<int>>	less_head(new ListNode_shared<int>),
//										equal_head(new ListNode_shared<int>),
//										greater_head(new ListNode_shared<int>);
//
//	shared_ptr<ListNode_shared<int>>	less_iter = less_head,
//										equal_iter = equal_head,
//										greater_iter = greater_head;
//		
//	shared_ptr<ListNode_shared<int>> iter = l;
//	while (iter) {
//		// 추가 작업AppendNode(&iter, iter->data < x ? &less_iter : iter->data == x ? &equal_iter : &greater_iter);
//	}
//	greater_iter->next = nullptr;
//	equal_iter->next = greater_head->next;
//	less_iter->next = equal_head->next;
//	return less_head->next;
//}

// Num 13 연결리스트를 정수로 사용해서 덧셈하기
shared_ptr<ListNode_shared<int>> AddTwoNumbers(shared_ptr<ListNode_shared<int>> L1,
											   shared_ptr<ListNode_shared<int>> L2) {
	shared_ptr<ListNode_shared<int>> dummy_head(new ListNode_shared<int>);
	auto place_iter = dummy_head;
	int carry = 0;
	while (L1 || L2 || carry) {
		int val = carry + (L1 ? L1->data : 0) + (L2 ? L2->data : 0);
		L1 = L1 ? L1->next : nullptr;
		L2 = L2 ? L2->next : nullptr;
		place_iter->next = make_shared<ListNode_shared<int>>(val % 10, nullptr);
		carry = val / 10, place_iter = place_iter->next;
	}
	return dummy_head->next;
}