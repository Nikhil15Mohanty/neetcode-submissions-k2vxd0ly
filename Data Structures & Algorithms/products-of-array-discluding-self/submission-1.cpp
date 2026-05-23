class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result;
        for (int i = 0; i<size; i++) {
            int product = 1;
            for (int j = 0; j<size; j++) {
                if (nums[i] == nums[j] && i == j) {
                    continue;
                }
                else {
                    product*= nums[j];
                }
            }

            result.push_back(product);
        }

        return result;
    }
};
