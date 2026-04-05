class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        vector<bool> checkForMissingValue(size+1, false);

        for (int i = 0; i <= size; i++) {
            if (nums[i] <= 0) {
                continue;
            }

            if (nums[i] > size) {
                continue;
            }

            checkForMissingValue[nums[i]] = true;
        }

        for (int i = 1; i <=size; i++) {
            if (checkForMissingValue[i] != true) {
                return i;
            }
        }
        return size + 1;
    }
};