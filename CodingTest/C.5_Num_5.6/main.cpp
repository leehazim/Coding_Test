#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

double BuyAndSellStockOnce(const std::vector<double>& prices) {
	// �ּҰ��� double�� ���� �� �ִ� �ִ��� ���� ��, ������ �ǸŰ� ��Ģ�̶� ù��° ���������� ���� ���� ���� �� ������ �̿��Ͽ� ����ȭ��
	double min_price_so_far = std::numeric_limits<double>::infinity(), max_profit = 0;
	// ������� for�� for(������ Ÿ�� element : ������ ����Ʈ(�迭, ����))���� �ڵ����� ��� ���� ��ȸ�ϰ� ����.
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
	std::cout << "���� �ֽ� �ִ� ������ : " << result << "�Դϴ�." << std::endl;
	return 0;
}