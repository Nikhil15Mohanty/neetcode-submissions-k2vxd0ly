class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        bool contains1 = false;
        for (int i = 0; i<size; i++) {
            if (nums[i] == 1) {
                contains1 = true;
            }

            if (nums[i] <= 0 || nums[i] > size) {
                nums[i] = 1;
            }
        }

        for (int i= 0; i< size; i++) {
            int number = abs(nums[i]);
            int index = number - 1;

            if (nums[index] < 0) {
                continue;
            }

            nums[index] *= -1;
        }

        if (contains1 == false) {
            return 1;
        }

        for (int i = 0; i<size; i++) {
            if (nums[i] > 0) {
                return i + 1;
            } 
        }

        return size + 1;
    }
};