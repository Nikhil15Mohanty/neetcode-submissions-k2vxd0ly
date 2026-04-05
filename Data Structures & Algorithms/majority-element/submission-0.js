class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    majorityElement(nums) {
        const hash_map = new Map();
        nums.forEach((eachNumber) => {
            if (hash_map.has(eachNumber)) {
                hash_map.set(eachNumber,hash_map.get(eachNumber) + 1)
            } else {
                hash_map.set(eachNumber, 1);
            }
        });

        let parScore = nums.length / 2;
        let result;
        hash_map.forEach((value, key) => {
            if (value > parScore) {
                result =  key;
            }
        })
        return result;
    }
}
