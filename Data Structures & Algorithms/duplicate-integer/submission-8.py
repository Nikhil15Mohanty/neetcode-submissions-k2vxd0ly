class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        my_set = set()
        for val in nums:
            if val in my_set:
                return True
            my_set.add(val)
        return False
        