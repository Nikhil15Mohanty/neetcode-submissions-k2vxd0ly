class Solution {
    /**
     * @param {number[]} nums
     * @param {number} val
     * @return {number}
     */
    removeElement(nums, val) {
        let new_size = 0;
        for (let i = 0; i< nums.length; i++) {
            if (nums[i] != val) {
                nums[new_size] = nums[i];
                new_size++;
            }
        }
        return new_size;
    }
}
