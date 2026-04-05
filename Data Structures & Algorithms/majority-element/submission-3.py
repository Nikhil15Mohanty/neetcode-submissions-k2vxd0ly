class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = 0
        count = 0
        par_score = len(nums) / 2
        verification = 0
        # select candidate
        for num in nums:
            if count == 0:
                candidate = num
                count = 1
                continue
            if count !=0 and num == candidate:
                count += 1
            else:
                count -= 1
        for num in nums:
            if candidate == num:
                verification += 1
        
        return candidate if verification > par_score else -1