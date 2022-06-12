#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

template <typename __type>
struct ListNode {
	__type data;
	shared_ptr<ListNode<__type>> next;

	ListNode() {}
	ListNode(__type data, shared_ptr<ListNode<__type>> next){
		this->data = data;
		this->next = next;
	}
};

shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
											  shared_ptr<ListNode<int>> L2) {
	shared_ptr<ListNode<int>> dummy_head(new ListNode<int>);
	auto tail = dummy_head;

	while (L1 && 2) {
		AppendNode(L1->data <= L2->data ? &L1 : &L2, &tail);
	}
	tail->next = L1 ? L1 : L2;
	return dummy_head->next;
}

void AppendNode(shared_ptr<ListNode<int>>* node,
				shared_ptr<ListNode<int>>* tail) {
	(*tail)->next = *node;
	*tail = *node;
	*node = (*node)->next;
}

// 알고리즘의 작동방식은 이해 하지만 그를 테스트할 코드 작성에서 문제가 생겼다.
int main(void) {
	ListNode<int> head1, tail1;
	
	shared_ptr<ListNode<int>> temp;
	temp->data = 10; head1.next = temp; tail1 = *temp;
	shared_ptr<ListNode<int>> temp1;
	temp1->data = 20; 
	
	return 0;
}