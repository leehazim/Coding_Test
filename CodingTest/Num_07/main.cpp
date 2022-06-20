#include <iostream>
#include <algorithm>
using namespace std;

template <typename __type>
struct LinkNode {
	__type data;
	shared_ptr<LinkNode<__type>> next;
};

shared_ptr<LinkNode<int>> RemoveKthLast(const shared_ptr<LinkNode<int>>& L, int k) {
	auto dummy_head = make_shared<LinkNode<int>>(0, L);
	auto first = dummy_head->next;
	while (k--) {
		first = first->next;
	}

	auto second = dummy_head;
	while (first) {
		second = second->next, first = first->next;
	}
	second->next = second->next->next;
	return dummy_head->next;
}

// shared_ptr<typename __type> == 
// 참조 사용이 끝나면 객체를 자동으로 해제해주는 스마트 포인터
// 사용방식은 shared_ptr<type> data(new type()); 방식으로 할당한다.
int main(void) {
	shared_ptr<LinkNode<int>> temp(new LinkNode<int>);
	shared_ptr<LinkNode<int>> head(new LinkNode<int>);
	temp->data = 10;
	temp->next = nullptr;
	head->data = 0;
	head->next = temp;
	 
	cout << head->next->data << endl;
	
	return 0;
}