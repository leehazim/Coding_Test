#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

// ���߿� �ٽ� �ѹ� ���� ���� �͵� ��õ
bool CanReachEnd(const std::vector<int>& max_advance_steps) {
	int furthest_reach_so_far = 0, last_index = size(max_advance_steps) - 1;
	for (int i = 0;
		 i <= furthest_reach_so_far && furthest_reach_so_far < last_index; i++) {
		furthest_reach_so_far =
			max(furthest_reach_so_far, max_advance_steps[i] + i);
	}
	return furthest_reach_so_far >= last_index;
}

int main(void) {

	std::vector<int> q = { 3, 3, 1, 0, 2, 0, 1 };
	bool isCanReach = CanReachEnd(q);
	std::cout << "�� �迭�� ������ ���� �� �� " << (isCanReach ? "�ֽ��ϴ�." : "�����ϴ�.") << std::endl;
	return 0;
}