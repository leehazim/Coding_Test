#include <iostream>
#include <algorithm>
using namespace std;

template <typename __type>
struct ListNode {
	__type data;
	shared_ptr<ListNode<__type>> next;
};

shared_ptr<ListNode<int>> HasCycle(const shared_ptr<ListNode<int>>& head) {
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

shared_ptr<ListNode<int>> OverlappingNoCycleLists(shared_ptr<ListNode<int>> l0, shared_ptr<ListNode<int>> l1) {
	int l0_len = Length(l0), l1_len = Length(l1);

	AdvanceListByK(abs(l0_len - l1_len), l0_len > l1_len ? &l0 : &l1);

	while (l0 && l1 && l0 != l1) {
		l0 = l0->next, l1 = l1->next;
	}
	return l0;
}

int Length(shared_ptr<ListNode<int>> L) {
	int length = 0;
	while (L) {
		length++;
		L = L->next;
	}
	return length;
}

void AdvanceListByK(int k, shared_ptr<ListNode<int>>* L) {
	while (k--) {
		*L = (*L)->next;
	}
}

shared_ptr<ListNode<int>> OverlappingLists(shared_ptr<ListNode<int>> l0, shared_ptr<ListNode<int>> l1) {
	auto root0 = HasCycle(l0), root1 = HasCycle(l1);

	if (!root0 && !root1) {
		return OverlappingNoCycleLists(l0, l1);
	}
	else if ((root0 && !root1) || (!root0 && root1)) {
		return nullptr;
	}

	auto temp = root1;
	do {
		temp = temp->next;
	} while (temp != root0 && temp != root1);
	return temp == root0 ? root1 : nullptr;
}

int Distance(shared_ptr<ListNode<int>> a, shared_ptr<ListNode<int>> b) {
	int dis = 0;
	while (a != b) {
		a = a->next;
		dis++;
	}
	return dis;
}