class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int product;
        int ans = nums[0];
        for (int i = 0; i<size; i++) {
            product = 1;
            for (int j = i; j<size; j++) {
                product *= nums[j];
                ans = max(ans, product);
            }
        }

        return ans;
    }
};
