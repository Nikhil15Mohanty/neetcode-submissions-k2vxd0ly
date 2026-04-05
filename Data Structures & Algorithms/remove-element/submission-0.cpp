class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int new_size = 0;
        for (int i = 0; i< nums.size(); i++) {
            if (nums[i] != val) {
                nums[new_size] = nums[i];
                new_size++;
            }
        }
        return new_size;
    }
};