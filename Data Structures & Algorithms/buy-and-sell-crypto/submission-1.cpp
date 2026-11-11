class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Time complexity: O(N)
        // Space complexity: O(1)
        int buy_idx = 0;
        int max_profit = 0;

        for (int sell_idx = 1; sell_idx < prices.size(); sell_idx++) {
            if (prices[sell_idx] > prices[buy_idx]) {
                max_profit = std::max(max_profit, prices[sell_idx] - prices[buy_idx]);
            }
            else { // prices[sell_idx] <= prices[buy_idx] !!! there is a new minimum on the market, buy at this point
                buy_idx = sell_idx;
            }
        }
        return max_profit;
    }
};
