class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        hash_map = {}
        par_score = len(nums) / 2
        for num in nums:
            if num in hash_map:
                hash_map[num] = hash_map[num] + 1
            else:
                hash_map[num] = 1
        for num in hash_map:
            if hash_map[num] > par_score:
                return num
        return -1