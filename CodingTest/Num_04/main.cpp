#include <iostream>
#include <algorithm>
using namespace std;

template <typename __type>
struct ListNode {
	__type data;
	shared_ptr<ListNode<__type>> next;
};

shared_ptr<ListNode<int>> OverlappingNoCycleLists(shared_ptr<ListNode<int>> l0,	shared_ptr<ListNode<int>> l1) {
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