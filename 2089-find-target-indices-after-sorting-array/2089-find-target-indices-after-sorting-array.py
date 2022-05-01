class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        # sort the array
        nums.sort()

        left = 0
        right = len(nums)-1
        res = []
        while left <= right:
            mid = (left+right) // 2
            if nums[mid] >= target:
                right = mid - 1
            else:
                left = mid + 1
        for i in range(left, len(nums)):
            if nums[i] == target:
                res.append(i)
            else:
                break

        return res