class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    majorityElement(nums) {
        let candidate = 0;
        let count = 0;
        nums.forEach((num) => {
            if (count == 0) {
                candidate = num;
                count++;
            } else if (count && candidate == num) {
                count++;
            } else {
                count--;
            }
        })

        return candidate;
    }
}
