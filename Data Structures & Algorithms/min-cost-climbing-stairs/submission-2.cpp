#include<bits/stdc++.h>
class Solution {
public:
    int n;
    int t[101];
    int solve(int index, vector<int>& cost) {
        if (index >= n) return 0;
        if (t[index] != -1) return t[index];
        return t[index] = cost[index] + min(solve(index+1, cost), solve(index+2, cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t, -1, sizeof(t));
        n = cost.size();
        return min(solve(0, cost), solve(1, cost));
    }
};
