#include<bits/stdc++.h>
class Solution {
public:
    int size;
    int t[31][3001];
    int solve(vector<int>& stones, int currentIndex, int currentSum, int totalSum) {
        if (currentIndex == size) {
            return abs(totalSum - (2 * currentSum));
        }

        if (t[currentIndex][currentSum] != -1) return t[currentIndex][currentSum];

        int take = solve(stones, currentIndex +1, currentSum + stones[currentIndex], totalSum);
        int notTake = solve(stones, currentIndex + 1, currentSum, totalSum);

        return t[currentIndex][currentSum] = min(take, notTake);
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(t, -1, sizeof(t));
        size = stones.size();
        int totalSum = 0;
        for (int stone : stones) {
            totalSum+= stone;
        }

        return solve(stones, 0, 0, totalSum);
    }
};