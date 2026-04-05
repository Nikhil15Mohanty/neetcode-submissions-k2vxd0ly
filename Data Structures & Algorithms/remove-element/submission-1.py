class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        new_size = 0;
        for i in range(len(nums)):
            if nums[i] != val:
                nums[new_size] = nums[i]
                new_size+=1
        return new_size

        