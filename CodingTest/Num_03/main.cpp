#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template <typename __type>
struct ListNode {
	__type data;
	shared_ptr<ListNode<__type>> next;
};

shared_ptr<ListNode<int>> HasCycle(const shared_ptr<ListNode<int>>& head, shared_ptr<ListNode<int>>) {
	shared_ptr<ListNode<int>> fast = head, slow = head;

	while (fast && fast->next) {
		slow = slow->next, fast = fast->next->next;
		if (slow == fast) {
			int cycle_len = 0;
			do {
				cycle_len++;
				fast = fast->next;
			} while (slow != fast);

			auto cycle_len_advanced_iter = head;
			while (cycle_len--) {
				cycle_len_advanced_iter = cycle_len_advanced_iter->next;
			}
			auto iter = head;
			while (iter != cycle_len_advanced_iter) {
				iter = iter->next;
				cycle_len_advanced_iter = cycle_len_advanced_iter->next;
			}
			return iter;
		}
	}
	return nullptr;
}