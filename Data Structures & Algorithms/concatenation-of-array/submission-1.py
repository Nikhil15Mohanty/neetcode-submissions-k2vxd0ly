class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        ans = [0] * (2 * len(nums))
        for index, num in enumerate(nums):
            ans[index] = ans[index + len(nums)] = num
        return ans
        