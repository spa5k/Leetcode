class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for num in nums:
            absValue = abs(num)

            if nums[absValue-1] < 0:
                return absValue

            nums[absValue-1] *= -1
        return -1