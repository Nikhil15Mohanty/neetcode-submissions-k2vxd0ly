class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        for (int buy = 0; buy < n; buy++) {
            for (int sell = buy + 1; sell < n; sell++) {
                int profit = prices[sell] - prices[buy];
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};