#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int t[1001][1001];

    int solve(int index, int prev, vector<int>& nums, int size) {

        if (index >= size)
            return 0;

        // shifted by +1
        if (t[index][prev + 1] != -1)
            return t[index][prev + 1];

        int skip = solve(index + 1, prev, nums, size);

        int take = 0;

        if (prev == -1 || nums[index] > nums[prev]) {
            take = 1 + solve(index + 1, index, nums, size);
        }

        return t[index][prev + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {

        memset(t, -1, sizeof(t));

        int size = nums.size();

        return solve(0, -1, nums, size);
    }
};