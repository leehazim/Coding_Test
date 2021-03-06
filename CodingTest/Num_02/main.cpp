#include <iostream>
#include <algorithm>
using namespace std;

template <typename __type>
struct ListNode {
	__type data;
	
	shared_ptr<ListNode<__type>> next;
};

shared_ptr<ListNode<int>> ReverseSubList(shared_ptr<ListNode<int>> L, int start, int finish) {
	auto dummy_head = make_shared<ListNode<int>>(0, L);
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