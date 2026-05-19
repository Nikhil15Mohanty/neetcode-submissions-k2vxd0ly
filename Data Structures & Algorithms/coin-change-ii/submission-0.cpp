#include<bits/stdc++.h>
class Solution {
public:
    int n;
    int t[101][5001];
    int solve(vector<int>& coins, int amount, int currentIndex) {
        if (amount == 0) return 1;

        if (amount < 0) return 0;

        if (currentIndex >= n) return 0;

        if (t[currentIndex][amount] != -1) return t[currentIndex][amount];

        int take = solve(coins, amount - coins[currentIndex], currentIndex);
        int skip = solve(coins, amount, currentIndex+1);

        return t[currentIndex][amount]=take + skip;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(t, -1, sizeof(t));
        return solve(coins, amount, 0);
    }
};
