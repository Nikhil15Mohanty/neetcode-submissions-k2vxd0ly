class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums) {
        const size = nums.length
        nums.sort((a, b) => a - b);
        for (let i = 0; i<size - 1; i++) {
           if (nums[i] == nums[i+1]) {
            return true
           } 
        }
        return false;
    }
}
