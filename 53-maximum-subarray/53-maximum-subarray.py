class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSubArr = nums[0]

        currentSum = 0

        for n in nums:
            if currentSum < 0:
                currentSum = 0
            currentSum += n
            maxSubArr = max(currentSum, maxSubArr)
        return maxSubArr