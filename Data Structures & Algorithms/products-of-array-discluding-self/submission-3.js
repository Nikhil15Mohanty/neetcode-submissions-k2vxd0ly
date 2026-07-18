class Solution {
    /**
     * @param {number[]} nums
     * @return {number[]}
     */
    solve(nums, index) {
        let val = 1;
        for (let i = 0; i < nums.length; i++) {
            if (index == i) continue;
            val *= nums[i];
        }

        return val;
    }
    productExceptSelf(nums) {
        const result = [];
        let value;
        for (let i = 0; i < nums.length; i++) {
            value = this.solve(nums, i);
            result.push(value);
        }

        return result;
    }
}
