#include<bits/stdc++.h>
class Solution {
public:
    int n;
    int t[101];
    int solve(vector<int>& nums, int index) {
        if (index >= n) return 0;
        if (t[index]!= -1) return t[index];
        int pick = nums[index] + solve(nums,index+2);
        int skip = solve(nums, index+1);
        return t[index] = max(pick, skip);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        int result = solve(nums, 0);
        return result;
    }
};
