class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums, target) {
        const m = new Map();

        nums.map((num, index) => (
            m.set(num, index)
        ));

        for (const [index, num] of nums.entries()) {
            const rem = target - num;
            if (m.has(rem) && m.get(rem) !== index) return [index, m.get(rem)]
        }

        return []

    }
}
