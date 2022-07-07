#include <iostream>
#include <algorithm>
#include <memory>
#include <stack>
using namespace std;

/// <summary>
/// 책의 예제를 보고 따라한 클래스
/// </summary>
class StackBook {
public:
	bool Empty() const { return empty(element_with_cached_max_); }
	int Max() const { return element_with_cached_max_.top().max; }

	int Pop() {
		int pop_element = element_with_cached_max_.top().element;
		element_with_cached_max_.pop();
		return pop_element;
	}

	void Push(int x) {
		element_with_cached_max_.emplace(
			ElementWithCachedMax{ x, max(x, Empty() ? x : Max()) });
	}

private:
	// Num1 스택내의 최대값을 확인하는 메소드
	struct ElementWithCachedMax { int element, max; };
	stack<ElementWithCachedMax> element_with_cached_max_;
};

// 직접 생각한 클래스
template <typename __type>
class Stack {
public:
	Stack() : m_arr(nullptr), m_size(-1), m_capacity(0), m_growby(10), m_max(0), m_min(99999999999) {}
	Stack(int size) : m_capacity(size), m_size(-1), m_growby(10), m_max(0), m_min(99999999999) {
		m_arr = new __type[m_capacity];
	}
	~Stack() { if (m_arr != nullptr) delete[] m_arr; }

	void Push(__type value);
	__type Top();
	void Pop();
	bool Empty();

	// Num 1 스택 내의 최대 최소값을 구하는 구현을 추가하기
	__type GetMax() const { return m_max; }
	__type GetMin() const { return m_min; }
	int GetSize() const { return m_size; }
	int GetCapacity() const { return m_capactiy; }

private:
	__type* m_arr;
	int m_size; 
	int m_capacity;
	const int m_growby;

	__type m_max;
	__type m_min;
};

template<typename __type>
void Stack<__type>::Push(__type value) {
	if (m_arr == nullptr){
		m_capacity += m_growby;
		m_arr = new __type[m_capacity];
	}

	if ((m_size + 1) > m_capacity) {
		__type* temp = new __type[m_capacity];
		for (int i = 0; i <= m_size; i++) temp[i] = m_arr[i];
		delete[] m_arr; m_arr = nullptr;
		m_capacity += m_growby;
		m_arr = new __type[m_capacity];
		for (int i = 0; i <= m_size; i++) m_arr[i] = temp[i];
		delete[] temp;
	}	

	if (value > m_max) m_max = value;
	if (value < m_min) m_min = value;
	m_arr[++m_size] = value;
} 

template<typename __type>
__type Stack<__type>::Top() {
	return m_arr[m_size];
}

template<typename __type>
void Stack<__type>::Pop() {
	if (Empty) return;
	if (m_arr[m_size] == m_max || m_arr[m_size] == m_min) {
		m_max = 0;
		m_min = 999999999;
		for (int i = 0; i < m_size; i++) {
			if (m_arr[i] > m_max) m_max = m_arr[i];
			if (m_arr[i] < m_min) m_min = m_arr[i];
		}
	}
	m_size--;
}

template<typename __type>
bool Stack<__type>::Empty() {
	return m_size == -1 ? true : false;
}

int main(void) {
	Stack<int> s;
	s.Push(10);
	
	return 0;
}