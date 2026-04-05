#include<cstring>
class Solution {
public:
    int t[101];
    int solve (vector<int>& nums, int index) {
        if (index >= nums.size()) {
            return 0;
        }

        if (t[index] != -1) return t[index];

        int result = max(nums[index] + solve(nums, index+2), solve(nums, index+1));
        return t[index] = result;
    }
    int rob(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(nums, 0);
    }
};