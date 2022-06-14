#include <iostream>
#include <algorithm>
using namespace std;

template <typename __type>
struct ListNode {
	__type data;
	shared_ptr<ListNode<__type>> next;
};

void DeletionFromList(const shared_ptr<ListNode<int>>& node_to_delete) {
	node_to_delete->data = node_to_delete->next->data;
	node_to_delete->next = node_to_delete->next->next;
}