#include<bits/stdc++.h>
class Solution {
public:
    int n;
    int t[5001][2];
    int solve(vector<int>& prices, int currentIndex, bool canBuy) {
        if (currentIndex >= n) {
            return 0;
        }

        if (t[currentIndex][canBuy] != -1) return t[currentIndex][canBuy];

        if (canBuy) {
            int buy = -prices[currentIndex] + solve(prices, currentIndex+1, false);
            int skip = solve(prices, currentIndex+1, true);

            return t[currentIndex][canBuy]=max(buy, skip);
        } else {
            int sell = prices[currentIndex] + solve(prices, currentIndex+2, true);
            int hold = solve(prices, currentIndex+1, false);

            return t[currentIndex][canBuy]=max(sell, hold);
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(t, -1, sizeof(t));
        n = prices.size();
        return solve(prices, 0, true);
    }
};
