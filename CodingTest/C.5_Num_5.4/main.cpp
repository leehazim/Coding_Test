#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

// 나중에 다시 한번 살펴 보는 것도 추천
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
	std::cout << "이 배열은 끝까지 도달 할 수 " << (isCanReach ? "있습니다." : "없습니다.") << std::endl;
	return 0;
}