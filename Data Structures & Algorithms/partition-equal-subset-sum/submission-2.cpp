#include<bits/stdc++.h>
class Solution {
public:
    bool t[101][51];
    bool solve(int index, vector<int>&nums, int target) {
         if (target == 0) return true;
         if (t[index][target] != false) return t[index][target];
         if (index >= nums.size()) return false;

         bool skip = solve(index +1, nums, target);
         bool take = false;
         if (nums[index] <= target) {
            take = solve(index +1, nums, target - nums[index]);
         }

         return t[index][target] = take | skip;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        memset(t, false, sizeof(t));
        for (auto num: nums) {
            total += num;
        }
        if (total % 2 != 0) return false;
        return solve(0, nums, total/2);
    }
};
