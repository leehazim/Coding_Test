#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

double BuyAndSellStockOnce(const std::vector<double>& prices) {
	// 최소값을 double이 가질 수 있는 최대의 값을 줌, 매입후 판매가 규칙이라서 첫번째 구간에서의 값이 답이 있을 수 없음을 이용하여 간소화됨
	double min_price_so_far = std::numeric_limits<double>::infinity(), max_profit = 0;
	// 범위기반 for문 for(데이터 타입 element : 데이터 리스트(배열, 벡터))등을 자동으로 모든 구간 순회하게 해줌.
	for (double price : prices) {
		double max_profit_sell_today = price - min_price_so_far;
		max_profit = max(max_profit, max_profit_sell_today);
		min_price_so_far = min(min_price_so_far, price);
	}
	return max_profit;
}

int main(void) {
	std::vector<double> q = { 310, 315, 275, 295, 260, 270, 290, 230, 255, 250 };
	double result = BuyAndSellStockOnce(q);
	std::cout << "금일 주식 최대 이윤은 : " << result << "입니다." << std::endl;
	return 0;
}