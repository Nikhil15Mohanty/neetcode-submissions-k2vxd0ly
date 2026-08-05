class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int bestStockToBuy = prices[0];
        int maxProfit = 0;

        for (int i = 1; i<n;i++) {
            if (prices[i] < bestStockToBuy) {
                bestStockToBuy = prices[i];
            } else {
                maxProfit = max(maxProfit, prices[i] - bestStockToBuy);
            }
        }
        return maxProfit;
    }
};
