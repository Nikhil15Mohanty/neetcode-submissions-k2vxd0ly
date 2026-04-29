#include<cstring>
class Solution {
public:
    int t[101];

    int solve (vector<int>& nums, int index, int n) {
        if (index > n) {
            return 0;
        }

        if (t[index] != -1) return t[index];

        int steal = nums[index] + solve(nums, index+2, n);
        int skip = solve(nums, index+1, n);

        return t[index] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n==2) return max(nums[0], nums[1]);

        memset(t, -1, sizeof(t));
        int steal_first_house = solve(nums, 0, n-2);

        memset(t, -1, sizeof(t));
        int skip_first_house = solve(nums, 1, n-1);

        return max(steal_first_house, skip_first_house);
    }
};
