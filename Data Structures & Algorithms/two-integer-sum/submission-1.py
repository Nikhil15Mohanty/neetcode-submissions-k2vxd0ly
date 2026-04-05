class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        has_map = {}
        for index, val in enumerate(nums):
            diff = target - val
            if diff in has_map:
                return [has_map[diff], index]
            has_map[val] = index
        return []
        