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

	// �ߺ��� ���Ҹ� ���� ���ĵ� ����Ʈ��� ����
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
			if (temp->data % 2 == 0 && /*���� ��尡 ¦��*/
-				temp1->data % 2 == 0 && /* ���� ��尡 ¦��*/
				temp2->data % 2 != 0) { /* �ٴ��� ��尡 Ȧ��*/
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

// �ǹ� � ���� k�� �������� k���� ū Ű�� ����������
// k���� ���� Ű�� �������� ��ġ�ϴ� ������ �ǹ����̶� �Ѵ�.
// �ܼ����� ����Ʈ�� ���� k�� �־����� �� k�� �������� ����Ʈ�� �ǹ��� �ϴ� �Լ�

	void Pivoting(int k) {
		temp = _head;
		// �ǹ����� ���� ���� ��带 ã�´�.
		while (temp) {
			if (temp->data == k)break;
			temp = temp->next;
		}
		// ��尡 ������ ������.
		if(temp == nullptr) return;
		
		// �ǹ����� ���� ������ ���� ���Ѵ�.
		ListNode<__type>* pivot = temp;
		ListNode<__type>* first_half = _head, *first_half_next = _head->next;
		ListNode<__type>* second_half = temp->next, * second_half_next = temp->next->next;

		while (true) {
			while (first_half_next->data < pivot->data) {
				// ��� ��庸�� �� ��带 ������ �ִ´�.
				first_half = first_half->next;
				first_half_next = first_half_next->next;
			}
			while (second_half_next->data < pivot->data) {
				second_half_next = second_half_next->next;
				second_half = second_half->next;
			}

			if (!second_half_next || !first_half_next) return;

			ListNode<__type>* tmp = second_half_next->next;
			first_half->next = second_half_next;
			second_half_next->next = first_half_next->next;
			first_half_next->next = tmp;
			second_half->next = first_half_next;
		}
		
	}
private:
	ListNode<__type>* _head;
	ListNode<__type>* _tail;
	ListNode<__type>* temp;
};

int main(void) {
	List<int> li;
	li.PushBack(20);
	li.PushBack(50);
	li.PushBack(100);
	li.PushBack(130);
	li.PushBack(30);
	li.PushBack(60);
	li.PushBack(40);
	li.PushBack(0);
	li.PushBack(70);
	li.PushBack(80);
	li.PushBack(90);
	li.PushBack(110);
	li.PushBack(120);
	li.PrintNode();
	std::cout << std::endl;
	li.Pivoting(40);
	li.PrintNode();

	return 0;
}

// �ܼ� ���Ḯ��Ʈ���� ������ ���� ����Ʈ �ϱ�
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

// å������ ¦�� Ȧ�� ���� �˰���
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

shared_ptr<ListNode1<int>> ReverseSubList(shared_ptr<ListNode1<int>> L, int start, int finish) {
	auto dummy_head = make_shared<ListNode1<int>>(0, L);
	auto sublist_head = dummy_head;
	int k = 1;
	while (k++ < start) {
		sublist_head = sublist_head->next;
	}
	auto sublist_iter = sublist_head->next;
	while (start++ < finish) {
		auto temp = sublist_iter->next;
		sublist_iter->next = temp->next;
		temp->next = sublist_head->next;
		sublist_head->next = temp;
	}
	return dummy_head->next;
}

// ȸ������ Ȯ���ϴ� �˰���
bool IsLinkedListAPalindrome(shared_ptr<ListNode1<int>>L) {
	shared_ptr<ListNode1<int>>slow = L, fast = L;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	// list�� ��� ������ ����� �ľ��ϴ� �ڵ� �߰� �� �� ������ �Ű������� �ѱ���.

	auto first_half_iter = L, second_half_iter = ReverseSubList(slow, 0, 10);
	while (second_half_iter && first_half_iter) {
		if (second_half_iter->data != first_half_iter->data) return false;
		second_half_iter = second_half_iter->next;
		first_half_iter = first_half_iter->next;
	}
	return true;
}