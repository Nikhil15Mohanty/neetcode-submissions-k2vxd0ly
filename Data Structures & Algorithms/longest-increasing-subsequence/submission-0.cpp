#include<cstring>
class Solution {
public:
    int n;
    int t[1001][1001];
    int solve(vector<int>& nums, int index, int currentIndex) {
        if (currentIndex >=n ) {
            return 0;
        }

        if (index !=  -1 && t[currentIndex][index] != -1) return t[currentIndex][index];

        int take=0;
        if (index == -1 || nums[currentIndex] > nums[index]) {
            take = 1 + solve(nums,currentIndex, currentIndex+1);
        }
        int skip = solve(nums, index, currentIndex+1);

        return t[currentIndex][index]=max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        n = nums.size();
        return solve(nums, -1, 0);
    }
};
