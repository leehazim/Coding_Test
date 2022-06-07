#include <iostream>
#include <vector>
#include <algorithm>

double BuyAndSellStockTwice(const std::vector<double>& prices) {
	double max_total_profit = 0;
	std::vector<double> first_buy_sell_profits(size(prices), 0);
	double min_price_so_far = std::numeric_limits<double>::infinity();

	for (int i = 0; i < size(prices); i++) {
		min_price_so_far = std::min(min_price_so_far, prices[i]);
		max_total_profit = std::max(max_total_profit, prices[i] - min_price_so_far);
		first_buy_sell_profits[i] = max_total_profit;
	}

	double max_price_so_far = std::numeric_limits<double>::min();
	for (int i = size(prices) - 1; i > 0; i--) {
		max_price_so_far = std::max(max_price_so_far, prices[i]);
		max_total_profit = std::max(max_total_profit, 
									max_price_so_far - prices[i] + first_buy_sell_profits[i]);
	}
	return max_total_profit;
}